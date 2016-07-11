//
//  NFA.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/10/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "NFA.hpp"


//==========================================================================================================
// Add a state if it doesn't exists yet
//==========================================================================================================
void NFA::add_state(int state, bool accepting_state) {
    if(state < table.size())
        return; // State already exists 
    
    if(state != table.size())
        throw string("Can only add state that is the next after the current last state");
        
    accepting.push_back(accepting_state);
    table.push_back(vector<set<int>>(NUM_SYMBOLS + 1)); // Add one place for epsilon transition
}


//==========================================================================================================
// Add transition from from_state on symbol sym to to_state
//==========================================================================================================
void NFA::add_transition(int from_state, Symbol sym, int to_state, bool to_state_accepting) {
    add_state(from_state);
    add_state(to_state, to_state_accepting);
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
    int i = 0;
    for(auto& state_entry: table) {
        if(accepting[i])
            cout << "Accepting ";
        cout << "state " << i << ":" << endl;
        
        for(int sym = 0; sym < state_entry.size(); ++sym) {
            cout << "Transitions for symbol " << symbol_to_string(Symbol(sym)) << ": ";
            for(auto& state: state_entry[sym])
                cout << state << " ";
            cout << endl;
        }
        cout << endl;
        ++i;
    }
}