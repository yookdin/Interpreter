//
//  utils.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/10/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "common.h"
#include "utils.h"
#include "Operator.hpp"

bimap<Symbol, string> symbol_str_map = {
    {START, "START"},
    {LEFT_PAREN, "("}, {RIGHT_PAREN, ")"}, {EOI, "$"}, {ASSIGN, "="}, {SEMI_COLON, ";"}, {LEFT_CURLY, "{"}, {RIGHT_CURLY, "}"},
    {IF, "if"}, {ELSE, "else"},
    {NUM, "NUM"}, {ID, "ID"},
    {ADD, "+"}, {SUB, "-"}, {MUL, "*"}, {DIV, "/"}, {MOD, "%"}, {NOT, "not"}, {OR, "or"}, {AND, "and"},
    {EQ, "=="}, {NE, "!="}, {GT, ">"}, {LT, "<"}, {GE, ">="}, {LE, "<="}, {STR_MATCH, "~"}, {NO_STR_MATCH, "!~"},
    {QUESTION_MARK, "?"}, {COLON, ":"},
    {EXP, "EXP"}, {BLOCK, "BLOCK"}, {STATEMENT, "STATEMENT"}, {STATEMENTS, "STATEMENTS"}
};


//==========================================================================================================
//==========================================================================================================
bool is_nonterminal(Symbol sym) { return (sym == START or sym >= NONTERMINALS_START); }

//==========================================================================================================
//==========================================================================================================
bool is_terminal(Symbol sym) { return not is_nonterminal(sym); }

//==========================================================================================================
//==========================================================================================================
bool is_op(Symbol sym) { return sym >= ADD and sym < EXP; }

//==========================================================================================================
//==========================================================================================================
Operator* get_op(Symbol sym) { return get_op(symbol_str_map[sym]); }

//==========================================================================================================
//==========================================================================================================
Operator* get_op(string name) { return name_op_map[name]; }

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
