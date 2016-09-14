//
//  LALR_TableGenerator.cpp
//  ParserGenerator
//
//  Created by Yuval Dinari on 9/1/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "LALR_TableGenerator.hpp"


//==========================================================================================================
// According to given grammar file, generate the parser tables file
//==========================================================================================================
LALR_TableGenerator::LALR_TableGenerator(string grammar_file, string parser_tables_file): grammar(grammar_file) {
    build_table();
    write_tables_file(parser_tables_file);
}


//==========================================================================================================
// Build the internal table that will be used to write the parser-table file.
// The configuration sets are the states of the state machine. For each constructed one, add a state, then
// calculate its transition (successor function), which might create new configuration sets.
// Initial configuration set is the closure of the initial configuration which is:
// [S' -> • S, $]
// States are merged on the fly to create an LALR table.
//==========================================================================================================
void LALR_TableGenerator::build_table() {
    Configuration c0(&grammar, grammar.productions[0], 0, {EOI}); // Initial configuration
    
    // A list of the configuration sets, for each a state will be created
    vector<ConfigurationSet> configurating_sets{ConfigurationSet(c0)};
    
    // Adding the starting state
    table.push_back(vector<Action>(NUM_SYMBOLS));
    
    //------------------------------------------------------------------------------------------------------
    // As long as there are new states in the table, calculate the transitions for them, while creating new
    // states if needed
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < table.size(); ++i) {
        cout << i << " "; fflush(stdout);
        
        for(int sym = 0; sym < NUM_SYMBOLS; ++sym) { // for each symbol
            ConfigurationSet cs(&grammar);
            
            for(auto c: configurating_sets[i]) {    // for each configuration in current state
                if(not c.next_symbol_exists() or c.get_next_symbol() != sym) 
                    continue;

                cs.merge(c.get_transition_configuration());
            }

            if(cs.empty()) continue;
                        
            // TODO: check if can speed this O(n^2) check by using hash table for states
            for(int j = 0; j < table.size(); ++j) {
                if(configurating_sets[j] == cs) { // Set already exist, just add transition to it
                    table[i][sym] = {SHIFT, j};
                    break;
                }
            
                if(configurating_sets[j].lalr_equivalent(cs)) { // Sets can be merged to create an LALR(1) state
                    configurating_sets[j].merge(cs);
                    update_successors(j, i, configurating_sets); // Update successors states due to the merge
                    table[i][sym] = {SHIFT, j};
                    break;
                }
            }
            
            if(table[i][sym].kind == ERROR) { // Transition not set yet, create new state
                configurating_sets.push_back(cs);
                table.push_back(vector<Action>(NUM_SYMBOLS)); // Add a new state, with no transitions defined yet
                table[i][sym] = {SHIFT, (int)table.size() - 1};
            }
             
        } // for each symbol
        
    } // for each new state
    

    //------------------------------------------------------------------------------------------------------
    // Add the reductions for each state
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < table.size(); ++i)
        add_reductions(i, configurating_sets);
}


//==========================================================================================================
// After an LALR merge the lookahead sets grow, so need to update the successor states already created from
// the original state (before the merge).
// To handle loops in the states graph, only call recursively on state that were actually updated.
// This ensures that we won't loop forever, and also that we don't miss anything.
//==========================================================================================================
void LALR_TableGenerator::update_successors(int state, int last_complete_state, vector<ConfigurationSet>& configurating_sets) {

    if(state > last_complete_state) return; // No need to update successors, they weren't calculated yet
    
    set<int> states_to_update;
    
    for(auto c: configurating_sets[state]) {
        if(not c.next_symbol_exists()) // This configuration didn't cause any transition 
            continue;
        
        Symbol sym = c.get_next_symbol();
        
        // Check if SHIFT, because it's possible (I think) to update on the current state, while not all of its transitions has been defined
        if(table[state][sym].kind == SHIFT) {           
            bool updated = configurating_sets[table[state][sym].val].update_lookaheads(c);
            if(updated) {
                states_to_update.insert(table[state][sym].val);
            }
        }
    }

    // Recursively call update_successors() for all the states that were updated, because their successors needs to be updated also!
    for(auto s: states_to_update)
        update_successors(s, last_complete_state, configurating_sets);
}


//==========================================================================================================
//==========================================================================================================
void LALR_TableGenerator::add_reductions(int state, vector<ConfigurationSet>& configurating_sets) {
    for(auto c: configurating_sets[state]) {
        if(not c.reducable()) continue;
        
        // Add a reduce action for each symbol in the configuration lookahead set
        for(auto sym: c.lookaheads) {
            
            if(table[state][sym].kind != ERROR) { // There's a conflict, try to resolve
                
                ResolutionResult res; 
                
                try {
                    res = resolve_conflict(c, sym, table[state][sym], table[state][sym].message); 
                } catch(string err) {
                    cout << endl << "Conflict resolution error. Current state is " << state << ":" << endl;
                    configurating_sets[state].print();
                    cout << "Current configuration is:" << endl;
                    c.print();
                    cout << "Previous action is shift to state " << table[state][sym].val << ":" << endl;
                    configurating_sets[table[state][sym].val].print();
                    throw;
                }
                
                // This sequence is not allowed. This happens for consecutive operators with no associativity,
                // meaning they're not allowed to be chained
                if(res == NOT_ALLOWED)
                    table[state][sym].kind = ERROR;
                
                if(res != REDUCE_WIN) continue;
            }
            
            // No confilict or REDUCE_WIN
            if(c.production[0] == START) {
                if(sym != EOI)
                    throw string("START symbol should only be reduced on $ symbol");
                table[state][sym].kind = ACCEPT;
            } else {
                table[state][sym] = {REDUCE, c.production.index};                    
            }
        } // for each symbol in the lookahead set
    } // for each configuration in the set
}



//==========================================================================================================
// Conflicts that can be resolved are only shift-reduce of the following kinds:
// o if-else - else (shift) wins, causing else to be always associated with closet preceding if
// o Infix operators - resolve according to operator precedence and associativity
//==========================================================================================================
LALR_TableGenerator::ResolutionResult LALR_TableGenerator::resolve_conflict(const Configuration& c, Symbol sym, Action& action, string& err_msg) {
    if(action.kind != SHIFT)
        throw string("Can't resolve a reduce-reduce conflict");

    if(sym == ELSE) {
        return SHIFT_WIN;
    }
    
    if(not is_op(sym)) {
        throw string("Can't resolve conflict, current symbol is " + symbol_str_map[sym] + " which isn't an operator");
    }
    
    if(c.production.op == nullptr)
        throw string("Can't resolve conflict, production doesn't have an operator associated with it");
    
    Operator *left_op = c.production.op, *right_op = get_op(sym);
    
    if(left_op->precedence == right_op->precedence and left_op->associativity == Operator::NONE) {                    
        err_msg = "Sequence: \"EXP " + left_op->get_name() + " EXP " + right_op->get_name() + " EXP\" not allowed";
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
// Write a source file containing the parser state machine table (action per (state, symbol), and production
// info table
//==========================================================================================================
void LALR_TableGenerator::write_tables_file(string filename) {
    ofstream file = ofstream(filename);
    
    if(!file.is_open())
        throw string("File " + filename + " can't be written");
    
    file << "// Generated parser tables file" << endl << endl;
    file << "#include \"Parser.hpp\"" << endl << endl;
    write_productions_table(file);
    write_gen_ast_function(file);
    write_parser_table(file);
    file.close();
}


//==========================================================================================================
//==========================================================================================================
void LALR_TableGenerator::write_parser_table(ofstream& file) {
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
            if(action.kind == SHIFT or action.kind == REDUCE)
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
// For the parsing process, only the nonterminal and the RHS size per production is needed, so write it.
//==========================================================================================================
void LALR_TableGenerator::write_productions_table(ofstream &file) {
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
// Write the function that knows how to generate an AST given a production number and the parsing elements
// extracted from the stack for a reduction operation.
//==========================================================================================================
void LALR_TableGenerator::write_gen_ast_function(ofstream& file) {
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
void LALR_TableGenerator::print() {
    cout << "LR_Table:" << endl;
    
    vector<int> col_widths;
    for(int sym = 0; sym < NUM_SYMBOLS; ++sym) {
        string name = symbol_str_map[Symbol(sym)];
        col_widths.push_back(max(5, int(name.length()) + 2));
    }
    print_separation_line(col_widths);    
    
    // Print column names
    cout << "   |";
    for(int sym = 0; sym < NUM_SYMBOLS; ++sym) {
        string name = symbol_str_map[Symbol(sym)];
        col_widths.push_back(max(5, int(name.length()) + 2));
        
        int leading_spaces = (col_widths[sym] - name.length()) / 2;
        cout << setfill(' ') << setw(leading_spaces) << "";
        cout << left << setw(col_widths.back() - leading_spaces) << name;
        cout << "|";
    }
    cout << endl;
    print_separation_line(col_widths);
    
    // Print row per state
    for(int i = 0; i < table.size(); ++i) {
        cout << std::left << std::setw(3) << i << "|";
        
        for(int sym = 0; sym < NUM_SYMBOLS; ++sym) {
            string action = table[i][sym].to_string();
            cout << " " << action;
            cout << std::right << std::setw(col_widths[sym] - action.length()) << "|";
        }
        
        cout << endl;
        print_separation_line(col_widths);
    }
    cout << endl;
}

//==========================================================================================================
//==========================================================================================================
void LALR_TableGenerator::print_separation_line(vector<int> col_widths) {
    cout << "---";
    for(int sym = 0; sym < NUM_SYMBOLS; ++sym) {
        cout << "+";
        for(int i = 0; i < col_widths[sym]; ++i) cout << "-";
    }
    cout << "+" << endl;
}


//==========================================================================================================
// Perform the closure operation on the configuration
//==========================================================================================================
ConfigurationSet::ConfigurationSet(Configuration c): grammar(c.grammar) {
    UnorderedSet<Configuration> tmp_set{c};
    vector<Configuration> cur_configs{c};
    
    //------------------------------------------------------------------------------------------------------
    // While there are new configurations in the set, try to to extend them
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < cur_configs.size(); ++i) {
        if(cur_configs[i].closed) continue; // Current configuration can't be extended
        
        Symbol nonterminal = cur_configs[i].get_next_symbol();
        Set<Symbol> lookaheads = cur_configs[i].get_actual_lookahead_set();
        
        for(auto& p: grammar->productions) {
            if(p.get_lhs() != nonterminal) continue;
            
            Configuration c(grammar, p, 0, lookaheads);
            
            if(tmp_set.count(c) == 0) { // The check is not necessary when adding to a set, but it is to know whether to add to cur_configs
                tmp_set.insert(c);
                cur_configs.push_back(c);
            }
        }
    }
    
    //------------------------------------------------------------------------------------------------------
    // Transform actual configuration objects to map entries, while merging configurations that only differ
    // in their lookahead sets.
    //------------------------------------------------------------------------------------------------------
    for(auto& c: tmp_set) {
        m[{c.production.index, c.pos}].insert(c.lookaheads); // Either create a new entry or merge lookaheads into existing one
    }
}


//==========================================================================================================
// Add all configurations in other. If configurations exists which only differs in their lookahead sets,
// only merge the lookahead sets.
//==========================================================================================================
void ConfigurationSet::merge(ConfigurationSet other) {
    for(auto& p: other.m)
        m[p.first].insert(p.second);
}


//==========================================================================================================
// The sets are considered equivalent if their cores (configurations without the lookahead sets) are equal. 
//==========================================================================================================
bool ConfigurationSet::lalr_equivalent(ConfigurationSet& other) {
    if(m.size() != other.m.size())
        return false;
    
    auto i1 = m.begin(), i2 = other.m.begin();
    
    for(; i1 != m.end(); ++i1, ++i2) {
        if(i1->first != i2->first)
            return false;
    }
    
    return true;
}


//==========================================================================================================
// Given a configuration which has a transition into this configuration set, and which had its lookahead
// set augmented due to LALR states merge, find the configuration in the current set that the input
// configuration "points" to, and update its lookahead set.
// Also update all the configurations of the closure of that configuration.
// Return true if something was actually added
//==========================================================================================================
bool ConfigurationSet::update_lookaheads(Configuration& config) {
    int pos = config.pos + 1; // The position of the dot advances in the transition
    
    // Symbols will be added only if config lookahead contains new symbols 
    bool res = not config.lookaheads.is_difference_empty(m[{config.production.index, pos}]); 
    
    if(res) {
        // Update the configuration that is due to the transition
        m[{config.production.index, pos}].insert(config.lookaheads);
        
        // If the position is just before the last symbol, may need to update the lookahead of the closure set
        if(config.production.rhs_size() == pos + 1) {
            Symbol S = config.production[pos+1]; // The last symbol of the production
            
            if(is_nonterminal(S)) {
                for(auto& p: m) {
                    if(grammar->productions[p.first.first].get_lhs() == S and p.first.second == 0)
                        p.second.insert(config.lookaheads);
                }
            }
        }
    }
    return res;
}


//==========================================================================================================
//==========================================================================================================
void ConfigurationSet::print() {
    for(auto c: *this) c.print();
    cout << endl;
}






























