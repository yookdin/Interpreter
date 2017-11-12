//
//  AST.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/16/16.
//  Copyright © 2016 Vonage. All rights reserved.
//
// TODO:
// o Optimize evaluating constants, so not to create a new Value each time?

#ifndef AST_hpp
#define AST_hpp


#include "Token.hpp"
#include "ParseElement.h"
#include "Value.hpp"
#include "Operator.hpp"


class AstVisitor;
class Interpreter;


//==========================================================================================================
//==========================================================================================================
class AST: public ParseElement {
public:
    Interpreter *interpreter = nullptr;
    vector<AST*> children;

    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
    AST* get_ast() override {
        return this;
    }

    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
    bool is_token() override {
        return false;
    }

    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
    virtual ~AST(){}
    
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
    void print();
    void free();
    
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
    void add_child(AST* ast) {
        if(ast == nullptr)
            THROW << "Trying to add null child";
        
        children.push_back(ast);
    }

    void pre_order_traverse(AstVisitor& visitor);
    void post_order_traverse(AstVisitor& visitor);
    
    // When eval-ing a non-value node, no_value will be returned
    // Note: eval not done with traverse because each node has its own logic
    virtual SharedValue eval() = 0;

    virtual string get_name() = 0;
    virtual void print_node() { Print(false) << get_name() << endl; }
    vector<SharedValue> get_children_as_parameters();
    
protected:
    enum JumpKind {BREAK, CONTINUE};
    
    void eval_children(int start);
    vector<SharedValue> get_children_vals();
    void add_flat_statements(AST*);
};


//==========================================================================================================
//==========================================================================================================
class NumAST: public AST {
public:
    NumAST(vector<ParseElement*>& elements): num(((NumToken*)elements[0]->get_token())->val) {}
    
    SharedValue eval() override { 
        return SharedValue(new Num(num)); 
    }
    
    string get_name() override { 
        return to_string(num); 
    }

    const int num;
};


//==========================================================================================================
//==========================================================================================================
class BoolAST: public AST {
public:
    BoolAST(vector<ParseElement*>& elements): val(((BoolToken*)elements[0]->get_token())->val) {}
    
    SharedValue eval() override { 
        return SharedValue(new Bool(val)); 
    }
    
    string get_name() override { 
        return to_string(val); 
    }
    
    const bool val;
};


//==========================================================================================================
//==========================================================================================================
class StringAST: public AST {
public:
    StringAST(vector<ParseElement*>& elements): val(((StringToken*)elements[0]->get_token())->val) {}
    
    SharedValue eval() override;
    
    string get_name() override { 
        return "\"" + val + "\""; 
    }
    
    const string val;
};


//==========================================================================================================
//==========================================================================================================
class ListAST: public AST {
public:
    ListAST(vector<ParseElement*>& elements);
    
    SharedValue eval() override;
    
    string get_name() override { 
        return "list"; 
    }
};


//==========================================================================================================
//==========================================================================================================
class RangeAST: public AST {
public:
    RangeAST(vector<ParseElement*>& elements);
    SharedValue eval() override;
    
    string get_name() override { 
        return "range"; 
    }
};



//==========================================================================================================
//==========================================================================================================
class NakedListAST: public AST {
public:
    NakedListAST(vector<ParseElement*>& elements);
    
    SharedValue eval() override {
        THROW << "NakedListAST::eval() should never be called";
    }
    
    string get_name() override { 
        return "naked-list"; 
    }
};



//==========================================================================================================
//==========================================================================================================
class OpAST: public AST {
public:
    OpAST(Operator* _op): op(_op){}
    
    string get_name() override { 
        return op->get_name(); 
    }

    const Operator* op;
};


//==========================================================================================================
//==========================================================================================================
class BopAST: public OpAST {
public:
    BopAST(vector<ParseElement*>& elements);
    SharedValue eval() override;
};


//==========================================================================================================
// Dot access currenlty supports only function calls on the left value.
// It is a binary operator, but with a different evaluation method than other Bops: the right child is not
// fully evaluated (the function isn't called), but rather sent to the left child for evaluation.
//==========================================================================================================
class DotAccessAST: public BopAST {
public:
    DotAccessAST(vector<ParseElement*>& elements): BopAST(elements) {}
    SharedValue eval() override;
};


//==========================================================================================================
//==========================================================================================================
class UopAST: public OpAST {
public:
    UopAST(vector<ParseElement*>& elements);
    SharedValue eval() override;
};


//==========================================================================================================
//==========================================================================================================
class CondExpAST: public AST {
public:
    CondExpAST(vector<ParseElement*>& elements);
    SharedValue eval() override;
    
    string get_name() override { 
        return "?:"; 
    }
};


//==========================================================================================================
//==========================================================================================================
class VarAST: public AST {
public:
    VarAST(vector<ParseElement*>& elements): name(((IdentifierToken*)elements[0]->get_token())->name) {} 
    
    SharedValue eval() override;
    
    string get_name() override { 
        return name; 
    }

    const string name;
};


//==========================================================================================================
//==========================================================================================================
class AssignmentAST: public AST {
public:
    AssignmentAST(vector<ParseElement*>& elements);
    SharedValue eval() override;
    
    string get_name() override { 
        return (conditional ? "?=" : "="); 
    }
    
private:
    const bool conditional;
};


//==========================================================================================================
//==========================================================================================================
class StatementsAST: public AST {
public:
    StatementsAST(vector<ParseElement*>& elements);
    SharedValue eval() override;
    
    string get_name() override { 
        return "Statements"; 
    }
};


//==========================================================================================================
//==========================================================================================================
class IfAST: public AST {
public:
    IfAST(vector<ParseElement*>& elements);
    SharedValue eval() override;
    
    string get_name() override { 
        return "if"; 
    }
};


//==========================================================================================================
//==========================================================================================================
class IfElseAST: public AST {
public:
    IfElseAST(vector<ParseElement*>& elements);
    SharedValue eval() override;
    
    string get_name() override { 
        return "if-else"; 
    }
};


//==========================================================================================================
//==========================================================================================================
class WhileAST: public AST {
public:
    WhileAST(vector<ParseElement*>& elements);
    SharedValue eval() override;
    
    string get_name() override { 
        return "while"; 
    }
};


//==========================================================================================================
//==========================================================================================================
class RepeatAST: public AST {
public:
    RepeatAST(vector<ParseElement*>& elements);
    SharedValue eval() override;
    
    string get_name() override { 
        return "repeat"; 
    }
    
private:
    int times; // How many times to repeat body
};

        
//==========================================================================================================
//==========================================================================================================
class ForAST: public AST {
public:
    ForAST(vector<ParseElement*>& elements);
    SharedValue eval() override;
    
    string get_name() override { 
        return "for"; 
    }
    
private:
    string item_name;
};


//==========================================================================================================
//==========================================================================================================
class BreakAST: public AST {
public:
    BreakAST(vector<ParseElement*>& elements) {}
    
    SharedValue eval() override { 
        throw BREAK; // Will be caught by containing loop node 
    }
    
    string get_name() override { 
        return "break"; 
    }
};


//==========================================================================================================
//==========================================================================================================
class ContinueAST: public AST {
public:
    ContinueAST(vector<ParseElement*>& elements) {}
    
    SharedValue eval() override { 
        throw CONTINUE; // Will be caught by containing loop node 
    }
    
    string get_name() override { 
        return "continue"; 
    }
};


//==========================================================================================================
//==========================================================================================================
class ParamValAST: public AST {
public:
    ParamValAST(vector<ParseElement*>& elements);
    SharedValue eval() override;
    
    string get_name() override { 
        return "param-val: " + name; 
    }

    const string name;
};


//==========================================================================================================
//==========================================================================================================
class ParamValsAST: public AST {
public:
    ParamValsAST(vector<ParseElement*>& elements);
    
    SharedValue eval() override;
    
    string get_name() override { 
        return "param-vals-list"; 
    }
};


//==========================================================================================================
// Base for function and command call, which have the same functionality but different construction
//==========================================================================================================
class CallableAST: public AST {
public:
    CallableAST(vector<ParseElement*>& elements): name(((IdentifierToken*)elements[0]->get_token())->name) {}
    CallableAST(string _name): name(_name) {}
    
    SharedValue eval() override;
    
    string get_name() override { 
        return name + "()"; 
    }
    
    const string name;
};


//==========================================================================================================
//==========================================================================================================
class FuncAST: public CallableAST {
public:
    FuncAST(vector<ParseElement*>& elements);
};


//==========================================================================================================
//==========================================================================================================
class CommandAST: public CallableAST {
public:
    CommandAST(vector<ParseElement*>& elements);
};


//==========================================================================================================
//==========================================================================================================
class TryFinallyAST: public AST {
public:
    TryFinallyAST(vector<ParseElement*>& elements);
    SharedValue eval() override;
    
    string get_name() override {
        return "try-finally";
    }
};
        
#endif /* AST_hpp */




























