//
//  SLR_Table.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/13/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "SLR_Table.hpp"


//==========================================================================================================
//==========================================================================================================
SLR_Table::SLR_Table(Grammar& grammar, DFA& dfa): table(vector<vector<Action>>(dfa.get_num_states(), vector<Action>(NUM_TABLE_SYMBOLS))) {
    
    //------------------------------------------------------------------------------------------------------
    // Add the SHIFT and GO actions. SHIFT are for terminals symbols, GO for nonterminals. The value is the
    // number of state to go to.
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < dfa.get_num_states(); ++i) {
        for(int sym = 0; sym < NUM_TABLE_SYMBOLS; ++sym) {
            if(dfa.table[i][sym] >= 0) {
                table[i][sym].kind = (is_terminal(Symbol(sym)) ? Action::SHIFT : Action::GO);
                table[i][sym].val = dfa.table[i][sym]; 
            }
        }
    }

    //------------------------------------------------------------------------------------------------------
    // Add the REDUCE and ACCEPT actions
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < dfa.accepting.size(); ++i) {
        int p = dfa.accepting[i]; 
        if(p < 0) continue;
        
        Symbol N = grammar.get_nonterminal_of_production(p);
        
        for(auto s: grammar.get_follow_set(N)) {
            if(table[i][s].kind != Action::ERROR)
                throw string("Trying to add REDUCE action where action " + table[i][s].to_string() + " already exists");
            
            if(p > 0) {
                table[i][s].kind = Action::REDUCE;
                table[i][s].val = p;
            } else {
                table[i][s].kind = Action::ACCEPT;
            }
        } // for each symbol in Follow(N)
    } // for each state
}


//==========================================================================================================
//==========================================================================================================
void SLR_Table::print() {
    cout << "SLR_Table:" << endl;
    
    for(int i = 0; i < table.size(); ++i) {
        cout << "state " << i << ":" << endl;
        
        for(int sym = 0; sym < NUM_TABLE_SYMBOLS; ++sym) {
            if(table[i][sym].kind != Action::ERROR)
                cout << "Action for symbol " << symbol_to_string(Symbol(sym)) << ": " << table[i][sym].to_string() << endl;
        }
        cout << endl;
    }
}


//==========================================================================================================
//==========================================================================================================
string SLR_Table::Action::to_string() {
    string val_str = std::to_string(val);
    switch (kind) {
        case SHIFT: return "SHIFT_" + val_str;
        case GO: return "GO_" + val_str;
        case REDUCE: return "REDUCE_" + val_str;
        case ACCEPT: return "ACCEPT";
        case ERROR: return "ERROR";
    }
}





















