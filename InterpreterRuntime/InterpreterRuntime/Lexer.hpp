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
    
    string input;
    string::const_iterator iter;
    int line_num;
    bool in_string;
    int num_open_brackets;
    string cur_string;

    enum StringKind { QUOTES, BRACKETS };
    stack<StringKind> string_kinds;
    
    void reset();
    
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
    
    // Note: these are esacaped in any kind of string. In quoted strings " need to be escaped,
    // in bracketed strings ]] needs to be escaped (like this: \]])
    bool is_escaped_char(char c) { return c == '[' or c == '\\'; }
    
    string create_syntax_err_msg(string& filename);
    void get_current_line_position(int& start, int& len);
};

 
#endif /* Lexer_hpp */
