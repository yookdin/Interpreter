//
//  Operator.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/18/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "Operator.hpp"


map<string, Operator*> name_op_map = {
    {"+", new Add()}, {"-", new Subtract()}, {"*", new Mul()}, {"/", new Div()}, {"%", new Mod()},
    {"not", new Not()}, {"or", new Or()}, {"and", new And()},
    {"==", new Equal()}, {"!=", new NotEqual()}, {">", new GreaterThan()}, {"<", new LessThan()}, {">=", new GreaterThanEqual()},
    {"<=", new LessThanEqual()}, {"~", new StringMatch()}, {"!~", new NoStringtMatch()},
    {"?", new QuestionMark()}, {":", new Colon()}, {"?:", new CondExp()}
};


//==========================================================================================================
//==========================================================================================================
Operator::Operator(string _name, int _num_operands, int _precedence, Associativity _associativity):
    name(_name), num_operands(_num_operands), precedence(_precedence), associativity(_associativity) {}


//==========================================================================================================
//==========================================================================================================
bool Operator::should_precede(const Operator& other) {
    return (precedence < other.precedence or (precedence == other.precedence and associativity == LEFT));
}