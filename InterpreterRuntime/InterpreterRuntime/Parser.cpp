//
//  Parser.cpp
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/21/16.
//  Copyright © 2016 Vonage. All rights reserved.
//


#include <stack>
using namespace std;

#include "sip_tester_utils.hpp"
#include "Parser.hpp"


//==========================================================================================================
//==========================================================================================================
AST* Parser::parse(vector<Token*> tokens) {
    if(tokens.empty() or tokens[0]->sym == EOI)
        return nullptr;
    
    stack<ParserStackElement> stack;
    stack.push({0, nullptr});
    
    //------------------------------------------------------------------------------------------------------
    // Go over tokens. For each token perform action according to it and current state
    //------------------------------------------------------------------------------------------------------
    for(int i = 0; i < tokens.size();) {
        Token* token = tokens[i];
        Action action = table[stack.top().state][token->sym]; 
        
        switch(action.kind) {
            case SHIFT: {
                stack.push({action.val, token});
                ++i;
                break;
            }
            case REDUCE: { // Perform the REDUCE and GO action that immediately follows it
                
                Symbol N = production_infos[action.val].lhs;
                int rhs_size = production_infos[action.val].rhs_size; 
                vector<ParseElement*> elements;
                
                while(rhs_size-- > 0) { 
                    elements.push_back(stack.top().elem);
                    stack.pop();
                }
                
                reverse(elements.begin(), elements.end()); // Reverse to restore original order
                AST* ast = gen_ast(action.val, elements);
                
                action = table[stack.top().state][N];
                
                if(action.kind != SHIFT)
                    THROW << "Expected action for [" << stack.top().state << "," << symbol_str_map[N] << "] to be SHIFT but found: " << action.to_string();
                
                stack.push({action.val, ast});
                break;
            }
            case ACCEPT: {
                if(i < tokens.size() - 1)
                    THROW << "ACCEPT reached before end of input";
                
                AST* res = stack.top().elem->get_ast();
                stack.pop(); // ACCEPT is REDUCE for production 0, which always has just one symbol on right-hand-side
                if(stack.top().state != 0 or stack.size() != 1)
                    THROW << "Expected stack to contain just the start state after ACCEPT";
                
                return res;
            }
            case ERROR: {
                THROW << create_err_msg(stack.top(), *token);
            }
        }
    }
    
    Print() << "Error: end of input reached. Current state is " << stack.top().state << endl; 
    return nullptr;
}


//==========================================================================================================
//==========================================================================================================
string Parser::create_err_msg(ParserStackElement& stack_element, Token& token) {
    string prev_symbol, cur_symbol = token.get_name();
    
    if(cur_symbol == "$")
        cur_symbol = "end-of-input";
    
    int state = stack_element.state;

    if(state == 0) { // start state
        return "Parsing error: can't start with " + cur_symbol;
    }
    
    // This should never happen, it it does it's an internal error
    if(not stack_element.elem->is_token())
        THROW << "A parse error while top of the stack contains an AST";
        
    prev_symbol = stack_element.elem->get_token()->get_name();
    return "Parsing error: " + cur_symbol + " after " + prev_symbol;
}


//==========================================================================================================
// Sometimes nothing new should be done, just return the first AST in the list of elements. The other are
// tokens that aren't needed in the AST (like parentheses).
//==========================================================================================================
AST* Parser::extract_ast(vector<ParseElement*>& elements) {
    for(auto& elem: elements) {
        if(not elem->is_token()) {
            return elem->get_ast();
        }
    }
    
    THROW << "No AST found in elements received by AST factory";
}



//==========================================================================================================
// If left child is a BopAST with the same operator as current one, and its associativity is left, then add
// the right child to the existing tree, instead of creating a new tree. So when consecutive operators
// appear, they will result in just one tree with many children, which will evaluate from left to right.
//==========================================================================================================
AST* Parser::gen_bop_ast(vector<ParseElement*>& elements) {
    return new BopAST(elements);
}








