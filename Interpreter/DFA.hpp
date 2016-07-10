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
private:
    const int num_symbols;
    vector<bool> accepting;
    vector<vector<int>> table;
    
    set<int> calc_epsilon_closure(int state, NFA& nfa);
    int get_unmarked_element(map<int, bool>& closure);
};


#endif /* DFA_hpp */
