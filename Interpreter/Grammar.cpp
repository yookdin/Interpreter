//
//  Grammar.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/13/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "Grammar.hpp"


//==========================================================================================================
//==========================================================================================================
void Grammar::add_production(vector<Symbol> production) {
    if(production.size() < 2)
        throw string("Production must have at least two symbols"); // TODO: what about production of the empty string?
    
    if(not is_nonterminal(production[0]))
        throw string("Production must have a nonterminal on the left-hand-side");
    
    productions.push_back(production);
}


//==========================================================================================================
//==========================================================================================================
Symbol Grammar::get_nonterminal_of_production(int p) {
    return productions[p][0];
}


//==========================================================================================================
//==========================================================================================================
void Grammar::print() {
    for(int i = 0; i < productions.size(); ++i) {
        cout << i << ": " << symbol_to_string(productions[i][0]) << " --> ";
        for(int j = 1; j < productions[i].size(); ++j)
            cout << symbol_to_string(productions[i][j]) << " ";
        cout << endl;
    }
}