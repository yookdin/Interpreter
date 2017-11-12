//
//  set_vars.h
//  MockServer
//
//  Created by Yuval Dinari on 7/31/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef set_vars_h
#define set_vars_h

//==========================================================================================================
// C++11 ugly way to iterate over an arguments pack. You can't really iterate, so you create these
// functions. Each recursive call to the second function (with the arguments pack) will be with one fewer
// args, so evantually the first function will be called.
//==========================================================================================================

//==========================================================================================================
// This is the function called to end the recursion
//==========================================================================================================
template<class T>
void set_vars_internal(deque<SharedValue> args, T& var) {
    if(not args[0]->is_no_value())
        var = (T)*args[0];
}


//==========================================================================================================
// This is the recursive funtion
//==========================================================================================================
template <class T, class... Vars>
void set_vars_internal(deque<SharedValue> args, T& var, Vars&... vars) {
    
    if(sizeof...(Vars) + 1 != args.size()) // + 1 because there's one explicit argument and a parameter pack
        THROW << "Argument number mismatch!";
    
    if(not args[0]->is_no_value())
        var = (T)*args[0];
    
    args.pop_front();
    set_vars_internal(args, vars...); // Will eventually call the single valued set_vars_internal()
}


//==========================================================================================================
// This is the function called by an Interpreter::CallableFunction, for setting a variable number of
// variables according to an input param-val pairs list 'named_args'.
// The 'arg_names' list determines the order in which the values should be arranged to match the order of the
// input variables.
// NOTE: there could be more variables than arguments. In that case, those variables that don't have a
// corresponding argument, won't be changed.
//==========================================================================================================
template <class T, class... Vars>
void set_vars(string func_name, vector<SharedValue> named_args, vector<string> arg_names, T& t, Vars&... vars) {
    
    //------------------------------------------------------------------------------------------------------
    // Turn named args which is supposed to be a param-val pair list into a map of name and values.
    //------------------------------------------------------------------------------------------------------
    map<string, SharedValue> args_map;
    for(auto arg: named_args) {
        if(arg->get_type() != Value::PARAM_VAL)
            THROW << "Expected all arguments for function " << func_name << " to be param-value pairs";
        
        ParamVal* param_val = (ParamVal*)arg.get();
        args_map[param_val->name] = param_val->val;
    }
    
    //------------------------------------------------------------------------------------------------------
    // Arrange the arguments according to the order of input argument names
    //------------------------------------------------------------------------------------------------------
    deque<SharedValue> args;
    for(auto& name: arg_names) {
        if(args_map.count(name) != 0)
            args.push_back(args_map[name]);
        else
            args.push_back(no_value); // This is to indicate value not given, so variable value won't change
    }
    
    //------------------------------------------------------------------------------------------------------
    // Set the variables in the arguments pack according to 'args'
    //------------------------------------------------------------------------------------------------------
    set_vars_internal(args, t, vars...);
}


//==========================================================================================================
// Like set_vars(), but require to have arguents for all variables
//==========================================================================================================
template <class T, class... Vars>
void set_exact_vars(string func_name, vector<SharedValue> named_args, vector<string> arg_names, T& t, Vars&... vars) {
    
    //------------------------------------------------------------------------------------------------------
    // Turn named args which is supposed to be a param-val pair list into a map of name and values.
    //------------------------------------------------------------------------------------------------------
    map<string, SharedValue> args_map;
    for(auto arg: named_args) {
        if(arg->get_type() != Value::PARAM_VAL)
            THROW << "Expected all arguments for function " << func_name << " to be param-value pairs";
        
        ParamVal* param_val = (ParamVal*)arg.get();
        args_map[param_val->name] = param_val->val;
    }
    
    //------------------------------------------------------------------------------------------------------
    // Arrange the arguments according to the order of input argument names
    //------------------------------------------------------------------------------------------------------
    deque<SharedValue> args;
    for(auto& name: arg_names) {
        if(args_map.count(name) != 0)
            args.push_back(args_map[name]);
        else
            THROW << "Argument missing for variable " << name << " in function " << func_name;
    }
    
    //------------------------------------------------------------------------------------------------------
    // Set the variables in the arguments pack according to 'args'
    //------------------------------------------------------------------------------------------------------
    set_vars_internal(args, t, vars...);
}


#endif /* set_vars_h */
