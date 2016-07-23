//
//  AST.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/16/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef AST_hpp
#define AST_hpp

#include "common_headers.h"
#include "Token.hpp"
#include "ParseStackElement.hpp"
#include "Operator.hpp"

//==========================================================================================================
//==========================================================================================================
class AST {
public:
    void print();
    void add_child(AST* ast) {
        if(ast == nullptr) throw string("Trying to add null child");
        children.push_back(ast);
    }

    vector<AST*> children;

    virtual void print_node() = 0;
    
protected:
    void recursive_print(int indentation_level);
};


//==========================================================================================================
//==========================================================================================================
class NumAST: public AST {
public:
    NumAST(vector<TokenOrAST>& elements): num(extract_num(elements)) {}
    const int num;
    void print_node() { cout << num << endl; }
    
private:
    int extract_num(vector<TokenOrAST>& elements);
};


//==========================================================================================================
//==========================================================================================================
class OpAST: public AST {
public:
    OpAST(Operator* _op): op(_op){}
    void print_node() { op->print(); }
protected:
    const Operator* op;
};


//==========================================================================================================
//==========================================================================================================
class BopAST: public OpAST {
public:
    BopAST(vector<TokenOrAST>& elements);
};


//==========================================================================================================
//==========================================================================================================
class UopAST: public OpAST {
public:
    UopAST(vector<TokenOrAST>& elements);
};


//==========================================================================================================
//==========================================================================================================
class CondExpAST: public AST {
public:
    CondExpAST(vector<TokenOrAST>& elements);
    void print_node() { cout << "?:" << endl; }
};


//==========================================================================================================
//==========================================================================================================
class VarAST: public AST {
public:
    VarAST(string _name): name(_name) {}
    VarAST(vector<TokenOrAST>& elements): name(((IdentifierToken*)elements[0].get_token())->name) {} 
    void print_node() { cout << name << endl; }

    const string name;
};


//==========================================================================================================
//==========================================================================================================
class AssignmentAST: public AST {
public:
    AssignmentAST(vector<TokenOrAST>& elements);
    void print_node() { cout << '=' << endl; }
};


//==========================================================================================================
//==========================================================================================================
class StatementsAST: public AST {
public:
    StatementsAST(vector<TokenOrAST>& elements);
    void print_node() { cout << "Statements" << endl; }
};


//==========================================================================================================
//==========================================================================================================
class IfAST: public AST {
public:
    IfAST(vector<TokenOrAST>& elements);
    void print_node() { cout << "if" << endl; }
};


//==========================================================================================================
//==========================================================================================================
class IfElseAST: public AST {
public:
    IfElseAST(vector<TokenOrAST>& elements);
    void print_node() { cout << "if-else" << endl; }
};


//==========================================================================================================
//==========================================================================================================
class WhileAST: public AST {
public:
    WhileAST(vector<TokenOrAST>& elements);
    void print_node() { cout << "while" << endl; }
};


//==========================================================================================================
//==========================================================================================================
class RepeatAST: public AST {
public:
    RepeatAST(vector<TokenOrAST>& elements);
    void print_node() { cout << "repeat" << endl; }
    
private:
    int times; // How many times to repeat body
};


//==========================================================================================================
//==========================================================================================================
class ParamsAST: public AST {
public:
    ParamsAST(vector<TokenOrAST>& elements);
    void print_node() { cout << "params-list" << endl; }
};


//==========================================================================================================
//==========================================================================================================
class NamedParamAST: public AST {
public:
    NamedParamAST(vector<TokenOrAST>& elements);
    void print_node() { cout << "named-param: " << name << endl; }
    const string name;
};


//==========================================================================================================
//==========================================================================================================
class NamedParamsAST: public AST {
public:
    NamedParamsAST(vector<TokenOrAST>& elements);
    void print_node() { cout << "named-params-list" << endl; }
};


//==========================================================================================================
//==========================================================================================================
class FuncAST: public AST {
public:
    FuncAST(vector<TokenOrAST>& elements);
    void print_node() { cout << name << "()" << endl; }
    
    const string name;
};



#endif /* AST_hpp */




























