// Generated parser tables file

#include "Parser.hpp"

//==========================================================================================================
// Table of productions info: Left-hand-side nonterminal and number of symbols on right-hand-side
//==========================================================================================================
vector<ProductionInfo> Parser::production_infos = {
    {START, 1}, {STATEMENT, 3}, {EXP, 1}, {EXP, 1}, {EXP, 1}, {EXP, 1}, {EXP, 3}, {EXP, 3}, 
};


//==========================================================================================================
// Generate an AST acording to production number
//==========================================================================================================
AST* Parser::gen_ast(int production, vector<TokenOrAST>& elements) {
    switch(production) {
        case 1: return new AssignmentAST(elements);
        case 2: return new NumAST(elements);
        case 3: return new BoolAST(elements);
        case 4: return new StringAST(elements);
        case 5: return new VarAST(elements);
        case 6: return extract_ast(elements);
        case 7: return new BopAST(elements);
    } // switch

    return nullptr;

} // Parser::gen_ast()


//==========================================================================================================
// Table of actions per (state, symbol) pair
//==========================================================================================================
vector<vector<Action>> Parser::table = {
    // State 0
    {{ERROR}, {SHIFT, 1}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 2}, {ERROR}, 
    {ERROR}, },

    // State 1
    {{ERROR}, {ERROR}, {ACCEPT}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 2
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 3}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 3
    {{SHIFT, 4}, {ERROR}, {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {SHIFT, 7}, {SHIFT, 8}, 
    {SHIFT, 9}, },

    // State 4
    {{ERROR}, {ERROR}, {REDUCE, 1}, {ERROR}, {ERROR}, {SHIFT, 10}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 5
    {{SHIFT, 11}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {SHIFT, 15}, 
    {SHIFT, 16}, },

    // State 6
    {{ERROR}, {ERROR}, {REDUCE, 3}, {ERROR}, {ERROR}, {REDUCE, 3}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 7
    {{ERROR}, {ERROR}, {REDUCE, 5}, {ERROR}, {ERROR}, {REDUCE, 5}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 8
    {{ERROR}, {ERROR}, {REDUCE, 2}, {ERROR}, {ERROR}, {REDUCE, 2}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 9
    {{ERROR}, {ERROR}, {REDUCE, 4}, {ERROR}, {ERROR}, {REDUCE, 4}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 10
    {{SHIFT, 17}, {ERROR}, {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {SHIFT, 7}, {SHIFT, 8}, 
    {SHIFT, 9}, },

    // State 11
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 12
    {{SHIFT, 20}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {SHIFT, 15}, 
    {SHIFT, 16}, },

    // State 13
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 3}, {REDUCE, 3}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 14
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 5}, {REDUCE, 5}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 15
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 2}, {REDUCE, 2}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 16
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 4}, {REDUCE, 4}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 17
    {{ERROR}, {ERROR}, {REDUCE, 7}, {ERROR}, {ERROR}, {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 18
    {{ERROR}, {ERROR}, {REDUCE, 6}, {ERROR}, {ERROR}, {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 19
    {{SHIFT, 21}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {SHIFT, 15}, 
    {SHIFT, 16}, },

    // State 20
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 22}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 21
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 7}, {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 22
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 6}, {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

}; // Parser::table


