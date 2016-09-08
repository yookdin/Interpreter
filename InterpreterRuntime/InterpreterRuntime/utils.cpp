//
//  utils.cpp
//  SymbolGenerator
//
//  Created by Yuval Dinari on 7/21/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "utils.hpp"

string action_kind_to_string(ParserActionKind kind) {
    switch (kind) {
        case SHIFT: return "SHIFT";
        case REDUCE: return "REDUCE";
        case ACCEPT: return "ACCEPT";
        case ERROR: return "ERROR";
    }
}


//==========================================================================================================
// Remove leading and trailing spaces and comment
//==========================================================================================================
string& trim(string& line, string comment_start) {
    if(line.empty())
    {
        return line;
    }
    
    string spaces = " \t\n\r";
    line.erase(0, line.find_first_not_of(spaces));
    
    if(not comment_start.empty()) {
        size_t pos = line.find(comment_start);
        if(pos != string::npos)
            line.erase(pos);
    }
    
    line.erase(line.find_last_not_of(spaces) + 1);
    return line;    
}

//==========================================================================================================
// String to boolean
//==========================================================================================================
bool stob(string s)
{
    if(s == "true")
    {
        return true;
    }
    else if(s == "false")
    {
        return false;
    }
    else
    {
        throw string("Wrong format of string for stob(): " + s);
    }
}


//==========================================================================================================
//==========================================================================================================
string to_string(bool b) { return (b ? "true" : "false"); }


//==========================================================================================================
//==========================================================================================================
string symbol_to_string(int sym) {
    return symbol_str_map[(Symbol)sym];
}
















