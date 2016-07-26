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
#include "FunctionTable.hpp"

//==========================================================================================================
//==========================================================================================================
class Interpreter {
public:
    Interpreter(FunctionTable& _functab): functab(_functab){}
    void interpret(string filename);
    Value* get_val(string var);
    void set_val(string var, Value& val) { symtab.set_val(var, val); }
    Value* call_func(string name, vector<Value*> args) { return functab.call(name, args); }
    void print();
    
private:
    Lexer lexer;
    Parser parser;
    SymbolTable symtab;
    FunctionTable& functab;
    
    void update_interpreter_pointers(AST* ast);
};



#endif /* Interpreter_hpp */
