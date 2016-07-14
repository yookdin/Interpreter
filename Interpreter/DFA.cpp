
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
DFA::DFA(NFA nfa) {
    nfa_to_dfa(nfa);
    minimize();
}


//==========================================================================================================
// Create a DFA from an NFA using the Subset-Construction algorithm
//==========================================================================================================
void DFA::nfa_to_dfa(NFA& nfa) {
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
    table.push_back(vector<int>(NUM_TABLE_SYMBOLS, -1)); // Adding the start state
    
    //------------------------------------------------------------------------------------------------------
    // As long as there are new states in the DFA, calcuate the transitions for them, while creating new
    // states if needed
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < table.size(); ++i) {
        for(int sym = 0; sym < NUM_TABLE_SYMBOLS; ++sym) { // For each possible symbol
            
            //----------------------------------------------------------------------------------------------
            // Get the set of reachable NFA states from the current DFA state for the current symbol
            //----------------------------------------------------------------------------------------------
            set<int> reachable_set = nfa.get_rechable_set(nfa_states[i], Symbol(sym));
            for(auto& s: reachable_set) { // Add the epsilon-closure
                reachable_set.insert(epsilon_closures[s].begin(), epsilon_closures[s].end());
            }
            
            if(reachable_set.empty())
                continue;
            
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
            
            table[i][sym] = state; // Add this transition
            if(state == table.size()) { // New state
                nfa_states.push_back(reachable_set);
                table.push_back(vector<int>(NUM_TABLE_SYMBOLS, -1));
            }
            
        } // for each symbol
    } // for each new state
    
    //------------------------------------------------------------------------------------------------------
    // Mark a state as accepting if any of the NFA states corresponding to it are accepting
    //------------------------------------------------------------------------------------------------------
    accepting.resize(get_num_states(), -1);
    for(int i = 0; i < nfa_states.size(); ++i) {
        for(auto s: nfa_states[i]) {
            if(nfa.accepting[s] >= 0) { 
                if(accepting[i] >= 0)
                    throw string("DFA state contain accepting NFA states with different production rules");
                accepting[i] = nfa.accepting[s];
                break;
            }
        }
    }
} // nfa_to_dfa()


//==========================================================================================================
// Mimimize the DFA using Myphill-Nerode based algorithm. The algorithm consider all state pairs, marking
// them as non-equivalent if possible. When finished, those not marked are put in the same new state.
// Steps:
// 1. Mark as non-equivalent those pairs with different accepting values
// 2. Iteratively mark pairs that for any input symbol go to a marked pair (or transition defined just for
//    one of them on that symbol).
// 3. Combine unmarked pairs to form new states.
// 4. Write the new transitions, mark accepting new states
//==========================================================================================================
void DFA::minimize() {
    //------------------------------------------------------------------------------------------------------
    // Create the pairs and do initial mark (true means pair is non-equivalent)
    //------------------------------------------------------------------------------------------------------
    vector<bool*> pairs;
    int num_states = get_num_states();
    
    for(int i = 0; i < num_states - 1; ++i) {
        pairs.push_back(new bool[num_states - i - 1]);
        pairs[i] -= (i+1); // This ugly trick enables accessing pairs[i][j], but actually using just half the memory
        
        for(int j = i+1; j < num_states; ++j) {
            pairs[i][j] = (accepting[i] != accepting[j]);
        }
    }
    
    //------------------------------------------------------------------------------------------------------
    // Mark until an iteration where no changes are made
    //------------------------------------------------------------------------------------------------------
    bool changed = true;
    while(changed) {
        changed = false;
        
        for(int i = 0; i < num_states - 1; ++i) {
            for(int j = i+1; j < num_states; ++j) {
                if(pairs[i][j]) continue; // Pair already marked
                
                for(int sym = 0; sym < NUM_TABLE_SYMBOLS; ++sym) {
                    int x = get_next_state(i, sym), y = get_next_state(j, sym);
                    if(x == y) continue;

                    sort_pair(x,y); // Must have the smaller index first to access pairs table
                    
                    if(x == -1 or pairs[x][y]) {
                        pairs[i][j] = true;
                        changed = true;
                    }
                } // for each symbol
            }
        }
    }
    
    //------------------------------------------------------------------------------------------------------
    // Combine states:
    // 1. A new state is a set of old states which are equivalent
    // 2. If an old state is not equivalent to any other state, a new state is created that contains only it
    // 3. After adding a pair {i,j} (i < j}, there's no need to look at pairs {j,x} (j < x), because pair
    // {i,x} must have already been added.
    //------------------------------------------------------------------------------------------------------
    vector<vector<int>> new_states;
    vector<int> old_to_new(num_states, -1);
    set<int> added_states;
    
    for(int i = 0; i < num_states - 1; ++i) {
        if(added_states.count(i) != 0) continue;
        
        new_states.push_back({i});
        old_to_new[i] = new_states.size() - 1;
        
        for(int j = i+1; j < num_states; ++j) {
            if(not pairs[i][j]) {
                new_states.back().push_back(j);
                old_to_new[j] = new_states.size() - 1;
                added_states.insert(j);
            }
        }
    }
    
    if(added_states.empty()) // No minimization occurred
        return;
    
    // If the last state wasn't combined with any other state, add a new state that contains only it;
    // This is needed because the last state has no entry in the pairs table as a first of any pair
    if(added_states.count(num_states-1) == 0)
        new_states.push_back({num_states-1});
    
    //------------------------------------------------------------------------------------------------------
    // Write new transitions and mark accepting new states. Then replace the old DFA with the new one.
    //------------------------------------------------------------------------------------------------------
    vector<int> new_accepting(new_states.size(), -1);
    vector<vector<int>> new_table(new_states.size(), vector<int>(NUM_TABLE_SYMBOLS, -1));
    
    for(int i = 0; i < new_states.size(); ++i) {
        for(auto s: new_states[i])
            if(accepting[s] != accepting[new_states[i][0]])
                throw string("DFA states found to be equivalent yet have different accepting values");
        
        new_accepting[i] = accepting[new_states[i][0]]; // If the first is accepting they all are, and vice versa
        
        for(int sym = 0; sym < NUM_TABLE_SYMBOLS; ++sym) {
            // Since all old states in this new states are equivalent, need to check only one
            int old_next_state = get_next_state(new_states[i][0], sym);
            if(old_next_state != -1)
                new_table[i][sym] = old_to_new[old_next_state];
        }
    }
    
    accepting = new_accepting;
    table = new_table;
    

    //------------------------------------------------------------------------------------------------------
    // Free memory
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < num_states - 1; ++i) {
        delete (pairs[i] + i + 1);
    }    
} // minimize()



//==========================================================================================================
//==========================================================================================================
void DFA::sort_pair(int& x, int& y) {
    if(x > y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
}


//==========================================================================================================
//==========================================================================================================
void DFA::print() {
    cout << "DFA:" << endl;
    for(int i = 0; i < table.size(); ++i) {
        cout << "state " << i;
        if(accepting[i] >= 0) cout << " (accepting = " << accepting[i] << ") ";
        cout << ":" << endl;

        for(int sym = 0; sym < NUM_TABLE_SYMBOLS; ++sym) {
            if(table[i][sym] >= 0)
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
    // As long as there are states in the list, add their epsilon neighbors, but only if they weren't added
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












