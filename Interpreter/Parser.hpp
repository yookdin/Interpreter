//
//  Parser.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/13/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp


#include "common.h"
#include "Token.hpp"
#include "SLR_Table.hpp"
#include "AST_Factory.hpp"

//==========================================================================================================
//==========================================================================================================
class Parser {
public:
    Parser(string grammar_file);
    void parse(vector<Token*> tokens);
    
private:
    Grammar grammar;
    SLR_Table table;
    AST_Factory ast_factory;
};


#endif /* Parser_hpp */
