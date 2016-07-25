//
//  AstVisitor.hpp
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/25/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef AstVisitor_hpp
#define AstVisitor_hpp

#include "common_headers.h"
#include "AST.hpp"


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
        cout << setw(level * tab_width) << "";
        ast.print_node(); 
    }
    void before_descending(AST&) { ++level; }
    void after_descending(AST&) { --level; }
private:
    int level = 0;
    const int tab_width = 3;
};


//==========================================================================================================
// Update the interpreter field of var and function nodes.
//==========================================================================================================
class UpdateInterpreterVisitor: public AstVisitor {
public:
    UpdateInterpreterVisitor(Interpreter* _interpreter): interpreter(_interpreter) {}
    
    void visit(AST& ast) { 
        if(typeid(ast) == typeid(VarAST)) { 
            dynamic_cast<VarAST&>(ast).interpreter = interpreter;
        }
        else if(typeid(ast) == typeid(FuncAST)) {
            dynamic_cast<FuncAST&>(ast).interpreter = interpreter;
        }
        else if(typeid(ast) == typeid(AssignmentAST)) {
            dynamic_cast<AssignmentAST&>(ast).interpreter = interpreter;
        }
    }
    
private:
    Interpreter* interpreter;
};


#endif /* AstVisitor_hpp */















