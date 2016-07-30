//
//  Lexer.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/6/16.
//  Copyright © 2016 Vonage. All rights reserved.
//
//  Two kind of strings are supported:
//  1. "..."   // Here you need \" to get literal quote
//  2. [[...]] // Here you need \]] to get a literal ]]
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
regex Lexer::num_re("^-?\\d+\\b");
regex Lexer::bool_re("^(true|false)\\b");
regex Lexer::id_re("^[_[:alpha:]]\\w*");
regex Lexer::keyword_re("^(\\+|-|\\*|/|%|not|or|and|\\?=|==|!=|<=|>=|<|>|~|!~|\\?|:|\\(|\\)|=|\\{|\\}|;|,|if|else|while|repeat|times|break|continue)");


//==========================================================================================================
//==========================================================================================================
void Lexer::lex(string filename, vector<Token*>& tokens) {
    ifstream file = ifstream(filename);
    
    if(!file.is_open())
        throw string("File " + filename + " not found");

    reset();
    input.assign(istreambuf_iterator<char>(file), istreambuf_iterator<char>());
    
    //------------------------------------------------------------------------------------------------------
    // Turn file text into tokens
    //------------------------------------------------------------------------------------------------------
    skip_irrelevant();
    while(iter != input.end()) {
        if(try_string(tokens))
            continue;
        skip_irrelevant();
        if(iter == input.end()) break;
        
        Token* token = try_match();
        
        if(token == nullptr)
            throw create_syntax_err_msg(filename);
        
        tokens.push_back(token);
    }

    if(num_open_brackets > 0)
        throw string("'[' without closing ']'");
        
    if(in_string)
        throw string("String not terminated");
    
    tokens.push_back(new KeywordToken(EOI));
    input.clear();
}


//==========================================================================================================
// See if current char can be processed as a string char (including start/end of string/interpolation).
//==========================================================================================================
bool Lexer::try_string(vector<Token*>& tokens) {
    
    //------------------------------------------------------------------------------------------------------
    // Inside a string, check for end of string or start of interpolation
    //------------------------------------------------------------------------------------------------------
    if(in_string) {
        string seq = get_next_string_chars();
        
        if(in_string) {
            cur_string += seq;
        }
        else {
            tokens.push_back(new StringToken(cur_string));
            cur_string.clear();
            
            if(seq == "[") { // Start of interpolation
                tokens.push_back(new KeywordToken(ADD));        // String interpolation is implemented by performing contactanation
                tokens.push_back(new KeywordToken(LEFT_PAREN)); // We want the interpolated expression to be evaluated seperately from the string containing it 
                ++num_open_brackets;
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
    // Outside a string, check for end of interpolation. Note: currently '[' and ']' are only used in string
    // interpolation
    //------------------------------------------------------------------------------------------------------
    if(*iter == ']') {
        if(num_open_brackets == 0) throw string("']' with no preceding '['");
        --num_open_brackets;
        tokens.push_back(new KeywordToken(RIGHT_PAREN)); // Close the interpolated expression
        tokens.push_back(new KeywordToken(ADD));
        in_string = true;
        ++iter;
        return true;
    }

    return false;
}


//==========================================================================================================
// Get the next string char, while checking for end of string, esacaped sequences, or start of interpolation.
// This needs to return a string and not a char because of "]]"
//==========================================================================================================
string Lexer::get_next_string_chars() {
    
    string res;
    
    //------------------------------------------------------------------------------------------------------
    // Check if string has ended by an end of string (" or ]])
    //------------------------------------------------------------------------------------------------------
    if(check_string_end(res)) {
        in_string = false;
        string_kinds.pop();
        return ""; // End of string sequence is not part of the string
    }
   
    //------------------------------------------------------------------------------------------------------
    // Check if escaped sequence
    //------------------------------------------------------------------------------------------------------
    if(*iter == '\\') {
        ++iter;

        if(check_string_end(res)) // Check if literal string end sequence
            return res;
    
        if(is_escaped_char(*iter)) {
            res = *(iter++);
            return res;
        }
        
        return "\\"; // If the backslash doesn't escape, it is literal
    }
    
    if(*iter == '[') 
        in_string = false; // Start of interpolation, but don't pop the string_kinds stack because string will continue
    else if(*iter == '\n')
        ++line_num;
    
    res = *(iter++);
    return res;
}


//==========================================================================================================
// Check if current sequence of chars can be a string end. Whether it really is depends on whether it is not
// preceded by a backslash.
//==========================================================================================================
bool Lexer::check_string_end(string& end_chars) {
    if(string_kinds.top() == QUOTES and *iter == '"') {
        ++iter;
        end_chars = "\"";
        return true;
    }
    
    if(string_kinds.top() == BRACKETS) {
        if(iter + 1 == input.end())
            throw string("End of input reached while within string");
        if(*iter == ']' and *(iter+1) == ']') {
            iter += 2;
            end_chars = "]]";
            return true;
        }
    }
    
    return false;
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
    if(regex_search(iter, input.cend(), match, keyword_re))
        return new KeywordToken(symbol_str_map[match[0]]);
    
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
// Skip spaces and comments
//==========================================================================================================
void Lexer::skip_irrelevant() {
    while(skip_spaces() or skip_comment());
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
    input.clear();
    iter = input.begin();
    line_num = 1;
    in_string = false;
    num_open_brackets = 0;
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
string Lexer::create_syntax_err_msg(string& filename) {
    string res = "Unrecognized syntax at file " + filename + ", line " + to_string(line_num) + ":\n";
    int start, len, cur_pos = iter - input.begin();
    get_current_line_position(start, len);
    res += input.substr(start, len) + "\n";
    res += string(cur_pos - start, ' ') + "^\n"; // Indicates where in the line the error occurred
    return res;
}






















