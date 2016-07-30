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
#include "Value.hpp"
#include "Operator.hpp"
#include "SymbolTable.hpp"

class AstVisitor;
class Interpreter;

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

    void traverse(AstVisitor& visitor);
    
    // When eval-ing a non-value node, no_value will be returned
    // Note: eval not done with traverse because each node has its own logic
    virtual Value& eval() = 0;

    virtual string get_name() = 0;
    virtual void print_node() { cout << get_name() << endl; }
    
protected:
    enum JumpKind {BREAK, CONTINUE};
    
    void eval_children(int start = 0);
    vector<Value*> get_children_vals();
};


//==========================================================================================================
//==========================================================================================================
class NumAST: public AST {
public:
    NumAST(vector<TokenOrAST>& elements): num(((NumToken*)elements[0].get_token())->val) {}
    Value& eval() { return *(new Num(num)); }
    string get_name() { return to_string(num); }

    const int num;
};


//==========================================================================================================
//==========================================================================================================
class BoolAST: public AST {
public:
    BoolAST(vector<TokenOrAST>& elements): val(((BoolToken*)elements[0].get_token())->val) {}
    Value& eval() { return *(new Bool(val)); }
    string get_name() { return to_string(val); }
    
    const bool val;
};


//==========================================================================================================
//==========================================================================================================
class StringAST: public AST {
public:
    StringAST(vector<TokenOrAST>& elements): val(((StringToken*)elements[0].get_token())->val) {}
    Value& eval() { return *(new String(val)); }
    string get_name() { return "\"" + val + "\""; }
    
    const string val;
};


//==========================================================================================================
//==========================================================================================================
class OpAST: public AST {
public:
    OpAST(Operator* _op): op(_op){}
    
    Value& eval() {
        auto vals = get_children_vals();
        Value& res = op->eval(vals);
        for(auto v: vals)
            if(v->tmp) delete v;
        return res;
    } 
    string get_name() { return op->get_name(); }

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
    Value& eval();
    string get_name() { return "?:"; }
};


//==========================================================================================================
//==========================================================================================================
class VarAST: public AST {
public:
    VarAST(vector<TokenOrAST>& elements): name(((IdentifierToken*)elements[0].get_token())->name) {} 
    Value& eval();
    string get_name() { return name; }

    const string name;
    Interpreter* interpreter;
};


//==========================================================================================================
//==========================================================================================================
class AssignmentAST: public AST {
public:
    AssignmentAST(vector<TokenOrAST>& elements);
    Value& eval();
    string get_name() { return (conditional ? "?=" : "="); }
    
    Interpreter* interpreter;
    
private:
    const bool conditional;
};


//==========================================================================================================
//==========================================================================================================
class StatementsAST: public AST {
public:
    StatementsAST(vector<TokenOrAST>& elements);
    Value& eval();
    string get_name() { return "Statements"; }
};


//==========================================================================================================
//==========================================================================================================
class IfAST: public AST {
public:
    IfAST(vector<TokenOrAST>& elements);
    Value& eval();
    string get_name() { return "if"; }
};


//==========================================================================================================
//==========================================================================================================
class IfElseAST: public AST {
public:
    IfElseAST(vector<TokenOrAST>& elements);
    Value& eval();
    string get_name() { return "if-else"; }
};


//==========================================================================================================
//==========================================================================================================
class WhileAST: public AST {
public:
    WhileAST(vector<TokenOrAST>& elements);
    Value& eval();
    string get_name() { return "while"; }
};


//==========================================================================================================
//==========================================================================================================
class RepeatAST: public AST {
public:
    RepeatAST(vector<TokenOrAST>& elements);
    Value& eval();
    string get_name() { return "repeat"; }
    
private:
    int times; // How many times to repeat body
};


//==========================================================================================================
//==========================================================================================================
class BreakAST: public AST {
public:
    BreakAST(vector<TokenOrAST>& elements) {}
    Value& eval() { throw BREAK; }
    string get_name() { return "break"; }
};

//==========================================================================================================
//==========================================================================================================
class ContinueAST: public AST {
public:
    ContinueAST(vector<TokenOrAST>& elements) {}
    Value& eval() { throw CONTINUE; }
    string get_name() { return "continue"; }
};



//==========================================================================================================
//==========================================================================================================
class ParamsAST: public AST {
public:
    ParamsAST(vector<TokenOrAST>& elements);
    Value& eval() { throw string("ParamsAST::eval() should never be called"); }
    string get_name() { return "params-list"; }
};


//==========================================================================================================
//==========================================================================================================
class NamedParamAST: public AST {
public:
    NamedParamAST(vector<TokenOrAST>& elements);
    Value& eval();
    string get_name() { return "named-param: " + name; }

    const string name;
};


//==========================================================================================================
//==========================================================================================================
class NamedParamsAST: public AST {
public:
    NamedParamsAST(vector<TokenOrAST>& elements);
    Value& eval() { throw string("NamedParamsAST::eval() should never be called"); }
    string get_name() { return "named-params-list"; }
};


//==========================================================================================================
//==========================================================================================================
class FuncAST: public AST {
public:
    FuncAST(vector<TokenOrAST>& elements);
    Value& eval();
    string get_name() { return name + "()"; }
    
    const string name;
    Interpreter* interpreter;
};



#endif /* AST_hpp */




























