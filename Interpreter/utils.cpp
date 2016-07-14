//
//  utils.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/10/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "common.h"

//==========================================================================================================
//==========================================================================================================
string symbol_to_string(int sym) {
    if(sym == NUM_TABLE_SYMBOLS)
        return "EPSILON";
    
    switch (sym) {
        case START: return "START";
        case EOI: return "$";
        case LEFT_PAREN: return "(";
        case RIGHT_PAREN: return ")";
        case NUM: return "NUM";
        case OP: return "OP";
        case EXP: return "EXP";
        default: throw string("Value of symbol out of bounds");
    }
}


//==========================================================================================================
//==========================================================================================================
Symbol string_to_symbol(string str) {
    if     (str == "START")         return START;
    else if(str == "LEFT_PAREN")    return LEFT_PAREN;
    else if(str == "(")             return LEFT_PAREN;
    else if(str == "RIGHT_PAREN")   return RIGHT_PAREN;
    else if(str == ")")             return RIGHT_PAREN;
    else if(str == "NUM")           return NUM;
    else if(str == "OP")            return OP;
    else if(str == "EOI")           return EOI;
    else if(str == "EXP")           return EXP;
    else throw string("No matching symbol for string \"" + str + "\"");
}


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
