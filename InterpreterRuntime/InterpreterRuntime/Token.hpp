//
//  Token.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/6/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Token_hpp
#define Token_hpp

#include "Operator.hpp"
#include "sip_tester_utils.hpp"
#include "ParseElement.h"


//==========================================================================================================
//==========================================================================================================
class Token: public ParseElement
{
public:
    Token* get_token() override {
        return this;
    }
    
    bool is_token() override {
        return true;
    }

    Token(Symbol _sym): sym(_sym) {}
    
    string get_name() { return symbol_str_map[sym]; }
    virtual void print() { cout << get_name() << endl; }    
    
    const Symbol sym;
};


//==========================================================================================================
//==========================================================================================================
class TokenWithValue: public Token {
public:
    TokenWithValue(Symbol _sym): Token(_sym) {}
    virtual string value_to_string() = 0;
    virtual void print() { cout << get_name() << ": " << value_to_string() << endl; }
};


//==========================================================================================================
//==========================================================================================================
class NumToken: public TokenWithValue {
public:
    NumToken(string n): TokenWithValue(NUM), val(string_to_int(n)) {}
    string value_to_string() { return to_string(val); }
    const int val;
};


//==========================================================================================================
//==========================================================================================================
class BoolToken: public TokenWithValue {
public:
    BoolToken(string b): TokenWithValue(BOOL), val(stob(b)) {}
    string value_to_string() { return to_string(val); }
    const bool val;
};


//==========================================================================================================
//==========================================================================================================
class StringToken: public TokenWithValue {
public:
    StringToken(string s): TokenWithValue(STRING), val(s) {}
    string value_to_string() { return val; }
    const string val;
};


//==========================================================================================================
//==========================================================================================================
class IdentifierToken: public TokenWithValue {
public:
    IdentifierToken(string _name): TokenWithValue(ID), name(_name) {}
    string value_to_string() { return name; }
    const string name;
};


//==========================================================================================================
// An ID followed by a colon. It solves parsing ambiguities to identify this in the lexing instead of in the
// parsing process
//==========================================================================================================
class ParamToken: public TokenWithValue {
public:
    ParamToken(string _name): TokenWithValue(PARAM), name(_name) {}
    string value_to_string() { return name; }
    const string name;
};


//==========================================================================================================
// Keyword token includes all literal stuff, which means not only the words but also all punctuations and
// operators
//==========================================================================================================
class KeywordToken: public Token {
public:
    KeywordToken(Symbol sym): Token(sym) {} 
};


#endif /* Token_hpp */




























