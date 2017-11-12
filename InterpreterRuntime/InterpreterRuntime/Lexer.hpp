//
//  Lexer.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/6/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Lexer_hpp
#define Lexer_hpp

#include <stack> 
using namespace std;

#include "Token.hpp"

//==========================================================================================================
//==========================================================================================================
class Lexer {
public:
    void lex_from_file(string filename, vector<Token*>& tokens);
    void lex_from_string(string str, vector<Token*>& tokens);
    static const regex keyword_re, num_re, bool_re, id_re;
    
private:
    typedef Token*(Lexer::*token_matcher)(smatch& match);
    static vector<token_matcher> matchers;
    
    string filename;
    string input;
    string::const_iterator iter;
    int line_num;
    bool in_string;
    
    enum OpenBracketKind { INTERPOLATION, SUBSCRIPT };
    stack<OpenBracketKind> open_brackets;
    
    string cur_string;

    enum StringKind { QUOTES, BRACKETS };
    stack<StringKind> string_kinds;
    
    void lex(vector<Token*>& tokens);
    void reset();
    
    Token* try_match();
    Token* match_keyword(smatch& match);
    Token* match_bool(smatch& match);
    Token* match_id(smatch& match);
    Token* match_num(smatch& match);
    
    bool skip_irrelevant();
    bool skip_spaces();
    bool skip_comment();
    
    bool try_string(vector<Token*>& tokens);
    char get_next_string_char(bool &start_of_interpolation);
    
    // Note: these are esacaped in any kind of string. In quoted strings " need to be escaped,
    // in bracketed strings ]] needs to be escaped (like this: \]])
    bool is_escaped_char(char c) { return c == '[' or c == '\\'; }
    
    string create_syntax_err_msg();
    void get_current_line_position(int& start, int& len);
    
    void try_parameter_token(Token*& token, vector<Token*>& tokens);
    bool is_parameter_preceding_token(Token* token);
};

 
#endif /* Lexer_hpp */
