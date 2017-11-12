//
//  Value.hpp
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/23/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Value_hpp
#define Value_hpp

#include <regex>
using namespace std;

#include "st_exception.h"
#include "common_utils.hpp"


//==========================================================================================================
//==========================================================================================================
class Value;
typedef shared_ptr<Value> SharedValue;
extern SharedValue no_value;


//==========================================================================================================
//==========================================================================================================
class Value {
public:
    enum Type {BOOL, NUMBER, STRING, RANGE, LIST, PARAM_VAL, PARAM_VALS_LIST, MATCH_RESULT, NO_VAL};
    
    static string get_type_name(Type type);
    static SharedValue from_string(string s);
    
    Value(Type _type): type(_type) {}
    
    Type get_type();
    string get_type_name() const;
    virtual Value* copy() const = 0;
    virtual void print();
    virtual bool is_no_value() const;
    
    SharedValue subscript(SharedValue v) const {
        return subscript(v->to_int());
    }
    
    virtual SharedValue subscript(int i) const;
    virtual SharedValue length(vector<SharedValue> args = {});
    virtual SharedValue match     (SharedValue other) const;
    virtual SharedValue not_match (SharedValue other) const;
    
    //------------------------------------------------------------------------------------------------------
    // Return pointer to specific Value type, or null if can't cast
    //------------------------------------------------------------------------------------------------------
    template<class T>
    T* get() {
        return dynamic_cast<T*>(this);
    }
        
    //------------------------------------------------------------------------------------------------------
    // By default all conversion are illegal. Derived classes will override those conversion they support
    //------------------------------------------------------------------------------------------------------
    virtual string to_string() const = 0;
    virtual int to_int() const;
    virtual long to_long() const;
    virtual bool to_bool() const;
    virtual vector<string> to_strings() const;
    
    // Note: it is needed to overload the built-in conversion operators, to enable conversions inside
    // templates, where the templated type is the one being converted to!
    explicit virtual operator string()         const { return to_string(); } 
    explicit virtual operator int()            const { return to_int(); }
    explicit virtual operator long()           const { return to_long(); }
    explicit virtual operator bool()           const { return to_bool(); }
    explicit virtual operator vector<string>() const { return to_strings(); }

    
    //------------------------------------------------------------------------------------------------------
    // Callable functions
    //------------------------------------------------------------------------------------------------------
    typedef SharedValue(Value::*CallableFunc)(vector<SharedValue> args);
    static map<string, CallableFunc> functab;
    virtual SharedValue call_func(string name, vector<SharedValue> args);
    SharedValue type_name(vector<SharedValue> args);
    
    
protected:
    const Type type;
    
private:
    string wrong_op_str(string op) const { return "Operator " + op + " not supported by type " + get_type_name(); }
    
public:
    
    //------------------------------------------------------------------------------------------------------
    // By default all operators are illeagal. Derived classes will override those they support
    //------------------------------------------------------------------------------------------------------
    virtual Value& operator- ()             const;
    virtual Value& operator+ (Value& other) const;
    virtual Value& operator- (Value& other) const;
    virtual Value& operator* (Value& other) const;
    virtual Value& operator/ (Value& other) const;
    virtual Value& operator% (Value& other) const;
    virtual Value& operator||(Value& other) const;
    virtual Value& operator&&(Value& other) const;
    virtual Value& operator! ()             const;
    virtual Value& operator==(Value& other) const;
    virtual Value& operator!=(Value& other) const;
    virtual Value& operator< (Value& other) const;
    virtual Value& operator> (Value& other) const;
    virtual Value& operator<=(Value& other) const;
    virtual Value& operator>=(Value& other) const;
    
}; // class Value


//==========================================================================================================
// Global operators to enbale expressiong involving Value and primitve types
//==========================================================================================================
bool operator<(const int& i, const SharedValue& v);
bool operator<(const SharedValue& v, const int& i);
bool operator>(const int& i, const SharedValue& v);
bool operator>(const SharedValue& v, const int& i);
bool operator<=(const int& i, const SharedValue& v);
bool operator<=(const SharedValue& v, const int& i);
bool operator>=(const int& i, const SharedValue& v);
bool operator>=(const SharedValue& v, const int& i);
bool operator==(const int& i, const SharedValue& v);
bool operator==(const SharedValue& v, const int& i);
bool operator!=(const int& i, const SharedValue& v);
bool operator!=(const SharedValue& v, const int& i);


//==========================================================================================================
// This represent a non-value, like nullptr. Should be only one global instance which everybody uses.
//==========================================================================================================
class NoValue: public Value {
public:
    NoValue();
    Value* copy() const override;
    bool is_no_value() const override;
    string to_string() const override;
};


//==========================================================================================================
// Classes in the Value family will implement this, to enable calling functions by name, and if not found
// roll the call up to the parent.
// Note: each class still need to instantiate its static function table.
//==========================================================================================================
#define VALUE_CALL_MECHANISM(Base, Derived)                                         \
public:                                                                             \
    typedef Base Super;                                                             \
    typedef SharedValue(Derived::*CallableFunc)(vector<SharedValue> args);          \
private:                                                                            \
    static map<string, CallableFunc> functab;                                       \
public:                                                                             \
    virtual SharedValue call_func(string name, vector<SharedValue> args) override { \
        if(functab.count(name) != 0)                                                \
            return (this->*functab[name])(args);                                    \
        else                                                                        \
            return Super::call_func(name, args);                                    \
    }

//==========================================================================================================
//==========================================================================================================
class Bool: public Value {
    VALUE_CALL_MECHANISM(Value, Bool);
public:
    
    static SharedValue from_string(string s);
    
    Bool(bool _val = false);
    
    void flip();
    
    string to_string() const override;
    bool to_bool() const override;
    Value& operator||(Value& other) const override;
    Value& operator&&(Value& other) const override;
    Value& operator==(Value& other) const override;
    Value& operator!=(Value& other) const override;
    
    Value* copy() const override;
    
private:
    bool val;
};


//==========================================================================================================
//==========================================================================================================
class Num: public Value {
    VALUE_CALL_MECHANISM(Value, Num);
public:
    static SharedValue from_string(string s);
    
    Num(long _val = 0);
    
    string to_string() const override;
    int to_int() const override;
    long to_long() const override;
    
    Value& operator- ()             const override;
    Value& operator+ (Value& other) const override;
    Value& operator- (Value& other) const override;
    Value& operator* (Value& other) const override;
    Value& operator/ (Value& other) const override;
    Value& operator% (Value& other) const override;
    Value& operator==(Value& other) const override;
    Value& operator!=(Value& other) const override;
    Value& operator< (Value& other) const override;
    Value& operator> (Value& other) const override;
    Value& operator<=(Value& other) const override;
    Value& operator>=(Value& other) const override;
    
    Value* copy() const override;
    
private:
    long val;
};


//==========================================================================================================
//==========================================================================================================
class String: public Value {
    VALUE_CALL_MECHANISM(Value, String);
public:

    static SharedValue from_string(string s);

    String(string _val = "");
    String(char c);
    
    string to_string() const override;
    bool to_bool() const override;
    long to_long() const override;
    int to_int() const override;
    
    Value& operator+ (Value& other) const override;
    Value& operator==(Value& other) const override;
    Value& operator!=(Value& other) const override;
    Value& operator< (Value& other) const override;
    Value& operator> (Value& other) const override;
    Value& operator<=(Value& other) const override;
    Value& operator>=(Value& other) const override;
    SharedValue match     (SharedValue other) const override;
    SharedValue not_match (SharedValue other) const override;

    Value* copy() const override;
    SharedValue subscript(int) const override;
    SharedValue length(vector<SharedValue> args) override;
    SharedValue empty(vector<SharedValue> args);
    
private:
    string val;
};


//==========================================================================================================
//==========================================================================================================
class Range: public Value {
    VALUE_CALL_MECHANISM(Value, Range);
public:
    Range(int s, int e);
    Range(SharedValue s, SharedValue e): Range(s->to_int(), e->to_int()) {}

    
    string to_string() const override;
    Value* copy() const override;
    SharedValue length(vector<SharedValue> args) override;
    SharedValue subscript(int) const override;

private:
    int s, e;
};


//==========================================================================================================
// List of values (actually SharedValue, that can wrap any Value)
//==========================================================================================================
class List: public Value {
    VALUE_CALL_MECHANISM(Value, List);
public:
    static SharedValue from_string(string s);

    List(vector<SharedValue> _values);
    Value* copy() const override;
    string to_string() const override;
    vector<string> to_strings() const override;
    SharedValue length(vector<SharedValue> args) override;
    SharedValue empty(vector<SharedValue> args);
    SharedValue subscript(int) const override;

private:
    vector<SharedValue> values;
    
    static SharedValue from_string(string& s, int& i);
    
}; // class List


//==========================================================================================================
// In order to enable calling function with named parameters, we need a Value that will represent a param-val
// pair.
//==========================================================================================================
class ParamVal: public Value {
    VALUE_CALL_MECHANISM(Value, ParamVal);
public:
    ParamVal(string _name, SharedValue _val);
    ParamVal(string _name, string _val);
    ParamVal(string _name, bool _val);
    
    Value* copy() const override;
    string to_string() const override;

    string name;
    SharedValue val;
};


//==========================================================================================================
// A list of param-value pairs.
//==========================================================================================================
class ParamValsList: public Value {
    VALUE_CALL_MECHANISM(Value, ParamValsList);
public:

    ParamValsList(vector<SharedValue> _values);
    
    Value* copy() const override;
    string to_string() const override;
    vector<SharedValue> get_values();
    SharedValue length(vector<SharedValue> args) override;
    SharedValue empty(vector<SharedValue> args);
    SharedValue subscript(int) const override;
    
private:
    vector<SharedValue> values;
    
}; // class ParamValsList


//==========================================================================================================
//==========================================================================================================
class MatchResult: public Value {
    VALUE_CALL_MECHANISM(Value, MatchResult);
public:
    MatchResult(string, string);
    Value* copy() const override;
    string to_string() const override;
    SharedValue length(vector<SharedValue> args) override;
    SharedValue empty(vector<SharedValue> args);
    SharedValue subscript(int) const override;

private:
    string str, regex_str;
    smatch match;
};

#endif /* Value_hpp */
















