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
    
    Operator(int _num_operands, int _precedence, Associativity _associativity):
        num_operands(_num_operands), precedence(_precedence), associativity(_associativity) {}
    
    const int num_operands;
    const int precedence;
    const Associativity associativity;
};


//==========================================================================================================
//==========================================================================================================
extern map<Symbol, Operator*> sym_op_map;


//==========================================================================================================
//==========================================================================================================
class Add: public Operator {
public:
    Add(): Operator(2, 3, LEFT) {}
};


//==========================================================================================================
//==========================================================================================================
class Subtract: public Operator {
public:
    Subtract(): Operator(2, 3, LEFT) {}
    
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
    Mul(): Operator(2, 2, LEFT) {}
    
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
    Div(): Operator(2, 2, LEFT) {}
    
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
    
    Mod(): Operator(2, 2, LEFT) {}
    
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
    
    Or(): Operator(2, 8, LEFT) {}
    
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
    
    And(): Operator(2, 7, LEFT) {}
    
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
    
    Not(): Operator(1, 1, RIGHT) {}
    
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
    Equal(): Operator(2, 6, LEFT) {}
    
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
    NotEqual(): Operator(2, 6, LEFT) {}
    
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
    
    LessThan(): Operator(2, 5, NONE) {}
    
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
    
    GreaterThan(): Operator(2, 5, NONE) {}
    
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
    LessThanEqual(): Operator(2, 5, NONE) {}
    
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
    
    GreaterThanEqual(): Operator(2, 5, NONE) {}
    
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
    StringMatch(): Operator(2, 4, NONE) {}
    
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
    NoStringtMatch(): Operator(2, 4, NONE) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        return &(operands[0]->not_match(*operands[1]));
//    }
};


//==========================================================================================================
//==========================================================================================================
class CondExp: public Operator {
public:
    CondExp(): Operator(3, 9, RIGHT) {}
    
//protected:
//    Value* execute(vector<Value*> operands)
//    {
//        throw string("TernaryOpenIf::execute() should never be called!");
//    }
};



#endif /* Operator_hpp */
