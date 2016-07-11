
//
//  DFA.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/10/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "DFA.hpp"


//==========================================================================================================
//==========================================================================================================
DFA::DFA(NFA& nfa) {
    vector<set<int>> epsilon_closures; // Epsilon closures per NFA state

    //------------------------------------------------------------------------------------------------------
    // Calculate epsilon-closures for each state in the NFA
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < nfa.get_num_states(); ++i) {
        epsilon_closures.push_back(calc_epsilon_closure(i, nfa));     
    }
    
    // Map between DFA state, and a set of NFA states it was constructed from (the index in the vector is the DFA state)
    vector<set<int>> nfa_states;
    nfa_states.push_back(epsilon_closures[0]); // Initial, starting state
    table.push_back({}); // Adding the start state
    
    //------------------------------------------------------------------------------------------------------
    // As long as there are new states in the DFA, calcuate the transitions for them, while creating new
    // states if needed
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < table.size(); ++i) {
        for(int sym = 0; sym < NUM_SYMBOLS; ++sym) { // For each possible symbol

            //----------------------------------------------------------------------------------------------
            // Get the set of reachable NFA states from the current DFA state
            //----------------------------------------------------------------------------------------------
            set<int> reachable_set = nfa.get_rechable_set(nfa_states[i], Symbol(sym));
            for(auto& s: reachable_set) { // Add the epsilon-closure
                reachable_set.insert(epsilon_closures[s].begin(), epsilon_closures[s].end());
            }
            
            if(reachable_set.empty()) {
                table[i].push_back(-1); // Indicating no transition on this symbol for the current state
                continue;
            }

            //----------------------------------------------------------------------------------------------
            // Check if this set already exists as a DFA state
            //----------------------------------------------------------------------------------------------
            int state = table.size();
            for(int j = 0; j < nfa_states.size(); ++j) {
                if(reachable_set == nfa_states[j]) {
                    state = j;
                    break;
                }
            }
            
            table[i].push_back(state); // Add this transition
            if(state == table.size()) { // New state
                nfa_states.push_back(reachable_set);
                table.push_back({});
            }
            
        } // for each symbol
    } // for each new state
    
    //------------------------------------------------------------------------------------------------------
    // Mark a state as accepting if any of the NFA states corresponding to it are accepting
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < nfa_states.size(); ++i) {
        bool cur_accepting = false;
        for(auto s: nfa_states[i]) {
            cur_accepting = cur_accepting or nfa.is_accepting(s);
            if(cur_accepting) break;
        }
        accepting.push_back(cur_accepting);
    }
    
    
} // DFA()


//==========================================================================================================
//==========================================================================================================
void DFA::print() {
    cout << "DFA:" << endl;
    for(int i = 0; i < table.size(); ++i) {
        cout << "state " << i;
        if(accepting[i]) cout << " (accepting) ";
        cout << ":" << endl;

        for(int sym = 0; sym < NUM_SYMBOLS; ++sym) {
            cout << "Transition for symbol " << symbol_to_string(Symbol(sym)) << ": " << table[i][sym] << endl;
        }
        cout << endl;
    }
}
 

//==========================================================================================================
// Calculate the epsiolon closure for a state in the NFA. This is needed for constructing the DFA.
//==========================================================================================================
set<int> DFA::calc_epsilon_closure(int state, NFA& nfa) {
    set<int> res;
    vector<int> cur_states;
    res.insert(state);
    cur_states.push_back(state);
    
    //------------------------------------------------------------------------------------------------------
    // As long as there are states in the list, add their epsilon neighbors, but only if they weren't adde
    // yet
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < cur_states.size(); ++i) {
        for(int s: nfa.get_epsilon_transitions(cur_states[i])) {
            if(res.count(s) == 0) {
                res.insert(s);
                cur_states.push_back(s);
            }
        }
    }
    
    return res;
}












