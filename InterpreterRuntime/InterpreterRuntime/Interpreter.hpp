//
//  Interpreter.hpp
//  MockServer
//
//  Created by Yuval Dinari on 7/31/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Interpreter_hpp
#define Interpreter_hpp

#include "Lexer.hpp"
#include "Parser.hpp"


//======================================================================================================================
//======================================================================================================================
class Interpreter {
public:
    Interpreter(){}
    ~Interpreter();
    
    void run(string filename, vector<SharedValue> &args, LogLevel log_level = LogLevel::ALL);
    static void parse_params_str(string params, vector<SharedValue> &param_vals);
    
    SharedValue call_func(string name, vector<SharedValue> args);
    SharedValue get_val(string var);
    void reset();
    
    
    //------------------------------------------------------------------------------------------------------------------
    // Return a pointer to a value of a specific requested type, or null if not found or doesn't match the type
    //------------------------------------------------------------------------------------------------------------------
    template<class T>
    T* get_val(string var) {
        return get_val(var)->get<T>();
    }
    
    //------------------------------------------------------------------------------------------------------------------
    // Wrappers to template get_cpp_val()
    //------------------------------------------------------------------------------------------------------------------
    string get_str_val(string var) { return get_real_val(var)->to_string(); }
    bool get_bool_val(string var)  { return get_real_val(var)->to_bool();   }
    int get_int_val(string var)    { return get_real_val(var)->to_int();    }
    
    void set_val(string var, SharedValue val);
    bool var_exists(string var);
    string get_script_name();
    bool call_id_exists(string call_id);

private:
    vector<map<string, SharedValue>> symtabs;
    vector<string> script_names;
    Lexer lexer;
    Parser parser;
    LogLevel log_level;
    
    void run(string str);
    void interpret(string str = "");
    void update_interpreter_pointers(AST* ast);
    void print_title();
    void print_end_title();
    SharedValue get_local_val(string var);
    bool function_exists(string name);
    SharedValue get_real_val(string var);
    
    //------------------------------------------------------------------------------------------------------------------
    // A type for functions that can be called from scripts
    //------------------------------------------------------------------------------------------------------------------
    typedef SharedValue(Interpreter::*CallableFunc)(vector<SharedValue> args);
    
    static map<string, CallableFunc> functab;
    
    void check_exact_params(string func_name, vector<Value::Type> expected_types, vector<SharedValue> args);
    
    //------------------------------------------------------------------------------------------------------------------
    // These are functions that can be called from scripts, common to clients and servers.
    //------------------------------------------------------------------------------------------------------------------
    SharedValue print(vector<SharedValue> args);
    SharedValue run_script(vector<SharedValue> args);
    SharedValue expect(vector<SharedValue> args);
    SharedValue sleep_seconds(vector<SharedValue> args);
    SharedValue sleep_milliseconds(vector<SharedValue> args);
    SharedValue replace(vector<SharedValue> args);
    SharedValue regex_match(vector<SharedValue> args);
    SharedValue var_exists(vector<SharedValue> args);
    SharedValue get_time_seconds(vector<SharedValue> args);
};


    
    
#endif /* Interpreter_hpp */
