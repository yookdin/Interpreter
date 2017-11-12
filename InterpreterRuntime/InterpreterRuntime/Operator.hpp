//
//  Operator.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/18/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Operator_hpp
#define Operator_hpp

#include <iostream>
#include <set>
using namespace std;

#include "Symbol.hpp"
#include "Value.hpp"


//==========================================================================================================
//==========================================================================================================
class Operator {
public:
    enum Associativity {LEFT, RIGHT, NONE};
    typedef Operator::Associativity Associativity;
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    Operator(Symbol _sym, int _num_operands, int _precedence, Associativity _associativity):
        sym(_sym), num_operands(_num_operands), precedence(_precedence), associativity(_associativity) {}

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    virtual string get_name() const { 
        return symbol_str_map[sym];
    }
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    void print() const { 
        cout << get_name() << endl;
    }
        
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    bool should_precede(const Operator& other) { 
        return (precedence < other.precedence or (precedence == other.precedence and associativity == LEFT)); 
    }
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    virtual SharedValue eval(vector<SharedValue> operands) const {
        if(operands.size() != num_operands)
            THROW << "Wrong num of operands for " << get_name() << ", expected " << num_operands << ", got " << operands.size();
        
        return execute(operands);
    }
    
    const Symbol sym;
    const int num_operands;
    const int precedence;
    const Associativity associativity;
    
protected:
    virtual SharedValue execute(vector<SharedValue>& operands) const = 0;
};


//==========================================================================================================
//==========================================================================================================
extern set<Symbol> operators;
extern map<pair<Symbol, int>, Operator*> sym_op_map;
bool is_op(Symbol); 
Operator* get_op(Symbol s, int num_operands);        


#endif /* Operator_hpp */












