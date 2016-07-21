//
//  Symbols.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/19/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Symbols_hpp
#define Symbols_hpp


#include "common.h"


//==========================================================================================================
//==========================================================================================================
//enum Symbol { START = -1, LEFT_PAREN, RIGHT_PAREN, NUM, ADD, SUB, MUL, DIV, MOD, NOT, OR, AND, EQ, NE, GT, LT, GE, LE, STR_MATCH, NO_STR_MATCH, QUESTION_MARK, COLON, EOI, EXP };
//#define NUM_TABLE_SYMBOLS 23
//#define NONTERMINALS_START (Symbol::EXP)
class Symbols {
    bimap<string, int> constants;
    bimap<string, int> punctuations;
    bimap<string, int> ops;
    bimap<string, int> nonterminals;
};

#endif /* Symbols_hpp */
