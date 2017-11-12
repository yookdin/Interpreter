//
//  Grammar.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/13/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include <fstream>
using namespace std;

#include "Grammar.hpp"


//==========================================================================================================
//==========================================================================================================
Production::Production(vector<Symbol> _symbols, string _action_name, int _index): symbols(_symbols), action_name(_action_name), index(_index) {
    // Find the last symbol that is an operator
    // Note: don't consider the first symbol, it is the left hand side of the production
    for(int i = symbols.size() - 1; i >= 1; --i) {
        if(is_op(symbols[i])) {
            if(i < symbols.size() - 1 and i > 1) // Infix operator, 2 operands
                last_op = get_op(symbols[i], 2);
            else
                last_op = get_op(symbols[i], 1); // Post/prefix, 1 operand
            break;
        }
    }
}


//==========================================================================================================
//==========================================================================================================
string Production::to_string() {
    string res = symbol_str_map[symbols[0]] + " -> ";
    
    for(int j = 1; j < size(); ++j)
        res += symbol_str_map[symbols[j]] + " ";
    
    return res;
}
    

//==========================================================================================================
//==========================================================================================================
Grammar::Grammar(string grammar_file) {
    read_grammar_file(grammar_file);
    calc_first_table();
}


//==========================================================================================================
// Create grammar from definitions in input file.
// Production are of the form:
// N -> A B C ...
//==========================================================================================================
void Grammar::read_grammar_file(string grammar_file) {
    ifstream file = ifstream(grammar_file);
    
    if(not file)
        throw string("File " + grammar_file + " not found");
        
    //------------------------------------------------------------------------------------------------------
    // For each production line extract the symbols and add a production
    //------------------------------------------------------------------------------------------------------
    for(string line; getline(file, line);) {
        if(trim(line, "//").empty())
            continue; // Ignore comments and empty lines
        
        if(regex_match(line, regex("(keyword|operator):.*"))) // Ignore keyword mapping and operator definition lines
            continue;
        
        vector<Symbol> symbols;
        string action_name;
        
        // If an action is specified, a number sign will serve to separate between the production and it
        int split_pos = line.find_first_of('#');        
        extract_symbols(line.substr(0, split_pos), symbols);
                
        if(split_pos != string::npos)
            extract_action(line.substr(split_pos + 1), action_name);
        
        // We know we're going to add the production for START at the beginning, so put as index the current index + 1
        productions.push_back(Production(symbols, action_name, productions.size() + 1));
    }
    
    //------------------------------------------------------------------------------------------------------
    // Add a production:
    // START -> FIRST-NONTERMINAL
    //------------------------------------------------------------------------------------------------------
    productions.push_front(Production({START, productions[0][0]}, "", 0));

} // read_grammar_file()


//==========================================================================================================
//==========================================================================================================
void Grammar::extract_symbols(string production_str, vector<Symbol>& symbols) {
    
    trim(production_str); // Must trim! o/w stringstream gets confused!
    regex production_re("(\\w+)\\s*->\\s*(.*)"); // Note: the RHS needs to parsed word by word
    smatch match_res;
    
    if(not regex_match(production_str, match_res, production_re))
        throw string("Unknown production in line:\n" + production_str);
    
    Symbol N = symbol_str_map[match_res[1]];
    if(not is_nonterminal(N))
        throw string("Expected left hand side of a production to be a nonterminal but received:\n" + production_str);
    
    symbols.push_back(N);
    
    stringstream sts(match_res[2]);
    string symbol_str;
    
    while(!sts.eof()) { // Extract the symbol names
        sts >> symbol_str;
        symbols.push_back(symbol_str_map[symbol_str]);
    } 
    
    if(symbols.size() < 2)
        throw string("Production must have at least two symbols"); // TODO: what about production of the empty string?
}


//==========================================================================================================
//==========================================================================================================
void Grammar::extract_action(string action_str, string& action_name) {
    trim(action_str);
    if(action_str.empty()) return;
    
    regex action_re("\\w+");
    smatch match_res;

    if(not regex_search(action_str, match_res, action_re))
        throw string("Unknown action in line:\n" + action_str);
    
    action_name = match_res[0];
}



//==========================================================================================================
// This is the First(symbol) relation. Since I assume not to have any nullable symbols, the definition is:
//
//              S is a terminal: {S}
//  First(S) =  
//              S is a nonterminal: Union(First(F)) where F is the first symbol of a right-hand-side sequence of a production for S
//
// This is a non-efficient algorithm, since it goes over all the productions again and again until nothing
// new is added. A possible optimization is to build a directed graph, where there's an edge for the first
// symbol of a RHS of a production to the nonterminal of the production.
// Then from all the nodes that are terminals, go BFS-ly and add the terminal to all reachable nodes.
//==========================================================================================================
void Grammar::calc_first_table() {
    bool added = true;
    while(added) {
        added = false;

        for(auto& p: productions) {
            Symbol N = p[0], F = p[1];
            int old_size = first_table[N].size();
            
            if(is_terminal(F))
                first_table[N].insert(F);
            else
                first_table[N].insert(first_table[F]);
        
            added = (added or first_table[N].size() > old_size);
        }
    }
}


//==========================================================================================================
//==========================================================================================================
Set<Symbol> Grammar::get_first_set(Symbol sym) {
    if(is_terminal(sym))
        return {sym};
    else
        return first_table[sym];
}




//==========================================================================================================
//==========================================================================================================
void Grammar::print() {
    cout << "Grammar:" << endl;
    for(int i = 0; i < productions.size(); ++i) {
        cout << i << ": " << productions[i].to_string() << endl;
    }
    
    for(auto& p: first_table) {
        cout << "First(" << symbol_str_map[p.first] << ") = { ";
        for(auto s: p.second)
            cout << symbol_str_map[s] << " ";
        cout << "}" << endl;
    }
}















