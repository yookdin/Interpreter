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
Grammar::Grammar(string grammar_file) {
    read_grammar_file(grammar_file);
    calc_follow_table();
}


//==========================================================================================================
// Create grammar from definitions in input file.
//==========================================================================================================
void Grammar::read_grammar_file(string grammar_file) {
    ifstream file = ifstream(grammar_file);
    
    if(!file.is_open())
        throw string("File " + grammar_file + " not found");
    
    regex production_line_re("(\\w+)\\s*->\\s*(.*)"); // Note: the RHS needs to parsed word by word
    vector<Symbol> production;
    smatch match_res;
    
    //------------------------------------------------------------------------------------------------------
    // For each production line extract the symbols and add a production
    //------------------------------------------------------------------------------------------------------
    for(string line; getline(file, line);) {
        if(trim(line).empty()) continue; // Ignore comments and empty lines
        
        if(regex_match(line, match_res, production_line_re)) {
            production.clear();
            
            Symbol N = string_to_symbol(match_res[1]);
            if(not is_nonterminal(N))
                throw string("Expected left hand side of a production to be a nonterminal");
            
            production.push_back(N);
            
            stringstream sts(match_res[2]);
            string symbol_str;
            
            while(!sts.eof()) { // Extract the symbol names
                 sts >> symbol_str;
                production.push_back(string_to_symbol(symbol_str));
            } 
            
            add_production(production);
        } else {
            throw string("Unkown line in grammar file:\n" + line);
        }
    }

    //------------------------------------------------------------------------------------------------------
    // First production nonterminal considered the start symbol. If it is not START, add a production:
    // START -> FIRST-NONTERMINAL
    //------------------------------------------------------------------------------------------------------
    if(productions[0][0] == START) {
        if(productions[0].size() != 2)
            throw string("Expected production for START to have just one symbol on right hand side");
        if(not is_nonterminal(productions[0][1]))
            throw string("Expected production for START to have a nonterminal on the right hand side");
    }
    else {
        productions.insert(productions.begin(), vector<Symbol>({START, productions[0][0]}));
    }

} // read_grammar_file()


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
Symbol Grammar::get_nonterminal_of_production(int p) { return productions[p][0]; }


//==========================================================================================================
//==========================================================================================================
int Grammar::get_production_rhs_size(int p) { return productions[p].size() - 1; }


//==========================================================================================================
// This is the First(symbol) relation. Since I assume not to have any nullable symbols, the definition is:
//
//              S is a terminal: {S}
//  First(S) =  
//              S is a nonterminal: Union(First(F)) where F is the first symbol of a right-hand-side sequence of a production for S
//
// This is a non-efficient algorithm, since it goes over all the production again and again until nothing
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
void Grammar::calc_follow_table() {
    calc_first_table();
    
    //------------------------------------------------------------------------------------------------------
    // To handle end-of-input correctly, add the EOI (= $) symbol to the follow of the start symbol.
    // This is instead of add another symbol to be the new start and a production: START' -> START $
    // That will have the same effect but causes some overhead of needing to deal with the new symbol and
    // production.
    //------------------------------------------------------------------------------------------------------
    follow_table[START].insert(EOI);
    
    //------------------------------------------------------------------------------------------------------
    // Go over the productions:
    // For a sequence ...NA, add First(A) to Follow(N).
    // For a sequence ...N, add a constraint: Follow(M) ⊆ Follow(N), where M is the LHS of the production.
    //------------------------------------------------------------------------------------------------------
    vector<pair<Symbol, Symbol>> follow_constraints; // Pair (M,N) means Follow(M) ⊆ Follow(N)
    
    for(auto& p: productions) {
        Symbol M = p[0];
        
        for(int j = 1; j < p.size(); ++j) {
            if(is_terminal(p[j])) continue;
            Symbol N = p[j];
            
            if(j < p.size() - 1) {
                follow_table[N].insert(get_first_set(p[j+1]));
            }
            else if(M != N) {
                follow_constraints.push_back({M,N});
            }
        }
    }

    //------------------------------------------------------------------------------------------------------
    // Go over the constraints and apply them, until no more changes are made
    //------------------------------------------------------------------------------------------------------
    bool added = true;
    while(added) {
        added = false;
        
        for(auto& c: follow_constraints) {
            Symbol M = c.first, N = c.second;
            int old_size = follow_table[N].size();
            follow_table[N].insert(follow_table[M]);
            added = (added or follow_table[N].size() > old_size);
        }
    }

} // calc_follow_table()


//==========================================================================================================
//==========================================================================================================
Set<Symbol> Grammar::get_follow_set(Symbol sym) {
    if(follow_table.count(sym) > 0)
        return follow_table[sym];
    else
        return {};
}


//==========================================================================================================
//==========================================================================================================
void Grammar::print() {
    cout << "Grammar:" << endl;
    for(int i = 0; i < productions.size(); ++i) {
        cout << i << ": " << symbol_to_string(productions[i][0]) << " --> ";
        for(int j = 1; j < productions[i].size(); ++j)
            cout << symbol_to_string(productions[i][j]) << " ";
        cout << endl;
    }
    
    for(auto& p: first_table) {
        cout << "First(" << symbol_to_string(p.first) << ") = { ";
        for(auto s: p.second)
            cout << symbol_to_string(s) << " ";
        cout << "}" << endl;
    }

    for(auto& p: follow_table) {
        cout << "Follow(" << symbol_to_string(p.first) << ") = { ";
        for(auto s: p.second)
            cout << symbol_to_string(s) << " ";
        cout << "}" << endl;
    }
    cout << endl;
}















