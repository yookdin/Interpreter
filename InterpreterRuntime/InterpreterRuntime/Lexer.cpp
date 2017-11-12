//
//  Lexer.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/6/16.
//  Copyright © 2016 Vonage. All rights reserved.
//
//  Two kind of strings are supported:
//  1. "..."   // Here you need \" to get literal quote
//  2. [[...]] // Here you need to escape at least one of two consecutives ] to get a literal ]]
//  In both kinds you can have string interpolation with []:
//  "My name is [get_name()], and x = [3+5]!"
//  [[My name is [get_name()], and x = [3+5]!]]
//  In both kinds you need \[ to get a literal [



#include "Lexer.hpp"


//==========================================================================================================
// Must try to match keywords before identifiers
//==========================================================================================================
vector<Lexer::token_matcher> Lexer::matchers = { 
    &Lexer::match_keyword, &Lexer::match_bool, &Lexer::match_id, &Lexer::match_num
};


//==========================================================================================================
//==========================================================================================================
const regex Lexer::bool_re("^(true|false)\\b");
const regex Lexer::id_re("^[_[:alpha:]]\\w*");
const regex Lexer::num_re("^\\d+\\b");


//==========================================================================================================
//==========================================================================================================
void Lexer::lex_from_file(string _filename, vector<Token*>& tokens) {
    reset();
    filename = _filename;
    ifstream file(filename);
    
    if(not file.is_open())
        THROW << "File " << filename << " not found";
    
    input.assign(istreambuf_iterator<char>(file), istreambuf_iterator<char>());
    lex(tokens);
    reset();
}


//==========================================================================================================
//==========================================================================================================
void Lexer::lex_from_string(string str, vector<Token*>& tokens) {
    reset();
    input = str;
    lex(tokens);
    reset();
}


//==========================================================================================================
//==========================================================================================================
void Lexer::lex(vector<Token*>& tokens) {

    // Remove occurences of backslash followed by newline. Note: to match a single backslash you need 4 backslashes
    // in the regular expression: a backslash needs a preceding backslash in the cpp source file to be literal, so the 4
    // becomes 2. And 2 are needed to tell the regular expression to treat it as literal and not as an operator.
    input = regex_replace(input, regex("\\\\\n"), "");

    iter = input.begin();
    
    //------------------------------------------------------------------------------------------------------
    // Turn file text into tokens
    //------------------------------------------------------------------------------------------------------
    skip_irrelevant();
    while(iter != input.end()) {
        if(try_string(tokens))
            continue;

        if(skip_irrelevant())
            continue;

        if(iter == input.end())
            break;
        
        Token* token = try_match(); // Try matching current text as one of the tokens types
        
        if(token == nullptr)
            THROW << create_syntax_err_msg();
        
        // Check if current and last tokens should be interpreted as a parameter ("ID:"). If so last token will
        // be popped and current (the colon) replaced with a parameter token.
        try_parameter_token(token, tokens);

        tokens.push_back(token);
    }

    if(not open_brackets.empty())
        THROW << "'[' without closing ']'";
        
    if(in_string)
        THROW << "String not terminated";
    
    tokens.push_back(new KeywordToken(EOI));
    input.clear();
}


//==========================================================================================================
// See if current char can be processed as a string char (including start/end of string/interpolation).
// Return whether a char was consumed or not.
// Note: return value may differ from in_string value.
//==========================================================================================================
bool Lexer::try_string(vector<Token*>& tokens) {
    
    //------------------------------------------------------------------------------------------------------
    // Inside a string, check for end of string or start of interpolation
    //------------------------------------------------------------------------------------------------------
    if(in_string) {
        bool start_of_interpolation;
        char c = get_next_string_char(start_of_interpolation);
        
        if(in_string) { // Still inside a string, add the returned char to the current string
            cur_string += c;
        }
        else { // String was terminated (either by end of string or start of interpolation), create a token
            tokens.push_back(new StringToken(cur_string));
            cur_string.clear();
            
            if(start_of_interpolation) { // Do not pop string kinds stack in this case, the current string will continue after the closing bracket
                tokens.push_back(new KeywordToken(ADD));        // String interpolation is implemented by performing contactanation
                tokens.push_back(new KeywordToken(LEFT_PAREN)); // We want the interpolated expression to be evaluated seperately from the string containing it 
                open_brackets.push(INTERPOLATION);
            }
            else { // String terminated, pop the string kinds stack
                string_kinds.pop();
            }
        }
        
        return true;
    }
    
    //------------------------------------------------------------------------------------------------------
    // Outside a string, check for string start
    //------------------------------------------------------------------------------------------------------
    if(*iter == '"') {
        in_string = true;
        string_kinds.push(QUOTES);
        ++iter;
        return true;
    }
    
    if(*iter == '[' and iter+1 != input.end() and *(iter+1) == '[') {
        in_string = true;
        string_kinds.push(BRACKETS);
        iter += 2;
        return true;
    }
    
    //------------------------------------------------------------------------------------------------------
    // Outside a string, check for end of interpolation.
    // Note: open_brackets stack holds the type of opening brackets found, but SUBSCRIPT open brackets are
    // only pushed if already inside an interpolation (i.e. a previous INTERPOLATION bracket is in the stack)
    //------------------------------------------------------------------------------------------------------
    if(not open_brackets.empty() and *iter == ']') {
        if(open_brackets.top() == INTERPOLATION) {
            tokens.push_back(new KeywordToken(RIGHT_PAREN)); // Close the interpolated expression
            tokens.push_back(new KeywordToken(ADD));
            in_string = true;
            ++iter;
        }
        
        open_brackets.pop();
        return in_string;
    }
    
    return false;
}


//==========================================================================================================
// Inside a string, get the next character, while checking if string terminates of interpolation starts.
//==========================================================================================================
char Lexer::get_next_string_char(bool &start_of_interpolation) {
    start_of_interpolation = false;
    
    //------------------------------------------------------------------------------------------------------
    // Check if escaped sequence. Escaped char sequences are:
    // \\ - a literal \
    // \n - a newline
    // \[ - a literal [ (not start of interpolated expression)
    // \" - a literal double quote; doesn't have to be esacaped if inside a bracketed string
    // \] - a literl ]; inside a bracketed string, to get two consecutive literal right brackets, at least
    //      one of them need to be escaped
    //------------------------------------------------------------------------------------------------------
    if(*iter == '\\') {
        if(iter + 1 == input.end())
            THROW << "End of input reached while within a string";
    
        ++iter;
        
        switch(*iter) {
            case '\\':
            case '"':
            case ']':
            case '[':
                return *(iter++);
            case 'n':
                ++iter;
                return '\n';                
            default:
                return '\\'; // if following char is not one of the known escaped chars, treat the backslash as literal 
        }        
    }

    //------------------------------------------------------------------------------------------------------
    // Check if start of interpolation
    //------------------------------------------------------------------------------------------------------
    if(*iter == '[') {
        ++iter;
        in_string = false;
        start_of_interpolation = true;
        return '\0';
    }
    
    //------------------------------------------------------------------------------------------------------
    // Check if end of string
    //------------------------------------------------------------------------------------------------------
    if(string_kinds.top() == QUOTES and *iter == '"') {
        ++iter;
        in_string = false;
        return '\0';
    }
    
    if(string_kinds.top() == BRACKETS and *iter == ']') {
        if(iter + 1 == input.end())
            THROW << "End of input reached while within a string";
        
        if(*(iter + 1) == ']') {
            iter += 2;
            in_string = false;
            return '\0';
        }
    }
    
    //------------------------------------------------------------------------------------------------------
    // Normal char - advance the iterator and return it
    //------------------------------------------------------------------------------------------------------
    return *(iter++);
}


//==========================================================================================================
//==========================================================================================================
Token* Lexer::try_match() {
    smatch match;
    
    for(auto matcher: matchers) {
        Token* token = (this->*matcher)(match);
        
        if(token != nullptr) {
            iter += match.length();
            skip_irrelevant();
            return token;
        }
    }
    
    return nullptr;
}


//==========================================================================================================
//==========================================================================================================
Token* Lexer::match_keyword(smatch& match) {
    if(regex_search(iter, input.cend(), match, keyword_re)) {
        // Only when inside a string interpolation (indicated by stack not empty) is there a need to keep 
        // track of subscript brackets
        if(match[0] == "[" and not open_brackets.empty())
            open_brackets.push(SUBSCRIPT);
            
        return new KeywordToken(symbol_str_map[match[0]]);
    }
    return nullptr;
}


//==========================================================================================================
//==========================================================================================================
Token* Lexer::match_num(smatch& match) {
    if(regex_search(iter, input.cend(), match, num_re))
        return new NumToken(match[0]);
    
    return nullptr;
}


//==========================================================================================================
//==========================================================================================================
Token* Lexer::match_bool(smatch& match) {
    if(regex_search(iter, input.cend(), match, bool_re))
        return new BoolToken(match[0]);
    
    return nullptr;
}


//==========================================================================================================
//==========================================================================================================
Token* Lexer::match_id(smatch& match) {
    if(regex_search(iter, input.cend(), match, id_re))
        return new IdentifierToken(match[0]);
    
    return nullptr;
}


//==========================================================================================================
// Check if current and last tokens should be interpreted as a parameter ("ID:")
//==========================================================================================================
void Lexer::try_parameter_token(Token*& token, vector<Token*>& tokens) {
    if(token->sym == COLON and tokens.size() > 0) {
        Token* last_token = tokens.back(); 
        
        if(typeid(*last_token) == typeid(IdentifierToken)) {
            // If parameter, replace ID token with param token and don't add the colon token
            if(tokens.size() == 1 or is_parameter_preceding_token(tokens[tokens.size() - 2])) {
                delete token; // Colon token no longer needed
                token = new ParamToken(((IdentifierToken*)last_token)->name);
                tokens.pop_back();
            }
        }
    }
}


//==========================================================================================================
// The sequence "ID :" can be either part of a param-val pair (ID:EXP), or part of a conditional expression
// (EXP ? EXP : EXP). It can be determined which is the case by looking at the token preceding the ID token.
//==========================================================================================================
bool Lexer::is_parameter_preceding_token(Token* token) {
    if(dynamic_cast<TokenWithValue*>(token) != nullptr)
        return true;

    switch(token->sym) {
        case LEFT_PAREN: case LEFT_CURLY: case COMMA: case ASSIGN: case CONDITIONAL_ASSIGN: case ID:
            return true;
        default:
            return false;
    }
}


//==========================================================================================================
// Skip spaces and comments
//==========================================================================================================
bool Lexer::skip_irrelevant() {
    bool skipped = false;
    while(skip_spaces() or skip_comment())
        skipped = true;
    return skipped;
}
          

//==========================================================================================================
//==========================================================================================================
bool Lexer::skip_spaces() {
    if(iter == input.end()) return false;
    auto cur_pos = iter;
    while(iter != input.end() and isspace(*iter)) {
        if(*iter == '\n') ++line_num;
        ++iter;
    }
    return iter > cur_pos;
}


//==========================================================================================================
//==========================================================================================================
bool Lexer::skip_comment() {
    if(iter == input.end()) return false;

    if(*iter == '#') {
        do { ++iter; } while(iter != input.end() and *iter != '\n');
        if(iter == input.end()) return false;
        
        ++iter;
        ++line_num;
        return true;
    }
    return false;        
}


//==========================================================================================================
//==========================================================================================================
void Lexer::reset() {
    filename.clear();
    input.clear();
    line_num = 1;
    in_string = false;
    cur_string.clear();
}


//==========================================================================================================
//==========================================================================================================
void Lexer::get_current_line_position(int& start, int& len) {
    int pos = iter - input.begin();
    
    start = input.rfind('\n', pos);
    if(start == string::npos)
        start = 0;
    else
        ++start;
    
    int end = input.find('\n', pos);

    if(end == string::npos)
        len = input.length() - start;
    else
        len = end - start;  
}


//==========================================================================================================
//==========================================================================================================
string Lexer::create_syntax_err_msg() {
    string res = "Lexer error: unrecognized syntax at ";
    
    if(not filename.empty()) {
        res += "file " + filename; 
    }
    else {
        res += "input string: \"" + input + "\"";
    }
    
    res +=  ", line " + to_string(line_num) + ":\n";
    
    int start, len, cur_pos = iter - input.begin();
    get_current_line_position(start, len);
    res += input.substr(start, len) + "\n";
    res += string(cur_pos - start, ' ') + "^\n"; // Indicates where in the line the error occurred
    return res;
}






















