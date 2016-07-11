//
//  main.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/6/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "common.h"
#include "NFA.hpp"
#include "DFA.hpp"

int main(int argc, const char * argv[]) {

    NFA nfa;
    nfa.add_transition(0, EXP, 1, true);
    nfa.add_transition(2, NUM, 3, true);
    nfa.add_transition(4, LEFT_PAREN, 5); 
    nfa.add_transition(5, EXP, 6); 
    nfa.add_transition(6, RIGHT_PAREN, 7, true); 
    nfa.add_transition(8, EXP, 9); 
    nfa.add_transition(9, OP, 10); 
    nfa.add_transition(10, EXP, 11, true); 
    nfa.add_epsilon_transition(0, 2);
    nfa.add_epsilon_transition(0, 4); 
    nfa.add_epsilon_transition(0, 8); 
    nfa.add_epsilon_transition(5, 2); 
    nfa.add_epsilon_transition(5, 4); 
    nfa.add_epsilon_transition(5, 8); 
    nfa.add_epsilon_transition(8, 2); 
    nfa.add_epsilon_transition(8, 4); 
    nfa.add_epsilon_transition(8, 8); 
    nfa.add_epsilon_transition(10, 2); 
    nfa.add_epsilon_transition(10, 4); 
    nfa.add_epsilon_transition(10, 8);
    
    DFA dfa(nfa);
    dfa.print();
    
    return 0;
}
