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
#include "Grammar.hpp"

int main(int argc, const char * argv[]) {

    try {
        Grammar G;
        G.add_production({START, EXP});
        G.add_production({EXP, NUM});
        G.add_production({EXP, LEFT_PAREN, EXP, RIGHT_PAREN});
        G.add_production({EXP, EXP, OP, EXP});
        
        NFA nfa(G);
        nfa.print();
        
        //    DFA dfa(nfa);
        //    dfa.print();
    } catch (string err) {
        cout << "Error: " << err << endl;
    }
    
    return 0;
}




























