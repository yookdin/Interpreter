//
//  Operator.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/18/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Operator_hpp
#define Operator_hpp

#include "common.h"

//==========================================================================================================
//==========================================================================================================
class Operator {
public:
    enum Associativity {LEFT, RIGHT, NONE};
    typedef Operator::Associativity Associativity;
    
    Operator(string name, int num_operands, int precedence, Associativity associativity);
    virtual void print() const { cout << name << endl; }
    
    bool should_precede(const Operator& other);
    
    const string name;
    const int num_operands;
    const int precedence;
    const Associativity associativity;
};


//==========================================================================================================
//==========================================================================================================
extern map<string, Operator*> name_op_map;


//==========================================================================================================
//==========================================================================================================
class Add: public Operator {
public:
    Add(): Operator("+", 2, 3, LEFT) {}
};


//==========================================================================================================
//==========================================================================================================
class Subtract: public Operator {
public:
    Subtract(): Operator("-", 2, 3, LEFT) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        return &(*operands[0] - *operands[1]);
//    }
};


//==========================================================================================================
//==========================================================================================================
class Mul: public Operator {
public:
    Mul(): Operator("*", 2, 2, LEFT) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        return &(*operands[0] * *operands[1]);
//    }
};


//==========================================================================================================
//==========================================================================================================
class Div: public Operator {
public:
    Div(): Operator("/", 2, 2, LEFT) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        return &(*operands[0] / *operands[1]);
//    }
};


//==========================================================================================================
//==========================================================================================================
class Mod: public Operator {
public:
    static const string str;
    
    Mod(): Operator("%", 2, 2, LEFT) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        return &(*operands[0] % *operands[1]);
//    }
};


//==========================================================================================================
//==========================================================================================================
class Or: public Operator {
public:
    static const string str;
    
    Or(): Operator("or", 2, 8, LEFT) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        return &(*operands[0] || *operands[1]);
//    }
};


//==========================================================================================================
//==========================================================================================================
class And: public Operator {
public:
    static const string str;
    
    And(): Operator("and", 2, 7, LEFT) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        return &(*operands[0] && *operands[1]);
//    }
};


//==========================================================================================================
//==========================================================================================================
class Not: public Operator {
public:
    static const string str;
    
    Not(): Operator("not", 1, 1, RIGHT) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        return &(!(*operands[0]));
//    }
};


//==========================================================================================================
//==========================================================================================================
class Equal: public Operator {
public:
    Equal(): Operator("==", 2, 6, LEFT) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        return &(*operands[0] == *operands[1]);
//    }
};


//==========================================================================================================
//==========================================================================================================
class NotEqual: public Operator {
public:
    NotEqual(): Operator("!=", 2, 6, LEFT) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        return &(*operands[0] != *operands[1]);
//    }
};


//==========================================================================================================
//==========================================================================================================
class LessThan: public Operator {
public:
    static const string str;
    
    LessThan(): Operator("<", 2, 5, NONE) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        return &(*operands[0] < *operands[1]);
//    }
};


//==========================================================================================================
//==========================================================================================================
class GreaterThan: public Operator {
public:
    static const string str;
    
    GreaterThan(): Operator(">", 2, 5, NONE) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        return &(*operands[0] > *operands[1]);
//    }
};


//==========================================================================================================
//==========================================================================================================
class LessThanEqual: public Operator {
public:
    LessThanEqual(): Operator("<=", 2, 5, NONE) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        return &(*operands[0] <= *operands[1]);
//    }
};


//==========================================================================================================
//==========================================================================================================
class GreaterThanEqual: public Operator {
public:
    static const string str;
    
    GreaterThanEqual(): Operator(">=", 2, 5, NONE) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        return &(*operands[0] >= *operands[1]);
//    }
};


//==========================================================================================================
// String matching
//==========================================================================================================
class StringMatch: public Operator {
public:
    StringMatch(): Operator("~", 2, 4, NONE) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        return &(operands[0]->match(*operands[1]));
//    }
};


//==========================================================================================================
// No string match
//==========================================================================================================
class NoStringtMatch: public Operator {
public:
    NoStringtMatch(): Operator("!~", 2, 4, NONE) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        return &(operands[0]->not_match(*operands[1]));
//    }
};

//==========================================================================================================
// This is needed just for parsing, won't appear in the AST
//==========================================================================================================
class QuestionMark: public Operator {
public:
    QuestionMark(): Operator("?", 0, 9, RIGHT) {}
};


//==========================================================================================================
// This is needed just for parsing, won't appear in the AST
//==========================================================================================================
class Colon: public Operator {
public:
    Colon(): Operator(":", 0, 10, LEFT) {}
};


//==========================================================================================================
//==========================================================================================================
class CondExp: public Operator {
public:
    CondExp(): Operator("?:", 3, -1, NONE) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        throw string("TernaryOpenIf::execute() should never be called!");
//    }
};



#endif /* Operator_hpp */
