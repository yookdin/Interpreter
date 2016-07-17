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
SLR_Table::SLR_Table(Grammar& grammar, DFA dfa): table(vector<vector<Action>>(dfa.get_num_states(), vector<Action>(NUM_TABLE_SYMBOLS))) {
    
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
        
        Symbol N = grammar.productions[p][0];
        
        for(auto s: grammar.get_follow_set(N)) {
            // TODO: add conflict resolution using external operator table
//            if(table[i][s].kind != Action::ERROR)
//                throw string("Trying to add REDUCE action where action " + table[i][s].to_string() + " already exists");
            
            if(p > 0) {
                table[i][s].kind = Action::REDUCE;
                table[i][s].val = p;
            } else {
                if(s != EOI)
                    throw string("ACCEPT action should be only for end-of-input symbol");
                table[i][s].kind = Action::ACCEPT;
            }
        } // for each symbol in Follow(N)
    } // for each state
}


//==========================================================================================================
//==========================================================================================================
void SLR_Table::print() {
    cout << "SLR_Table:" << endl;
    
    cout << "   |";
    vector<int> col_widths;
    for(int sym = 0; sym < NUM_TABLE_SYMBOLS; ++sym) {
        string name = symbol_to_string(Symbol(sym));
        col_widths.push_back(max(5, int(name.length()) + 2));
        
        int leading_spaces = (col_widths.back() - name.length()) / 2;
        cout << setfill(' ') << setw(leading_spaces) << "";
        cout << left << setw(col_widths.back() - leading_spaces) << name;
 
        if(sym < NUM_TABLE_SYMBOLS - 1)
            cout << "|";
        else
            cout << endl;
    }
    
    int table_width = 4;
    for(auto l: col_widths) table_width += l+1;
    table_width -= 2;
    cout << "---";
    for(int sym = 0; sym < NUM_TABLE_SYMBOLS; ++sym) {
        cout << "+";
        for(int i = 0; i < col_widths[sym]; ++i) cout << "-";
    }
    cout << endl;

    for(int i = 0; i < table.size(); ++i) {
        cout << std::left << std::setw(3) << i << "|";
        
        for(int sym = 0; sym < NUM_TABLE_SYMBOLS; ++sym) {
            string action = table[i][sym].to_string();
            cout << " " << action;
            if(sym < NUM_TABLE_SYMBOLS - 1)
                cout << std::right << std::setw(col_widths[sym] - action.length()) << "|";
            else
                cout << endl;
        }
    }
    cout << endl;
}


//==========================================================================================================
//==========================================================================================================
SLR_Table::Action& SLR_Table::get_action(int state, Symbol sym) {
    return table[state][sym];
}


//==========================================================================================================
//==========================================================================================================
string SLR_Table::Action::to_string() {
    string val_str = std::to_string(val);
    switch (kind) {
        case SHIFT: return "s" + val_str;
        case GO: return "g" + val_str;
        case REDUCE: return "r" + val_str;
        case ACCEPT: return "a";
        case ERROR: return "";
    }
}




















