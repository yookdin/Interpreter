//
//  SLR_Table.hpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/13/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef SLR_Table_hpp
#define SLR_Table_hpp

#include "common_headers.h"
#include "utils.hpp"
#include "DFA.hpp"

//==========================================================================================================
//==========================================================================================================
class SLR_Table {
public:
    SLR_Table(string grammar_file, string parser_tables_file); 
    void print();

private:    
    vector<vector<Action>> table;
    Grammar grammar;
    string tab = "    ";
    
    void build_slr_table(DFA& dfa);
    void write_parser_tables_file(string filename);
    void write_slr_table(ofstream& file);
    void write_productions_table(ofstream& file);
    void write_gen_ast_function(ofstream& file);
    
    enum ResolutionResult {SHIFT_WIN, REDUCE_WIN, NOT_ALLOWED};
    ResolutionResult resolve_conflict(Production& production, Symbol sym, string& msg);
};



#endif /* SLR_Table_hpp */
