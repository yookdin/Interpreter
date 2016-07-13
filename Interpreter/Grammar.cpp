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
    // Add a "real" start symbol, with a single production that is the old start symbol followed by end of
    // input symbol. This will enable handling end of input in the same way as any follow symbol.
    //------------------------------------------------------------------------------------------------------
    productions.insert(productions.begin(), {REAL_START, START, EOI});
    
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
void Grammar::print() {
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
}















