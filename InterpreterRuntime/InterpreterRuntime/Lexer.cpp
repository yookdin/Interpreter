//
//  Lexer.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/6/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

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
regex Lexer::keyword_re("^(\\+|-|\\*|/|%|not|or|and|==|!=|<=|>=|<|>|~|!~|\\?|:|\\(|\\)|=|\\{|\\}|;|,|if|else|while|repeat|times)");


//==========================================================================================================
//==========================================================================================================
void Lexer::lex(string filename, vector<Token*>& tokens) {
    ifstream file = ifstream(filename);
    
    if(!file.is_open())
        throw string("File " + filename + " not found");

    input.assign(istreambuf_iterator<char>(file), istreambuf_iterator<char>());
    iter = input.begin();
    bool in_string = false;
    int num_open_brackets = 0;
    string cur_string;
    
    //------------------------------------------------------------------------------------------------------
    // Turn file text into tokens
    //------------------------------------------------------------------------------------------------------
    skip_irrelevant();
    while(iter != input.end()) {
        if(try_string_char(in_string, cur_string, num_open_brackets, tokens))
            continue;
        skip_irrelevant();
        if(iter == input.end()) break;
        
        Token* token = try_match();
        if(token == nullptr)
            throw string("Unrecognized syntax at file " + filename + ": \"" + input.substr(iter - input.begin(), 20) + "\"..."); // TODO: calc and add line number
        tokens.push_back(token);
    }

    if(num_open_brackets > 0)
        throw string("'[' without closing ']'");
        
    tokens.push_back(new KeywordToken(EOI));
    input.clear();
}


//==========================================================================================================
// See if current char can be processed as a string char (including start/end of string/interpolation).
//==========================================================================================================
bool Lexer::try_string_char(bool& in_string, string& cur_string, int& num_open_brackets, vector<Token*>& tokens) {
    if(in_string) {
        bool string_ended;
        char c = get_next_string_char(string_ended);
        
        if(not string_ended) {
            cur_string.push_back(c);
        }
        else {
            in_string = false;
            tokens.push_back(new StringToken(cur_string));
            cur_string.clear();
            
            if(c == '[') { // Start of interpolation
                tokens.push_back(new KeywordToken(ADD)); // String interpolation is implemented by performing contactanation
                ++num_open_brackets;
            }
        }
        
        return true;
    }
    
    if(*iter == '"') {
        in_string = true;
        ++iter;
        return true;
    }
    
    // Note: currently '[' and ']' are only used in string interpolation
    if(*iter == ']') {
        if(num_open_brackets == 0) throw string("']' with no preceding '['");
        --num_open_brackets;
        tokens.push_back(new KeywordToken(ADD));
        in_string = true;
        ++iter;
        return true;
    }

    return false;
}


//==========================================================================================================
//==========================================================================================================
char Lexer::get_next_string_char(bool& string_ended) {
    string_ended = false;
    
    if(*iter == '\\') {
        if(iter+1 == input.end())
            throw string("End of input reached while withing string");
        
        ++iter;
        if(*iter == '"' or *iter == '[' or *iter == '\\')
            ++iter; // Skip also the escaped char        
    }
    else {
        if(*iter == '"' or *iter == '[') {
            string_ended = true;
        }
        ++iter;
    }
    
    return *(iter - 1);
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
    while(iter != input.end() and isspace(*iter)) ++iter;
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
        return true;
    }
    return false;        
}






























