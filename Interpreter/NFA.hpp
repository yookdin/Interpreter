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

//==========================================================================================================
//==========================================================================================================
class NFA {
public:
    NFA(int _num_symbols): num_symbols(_num_symbols){}
    void add_transition(int from_state, Symbol sym, int to_state, bool to_state_accepting = false);
    long get_num_states() { return table.size(); }
    bool is_accepting(int state) { return accepting[state]; }
    void print();
    
    friend class DFA;
private:
    const int num_symbols;
    void add_state(int state, bool accepting = false);
    vector<bool> accepting;
    vector<vector<set<int>>> table;
    set<int>& get_epsilon_transitions(int state);
    set<int> get_rechable_set(set<int>& src_set, Symbol sym);
};


#endif /* NFA_hpp */
