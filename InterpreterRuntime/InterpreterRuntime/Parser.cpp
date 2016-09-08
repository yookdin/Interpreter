//
//  Parser.cpp
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/21/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "utils.hpp"
#include "Parser.hpp"
#include "ParseStackElement.hpp"


//==========================================================================================================
//==========================================================================================================
AST* Parser::parse(vector<Token*> tokens) {
    if(tokens.empty() or tokens[0]->sym == EOI)
        return nullptr;
    
    for(int i = 0; i < tokens.size(); ++i) {
        if(is_nonterminal(tokens[i]->sym))
            throw string("Token kind for parsing should be a terminal");
    }
    
    stack<ParseStackElement> stack;
    stack.push(0);
    
    //------------------------------------------------------------------------------------------------------
    // Go over tokens. For each token perform action according to it and current state
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < tokens.size();) {
        Token* token = tokens[i];
        Action action = table[stack.top().state][token->sym]; 
        
        switch(action.kind) {
            case SHIFT: {
                stack.push(ParseStackElement(action.val, token));
                ++i;
                break;
            }
            case REDUCE: { // Perform the REDUCE and GO action that immediately follows it
                
                Symbol N = production_infos[action.val].lhs;
                int rhs_size = production_infos[action.val].rhs_size; 
                vector<TokenOrAST> elements;
                
                while(rhs_size-- > 0) { 
                    elements.push_back(stack.top().get_token_or_ast());
                    stack.pop();
                }
                
                reverse(elements.begin(), elements.end()); // Reverse to restore original order
                AST* ast = gen_ast(action.val, elements);
                
                action = table[stack.top().state][N];
                
                if(action.kind != SHIFT)
                    throw string("Expected action for [" + to_string(stack.top().state) + "," + symbol_str_map[N] + "] to be SHIFT but found: " + action.to_string());
                
                stack.push(ParseStackElement(action.val, ast));
                break;
            }
            case ACCEPT: {
                if(i < tokens.size() - 1)
                    throw string("ACCEPT reached before end of input");
                
                AST* res = stack.top().get_token_or_ast().get_ast();
                stack.pop(); // ACCEPT is REDUCE for production 0, which always has just one symbol on right-hand-side
                if(stack.top().state != 0 or stack.size() != 1)
                    throw string("Expected stack to contain just the start state after ACCEPT");
                
                return res;
            }
            case ERROR: {
                cout << create_err_msg(stack.top(), *token) << endl;
                return nullptr;
            }
        }
    }
    
    for(auto t: tokens) delete t;
    
    cout << "Error: end of input reached. Current state is " << stack.top().state << endl; 
    return nullptr;
}


//==========================================================================================================
//==========================================================================================================
string Parser::create_err_msg(ParseStackElement& stack_element, Token& token) {
    string prev_symbol, cur_symbol = token.get_name();
    if(cur_symbol == "$") cur_symbol = "end-of-input";
    int state = stack_element.state;

    if(state == 0) { // start state
        return "Error: can't start with " + cur_symbol;
    }
    
    // This should never happen, it it does it's an internal error
    if(not stack_element.get_token_or_ast().is_token)
        throw string("A parse error while top of the stack contains an AST");
        
    prev_symbol = stack_element.get_token()->get_name();
    return "Error: " + cur_symbol + " after " + prev_symbol;
}


//==========================================================================================================
// Sometimes nothing new should be done, just return the only AST in the list of elements. The other are
// tokens that aren't needed in the AST (like parentheses).
//==========================================================================================================
AST* Parser::extract_ast(vector<TokenOrAST>& elements) {
    for(auto& elem: elements) {
        AST* ast;
        if((ast = elem.get_ast()) != nullptr)
            return ast;
    }
    
    throw string("No AST found in elements received by AST factory");
}