//
//  Parser.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/13/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "Parser.hpp"


//==========================================================================================================
//==========================================================================================================
Parser::Parser(string grammar_file) {
    Grammar grammar(grammar_file);
    NFA nfa(grammar);
    DFA dfa(nfa);
    table = SLR_Table(grammar, dfa);
}
