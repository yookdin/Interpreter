//
//  LR_TableGenerator.cpp
//  ParserGenerator
//
//  Created by Yuval Dinari on 9/1/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "LR_TableGenerator.hpp"


//==========================================================================================================
//==========================================================================================================
LR_TableGenerator::LR_TableGenerator(string grammar_file): grammar(grammar_file) {
    
}


//==========================================================================================================
// The configuration sets are the states of the state machine. For each constructed one, add a state, then
// calculate its transition (successor function), which might create new configuration sets.
// Initial configuration set is the closure of the initial configuration which is:
// [S' -> • S, $]
//==========================================================================================================
void LR_TableGenerator::build_table() {
    //Configuration* c0 = new Configuration(grammar, grammar.productions[0], 0, {EOI});
    
    //set<Configuration*> cs0 = closure(c0);
}


//==========================================================================================================
//==========================================================================================================
unordered_set<Configuration> LR_TableGenerator::closure(Configuration c) {
    unordered_set<Configuration> res;
    res.insert(c);
    vector<Configuration> cur_configs;
    cur_configs.push_back(c);
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < cur_configs.size(); ++i) {
        if(cur_configs[i].closed) continue;
        
        Symbol nonterminal = cur_configs[i].get_next_symbol();
        set<Symbol> lookaheads = cur_configs[i].get_actual_lookahead_set();
        
        for(auto& p: grammar.productions) {
            if(p.get_lhs() != nonterminal) continue;
            
            Configuration c(grammar, p, 0, lookaheads);
        }
        
        //        for(int s: nfa.get_epsilon_transitions(cur_states[i])) {
        //            if(res.count(s) == 0) {
        //                res.insert(s);
        //                cur_states.push_back(s);
        //            }
        //        }
    }

//set<Configuration*> LR_TableGenerator::closure(Configuration* c) {
//    set<Configuration*> res;
//    res.insert(c);
//    vector<Configuration*> cur_configs;
//    cur_configs.push_back(c);
//    
//    //------------------------------------------------------------------------------------------------------
//    //------------------------------------------------------------------------------------------------------
//    for(int i = 0; i < cur_configs.size(); ++i) {
//        if(cur_configs[i]->closed) continue;
//        
//        Symbol nonterminal = cur_configs[i]->get_next_symbol();
//        set<Symbol> lookaheads = cur_configs[i]->get_actual_lookahead_set();
//        
//        for(auto& p: grammar.productions) {
//            if(p.get_lhs() != nonterminal) continue;
//            
//            Configuration c(grammar, p, 0, lookaheads);
//        }
//        
////        for(int s: nfa.get_epsilon_transitions(cur_states[i])) {
////            if(res.count(s) == 0) {
////                res.insert(s);
////                cur_states.push_back(s);
////            }
////        }
//    }

    
    return res;
}
