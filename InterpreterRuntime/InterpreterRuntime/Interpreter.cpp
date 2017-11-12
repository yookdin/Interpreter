//
//  Interpreter.cpp
//  MockServer
//
//  Created by Yuval Dinari on 7/31/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "Interpreter.hpp"
#include "AstVisitor.hpp"


//==========================================================================================================
//==========================================================================================================
Interpreter::~Interpreter() {
    reset();
}


//==========================================================================================================
//==========================================================================================================
void Interpreter::reset() {
    symtabs.clear();
    script_names.clear();
}


//==========================================================================================================
// Run a script
//==========================================================================================================
void Interpreter::run(string filename, vector<SharedValue> &args, LogLevel _log_level) {
    
    log_level = _log_level;
    symtabs.push_back(map<string, SharedValue>());

    for(int i = 0; i < args.size(); ++ i) {
        ParamVal *param_val = args[i]->get<ParamVal>();
        
        if(param_val == nullptr)
            THROW << "Input values to Interpreter::run() should be param-val pairs";
        
        if(filename.empty() and param_val->name == "file") {
            filename = (string)*param_val->val;
        }
        else {
            // Copy the values, because we want each symbol table to have its own values
            set_val(param_val->name, SharedValue(param_val->val->copy()));
        }
    }
    
    if(filename.empty())
        THROW << "run() must be called with a file name";
        
    check_valid_file("script", filename);
    script_names.push_back(filename);
    
    if(log_level == LogLevel::ALL or log_level == LogLevel::TITLES)
        print_title();
    
    interpret(); // This actually parses and executes the file/string given
    
    if(log_level == LogLevel::ALL or log_level == LogLevel::TITLES)
        print_end_title();
    
    script_names.pop_back();
    symtabs.pop_back();    
}


//==========================================================================================================
// Parse the parameter string and return ParamValsList 
//==========================================================================================================
void Interpreter::parse_params_str(string params, vector<SharedValue> &param_vals) {
    Interpreter interpreter;
    
    // In order to use an Interpreter to parse the parameter string, and to be able to retrieve the result,
    // we need to create an assignement statement. Then, getting the value of the variable that was assigned
    // we'll have a list of param-val pairs.
    // Note: when assigning param-vals list it needs to be inside parentheses.
    params = "params = (" + params + ")";
    interpreter.run(params);
    
    for(auto v: interpreter.get_val<ParamValsList>("params")->get_values())
        param_vals.push_back(v);
}


//==========================================================================================================
// Running with an input string instead of a file is for internal uses, such as parsing a parameters string.
// Since parameters string are written with the same syntax as an scr file, the Interpreter can be used
// to parse it instead of writing another parsing method for that.
//==========================================================================================================
void Interpreter::run(string str) {
    symtabs.push_back(map<string, SharedValue>());
    interpret(str);
    // Note: don't pop symtabs, because we want might want to use the values
}


//==========================================================================================================
//==========================================================================================================
void Interpreter::interpret(string str) {
    vector<Token*> tokens;

    if(str.empty())
        lexer.lex_from_file(script_names.back(), tokens);
    else
        lexer.lex_from_string(str, tokens);
    
    AST* ast = parser.parse(tokens);
    
    for(auto t: tokens)
        delete t;
    
    if(ast == nullptr)
        return;
    
    update_interpreter_pointers(ast);
    ast->eval();
    ast->free();
}


//==========================================================================================================
// Some AST nodes need the interpreter, so go over the tree and update their pointers to point at 'this'.
//==========================================================================================================
void Interpreter::update_interpreter_pointers(AST* ast) {
    SetInterpreterVisitor visitor(this);
    ast->pre_order_traverse(visitor);
}


//==========================================================================================================
//==========================================================================================================
SharedValue Interpreter::call_func(string name, vector<SharedValue> args) {
    if(functab.count(name) == 0)
        THROW << "Function " << name << "() not recognized";
    
    return (this->*Interpreter::functab[name])(args);
}


//==========================================================================================================
//==========================================================================================================
SharedValue Interpreter::get_local_val(string var) {
    for(int i = symtabs.size() - 1; i >= 0; --i) {
        if(symtabs[i].count(var) != 0)
            return symtabs[i][var]; 
    }
    
    return no_value;
}


//==========================================================================================================
// The order of trying to get a value of a variable:
// 1. Local variables
// 2. As parameterless functions (e.g. default_ack, if not found otherwise will get the value of default_ack()
//    function call
//==========================================================================================================
SharedValue Interpreter::get_val(string var) {

    //------------------------------------------------------------------------------------------------------
    // Local vars - defined or passed to the script or any of its parents in the call chain
    //------------------------------------------------------------------------------------------------------
    SharedValue res = get_local_val(var);
    if(not res->is_no_value())
        return res;
    
    //------------------------------------------------------------------------------------------------------
    // Parameterless functions
    //------------------------------------------------------------------------------------------------------
    if(function_exists(var))
        return call_func(var, {});

    return res; // It's the caller responsibillity to check wether the value is valid
}


//==========================================================================================================
// Like get_val(), but fails if variable doesn't exist
//==========================================================================================================
SharedValue Interpreter::get_real_val(string var) {
    SharedValue val = get_val(var);
    
    if(val->is_no_value())
        THROW << "Variable \"" << var << "\" doesn't exist"; 
    
    return val;
}


//==========================================================================================================
//==========================================================================================================
void Interpreter::print_title() {
    ostringstream stream;
    
    stream << "====================================================================================================" << endl;
    stream << get_print_prefix() << "RUNNING SCENARIO: " << script_names.back() << endl;
    
    string params;

    for(auto& p: symtabs[0]) {
        params += p.first + " = " + p.second->to_string() + "\n";
    }
    
    stream << params;
    stream << "====================================================================================================" << endl;
    Print(false) << stream.str();
}


//==========================================================================================================
//==========================================================================================================
void Interpreter::print_end_title() {
    ostringstream stream;
    
    stream << "====================================================================================================" << endl;
    stream << "FINISHED SCENARIO: " << script_names.back() << endl;
    
    stream << "====================================================================================================" << endl;
    Print(false) << stream.str();
}


//==========================================================================================================
//==========================================================================================================
void Interpreter::set_val(string var, SharedValue val) { 
    if(symtabs.empty())
        THROW << "set_val() called but no active script is being run";
        
    symtabs.back()[var] = val; 
}


//==========================================================================================================
//==========================================================================================================
bool Interpreter::var_exists(string var) {
    for(int i = symtabs.size() - 1; i >= 0; --i) {
        if(symtabs[i].count(var) != 0)
            return true; 
    }
    
    return false;
}


//==========================================================================================================
//==========================================================================================================
string Interpreter::get_script_name() {
    return script_names.back();
}

//==========================================================================================================
//==========================================================================================================
bool Interpreter::function_exists(string name) {
    return functab.count(name) != 0;
}






