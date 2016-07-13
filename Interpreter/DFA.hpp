//
//  DFA.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/10/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef DFA_hpp
#define DFA_hpp

#include "common.h"
#include "NFA.hpp"

//==========================================================================================================
//==========================================================================================================
class DFA {
public:
    DFA(NFA& nfa);
    void print();
    
    friend class SLR_Table;
private:
    vector<int> accepting;
    vector<vector<int>> table;
    
    void nfa_to_dfa(NFA& nfa);
    void minimize();
    set<int> calc_epsilon_closure(int state, NFA& nfa);
    inline int get_next_state(int state, int sym) { return table[state][sym]; }
    inline int get_num_states() { return table.size(); }
    inline void sort_pair(int& x, int& y);
};


#endif /* DFA_hpp */
