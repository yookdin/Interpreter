//
//  Parser.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/13/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp


#include "common.h"
#include "SLR_Table.hpp"

//==========================================================================================================
//==========================================================================================================
class Parser {
public:
    Parser(string grammar_file);
    
private:
    SLR_Table table;
};


#endif /* Parser_hpp */
