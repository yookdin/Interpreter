//
//  Parser.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/13/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "Parser.hpp"

typedef SLR_Table::Action Action; 

//==========================================================================================================
// Build internal table from DFA, which is built from NFA, which is built from the grammar, which is built
// from definitions in the input file.
//==========================================================================================================
Parser::Parser(string grammar_file): grammar(grammar_file), table(grammar, DFA(NFA(grammar))) {}


//==========================================================================================================
//==========================================================================================================
void Parser::parse(vector<Token> tokens) {
    for(int i = 0; i < tokens.size(); ++i) {
        if(is_nonterminal(tokens[i].kind))
            throw string("Token kind for parsing should be a terminal");
    }

    stack<int> stack;
    stack.push(0);

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < tokens.size();) {
        Token token = tokens[i];
        Action action = table.get_action(stack.top(), token.kind); 
        
        switch(action.kind) {
            case Action::SHIFT: {
                stack.push(action.val);
                ++i;
                break;
            }
            case Action::GO: { // Should never be reached because tokens list received from lexer should contain only terminals
                throw string("GO action should never be reached directly");
                break;
            }
            case Action::REDUCE: { // Perform the REDUCE and GO action that immediately follows it
                Symbol N = get_nonterminal_of_production(action.val);
                int rhs_size = get_production_rhs_size(action.val);
                while(rhs_size-- > 0) stack.pop();
                
                action = table.get_action(stack.top(), N);
                
                if(action.kind != Action::GO)
                    throw string("Expected action for [" + to_string(stack.top()) + "," + symbol_to_string(N) + "] to be GO but found: " + action.to_string());
                
                stack.push(action.val);
                break;
            }
            case Action::ACCEPT: {
                if(i < tokens.size() - 1)
                    throw string("ACCEPT reached before end of input");
                
                stack.pop(); // ACCEPT is REDUCE for producation 0, which always has just one symbol on right-hand-side
                if(stack.top() != 0 or stack.size() != 1)
                    throw string("Expected stack to contain just the start state after ACCEPT");
                
                cout << "Success!" << endl;
                return;
            }
            case Action::ERROR: {
                cout << "Error on [" << to_string(stack.top()) << "," << symbol_to_string(token.kind) << "]" << endl;
                return;
            }
        }
    }
    
    cout << "Error: end of input reached. Current state is " << stack.top() << endl; 
}


//==========================================================================================================
//==========================================================================================================
Symbol Parser::get_nonterminal_of_production(int p) {
    return grammar.get_nonterminal_of_production(p);
}


//==========================================================================================================
//==========================================================================================================
int Parser::get_production_rhs_size(int p) {
    return grammar.get_production_rhs_size(p);
}















