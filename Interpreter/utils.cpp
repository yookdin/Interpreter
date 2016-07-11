//
//  utils.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/10/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "common.h"

string symbol_to_string(int sym) {
    if(sym == NUM_SYMBOLS)
        return "EPSILON";
    
    switch (sym) {
        case LEFT_PAREN: return "(";
        case RIGHT_PAREN: return ")";
        case NUM: return "NUM";
        case OP: return "OP";
        case EXP: return "EXP";
        default: throw string("Value of symbol out of bounds");
    }
}
