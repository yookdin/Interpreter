//
//  NFA.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/10/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef NFA_hpp
#define NFA_hpp

#include "common.h"
#include "Grammar.hpp"

//==========================================================================================================
//==========================================================================================================
class NFA {
public:
    NFA(Grammar& grammar);
    void add_transition(int from_state, Symbol sym, int to_state, int to_state_accepting_value = -1);
    void add_epsilon_transition(int from_state, int to_state);
    long get_num_states() { return table.size(); }
    void print();
    
    friend class DFA;
private:    
    void add_state(int state, int accepting_value = -1);
    vector<int> accepting; // -1: not accepting; o/w: accepting and the production rule number
    vector<vector<set<int>>> table;
    set<int>& get_epsilon_transitions(int state);
    set<int> get_rechable_set(set<int>& src_set, Symbol sym);
};


#endif /* NFA_hpp */
