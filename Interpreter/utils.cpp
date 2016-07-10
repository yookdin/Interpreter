//
//  utils.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/10/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "common.h"

string symbol_to_string(Symbol sym) {
    switch (sym) {
        case LEFT_PAREN: return "(";
        case RIGHT_PAREN: return ")";
        case NUM: return "NUM";
        case OP: return "OP";
        case EXP: return "EXP";
        case EPSILON: return "EPSILON";
    }
}
