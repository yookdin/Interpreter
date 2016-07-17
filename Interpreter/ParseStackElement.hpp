//
//  ParseStackElement.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/17/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef ParseStackElement_hpp
#define ParseStackElement_hpp

#include "common.h"
#include "Token.hpp"
#include "AST.hpp"


//======================================================================================================
//======================================================================================================
union TokenOrASTUnion {
    Token *token;
    AST* ast;
};


//======================================================================================================
//======================================================================================================
class TokenOrAST {
public:
    TokenOrAST(): token(nullptr) {}
    TokenOrAST(Token* _token): is_token(true), token(_token) {}
    TokenOrAST(AST* _ast): is_token(false), ast(_ast) {}
    
    Token* get_token() { return is_token ? token : nullptr; }
    AST* get_ast()     { return is_token ? nullptr : ast; }

private:
    bool is_token;
    union {
        Token *token;
        AST* ast;
    };
};


//======================================================================================================
//======================================================================================================
class ParseStackElement {
public:
    ParseStackElement(int s): state(s) {}
    ParseStackElement(int s, Token* token): state(s), token_or_ast(token) {}
    ParseStackElement(int s, AST* ast): state(s), token_or_ast(ast) {}

    TokenOrAST get_token_or_ast() { return token_or_ast; }
    
    const int state;
    
private:
    TokenOrAST token_or_ast;
};


#endif /* ParseStackElement_hpp */