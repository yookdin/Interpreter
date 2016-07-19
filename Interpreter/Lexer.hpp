//
//  Lexer.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/6/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Lexer_hpp
#define Lexer_hpp

#include "common.h"
#include "Token.hpp"

//==========================================================================================================
//==========================================================================================================
class Lexer {
public:
    void lex(string filename, vector<Token*>& tokens);
    
private:
    typedef Token*(Lexer::*token_matcher)(smatch& match);
    static vector<token_matcher> matchers;
    static regex num_re, op_re, id_re, keyword_re;
    
    string input;
    string::const_iterator pos;
    
    Token* try_match();
    Token* match_num(smatch& match);
    Token* match_op(smatch& match);
    Token* match_id(smatch& match);
    Token* match_keyword(smatch& match);
    
    void skip_irrelevant();
    bool skip_spaces();
    bool skip_comment();
};


#endif /* Lexer_hpp */
