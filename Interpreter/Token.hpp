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

//==========================================================================================================
//==========================================================================================================
class Token
{
public:
    Token(Symbol sym): kind(sym) {}
    virtual void print() { cout << symbol_to_string(kind) << endl; }
    
    const Symbol kind;
};


//==========================================================================================================
//==========================================================================================================
class NumToken: public Token {
public:
    NumToken(string n): Token(NUM), val(stoi(n)) {}
    void print() { cout << symbol_to_string(NUM) << "(" << to_string(val) << ")" << endl; }
    const int val;
};


//==========================================================================================================
//==========================================================================================================
class OpToken: public Token {
public:
    OpToken(string _op): Token(OP), op(_op) {}
    void print() { cout << symbol_to_string(OP) << "(" << op << ")" << endl; }
    
    string op;
};


//==========================================================================================================
//==========================================================================================================
class PunctuationToken: public Token {
public:
    PunctuationToken(Symbol sym): Token(sym) {} 
};


#endif /* Token_hpp */
