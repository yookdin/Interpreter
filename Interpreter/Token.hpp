//
//  Token.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/6/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Token_hpp
#define Token_hpp

#include "common.h"
#include "Operator.hpp"


//==========================================================================================================
//==========================================================================================================
class Token
{
public:
    Token(Symbol _sym): sym(_sym) {}
    virtual void print() { cout << symbol_str_map[sym] << endl; }
    
    const Symbol sym;
};


//==========================================================================================================
//==========================================================================================================
class NumToken: public Token {
public:
    NumToken(string n): Token(NUM), val(stoi(n)) {}
    void print() { cout << to_string(val) << endl; }
    const int val;
};


//==========================================================================================================
//==========================================================================================================
class IdentifierToken: public Token {
public:
    IdentifierToken(string _name): Token(ID), name(_name) {}
    void print() { cout << name << endl; }
    const string name;
};



//==========================================================================================================
//==========================================================================================================
class OpToken: public Token {
public:
    OpToken(string op): Token(symbol_str_map[op]), op(sym_op_map[sym]) {}
    void print() { cout << symbol_str_map[sym] << endl; }
    
    Operator* op;
};


//==========================================================================================================
//==========================================================================================================
class KeywordToken: public Token {
public:
    KeywordToken(Symbol sym): Token(sym) {} 
};


#endif /* Token_hpp */
