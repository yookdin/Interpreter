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
    void add_child(AST* ast) {
        if(ast == nullptr) throw string("Trying to add null child");
        children.push_back(ast);
    }

    const Symbol sym;
    vector<AST*> children;
    
protected:
    virtual void print_node() { cout << symbol_str_map[sym] << endl; }
    void recursive_print(int indentation_level);
};


//==========================================================================================================
//==========================================================================================================
class NumAST: public AST {
public:
    NumAST(vector<TokenOrAST>& elements): AST(NUM), num(extract_num(elements)) {}
    void execute();
    const int num;
    
private:
    void print_node() { cout << num << endl; }
    int extract_num(vector<TokenOrAST>& elements);
};


//==========================================================================================================
//==========================================================================================================
class OpAST: public AST {
public:
    OpAST(Symbol sym, Operator* _op): AST(sym), op(_op){}
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


//==========================================================================================================
//==========================================================================================================
class CondExpAST: public OpAST {
public:
    CondExpAST(vector<TokenOrAST>& elements);
    void execute();
};


//==========================================================================================================
//==========================================================================================================
class VarAST: public AST {
public:
    VarAST(string _name): AST(VAR), name(_name) {}
    VarAST(vector<TokenOrAST>& elements): AST(VAR), name(((IdentifierToken*)elements[0].get_token())->name) {} 
    void execute();
    const string name;
    
private:
    virtual void print_node() { cout << name << endl; }
};


//==========================================================================================================
//==========================================================================================================
class AssignmentAST: public AST {
public:
    AssignmentAST(vector<TokenOrAST>& elements);
    void execute();
};


//==========================================================================================================
//==========================================================================================================
class StatementsAST: public AST {
public:
    StatementsAST(vector<TokenOrAST>& elements);
    void execute();
};


//==========================================================================================================
//==========================================================================================================
class IfAST: public AST {
public:
    IfAST(vector<TokenOrAST>& elements);
    void execute();
};

#endif /* AST_hpp */




























