//
//  AST.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/16/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "AST.hpp"
#include "AstVisitor.hpp"
#include "Interpreter.hpp"


//==========================================================================================================
// Traverse the tree, perform the visitor action for each node
//==========================================================================================================
void AST::traverse(AstVisitor& visitor) {
    visitor.visit(*this);
    visitor.before_descending(*this);
    for(auto c: children) c->traverse(visitor);
    visitor.after_descending(*this);
}


//==========================================================================================================
//==========================================================================================================
void AST::print() {
    AstPrintVisitor print_visitor;
    traverse(print_visitor);
}


//==========================================================================================================
//==========================================================================================================
void AST::eval_children(int start) {
    for(int i = start; i < children.size(); ++i) children[i]->eval();
}


//==========================================================================================================
//==========================================================================================================
vector<Value*> AST::get_children_vals() {
    vector<Value*> res;
    for(auto c: children) res.push_back(& c->eval());
    return res;
}


//==========================================================================================================
//==========================================================================================================
BopAST::BopAST(vector<TokenOrAST>& elements): OpAST(get_op(elements[1].get_token()->sym)) {
    add_child(elements[0].get_ast());
    add_child(elements[2].get_ast());
}


//==========================================================================================================
//==========================================================================================================
UopAST::UopAST(vector<TokenOrAST>& elements): OpAST(get_op(elements[0].get_token()->sym)) {
    add_child(elements[1].get_ast());
}


//==========================================================================================================
//==========================================================================================================
CondExpAST::CondExpAST(vector<TokenOrAST>& elements) {
    add_child(elements[0].get_ast());
    add_child(elements[2].get_ast());
    add_child(elements[4].get_ast());
}


//==========================================================================================================
//==========================================================================================================
Value& CondExpAST::eval() {
    if(children[0]->eval())
        return children[1]->eval();
    else
        return children[2]->eval();
}


//==========================================================================================================
//==========================================================================================================
Value& VarAST::eval() {
    Value* val;
    if((val = interpreter->get_val(name)) == nullptr)
        return no_value;
    else
        return *val;
}


//==========================================================================================================
//==========================================================================================================
AssignmentAST::AssignmentAST(vector<TokenOrAST>& elements) {
    add_child(new VarAST(elements));
    add_child(elements[2].get_ast());
}


//==========================================================================================================
//==========================================================================================================
Value& AssignmentAST::eval() {
    string var = ((VarAST*)children[0])->name;
    Value& val = children[1]->eval();
    
    if(val.tmp) {
        val.tmp = false; // Prevent deleting this by OpAST
        interpreter->set_val(var, val);
    }
    else { // Create a copy of value, so every variable will have it's own
        interpreter->set_val(var, val.copy());
    }

    return no_value;
}


//==========================================================================================================
//==========================================================================================================
StatementsAST::StatementsAST(vector<TokenOrAST>& elements) {
    // Make children "flat", each shall be an actual statemet and statements nodes will be discarded
    for(auto& e: elements) {
        if(e.is_token) continue; // Probably a semi colon or curly brace
        
        AST* ast = e.get_ast();
        
        if(typeid(*ast) == typeid(StatementsAST))
            for(auto c: ast->children)
                add_child(c);
        else
            add_child(ast);
    }
}


//==========================================================================================================
//==========================================================================================================
Value& StatementsAST::eval() {
    eval_children();
    return no_value;
}


//==========================================================================================================
// First child will be the expression to evaluate. Rest will be the statements in the body
//==========================================================================================================
IfAST::IfAST(vector<TokenOrAST>& elements) {
    add_child(elements[1].get_ast());
    AST* ast = elements[2].get_ast();

    if(typeid(*ast) == typeid(StatementsAST))
        for(auto c: ast->children) add_child(c);
    else
        add_child(ast);
}


//==========================================================================================================
//==========================================================================================================
Value& IfAST::eval() {
    if(children[0]->eval())
        eval_children(1);
    
    return no_value;
}


//==========================================================================================================
//==========================================================================================================
IfElseAST::IfElseAST(vector<TokenOrAST>& elements) {
    add_child(elements[1].get_ast());
    add_child(elements[2].get_ast());
    add_child(elements[4].get_ast());
}


//==========================================================================================================
//==========================================================================================================
Value& IfElseAST::eval() {
    if(children[0]->eval())
        children[1]->eval();
    else
        children[2]->eval();
    
    return no_value;
}


//==========================================================================================================
//==========================================================================================================
WhileAST::WhileAST(vector<TokenOrAST>& elements) {
    add_child(elements[1].get_ast());
    AST* ast = elements[2].get_ast();
    
    if(typeid(*ast) == typeid(StatementsAST))
        for(auto c: ast->children) add_child(c);
    else
        add_child(ast);
}


//==========================================================================================================
//==========================================================================================================
Value& WhileAST::eval() {
    while(children[0]->eval())
        eval_children(1);
    
    return no_value;
}


//==========================================================================================================
// Each time this tree is executed, it will evaluate the expression (first child), then repeat the body that
// number of times. However, the next time the tree is evaluated the 'times' expression can have another
// value
//==========================================================================================================
RepeatAST::RepeatAST(vector<TokenOrAST>& elements) {
    add_child(elements[1].get_ast());
    AST* ast = elements[3].get_ast();
    
    if(typeid(*ast) == typeid(StatementsAST))
        for(auto c: ast->children) add_child(c);
    else
        add_child(ast);
}


//==========================================================================================================
//==========================================================================================================
Value& RepeatAST::eval() {
    int times = children[0]->eval();
    if(times < 0) throw string("'times' value of repeat statement must be greater or equal to 0");
    
    for(int i = 0; i < times; ++i)
        eval_children(1);
    
    return no_value;
}


//==========================================================================================================
// This won't appear in final AST
//==========================================================================================================
ParamsAST::ParamsAST(vector<TokenOrAST>& elements) {
    for(auto& e: elements) {
        if(not e.is_token) { // Skip commas, add everything else
            AST* ast = e.get_ast();
            if(typeid(*ast) == typeid(ParamsAST))
                for(auto c: ast->children) add_child(c);
            else
                add_child(ast);
        }
    }
}


//==========================================================================================================
//==========================================================================================================
NamedParamAST::NamedParamAST(vector<TokenOrAST>& elements): name(((IdentifierToken*)elements[0].get_token())->name) {
    add_child(elements[2].get_ast());
}


//==========================================================================================================
// Containing function node is responsible for taking the value and assigning it to the correct parameter
//==========================================================================================================
Value& NamedParamAST::eval() {
    return children[0]->eval();
}


//==========================================================================================================
//==========================================================================================================
NamedParamsAST::NamedParamsAST(vector<TokenOrAST>& elements) {
    for(auto& e: elements) {
        if(not e.is_token) { // Skip commas, add everything else
            AST* ast = e.get_ast();
            if(typeid(*ast) == typeid(NamedParamsAST))
                for(auto c: ast->children) add_child(c);
            else
                add_child(ast);
        }
    }
}


//==========================================================================================================
//==========================================================================================================
FuncAST::FuncAST(vector<TokenOrAST>& elements): name(((IdentifierToken*)elements[0].get_token())->name) {
    if(elements.size() != 3) { // 3 means no parameters : "ID ( )"
        // Get the children of the parameter list
        for(auto c: elements[2].get_ast()->children) add_child(c);
    }
}


//==========================================================================================================
//==========================================================================================================
Value& FuncAST::eval() {
    // TODO: find function, build params list, invoke it, return its value
    return no_value;
}






















