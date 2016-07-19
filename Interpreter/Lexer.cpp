//
//  Lexer.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/6/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "Lexer.hpp"


//==========================================================================================================
//==========================================================================================================
//Lexer::Lexer() {
//    //enum TokenKind { KEYWORD, IDENTIFIER, NUMBER, STRING, OPERATOR, PUNCTUATOR };
//    matchers.push_back({regex("if|else|elseif|while|repeat|for|end|continue|break"), KEYWORD});
//    matchers.push_back({regex("[_[:alpha:]]\\w*"), IDENTIFIER});
//    matchers.push_back({regex("\\d+"), NUMBER});
//    matchers.push_back({regex("\"((\\\\\"|[^\"])*)\""), STRING});
//    matchers.push_back({regex("==|!=|!~|<=|>=|=|<|>|+|-|*|/|%|~|?|:"), OPERATOR});
//    matchers.push_back({regex("(|)|,"), PUNCTUATOR});
//}


//==========================================================================================================
// Must try to match keywords before identifiers
//==========================================================================================================
vector<Lexer::token_matcher> Lexer::matchers = { 
    &Lexer::match_keyword, &Lexer::match_id, &Lexer::match_num, &Lexer::match_op
};


//==========================================================================================================
//==========================================================================================================
regex Lexer::num_re("^-?\\d+\\b");
regex Lexer::op_re("^(\\+|-|\\*|/|%|not|or|and|==|!=|<=|>=|<|>|~|!~|\\?|:)");
regex Lexer::id_re("^[_[:alpha:]]\\w*");
regex Lexer::keyword_re("^(\\(|\\)|=|\\{|\\}|;|if)");

//==========================================================================================================
//==========================================================================================================
void Lexer::lex(string filename, vector<Token*>& tokens) {
    ifstream file = ifstream(filename);
    
    if(!file.is_open())
        throw string("File " + filename + " not found");

    input.assign(istreambuf_iterator<char>(file), istreambuf_iterator<char>());
    pos = input.begin();
    skip_irrelevant();
    
    //------------------------------------------------------------------------------------------------------
    // Turn file text into tokens
    //------------------------------------------------------------------------------------------------------
    while(pos != input.end()) {
        Token* token = try_match();
        if(token == nullptr)
            throw string("Unrecognized syntax at file " + filename + ": " + input.substr(pos - input.begin(), 20) + " ..."); // TODO: calc and add line number
        tokens.push_back(token);
    }

    tokens.push_back(new KeywordToken(EOI));
    input.clear();
}


//==========================================================================================================
//==========================================================================================================
Token* Lexer::try_match() {
    smatch match;
    
    for(auto matcher: matchers) {
        Token* token = (this->*matcher)(match);
        
        if(token != nullptr) {
            pos += match.length();
            skip_irrelevant();
            return token;
        }
    }
    
    return nullptr;
}


//==========================================================================================================
//==========================================================================================================
Token* Lexer::match_num(smatch& match) {
    if(regex_search(pos, input.cend(), match, num_re))
        return new NumToken(match[0]);
    
    return nullptr;
}


//==========================================================================================================
//==========================================================================================================
Token* Lexer::match_op(smatch& match) {
    if(regex_search(pos, input.cend(), match, op_re))
        return new OpToken(match[0]);
    
    return nullptr;
}


//==========================================================================================================
//==========================================================================================================
Token* Lexer::match_id(smatch& match) {
    if(regex_search(pos, input.cend(), match, id_re))
        return new IdentifierToken(match[0]);
    
    return nullptr;
}


//==========================================================================================================
//==========================================================================================================
Token* Lexer::match_keyword(smatch& match) {
    if(regex_search(pos, input.cend(), match, keyword_re))
        return new KeywordToken(symbol_str_map[match[0]]);
    
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
    if(pos == input.end()) return false;
    auto cur_pos = pos;
    while(pos != input.end() and isspace(*pos)) ++pos;
    return pos > cur_pos;
}


//==========================================================================================================
//==========================================================================================================
bool Lexer::skip_comment() {
    if(pos == input.end()) return false;

    if(*pos == '#') {
        do { ++pos; } while(pos != input.end() and *pos != '\n');
        if(pos == input.end()) return false;
        ++pos;
        return true;
    }
    return false;        
}






























