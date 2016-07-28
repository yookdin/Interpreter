//
//  Interpreter.cpp
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/24/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "Interpreter.hpp"
#include "AstVisitor.hpp"


//==========================================================================================================
//==========================================================================================================
map<string, Interpreter::CallableFunc> Interpreter::functab = {
    {"print", &Interpreter::print},
    {"foo", &Interpreter::foo}
};


//==========================================================================================================
//==========================================================================================================
void Interpreter::interpret(string filename) {
    vector<Token*> tokens;
    lexer.lex(filename, tokens);
    AST* ast = parser.parse(tokens);
    ast->print();
    update_interpreter_pointers(ast);
    ast->eval();
}


//==========================================================================================================
//==========================================================================================================
void Interpreter::update_interpreter_pointers(AST* ast) {
    UpdateInterpreterVisitor visitor(this);
    ast->traverse(visitor);
}


//==========================================================================================================
//==========================================================================================================
Value& Interpreter::get_val(string var) {
    // TODO: check external symtab; try var as func with no params?
    return symtab.get_val(var);
}


//==========================================================================================================
//==========================================================================================================
Value& Interpreter::call_func(string name, vector<Value*> args) {
    if(functab.count(name) == 0)
        throw string("Function " + name + "() not recognized");

    Value& res = (this->*functab[name])(args);
    delete_args(args); // Arguments created for the function call no longer needed 
    return res;
}

//==========================================================================================================
//==========================================================================================================
void Interpreter::delete_args(vector<Value*> args) { 
    for(auto arg: args)
        if(arg->tmp)
            delete arg; 
}


//==========================================================================================================
//==========================================================================================================
Value& Interpreter::print(vector<Value*> args) {
    for(auto arg: args) arg->print();
    return no_value;
}


//==========================================================================================================
//==========================================================================================================
void Interpreter::print() {
    symtab.print();
}    







