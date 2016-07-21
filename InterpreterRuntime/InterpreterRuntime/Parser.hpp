//
//  Parser.hpp
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/21/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include "common_headers.h"
#include "utils.hpp"
#include "Token.hpp"
#include "AST.hpp"

class Parser {
public:
    AST* parse(vector<Token*> tokens);
    
    
private:
    static vector<vector<Action>> table;
    static vector<ProductionInfo> production_infos;
    
    AST* gen_ast(int production, vector<TokenOrAST>& elements);
    AST* extract_ast(vector<TokenOrAST>& elements);
};

#endif /* Parser_hpp */
