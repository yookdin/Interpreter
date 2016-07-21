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
#include "Symbol.hpp"

//==========================================================================================================
//==========================================================================================================
class Production {
public:
    Production(vector<Symbol> _symbols, string _action_name);
    
    Symbol operator[](int i) { return symbols[i]; }
    int size()               { return symbols.size(); }
    int rhs_size()           { return symbols.size() - 1; }
    
    const vector<Symbol> symbols;
    Operator* op; // The last op (if any) in the production
};


//==========================================================================================================
//==========================================================================================================
class Grammar {
public:
    Grammar(string grammar_file);
    void print();
    Set<Symbol> get_follow_set(Symbol sym);
    
    friend class NFA;
    friend class SLR_Table;
    friend class Parser;

private:
    // This can't be vector (true to C++11) because in order to be able to add in the front, you need the push_front()
    // member function of deque.
    // vector::insert() and emplace() call the assignment operator that doesn't work due to the const fields
    // (a bug in my opinion, should have been implemented the same way as deque::push_front()).
    deque<Production> productions;

    map<Symbol, Set<Symbol>> first_table;
    
    // Follow(N) = {t | (t is terminal) and (START => A N t B  (A and B can be empty))}
    map<Symbol, Set<Symbol>> follow_table;
    
    void read_grammar_file(string grammar_file);    
    void extract_symbols(string production_str, vector<Symbol>& symbols);
    void extract_action(string action_str, string& action_name);
    void calc_follow_table();
    void calc_first_table();
    Set<Symbol> get_first_set(Symbol sym);
};


#endif /* Grammar_hpp */
