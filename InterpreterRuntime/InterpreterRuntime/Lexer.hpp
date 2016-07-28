//
//  Lexer.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/6/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Lexer_hpp
#define Lexer_hpp

#include "common_headers.h"
#include "Token.hpp"

//==========================================================================================================
//==========================================================================================================
class Lexer {
public:
    void lex(string filename, vector<Token*>& tokens);
    
private:
    typedef Token*(Lexer::*token_matcher)(smatch& match);
    static vector<token_matcher> matchers;
    static regex keyword_re, num_re, bool_re, id_re;
    
    // Fields indicating current state
    string input;
    string::const_iterator iter;
    int line_num = 1;
    bool in_string = false;
    int num_open_brackets = 0;
    string cur_string;

    enum StringKind { QUOTES, BRACKETS };
    stack<StringKind> string_kinds;
    
    
    Token* try_match();
    Token* match_keyword(smatch& match);
    Token* match_num(smatch& match);
    Token* match_bool(smatch& match);
    Token* match_id(smatch& match);
    
    void skip_irrelevant();
    bool skip_spaces();
    bool skip_comment();
    
    bool try_string(vector<Token*>& tokens);
    string get_next_string_chars();
    bool check_string_end(string& end_chars);
    string get_current_line();
};

 
#endif /* Lexer_hpp */
