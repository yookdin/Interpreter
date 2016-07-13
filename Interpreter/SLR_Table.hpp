//
//  SLR_Table.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/13/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef SLR_Table_hpp
#define SLR_Table_hpp

#include "common.h"
#include "DFA.hpp"

//==========================================================================================================
//==========================================================================================================
class SLR_Table {
public:
    SLR_Table(){}
    SLR_Table(Grammar& grammar, DFA& dfa);
    void print();
    
    struct Action {
        Action(): kind(ERROR), val(-1) {}
        enum {SHIFT, GO, REDUCE, ACCEPT, ERROR} kind;
        int val;
        
        string to_string();
    };
    
private:
    vector<vector<Action>> table;
};



#endif /* SLR_Table_hpp */
