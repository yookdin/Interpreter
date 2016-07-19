//
//  AST.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/16/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef AST_hpp
#define AST_hpp

#include "common.h"
#include "Token.hpp"
#include "ParseStackElement.hpp"
#include "Operator.hpp"

//==========================================================================================================
//==========================================================================================================
class AST {
public:
    AST(Symbol _sym): sym(_sym) {}
    virtual void execute() = 0;
    void print();
    
protected:
    const Symbol sym;
    vector<AST*> children;
    
    virtual void print_node() = 0;
    void recursive_print(int indentation_level);
};


//==========================================================================================================
//==========================================================================================================
class NumAST: public AST {
public:
    NumAST(vector<TokenOrAST>& elements);
    void print_node();
    void execute();
    const int num;
    
private:
    int extract_num(vector<TokenOrAST>& elements);
};


//==========================================================================================================
//==========================================================================================================
class OpAST: public AST {
public:
    OpAST(Symbol sym, Operator* _op): AST(sym), op(_op){}
    void print_node() { cout << symbol_str_map[sym] << endl; }
    virtual void execute() = 0;
protected:
    const Operator* op;
};


//==========================================================================================================
//==========================================================================================================
class BopAST: public OpAST {
public:
    BopAST(vector<TokenOrAST>& elements);
    void execute();
};


//==========================================================================================================
//==========================================================================================================
class UopAST: public OpAST {
public:
    UopAST(vector<TokenOrAST>& elements);
    void execute();
};



#endif /* AST_hpp */
