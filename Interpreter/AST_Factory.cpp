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
    {"",        &AST_Factory::extract_ast},
    {"Num",     &AST_Factory::gen_num},
    {"Op",      &AST_Factory::gen_op}
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
AST* AST_Factory::gen_num(vector<TokenOrAST>& elements) {
    return new NumAST(elements);
}


//==========================================================================================================
//==========================================================================================================
AST* AST_Factory::gen_op(vector<TokenOrAST>& elements) {
    return new OpAST(elements);
}
