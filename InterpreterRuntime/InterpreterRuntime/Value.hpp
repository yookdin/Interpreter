//
//  Value.hpp
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/23/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Value_hpp
#define Value_hpp

#include "common_headers.h"


//==========================================================================================================
//==========================================================================================================
enum Type {BOOLEAN, NUMBER, STRING, NO_VAL};


//==========================================================================================================
//==========================================================================================================
class Value {
public:
    Value(Type _type): type(_type) {}
    Type get_type() { return type; }
    
    virtual string to_string() const = 0;
    
    //------------------------------------------------------------------------------------------------------
    // By default all conversion are undefined. Derived classes will override those conversion they support
    //------------------------------------------------------------------------------------------------------
    virtual operator bool() const { throw string("Conversion of " + get_type_name() + " to bool undefined"); }
    virtual operator int() const { throw string("Conversion of " + get_type_name() + " to int undefined"); }
    virtual operator string() const { throw string("Conversion of " + get_type_name() + " to string undefined"); }

    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    string get_type_name() const {
        switch(type) {
            case STRING: return "STRING";
            case NUMBER: return "NUMBER";
            case BOOLEAN: return "BOOLEAN";
            case NO_VAL: return "NO_VAL";
        }
    }

protected:
    const Type type;

private:
    string wrong_op_str(string op) { return "Operator " + op + " not supported by type " + get_type_name(); }
    
public:
    
    //------------------------------------------------------------------------------------------------------
    // By default all operators are undefined. Derived classes will override those they support
    //------------------------------------------------------------------------------------------------------
    virtual Value& operator+ (Value& other) { throw wrong_op_str("+");   }
    virtual Value& operator- (Value& other) { throw wrong_op_str("-");   }
    virtual Value& operator* (Value& other) { throw wrong_op_str("*");   }
    virtual Value& operator/ (Value& other) { throw wrong_op_str("/");   }
    virtual Value& operator% (Value& other) { throw wrong_op_str("%");   }
    virtual Value& operator||(Value& other) { throw wrong_op_str("or");  }
    virtual Value& operator&&(Value& other) { throw wrong_op_str("and"); }
    virtual Value& operator! ()             { throw wrong_op_str("not"); }
    virtual Value& operator==(Value& other) { throw wrong_op_str("==");  }
    virtual Value& operator!=(Value& other) { throw wrong_op_str("!=");  }
    virtual Value& operator< (Value& other) { throw wrong_op_str("<");   }
    virtual Value& operator> (Value& other) { throw wrong_op_str(">");   }
    virtual Value& operator<=(Value& other) { throw wrong_op_str("<=");  }
    virtual Value& operator>=(Value& other) { throw wrong_op_str(">=");  }
    virtual Value& match     (Value& other) { throw wrong_op_str("~");   }
    virtual Value& not_match (Value& other) { throw wrong_op_str("!~");  }    
};


//==========================================================================================================
//==========================================================================================================
class NoValue: public Value {
public:
    NoValue(): Value(NO_VAL){}
    string to_string() const { return get_type_name(); }
};

extern NoValue no_value;


//==========================================================================================================
//==========================================================================================================
class Bool: public Value {
public:
    Bool(bool _val = false): Value(BOOLEAN), val(_val) {}
    
    operator bool() const { return val; };
    Value& operator||(Value& other) { return *(new Bool(val || bool(other))); }
    Value& operator&&(Value& other) { return *(new Bool(val && bool(other))); }
    Value& operator!()              { return *(new Bool(!val)); }
    Value& operator==(Value& other) { return *(new Bool(val == bool(other))); }
    Value& operator!=(Value& other) { return *(new Bool(val != bool(other))); }

    string to_string() const { return ::to_string(val); }
    
private:
    bool val;
};


//==========================================================================================================
//==========================================================================================================
class Num: public Value {
public:
    Num(int _val = 0): Value(NUMBER), val(_val) {}
    
    operator int() const { return val; }
    Value& operator+ (Value& other) { return *(new Num(val  +  int(other))); }
    Value& operator- (Value& other) { return *(new Num(val  -  int(other))); }
    Value& operator* (Value& other) { return *(new Num(val  *  int(other))); }
    Value& operator/ (Value& other) { return *(new Num(val  /  int(other))); }
    Value& operator% (Value& other) { return *(new Num(val  %  int(other))); }
    Value& operator==(Value& other) { return *(new Bool(val == int(other))); }
    Value& operator!=(Value& other) { return *(new Bool(val != int(other))); }
    Value& operator< (Value& other) { return *(new Bool(val <  int(other))); }
    Value& operator> (Value& other) { return *(new Bool(val >  int(other))); }
    Value& operator<=(Value& other) { return *(new Bool(val <= int(other))); }
    Value& operator>=(Value& other) { return *(new Bool(val >= int(other))); }

    string to_string() const { return std::to_string(val); }
    
    Num foo() { return Num(3); }
    
private:
    int val;
};


//==========================================================================================================
//==========================================================================================================
class String: public Value {
public:
    String(string _val = ""): Value(STRING), val(_val) {}
    
    operator string() const { return val; }
    Value& operator+ (Value& other) { return *(new String(val + string(other)));}
    Value& operator==(Value& other) { return *(new Bool(val == string(other))); }
    Value& operator!=(Value& other) { return *(new Bool(val != string(other))); }
    Value& operator< (Value& other) { return *(new Bool(val <  string(other))); }
    Value& operator> (Value& other) { return *(new Bool(val >  string(other))); }
    Value& operator<=(Value& other) { return *(new Bool(val <= string(other))); }
    Value& operator>=(Value& other) { return *(new Bool(val >= string(other))); }

    Value& match(Value& other) { return *(new Bool(regex_match(val, regex(string(other))))); }
    Value& not_match(Value& other) { return not match(other); }

    string to_string() const { return val; }
    
private:
    string val;
    
};


#endif /* Value_hpp */
