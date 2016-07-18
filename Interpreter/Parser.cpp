//
//  Parser.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/13/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "Parser.hpp"
#include "ParseStackElement.hpp"

typedef SLR_Table::Action Action; 

//==========================================================================================================
// Build internal table from DFA, which is built from NFA, which is built from the grammar, which is built
// from definitions in the input file.
//==========================================================================================================
Parser::Parser(string grammar_file): grammar(grammar_file), table(grammar, DFA(NFA(grammar))) {}


//==========================================================================================================
//==========================================================================================================
AST* Parser::parse(vector<Token*> tokens) {
    if(tokens.empty() or tokens[0]->kind == EOI)
        return nullptr;
    
    for(int i = 0; i < tokens.size(); ++i) {
        if(is_nonterminal(tokens[i]->kind))
            throw string("Token kind for parsing should be a terminal");
    }

    stack<ParseStackElement> stack;
    stack.push(0);

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < tokens.size();) {
        Token* token = tokens[i];
        Action action = table.get_action(stack.top().state, token->kind); 
        
        switch(action.kind) {
            case Action::SHIFT: {
                stack.push(ParseStackElement(action.val, token));
                ++i;
                break;
            }
            case Action::GO: { // Should never be reached because tokens list received from lexer should contain only terminals
                throw string("GO action should never be reached directly");
                break;
            }
            case Action::REDUCE: { // Perform the REDUCE and GO action that immediately follows it
                
                Production& p = grammar.productions[action.val]; 
                Symbol N = p[0];
                int rhs_size = p.rhs_size();
                vector<TokenOrAST> elements;
                
                while(rhs_size-- > 0) { 
                    elements.push_back(stack.top().get_token_or_ast());
                    stack.pop();
                }
                
                AST* ast = p.ast_generator(elements);

                action = table.get_action(stack.top().state, N);
                
                if(action.kind != Action::GO)
                    throw string("Expected action for [" + to_string(stack.top().state) + "," + symbol_to_string(N) + "] to be GO but found: " + action.to_string());
                
                stack.push(ParseStackElement(action.val, ast));
                break;
            }
            case Action::ACCEPT: {
                if(i < tokens.size() - 1)
                    throw string("ACCEPT reached before end of input");
                
                AST* res = stack.top().get_token_or_ast().get_ast();
                stack.pop(); // ACCEPT is REDUCE for producation 0, which always has just one symbol on right-hand-side
                if(stack.top().state != 0 or stack.size() != 1)
                    throw string("Expected stack to contain just the start state after ACCEPT");
                
                cout << "Success!" << endl;
                return res;
            }
            case Action::ERROR: {
                cout << "Error on [" << to_string(stack.top().state) << "," << symbol_to_string(token->kind) << "]" << endl;
                return nullptr;
            }
        }
    }
    
    cout << "Error: end of input reached. Current state is " << stack.top().state << endl; 
    return nullptr;
}







