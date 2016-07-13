//
//  Grammar.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/13/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Grammar_hpp
#define Grammar_hpp

#include "common.h"

//==========================================================================================================
//==========================================================================================================
class Grammar {
public:
    void add_production(vector<Symbol> production);
    Symbol get_nonterminal_of_production(int p);
    void print();
    
    friend class NFA;
private:
    // For each production the first symbol is the lhs (must be a nonterminal) and the rest are the rhs
    vector<vector<Symbol>> productions;
};

#endif /* Grammar_hpp */
