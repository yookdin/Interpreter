//
//  AST_Factory.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/17/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef AST_Factory_hpp
#define AST_Factory_hpp

#include "common.h"
#include "AST.hpp"
#include "ParseStackElement.hpp"


//==========================================================================================================
//==========================================================================================================
class AST_Factory {
public:
    // Type of pointer to static function (that's why there's no class scope in the definition)
    typedef AST*(*ast_generator)(vector<TokenOrAST>& elements);

    static ast_generator get_ast_generator(string action_name);
private:
    static map<string, ast_generator> generators_map;
    
    static AST* extract_ast(vector<TokenOrAST>& elements);
    static AST* gen_num(vector<TokenOrAST>& elements);
    static AST* gen_bop(vector<TokenOrAST>& elements);
    static AST* gen_uop(vector<TokenOrAST>& elements);
};


#endif /* AST_Factory_hpp */
