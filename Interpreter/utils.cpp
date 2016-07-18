//
//  utils.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/10/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "common.h"
#include "utils.h"

bimap<Symbol, string> symbol_str_map = {
    {LEFT_PAREN, "("}, {RIGHT_PAREN, ")"}, {NUM, "NUM"}, {ADD, "+"}, {SUB, "-"}, {MUL, "*"}, {DIV, "/"}, {MOD, "%"},
    {NOT, "not"}, {OR, "or"}, {AND, "and"}, {EQ, "=="}, {NE, "!="}, {GT, ">"}, {LT, "<"}, {GE, ">="}, {LE, "<="}, 
    {STR_MATCH, "~"}, {NO_STR_MATCH, "!="}, {QUESTION_MARK, "?"}, {COLON, ":"}, {EOI, "$"}, {EXP, "EXP"}
};


//==========================================================================================================
//==========================================================================================================
bool is_nonterminal(Symbol sym) { return (sym < 0 or sym >= NONTERMINALS_START); }

//==========================================================================================================
//==========================================================================================================
bool is_terminal(Symbol sym) { return not is_nonterminal(sym); }

//==========================================================================================================
// Remove leading and trailing spaces and comment (//...)
//==========================================================================================================
string& trim(string& line)
{
    if(line.empty())
    {
        return line;
    }
    
    string spaces = " \t\n\r";
    line.erase(0, line.find_first_not_of(spaces));
    
    size_t pos = line.find("//");
    if(pos != string::npos)
    {
        line.erase(pos);
    }
    
    line.erase(line.find_last_not_of(spaces) + 1);
    return line;
}
