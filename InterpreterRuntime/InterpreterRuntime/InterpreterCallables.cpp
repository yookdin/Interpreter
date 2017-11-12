//
//  InterpreterCallables.cpp
//  SIPTester
//
//  Created by Yuval Dinari on 9/6/17.
//  Copyright © 2017 Yuk. All rights reserved.
//

#include <unistd.h>
#include "Interpreter.hpp"
#include "set_vars.h"


//==========================================================================================================
// Function callable from scripts
//==========================================================================================================
map<string, Interpreter::CallableFunc> Interpreter::functab = {
    {"print",                   &Interpreter::print},
    {"run_script",              &Interpreter::run_script},
    {"expect",                  &Interpreter::expect},
    {"sleep_seconds",           &Interpreter::sleep_seconds},
    {"sleep_milliseconds",      &Interpreter::sleep_milliseconds},
    {"replace",                 &Interpreter::replace},
    {"regex_match",             &Interpreter::regex_match},
    {"var_exists",              &Interpreter::var_exists},
    {"get_time_seconds",        &Interpreter::get_time_seconds}
};


//==========================================================================================================
//==========================================================================================================
SharedValue Interpreter::print(vector<SharedValue> args) {
    string message;
    
    for(auto arg: args) {
        message += arg->to_string();
    }
    
    Print() << message << endl;
    return no_value;
}


//==========================================================================================================
//==========================================================================================================
SharedValue Interpreter::run_script(vector<SharedValue> args) {
    run("", args, LogLevel::SIP_MESSAGES);
    return no_value;
}


//==========================================================================================================
//==========================================================================================================
SharedValue Interpreter::expect(vector<SharedValue> args) {
    check_exact_params(__func__, {Value::BOOL}, args);
    
    if(not *args[0])
        THROW << "expect() failed"; // TODO: How to give more information?
    
    return no_value;
}


//==========================================================================================================
//==========================================================================================================
SharedValue Interpreter::sleep_seconds(vector<SharedValue> args) {
    if(args.size() != 1)
        THROW << "sleep_seconds() expects just one parameter";
    
    int seconds = args[0]->to_int();
    usleep(seconds * 1000000);
    return no_value;
}


//==========================================================================================================
//==========================================================================================================
SharedValue Interpreter::sleep_milliseconds(vector<SharedValue> args) {
    if(args.size() != 1)
        THROW << "sleep_milliseconds() expects just one parameter";
    
    int ms = args[0]->to_int(); 
    usleep(ms * 1000);    
    return no_value;
}


//==========================================================================================================
// Parameters: original-string, regex-to-match, replacement-string
//==========================================================================================================
SharedValue Interpreter::replace(vector<SharedValue> args) {
    if(args.size() != 3)
        THROW << "replace() expects 3 arguments";
    
    for(auto& arg: args)
        if(arg->get_type() != Value::STRING)
            THROW << "replace() arguments must all be strings";
    
    string str = args[0]->to_string(), rgx = args[1]->to_string(), fmt = args[2]->to_string();
    str = regex_replace(str, regex(rgx), fmt);
    return Value::from_string(str);
}


//==========================================================================================================
//==========================================================================================================
SharedValue Interpreter::regex_match(vector<SharedValue> args) {
    if(args.size() != 2)
        THROW << "regex_match() expects 2 arguments";
    
    for(auto& arg: args)
        if(arg->get_type() != Value::STRING)
            THROW << "regex_match() arguments must all be strings";
    
    return SharedValue(new MatchResult(args[0]->to_string(), args[1]->to_string()));
}


//==========================================================================================================
//==========================================================================================================
SharedValue Interpreter::var_exists(vector<SharedValue> args) {
    string name = args[0]->to_string();
    return SharedValue(new Bool(var_exists(name)));
}


//==========================================================================================================
//==========================================================================================================
SharedValue Interpreter::get_time_seconds(vector<SharedValue> args) {
    time_t t = time(nullptr);
    return SharedValue(new Num(t));   
}


//==========================================================================================================
// Check that the given list of arguments is of the types specified be 'expected_types'
//==========================================================================================================
void Interpreter::check_exact_params(string func_name, vector<Value::Type> expected_types, vector<SharedValue> args) {
    int num_params = expected_types.size();
    func_name += "()";
    
    if(args.size() != num_params)
        THROW << func_name << " should have exactly " << num_params << " " << (num_params == 1 ? "parameter" : "parameters");
    
    for(int i = 0; i < args.size(); ++i) {
        if(args[i]->get_type() != expected_types[i])
            THROW << "Parameter " << i << " of function " << func_name << " should be " << Value::get_type_name(expected_types[i])
            << " but received " << args[i]->get_type_name();
    }
}

