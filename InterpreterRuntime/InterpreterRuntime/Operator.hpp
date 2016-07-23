//
//  Operator.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/18/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Operator_hpp
#define Operator_hpp

#include "common_headers.h"
#include "Symbol.hpp"
#include "Value.hpp"

//==========================================================================================================
//==========================================================================================================
class Operator {
public:
    enum Associativity {LEFT, RIGHT, NONE};
    typedef Operator::Associativity Associativity;
    
    Operator(Symbol _sym, int _num_operands, int _precedence, Associativity _associativity):
        sym(_sym), num_operands(_num_operands), precedence(_precedence), associativity(_associativity) {}

    string get_name() const { return symbol_str_map[sym]; }
    void print() const { cout << get_name() << endl; }
    
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    bool should_precede(const Operator& other) { 
        return (precedence < other.precedence or (precedence == other.precedence and associativity == LEFT)); 
    }
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    Value& eval(vector<Value*> operands) const {
        if(operands.size() != num_operands)
            throw string("Wrong num of operands for " + get_name() + ", expected " + to_string(num_operands) + ", got " + to_string(operands.size()));
        
        return execute(operands);
    }
    
    const Symbol sym;
    const int num_operands;
    const int precedence;
    const Associativity associativity;
    
protected:
    virtual Value& execute(vector<Value*> operands) const = 0;
};


//==========================================================================================================
//==========================================================================================================
extern map<Symbol, Operator*> sym_op_map;
bool is_op(Symbol); 
Operator* get_op(Symbol); 



//==========================================================================================================
//==========================================================================================================
class Add: public Operator {
public:
    Add(): Operator(ADD, 2, 3, LEFT) {}

protected:
    Value& execute(vector<Value*> operands) const {
        return *operands[0] + *operands[1];
    }
};


//==========================================================================================================
//==========================================================================================================
class Subtract: public Operator {
public:
    Subtract(): Operator(SUB, 2, 3, LEFT) {}
    
protected:
    Value& execute(vector<Value*> operands) const {
        return *operands[0] - *operands[1];
    }
};


//==========================================================================================================
//==========================================================================================================
class Mul: public Operator {
public:
    Mul(): Operator(MUL, 2, 2, LEFT) {}
    
protected:
    Value& execute(vector<Value*> operands) const {
        return *operands[0] * *operands[1];
    }
};


//==========================================================================================================
//==========================================================================================================
class Div: public Operator {
public:
    Div(): Operator(DIV, 2, 2, LEFT) {}
    
protected:
    Value& execute(vector<Value*> operands) const {
        return *operands[0] / *operands[1];
    }
};


//==========================================================================================================
//==========================================================================================================
class Mod: public Operator {
public:
    static const string str;
    
    Mod(): Operator(MOD, 2, 2, LEFT) {}
    
protected:
    Value& execute(vector<Value*> operands) const {
        return *operands[0] % *operands[1];
    }
};


//==========================================================================================================
//==========================================================================================================
class Or: public Operator {
public:
    static const string str;
    
    Or(): Operator(OR, 2, 8, LEFT) {}
    
protected:
    Value& execute(vector<Value*> operands) const {
        return *operands[0] || *operands[1];
    }
};


//==========================================================================================================
//==========================================================================================================
class And: public Operator {
public:
    static const string str;
    
    And(): Operator(AND, 2, 7, LEFT) {}
    
protected:
    Value& execute(vector<Value*> operands) const {
        return *operands[0] && *operands[1];
    }
};


//==========================================================================================================
//==========================================================================================================
class Not: public Operator {
public:
    static const string str;
    
    Not(): Operator(NOT, 1, 1, RIGHT) {}
    
protected:
    Value& execute(vector<Value*> operands) const {
        return !(*operands[0]);
    }
};


//==========================================================================================================
//==========================================================================================================
class Equal: public Operator {
public:
    Equal(): Operator(EQ, 2, 6, LEFT) {}
    
protected:
    Value& execute(vector<Value*> operands) const {
        return *operands[0] == *operands[1];
    }
};


//==========================================================================================================
//==========================================================================================================
class NotEqual: public Operator {
public:
    NotEqual(): Operator(NE, 2, 6, LEFT) {}
    
protected:
    Value& execute(vector<Value*> operands) const {
        return *operands[0] != *operands[1];
    }
};


//==========================================================================================================
//==========================================================================================================
class LessThan: public Operator {
public:
    static const string str;
    
    LessThan(): Operator(LT, 2, 5, NONE) {}
    
protected:
    Value& execute(vector<Value*> operands) const {
        return *operands[0] < *operands[1];
    }
};


//==========================================================================================================
//==========================================================================================================
class GreaterThan: public Operator {
public:
    static const string str;
    
    GreaterThan(): Operator(GT, 2, 5, NONE) {}
    
protected:
    Value& execute(vector<Value*> operands) const {
        return *operands[0] > *operands[1];
    }
};


//==========================================================================================================
//==========================================================================================================
class LessThanEqual: public Operator {
public:
    LessThanEqual(): Operator(LE, 2, 5, NONE) {}
    
protected:
    Value& execute(vector<Value*> operands) const {
        return *operands[0] <= *operands[1];
    }
};


//==========================================================================================================
//==========================================================================================================
class GreaterThanEqual: public Operator {
public:
    static const string str;
    
    GreaterThanEqual(): Operator(GT, 2, 5, NONE) {}
    
protected:
    Value& execute(vector<Value*> operands) const {
        return *operands[0] >= *operands[1];
    }
};


//==========================================================================================================
// String matching
//==========================================================================================================
class StringMatch: public Operator {
public:
    StringMatch(): Operator(STR_MATCH, 2, 4, NONE) {}
    
protected:
    Value& execute(vector<Value*> operands) const {
        return operands[0]->match(*operands[1]);
    }
};


//==========================================================================================================
// No string match
//==========================================================================================================
class NoStringtMatch: public Operator {
public:
    NoStringtMatch(): Operator(NO_STR_MATCH, 2, 4, NONE) {}
    
protected:
    Value& execute(vector<Value*> operands) const {
        return operands[0]->not_match(*operands[1]);
    }
};

//==========================================================================================================
// This is needed just for parsing, won't appear in the AST
//==========================================================================================================
class QuestionMark: public Operator {
public:
    QuestionMark(): Operator(QUESTION_MARK, 0, 9, RIGHT) {}
    Value& execute(vector<Value*> operands) const { throw string("Operator ? should never be executed"); }
};


//==========================================================================================================
// This is needed just for parsing, won't appear in the AST
//==========================================================================================================
class Colon: public Operator {
public:
    Colon(): Operator(COLON, 0, 10, LEFT) {}
    Value& execute(vector<Value*> operands) const { throw string("Operator : should never be executed"); }
};



#endif /* Operator_hpp */
