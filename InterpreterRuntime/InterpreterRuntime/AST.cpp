//
//  AST.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/16/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "AST.hpp"


//==========================================================================================================
//==========================================================================================================
void AST::print() {
    recursive_print(0);
}

//==========================================================================================================
//==========================================================================================================
void AST::recursive_print(int indentation_level) {
    cout << setw(indentation_level * 3) << "";
    print_node();
    for(auto& c: children) c->recursive_print(indentation_level + 1);
}


//==========================================================================================================
//==========================================================================================================
int NumAST::extract_num(vector<TokenOrAST>& elements) {
    return ((NumToken*)elements[0].get_token())->val;
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
AssignmentAST::AssignmentAST(vector<TokenOrAST>& elements) {
    string id = ((IdentifierToken*)elements[0].get_token())->name;
    add_child(new VarAST(id));
    add_child(elements[2].get_ast());
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
IfElseAST::IfElseAST(vector<TokenOrAST>& elements) {
    add_child(elements[1].get_ast());
    add_child(elements[2].get_ast());
    add_child(elements[4].get_ast());
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
























