//
//  AstVisitor.hpp
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/25/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef AstVisitor_hpp
#define AstVisitor_hpp

#include <iomanip>
using namespace std;

#include "AST.hpp"
#include "Interpreter.hpp"


//==========================================================================================================
// Generic AST visitor
//==========================================================================================================
class AstVisitor {
public:
    virtual void visit(AST&) = 0;
    virtual void before_descending(AST&) {}
    virtual void after_descending(AST&) {}
};

//==========================================================================================================
//==========================================================================================================
class AstPrintVisitor: public AstVisitor {
public:
    void visit(AST& ast) { 
        Print(false) << setw(level * tab_width) << "";
        ast.print_node(); 
    }
    void before_descending(AST&) { ++level; }
    void after_descending(AST&) { --level; }
private:
    int level = 0;
    const int tab_width = 3;
};


//==========================================================================================================
// Set the interpreter field
//==========================================================================================================
class SetInterpreterVisitor: public AstVisitor {
public:
    SetInterpreterVisitor(Interpreter* _interpreter): interpreter(_interpreter) {}
    
    void visit(AST& ast) {
        ast.interpreter = interpreter;
    }
    
private:
    Interpreter* interpreter;
};


//==========================================================================================================
//==========================================================================================================
class DeleteVisitor: public AstVisitor {
public:
    void visit(AST& ast) {
        delete &ast;
    }
};


#endif /* AstVisitor_hpp */















