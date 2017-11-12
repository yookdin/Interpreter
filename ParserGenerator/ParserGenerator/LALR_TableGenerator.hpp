//
//  LALR_TableGenerator.hpp
//  ParserGenerator
//
//  Created by Yuval Dinari on 9/1/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef LALR_TableGenerator_hpp
#define LALR_TableGenerator_hpp


#include <iomanip>
using namespace std;

#include "Grammar.hpp"


//==========================================================================================================
// Configuration is grammar production, plus position of parser within the production, plus lookaheads set -
// expected tokens to follow this configuration while parsing.
//==========================================================================================================
class Configuration {
public:
    Configuration(Grammar* _grammar, Production& _production, int _pos, Set<Symbol> _lookaheads): grammar(_grammar), production(_production), pos(_pos), lookaheads(_lookaheads) {
        
        // 'closed' indicates no other configurations should be added to a configuration set due to this configuration
        // A configuration can cause adding of others to its closure set only if the position of dot is followed by
        // a non-terminal
        closed = (pos == production.rhs_size()) or is_terminal(get_next_symbol());
    }
    
    Grammar* grammar;
    Production& production;
    int pos;    // Position of the dot, i.e. where we are in the parse of the production
    Set<Symbol> lookaheads; // One or more terminals that can follow this production
    bool closed;
    

    //------------------------------------------------------------------------------------------------------
    // True when the position (the dot) is after all the symbols in the production
    //------------------------------------------------------------------------------------------------------
    bool reducable() const {
        return pos == production.rhs_size();
    }
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    bool next_symbol_exists() const {
        return pos < production.rhs_size();
    }
        
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
    Set<Symbol> get_next_symbol_lookahead_set() const {
        if(not next_symbol_exists())
            throw string("Can't get_next_symbol_lookahead_set() when position is at the end of a production");
            
        if(pos == production.rhs_size() - 1)
            return lookaheads;
        else
            return grammar->get_first_set(production[pos + 2]); 
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
    bool operator==(const Configuration &other) const { 
        return (production.index == other.production.index and pos == other.pos and lookaheads == other.lookaheads);
    }
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    void print() const {
        ostringstream o;
        o << symbol_str_map[production[0]] << " ->";
        
        for(int i = 0; i < production.rhs_size(); ++i) {
            if(pos == i)
                o << " •";
            o << " " << symbol_str_map[production[i+1]];
        }

        if(pos == production.rhs_size())
            o << " •"; 
        
        cout << left << setw(50) << o.str() << " # ";
        
        for(auto s: lookaheads)
            cout << symbol_str_map[s] << " ";
        
        cout << endl;
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
// A set of configurations. This class handles the closure operation on configurations, merging of
// configuration sets, etc.
// Doesn't actually store configurations. Instead use a map which key is <production-index, position>, and
// value is the lookahead set. This makes it easier to merge configurations that differ only in their
// lookahead sets.
// However, iterating is possible, and a real Configuration object will be created to facilitate
// configuration queries.
//==========================================================================================================
class ConfigurationSet {
public:
    ConfigurationSet(Grammar* _grammar): grammar(_grammar){}
    
    ConfigurationSet(Configuration c): grammar(c.grammar) {
        add_closure(c);
    }
    
    void add_closure(Configuration c);
    void add_closure(int production_index, int pos);
    
    bool empty() { return m.empty(); }
    void merge(ConfigurationSet other);
    bool lalr_equivalent(ConfigurationSet& other, bool& really_equal);
    bool update_lookaheads(Configuration& config);
    void print();
    
    typedef pair<int,int> key_type;
    typedef Set<Symbol> value_type;
    typedef map<key_type, value_type>::iterator map_iterator; 
    
    
    //------------------------------------------------------------------------------------------------------
    // Will enable iteration over the set as if iterating over a real set of configurations
    //------------------------------------------------------------------------------------------------------
    struct iterator {
        iterator(Grammar* _grammar, map_iterator _map_iter): grammar(_grammar), map_iter(_map_iter) {}
        
        Configuration operator*() {
            return Configuration(grammar, grammar->productions[map_iter->first.first], map_iter->first.second, map_iter->second);
        }
        
        bool operator==(const iterator& other) { 
            return map_iter == other.map_iter;
        }
        
        bool operator!=(const iterator& other) {
            return map_iter != other.map_iter;
        }
        
        iterator& operator++() {
            ++map_iter;
            return *this;
        }
        
    private:
        map_iterator map_iter;
        Grammar* grammar;
    };
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    iterator begin() {
        return iterator(grammar, m.begin());
    }
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    iterator end() {
        return iterator(grammar, m.end());
    }
    
private:
    Grammar* grammar;
    map<key_type, Set<Symbol>> m;
};


//==========================================================================================================
// Generate LALR(1) table
//==========================================================================================================
class LALR_TableGenerator {
public:
    LALR_TableGenerator(string grammar_file, string parser_tables_file);
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
    
    void build_table();
    void update_successors(int state, int max_state, vector<ConfigurationSet>& configurating_sets);
    void add_reductions(int state, vector<ConfigurationSet>& configurating_sets);
    
    enum ResolutionResult {SHIFT_WIN, REDUCE_WIN, NOT_ALLOWED};
    ResolutionResult resolve_conflict(const Configuration& c, Symbol sym, Action& action, string& err_msg);

    void write_tables_file(string filename);
    void write_parser_table(ofstream& file);
    void write_productions_table(ofstream& file);
    void write_gen_ast_function(ofstream& file);

    void print_separation_line(vector<int> col_widths);
};


#endif /* LALR_TableGenerator_hpp */
