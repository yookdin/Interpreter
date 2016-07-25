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
void Interpreter::interpret(string filename) {
    vector<Token*> tokens;
    lexer.lex(filename, tokens);
    AST* ast = parser.parse(tokens);
    ast->print();
    update_interpreter_pointers(ast);
    ast->eval();
    print();
}


//==========================================================================================================
//==========================================================================================================
void Interpreter::update_interpreter_pointers(AST* ast) {
    UpdateInterpreterVisitor visitor(this);
    ast->traverse(visitor);
}


//==========================================================================================================
//==========================================================================================================
Value* Interpreter::get_val(string var) {
    // TODO: check external symtab; try var as func with no params?
    return symtab.get_val(var);
}


//==========================================================================================================
//==========================================================================================================
void Interpreter::print() {
    symtab.print();
}    






