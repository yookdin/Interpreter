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
    SLR_Table(Grammar& grammar, DFA dfa);
    void print();
    
    //======================================================================================================
    //======================================================================================================
    struct Action {
        Action(): kind(ERROR), val(-1) {}
        enum {SHIFT, GO, REDUCE, ACCEPT, ERROR} kind;
        int val;
        string message;
        
        string to_string();
    };

    Action& get_action(int state, Symbol sym);

    
    friend class Parser;
private:
    vector<vector<Action>> table;
    
    enum ResolutionResult {SHIFT_WIN, REDUCE_WIN, NOT_ALLOWED};
    ResolutionResult resolve_conflict(Production& production, Symbol sym, string& msg);
};



#endif /* SLR_Table_hpp */