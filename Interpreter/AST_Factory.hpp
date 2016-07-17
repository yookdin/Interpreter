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
    AST* gen_ast(string ast_name, vector<TokenOrAST> elements);
private:
    
};


#endif /* AST_Factory_hpp */
