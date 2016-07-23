//
//  utils.hpp
//  SymbolGenerator
//
//  Created by Yuval Dinari on 7/21/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp


#include <string>
using namespace std;

#include "Symbol.hpp"

enum ParserActionKind {SHIFT, GO, REDUCE, ACCEPT, ERROR};

string action_kind_to_string(ParserActionKind kind);

//======================================================================================================
//======================================================================================================
struct Action {
    Action(): kind(ERROR), val(-1) {}
    Action(ParserActionKind k, int v = -1): kind(k), val(v) { 
        if((kind == SHIFT or kind == REDUCE or kind == GO) and val <= 0)
            throw string("Shift or reduce actions need a value greater than 0");
    }
    
    ParserActionKind kind;
    int val;
    string message;
    
    string to_string() {
        string val_str = std::to_string(val);
        switch (kind) {
            case SHIFT: return "s" + val_str;
            case GO: return "g" + val_str;
            case REDUCE: return "r" + val_str;
            case ACCEPT: return "a";
            case ERROR: return "";
        }
    }
};


//======================================================================================================
//======================================================================================================
struct ProductionInfo {
    Symbol lhs;
    int rhs_size;
};


string& trim(string& line, string comment_start= "");
bool stob(string);
string to_string(bool);

#endif /* utils_hpp */
