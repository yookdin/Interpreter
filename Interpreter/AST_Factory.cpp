//
//  AST_Factory.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/17/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "AST_Factory.hpp"


//==========================================================================================================
//==========================================================================================================
map<string, AST_Factory::ast_generator> AST_Factory::generators_map = {
    {"",            &AST_Factory::extract_ast},
    {"Num",         &AST_Factory::gen_num},
    {"Bop",         &AST_Factory::gen_bop},
    {"Uop",         &AST_Factory::gen_uop},
    {"CondExp",     &AST_Factory::gen_cond_exp_op},
    {"Assignment",  &AST_Factory::gen_assignment},
    {"Statements",  &AST_Factory::gen_statements},
    {"Var",         &AST_Factory::gen_var},
    {"If",          &AST_Factory::gen_if}
};


//==========================================================================================================
//==========================================================================================================
AST_Factory::ast_generator AST_Factory::get_ast_generator(string action_name) {
    if(generators_map.count(action_name) == 0)
        throw string("Action name not recognized: " + action_name);
    return generators_map[action_name];
}


//==========================================================================================================
// Sometimes nothing new should be done, just return the only AST in the list of elements. The other are
// tokens that aren't needed in the AST (like parentheses).
//==========================================================================================================
AST* AST_Factory::extract_ast(vector<TokenOrAST>& elements) {
    for(auto& elem: elements) {
        AST* ast;
        if((ast = elem.get_ast()) != nullptr)
            return ast;
    }
    
    throw string("No AST found in elements received by AST factory");
}


//==========================================================================================================
//==========================================================================================================
AST* AST_Factory::gen_num(vector<TokenOrAST>& elements) { return new NumAST(elements); }
AST* AST_Factory::gen_bop(vector<TokenOrAST>& elements) { return new BopAST(elements); }
AST* AST_Factory::gen_uop(vector<TokenOrAST>& elements) { return new UopAST(elements); }
AST* AST_Factory::gen_cond_exp_op(vector<TokenOrAST>& elements) { return new CondExpAST(elements); }
AST* AST_Factory::gen_assignment(vector<TokenOrAST>& elements) { return new AssignmentAST(elements); }
AST* AST_Factory::gen_statements(vector<TokenOrAST>& elements) { return new StatementsAST(elements); }
AST* AST_Factory::gen_var(vector<TokenOrAST>& elements) { return new VarAST(elements); }
AST* AST_Factory::gen_if(vector<TokenOrAST>& elements) { return new IfAST(elements); }



































