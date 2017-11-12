//
//  parser_generator_utils.hpp
//  ParserGenerator
//
//  Created by Yuval Dinari on 7/31/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef parser_generator_utils_hpp
#define parser_generator_utils_hpp

#include <string>
using namespace std;

enum ParserActionKind {SHIFT, REDUCE, ACCEPT, ERROR};
string action_kind_to_string(ParserActionKind kind);
string& trim(string& line, string comment_start= "");

//======================================================================================================
// This struct represent an action the parser takes for a specific transition of its state machine.
//======================================================================================================
struct Action {
    Action(): kind(ERROR), val(-1) {}
    Action(ParserActionKind k, int v = -1): kind(k), val(v) { 
        if((kind == SHIFT or kind == REDUCE) and val <= 0)
            throw string("Shift or reduce actions need a value greater than 0");
    }
    
    ParserActionKind kind;
    int val;
    string message;
    
    string to_string() {
        string val_str = std::to_string(val);
        switch (kind) {
            case SHIFT: return "s" + val_str;
            case REDUCE: return "r" + val_str;
            case ACCEPT: return "a";
            case ERROR: return "";
        }
    }
};


#endif /* parser_generator_utils_hpp */
