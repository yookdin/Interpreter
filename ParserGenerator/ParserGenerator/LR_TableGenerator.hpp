//
//  LR_TableGenerator.hpp
//  ParserGenerator
//
//  Created by Yuval Dinari on 9/1/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef LR_TableGenerator_hpp
#define LR_TableGenerator_hpp

#include "common_headers.h"
#include "Grammar.hpp"


//==========================================================================================================
//==========================================================================================================
class Configuration {
public:
    Configuration(Grammar& _grammar, Production& _production, int _pos, set<Symbol> _lookaheads): grammar(_grammar), production(_production), pos(_pos), lookaheads(_lookaheads) {
//        for(auto s: _lookaheads)
//        lookahead.insert(_lookahead);
        
        // 'closed' indicates no other configurations should be added to a configuration set due to this configuration 
        closed = (pos == production.rhs_size()) or is_terminal(production[pos]);
    }
    
    Grammar& grammar;
    Production& production;
    int pos;    // Position of the dot, i.e. where we are in the parse of the production
    set<Symbol> lookaheads; // One or more terminals that can follow this production
    bool closed = false;
    

    //------------------------------------------------------------------------------------------------------
    // Return the symbol in the production after the current position 
    //------------------------------------------------------------------------------------------------------
    Symbol get_next_symbol() { 
        if(pos == production.rhs_size())
            throw string("No next symbol when position is at the end of a production");
        return production[pos];
    }

    //------------------------------------------------------------------------------------------------------
    // Return the first set of the portion of the production AFTER the next symbol, and if that is empty,
    // than return the what is already in the lookahead set.
    // This is used to perform the closure operation on this configuration.
    //------------------------------------------------------------------------------------------------------
    set<Symbol> get_actual_lookahead_set() {
        if(pos == production.rhs_size())
            throw string("Shouldn't call get_actual_lookahead_set() when position is at the end of a production");
            
        if(pos == production.rhs_size() - 1)
            return lookaheads;
        else
            return grammar.get_first_set(production[pos+1]);
    }
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    bool operator==(const Configuration &other) const { 
        return (production.index == other.production.index and pos == other.pos and lookaheads == other.lookaheads);
    }
};


//==========================================================================================================
// Template specialization of hash to enable using Configuration in an STL set
//==========================================================================================================
template <>
struct hash<Configuration>
{
    size_t operator()(const Configuration& c) const {
        
        // Compute individual hash values for first,
        // second and third and combine them using XOR
        // and bit shifting:
        
        // TODO: use the lookaheads values as well
        return ((hash<int>()(c.production.index) ^ (hash<int>()(c.pos) << 1)) >> 1);// ^ (hash<set<Symbol>>()(c.lookaheads) << 1);
    }
};



//==========================================================================================================
//==========================================================================================================
class LR_TableGenerator {
public:
    LR_TableGenerator(string grammar_file);
    
private:
    Grammar grammar;
    vector<vector<Action>> table;
    
    //set<Configuration*> closure(Configuration* c);
    unordered_set<Configuration> closure(Configuration c);
    void build_table();
    void write_table_files();
};


#endif /* LR_TableGenerator_hpp */
