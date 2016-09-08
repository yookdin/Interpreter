//
//  Operator.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/18/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "common_headers.h"
#include "Operator.hpp"

//==========================================================================================================
//==========================================================================================================
map<Symbol, Operator*> sym_op_map = { 
    {ADD, new Add()}, //{SUB, new Subtract()}, {MUL, new Mul()}, {DIV, new Div()}, {MOD, new Mod()},
    //{NOT, new Not()}, {OR, new Or()}, {AND, new And()},
    //{EQ, new Equal()}, {NE, new NotEqual()}, {GT, new GreaterThan()}, {LT, new LessThan()}, {GE, new GreaterThanEqual()}, {LE, new LessThanEqual()},
    //{STR_MATCH, new StringMatch()}, {NO_STR_MATCH, new NoStringtMatch()},
    //{QUESTION_MARK, new QuestionMark()}, {COLON, new Colon()}
};


//==========================================================================================================
//==========================================================================================================
bool is_op(Symbol s) { return sym_op_map.count(s) != 0; }
Operator* get_op(Symbol s) { return sym_op_map[s]; } 


