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
    Configuration(Grammar& _grammar, Production& _production, int _pos, Set<Symbol> _lookaheads): grammar(_grammar), production(_production), pos(_pos), lookaheads(_lookaheads) {
        
        // 'closed' indicates no other configurations should be added to a configuration set due to this configuration
        // A configuration can cause adding of others to its closure set only if the position of dot is followed by
        // a non-terminal
        closed = (pos == production.rhs_size()) or is_terminal(get_next_symbol());
    }
    
    Grammar& grammar;
    Production& production;
    int pos;    // Position of the dot, i.e. where we are in the parse of the production
    Set<Symbol> lookaheads; // One or more terminals that can follow this production
    bool closed;
    

    //------------------------------------------------------------------------------------------------------
    // True when the position (the dot) is after all the symbols in the production
    //------------------------------------------------------------------------------------------------------
    bool reducable() const { return pos == production.rhs_size();  }
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    bool next_symbol_exists() const { return pos < production.rhs_size(); }
    
    //------------------------------------------------------------------------------------------------------
    // Return the symbol in the production after the current position 
    //------------------------------------------------------------------------------------------------------
    Symbol get_next_symbol() const {
        if(not next_symbol_exists())
            throw string("No next symbol when position is at the end of a production");
        return production[pos+1]; // +1 because the production[0] is the lhs nonterminal
    }

    //------------------------------------------------------------------------------------------------------
    // Return the First() set of the portion of the production AFTER the next symbol, and if that is empty,
    // then return what is already in the lookahead set.
    // This is used to perform the closure operation on this configuration.
    //------------------------------------------------------------------------------------------------------
    Set<Symbol> get_actual_lookahead_set() const {
        if(pos == production.rhs_size())
            throw string("Shouldn't call get_actual_lookahead_set() when position is at the end of a production");
            
        if(pos == production.rhs_size() - 1)
            return lookaheads;
        else
            return grammar.get_first_set(production[pos + 2]); 
    }
    

    //------------------------------------------------------------------------------------------------------
    // Return a configuration where the dot moved passed the next symbol
    //------------------------------------------------------------------------------------------------------
    Configuration get_transition_configuration() const {
        if(not next_symbol_exists())
            throw string("Can't get next configuration when position is at the end of a production");
        return Configuration(grammar, production, pos+1, lookaheads);
    }
    

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    bool try_merge(const Configuration& other) {
        if(production.index != other.production.index or pos != other.pos) return false;
        lookaheads.insert(other.lookaheads);
        return true;
    }
    
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    bool operator==(const Configuration &other) const { 
        return (production.index == other.production.index and pos == other.pos and lookaheads == other.lookaheads);
    }
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    void print() const {
        cout << "[" << symbol_str_map[production[0]] << " ->";
        for(int i = 0; i < production.rhs_size(); ++i) {
            if(pos == i) cout << " •";
            cout << " " << symbol_str_map[production[i+1]];
        }
        if(pos == production.rhs_size()) cout << " •"; 
        
        cout << ", ";
        int i = 0;
        for(auto s: lookaheads) {
            cout << symbol_str_map[s];
            if(i++ < lookaheads.size() - 1) cout << "/";
        }
        
        cout << "]" << endl;
    }
};


//==========================================================================================================
// Template specialization of hash to enable using Configuration in an STL set
//==========================================================================================================
template <>
struct hash<Configuration>
{
    //------------------------------------------------------------------------------------------------------
    // Hash value from LSB:
    // 7 bits of production index, 4 bits of position, another 7 bits for each lookahead symbol.
    // This means maximum three lookaheads symbols will be used. Hopefully this will make most configurations
    // have different hash values.
    //------------------------------------------------------------------------------------------------------
    size_t operator()(const Configuration& c) const {
        
        size_t res = c.production.index + c.pos * 128;
        int i = 0;
        for(auto s: c.lookaheads) {
            res += s * pow(2, 11 + i++ * 7);
            if(i == 3) break;
        }
        
        return res;
    }
};



//==========================================================================================================
//==========================================================================================================
class LR_TableGenerator {
public:
    LR_TableGenerator(string grammar_file, string parser_tables_file);
    void print();
    
    void print(UnorderedSet<Configuration>& cs, int i) {
        cout << "Configurating set " << i << ":" << endl;
        for(auto c: cs)
            c.print();
        cout << endl;
    }
    
private:
    Grammar grammar;
    vector<vector<Action>> table; // Action per state and symbol
    string tab = "    ";
    
    UnorderedSet<Configuration> closure(Configuration c);
    
    enum ResolutionResult {SHIFT_WIN, REDUCE_WIN, NOT_ALLOWED};
    ResolutionResult resolve_conflict(const Configuration& c, Symbol sym, ParserActionKind action_kind);
    
    void build_table();
    void write_tables_file(string filename);
    void write_parser_table(ofstream& file);
    void write_productions_table(ofstream& file);
    void write_gen_ast_function(ofstream& file);

    void print_separation_line(vector<int> col_widths);
};


#endif /* LR_TableGenerator_hpp */
