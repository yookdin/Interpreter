//
//  Parser.hpp
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/21/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include "sip_tester_utils.hpp"
#include "Token.hpp"
#include "AST.hpp"


struct ParserStackElement {
    int state;
    ParseElement* elem;
};


class Parser {
public:
    AST* parse(vector<Token*> tokens);
    
    
private:
    static vector<vector<Action>> table;
    static vector<ProductionInfo> production_infos;
    
    AST* gen_ast(int production, vector<ParseElement*>& elements);
    AST* extract_ast(vector<ParseElement*>& elements);
    AST* gen_bop_ast(vector<ParseElement*>& elements);
    
    string create_err_msg(ParserStackElement &stack_element, Token& token);
};

#endif /* Parser_hpp */
