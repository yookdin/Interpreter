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
    void calc_follow_table();
    
    friend class NFA;
private:
    // For each production the first symbol is the lhs (must be a nonterminal) and the rest are the rhs
    vector<vector<Symbol>> productions;

    map<Symbol, Set<Symbol>> first_table;
    
    // Follow(N) = {t | (t is terminal) and (START => A N t B  (A and B can be empty))}
    map<Symbol, Set<Symbol>> follow_table;
    
    void calc_first_table();
    Set<Symbol> get_first_set(Symbol sym);

    
};

#endif /* Grammar_hpp */
