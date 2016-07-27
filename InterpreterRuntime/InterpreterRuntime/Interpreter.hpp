//
//  Interpreter.hpp
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/24/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Interpreter_hpp
#define Interpreter_hpp

#include "common_headers.h"
#include "Lexer.hpp"
#include "Parser.hpp"


//==========================================================================================================
//==========================================================================================================
class Interpreter {
public:
    void interpret(string filename);
    Value* get_val(string var);
    void set_val(string var, Value& val) { symtab.set_val(var, val); }
    Value* call_func(string name, vector<Value*> args);
    void print();
    
private:
    typedef Value*(Interpreter::*CallableFunc)(vector<Value*>);

    static map<string, CallableFunc> functab;
    Lexer lexer;
    Parser parser;
    SymbolTable symtab;
    
    void update_interpreter_pointers(AST* ast);
    Value* print(vector<Value*>);
};


#endif /* Interpreter_hpp */
