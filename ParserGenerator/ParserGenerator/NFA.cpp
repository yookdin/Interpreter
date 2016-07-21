//
//  NFA.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/10/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "NFA.hpp"


//==========================================================================================================
//==========================================================================================================
NFA::NFA(Grammar& grammar) {
    // Hold the initials states created from productions for a nonterminal. This is needed for adding the 
    // epsilon transitons
    map<Symbol, vector<int>> nonterminals_initial_states;
    int state = 0;
    
    //------------------------------------------------------------------------------------------------------
    // Add transitions for every production
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < grammar.productions.size(); ++i, ++state) {
        if(i > 0) // The start symbol will not have any transitions defined for it
            nonterminals_initial_states[grammar.productions[i][0]].push_back(state);
        
        for(int j = 1; j < grammar.productions[i].size(); ++j, ++state) {
            // When adding a transition on the last symbol of the production, the state is accepting
            int accepting_val = ((j == grammar.productions[i].size() - 1) ? i : -1);
            add_transition(state, grammar.productions[i][j], state + 1, accepting_val);
        }
    }
    
    //------------------------------------------------------------------------------------------------------
    // Add the epsilon transitions: whenever there is a transition from state s to state t on a nonterminal
    // N, we add epsilon transitions from s to the initial states of all the NFAs for productions with N on
    // the left-hand side
    //------------------------------------------------------------------------------------------------------
    for(int s = 0; s < table.size(); ++s) {
        for(int sym = 0; sym < NUM_NON_TERMINALS; ++sym) {
            if(not table[s][sym].empty()) { // Transition is defined
                for(auto i: nonterminals_initial_states[Symbol(sym)]) {
                    add_epsilon_transition(s, i);
                }
            }
        }
    }
}


//==========================================================================================================
// Add a state if it doesn't exists yet
//==========================================================================================================
void NFA::add_state(int state, int accepting_value) {
    if(state < table.size())
        return; // State already exists 
    
    if(state != table.size())
        throw string("Can only add state that is the next after the current last state");
        
    accepting.push_back(accepting_value);
    table.push_back(vector<set<int>>(NUM_SYMBOLS + 1)); // Add one place for epsilon transition
}


//==========================================================================================================
// Add transition from from_state on symbol sym to to_state
//==========================================================================================================
void NFA::add_transition(int from_state, Symbol sym, int to_state, int to_state_accepting_value) {
    add_state(from_state);
    add_state(to_state, to_state_accepting_value);
    table[from_state][sym].insert(to_state);
}


//==========================================================================================================
//==========================================================================================================
void NFA::add_epsilon_transition(int from_state, int to_state) {
    add_state(from_state);
    add_state(to_state);
    table[from_state][NUM_SYMBOLS].insert(to_state);
}


//==========================================================================================================
// Return all the states that can be reached directly from given state using epsilon transitions
//==========================================================================================================
set<int>& NFA::get_epsilon_transitions(int state) {
    return table[state][NUM_SYMBOLS]; // Epsilon transition are written after all the symbols transitions
}


//==========================================================================================================
// Return a set including all the states reachable from states in the given set, for the given input symbol.
// Note: this DOES NOT include the epsilon-closure of the states reachable by that transition.
//==========================================================================================================
set<int> NFA::get_rechable_set(set<int>& src_set, Symbol sym) {
    set<int> res;
    for(auto& state: src_set) {
        res.insert(table[state][sym].begin(), table[state][sym].end());
    }
    
    return res;
}


//==========================================================================================================
//==========================================================================================================
void NFA::print() {
    cout << "NFA" << endl;
    int i = 0;
    for(auto& state_entry: table) {
        string accepting_str;
        if(accepting[i] >= 0)
            accepting_str = " (accepting = " + to_string(accepting[i]) + ")"; 
        
        cout << "state " << i << accepting_str << endl;
        
        for(int sym = 0; sym < state_entry.size(); ++sym) {
            if(not state_entry[sym].empty()) {
                cout << "Transitions for symbol " << symbol_str_map[Symbol(sym)] << ": ";
                for(auto& state: state_entry[sym])
                    cout << state << " ";
                cout << endl;
            }
        }
        cout << endl;
        ++i;
    }
}




















