//
//  SLR_Table.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/13/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "SLR_Table.hpp"

//Parser::Parser(string grammar_file): grammar(grammar_file), table(grammar, DFA(NFA(grammar))) {}


//==========================================================================================================
//==========================================================================================================
SLR_Table::SLR_Table(string grammar_file, string parser_tables_file): grammar(grammar_file) {
    NFA nfa(grammar);
    DFA dfa(nfa);
    table.resize(dfa.get_num_states(), vector<Action>(NUM_SYMBOLS));
    build_slr_table(dfa);
    write_parser_tables_file(parser_tables_file);
}


//==========================================================================================================
//==========================================================================================================
void SLR_Table::build_slr_table(DFA& dfa) {

    //------------------------------------------------------------------------------------------------------
    // Add the SHIFT and GO actions. SHIFT are for terminals symbols, GO for nonterminals. The value is the
    // number of state to go to.
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < dfa.get_num_states(); ++i) {
        for(int sym = 0; sym < NUM_SYMBOLS; ++sym) {
            if(dfa.table[i][sym] >= 0) {
                table[i][sym].kind = (is_terminal(Symbol(sym)) ? SHIFT : GO);
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
            
            if(table[i][s].kind == ERROR and table[i][s].val == 0)
                throw string("Unexpected explicit error in [" + to_string(i) + "," + symbol_str_map[s] + "]");
            
            if(table[i][s].kind != ERROR) {
                if(table[i][s].kind != SHIFT)
                    throw string("Can't resolve conflict between reduce and " + table[i][s].to_string());

                ResolutionResult res = resolve_conflict(grammar.productions[p], s, table[i][s].message);
                
                if(res == NOT_ALLOWED) {
                    table[i][s].kind = ERROR; // This sequence is not allowed
                    table[i][s].val = 0;
                    continue;
                } else if(res == SHIFT_WIN) {
                    continue;
                }
            }
            
            // No action yet, or reduce won
            if(p > 0) {
                table[i][s].kind = REDUCE;
                table[i][s].val = p;
            } else {
                if(s != EOI)
                    throw string("ACCEPT action should be only for end-of-input symbol");
                table[i][s].kind = ACCEPT;
            }
        } // for each symbol in Follow(N)
    } // for each state
}


//==========================================================================================================
// Write a source file containing the parser state machine table (action per (state, symbol), and production
// info table
//==========================================================================================================
void SLR_Table::write_parser_tables_file(string filename) {
    ofstream file = ofstream(filename);
    
    if(!file.is_open())
        throw string("File " + filename + " can't be written");
    
    file << "// Generated parser tables file" << endl << endl;
    file << "#include \"Parser.hpp\"" << endl << endl;
    write_productions_table(file);
    write_gen_ast_function(file);
    write_slr_table(file);
    file.close();
}


//==========================================================================================================
//==========================================================================================================
void SLR_Table::write_slr_table(ofstream& file) {
    file << "//==========================================================================================================" << endl;
    file << "// Table of actions per (state, symbol) pair" << endl;
    file << "//==========================================================================================================" << endl;
    file << "vector<vector<Action>> Parser::table = {" << endl;
    
    int state = 0;
    for(auto& actions: table) {
        file << tab << "// State " << state++ << endl;
        file << tab << "{";
        
        int lines = 0;
        for(auto& action: actions) {
            file << "{" << action_kind_to_string(action.kind);
            if(action.kind == SHIFT or action.kind == GO or action.kind == REDUCE)
                file << ", " << action.val;
            file << "}, ";
            
            if(++lines % 10 == 0)
                file << endl << tab;
        }
        
        file << "}," << endl << endl;
    }
    
    file << "}; // Parser::table" << endl << endl << endl;
}


//==========================================================================================================
//==========================================================================================================
void SLR_Table::write_productions_table(ofstream &file) {
    file << "//==========================================================================================================" << endl;
    file << "// Table of productions info: Left-hand-side nonterminal and number of symbols on right-hand-side" << endl;
    file << "//==========================================================================================================" << endl;
    file << "vector<ProductionInfo> Parser::production_infos = {" << endl << tab;
        
    for(int i = 0; i < grammar.productions.size(); ++i) {
        Production& p = grammar.productions[i];
        file << "{" << symbol_str_map[p[0]] << ", " << p.rhs_size() << "}, "; 
        
        if((i + 1) % 10 == 0)
            file << endl << tab;
    }
    
    file << endl << "};" << endl << endl << endl;
}



//==========================================================================================================
//==========================================================================================================
void SLR_Table::write_gen_ast_function(ofstream& file) {
    file << "//==========================================================================================================" << endl;
    file << "// Generate an AST acording to production number" << endl;
    file << "//==========================================================================================================" << endl;
    file << "AST* Parser::gen_ast(int production, vector<TokenOrAST>& elements) {" << endl;
    file << tab << "switch(production) {" << endl;
    
    for(int i = 1; i < grammar.productions.size(); ++i) { // Skipping first production (START -> ...)
        file << tab << tab << "case " << i << ": return ";
        
        if( grammar.productions[i].action_name.empty())
            file << "extract_ast(elements);" << endl;
        else
            file <<  "new " << grammar.productions[i].action_name << "AST(elements);"<< endl;
    }
    
    file << tab << "} // switch" << endl << endl;
    file << tab << "return nullptr;" << endl << endl;
    file << "} // Parser::gen_ast()" << endl << endl << endl;
}





//==========================================================================================================
//==========================================================================================================
SLR_Table::ResolutionResult SLR_Table::resolve_conflict(Production& production, Symbol sym, string& msg) {
    if(sym == ELSE) {
        return SHIFT_WIN;
    }
    
    if(not is_op(sym))
        throw string("Can't resolve conflict, current symbol is " + symbol_str_map[sym] + " which isn't an operator");
    
    if(production.op == nullptr)
        throw string("Can't resolve conflict, production doesn't have an operator associated with it");
    
    Operator *left_op = production.op, *right_op = get_op(sym);
    
    if(left_op->precedence == right_op->precedence and left_op->associativity == Operator::NONE) {                    
        msg = "Sequence: \"EXP " + left_op->get_name() + " EXP " + right_op->get_name() + " EXP\" not allowed";
        return NOT_ALLOWED;
    }
    
    // If the left (first) operator should precede the right one, reduce should be performed. This is because reduce
    // means that operator will be evaluated first (appear higher in the AST).
    if(left_op->should_precede(*right_op))
        return REDUCE_WIN;
    else
        return SHIFT_WIN;
}


//==========================================================================================================
//==========================================================================================================
void SLR_Table::print() {
    cout << "SLR_Table:" << endl;
    
    cout << "   |";
    vector<int> col_widths;
    for(int sym = 0; sym < NUM_SYMBOLS; ++sym) {
        string name = symbol_str_map[Symbol(sym)];
        col_widths.push_back(max(5, int(name.length()) + 2));
        
        int leading_spaces = (col_widths.back() - name.length()) / 2;
        cout << setfill(' ') << setw(leading_spaces) << "";
        cout << left << setw(col_widths.back() - leading_spaces) << name;
 
        if(sym < NUM_SYMBOLS - 1)
            cout << "|";
        else
            cout << endl;
    }
    
    int table_width = 4;
    for(auto l: col_widths) table_width += l+1;
    table_width -= 2;
    cout << "---";
    for(int sym = 0; sym < NUM_SYMBOLS; ++sym) {
        cout << "+";
        for(int i = 0; i < col_widths[sym]; ++i) cout << "-";
    }
    cout << endl;

    for(int i = 0; i < table.size(); ++i) {
        cout << std::left << std::setw(3) << i << "|";
        
        for(int sym = 0; sym < NUM_SYMBOLS; ++sym) {
            string action = table[i][sym].to_string();
            cout << " " << action;
            if(sym < NUM_SYMBOLS - 1)
                cout << std::right << std::setw(col_widths[sym] - action.length()) << "|";
            else
                cout << endl;
        }
    }
    cout << endl;
}

















