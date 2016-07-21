// Generated parser tables file

#include "Parser.hpp"

//==========================================================================================================
// Table of productions info: Left-hand-side nonterminal and number of symbols on right-hand-side
//==========================================================================================================
vector<ProductionInfo> Parser::production_infos = {
    {START, 1}, {STATEMENTS, 1}, {STATEMENTS, 2}, {STATEMENTS, 3}, {STATEMENT, 3}, {STATEMENT, 1}, {BLOCK, 3}, {STATEMENT, 3}, {STATEMENT, 3}, {STATEMENT, 4}, 
    {STATEMENT, 5}, {EXP, 1}, {EXP, 1}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, 
    {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 2}, 
    {EXP, 5}, 
};


//==========================================================================================================
// Generate an AST acording to production number
//==========================================================================================================
AST* Parser::gen_ast(int production, vector<TokenOrAST>& elements) {
    switch(production) {
        case 1: return new StatementsAST(elements);
        case 2: return new StatementsAST(elements);
        case 3: return new StatementsAST(elements);
        case 4: return new AssignmentAST(elements);
        case 5: return new StatementsAST(elements);
        case 6: return new StatementsAST(elements);
        case 7: return new IfAST(elements);
        case 8: return new WhileAST(elements);
        case 9: return new RepeatAST(elements);
        case 10: return new IfElseAST(elements);
        case 11: return new NumAST(elements);
        case 12: return new VarAST(elements);
        case 13: return extract_ast(elements);
        case 14: return new BopAST(elements);
        case 15: return new BopAST(elements);
        case 16: return new BopAST(elements);
        case 17: return new BopAST(elements);
        case 18: return new BopAST(elements);
        case 19: return new BopAST(elements);
        case 20: return new BopAST(elements);
        case 21: return new BopAST(elements);
        case 22: return new BopAST(elements);
        case 23: return new BopAST(elements);
        case 24: return new BopAST(elements);
        case 25: return new BopAST(elements);
        case 26: return new BopAST(elements);
        case 27: return new BopAST(elements);
        case 28: return new BopAST(elements);
        case 29: return new UopAST(elements);
        case 30: return new CondExpAST(elements);
    } // switch

    return nullptr;

} // Parser::gen_ast()


//==========================================================================================================
// Table of actions per (state, symbol) pair
//==========================================================================================================
vector<vector<Action>> Parser::table = {
    // State 0
    {{GO, 1}, {ERROR}, {GO, 2}, {GO, 3}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {ERROR}, {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, {SHIFT, 8}, },

    // State 1
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 5}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 5}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 5}, {REDUCE, 5}, {ERROR}, {REDUCE, 5}, {ERROR}, {ERROR}, 
    {REDUCE, 5}, {REDUCE, 5}, {ERROR}, {ERROR}, {REDUCE, 5}, {ERROR}, {REDUCE, 5}, },

    // State 2
    {{GO, 1}, {ERROR}, {GO, 2}, {GO, 9}, {ERROR}, {ERROR}, {REDUCE, 1}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 10}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {REDUCE, 1}, {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, {SHIFT, 8}, },

    // State 3
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ACCEPT}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 4
    {{GO, 1}, {ERROR}, {GO, 2}, {GO, 11}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {ERROR}, {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, {SHIFT, 8}, },

    // State 5
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 6
    {{ERROR}, {GO, 13}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 7
    {{ERROR}, {GO, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 8
    {{ERROR}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 9
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 2}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 2}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 10
    {{GO, 1}, {ERROR}, {GO, 2}, {GO, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {ERROR}, {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, {SHIFT, 8}, },

    // State 11
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 12
    {{ERROR}, {GO, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 13
    {{GO, 1}, {ERROR}, {GO, 23}, {ERROR}, {SHIFT, 24}, {SHIFT, 25}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {ERROR}, {SHIFT, 31}, {SHIFT, 32}, {ERROR}, 
    {SHIFT, 33}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {SHIFT, 4}, {ERROR}, {SHIFT, 37}, {SHIFT, 5}, {ERROR}, {SHIFT, 38}, 
    {ERROR}, {SHIFT, 6}, {ERROR}, {SHIFT, 39}, {SHIFT, 7}, {ERROR}, {SHIFT, 8}, },

    // State 14
    {{ERROR}, {GO, 40}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 15
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, 
    {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {ERROR}, 
    {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, 
    {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, },

    // State 16
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {REDUCE, 11}, 
    {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {ERROR}, 
    {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {REDUCE, 11}, 
    {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, },

    // State 17
    {{ERROR}, {GO, 41}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 18
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 24}, {SHIFT, 25}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {ERROR}, {SHIFT, 31}, {SHIFT, 32}, {ERROR}, 
    {SHIFT, 33}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {ERROR}, {ERROR}, {SHIFT, 37}, {ERROR}, {ERROR}, {SHIFT, 38}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 39}, {ERROR}, {SHIFT, 42}, {ERROR}, },

    // State 19
    {{GO, 1}, {ERROR}, {GO, 43}, {ERROR}, {SHIFT, 24}, {SHIFT, 25}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {ERROR}, {SHIFT, 31}, {SHIFT, 32}, {ERROR}, 
    {SHIFT, 33}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {SHIFT, 4}, {ERROR}, {SHIFT, 37}, {SHIFT, 5}, {ERROR}, {SHIFT, 38}, 
    {ERROR}, {SHIFT, 6}, {ERROR}, {SHIFT, 39}, {SHIFT, 7}, {ERROR}, {SHIFT, 8}, },

    // State 20
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 3}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 3}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 21
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 6}, {REDUCE, 6}, {ERROR}, {REDUCE, 6}, {ERROR}, {ERROR}, 
    {REDUCE, 6}, {REDUCE, 6}, {ERROR}, {ERROR}, {REDUCE, 6}, {ERROR}, {REDUCE, 6}, },

    // State 22
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 24}, {SHIFT, 25}, {REDUCE, 4}, {SHIFT, 26}, {ERROR}, {ERROR}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {REDUCE, 4}, {SHIFT, 31}, {SHIFT, 32}, {ERROR}, 
    {SHIFT, 33}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {REDUCE, 4}, {REDUCE, 4}, {SHIFT, 37}, {REDUCE, 4}, {ERROR}, {SHIFT, 38}, 
    {REDUCE, 4}, {REDUCE, 4}, {ERROR}, {SHIFT, 39}, {REDUCE, 4}, {ERROR}, {REDUCE, 4}, },

    // State 23
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 7}, {REDUCE, 7}, {ERROR}, {REDUCE, 7}, {ERROR}, {ERROR}, 
    {SHIFT, 44}, {REDUCE, 7}, {ERROR}, {ERROR}, {REDUCE, 7}, {ERROR}, {REDUCE, 7}, },

    // State 24
    {{ERROR}, {GO, 45}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 25
    {{ERROR}, {GO, 46}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 26
    {{ERROR}, {GO, 47}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 27
    {{ERROR}, {GO, 48}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 28
    {{ERROR}, {GO, 49}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 29
    {{ERROR}, {GO, 50}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 30
    {{ERROR}, {GO, 51}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 31
    {{ERROR}, {GO, 52}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 32
    {{ERROR}, {GO, 53}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 33
    {{ERROR}, {GO, 54}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 34
    {{ERROR}, {GO, 55}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 35
    {{ERROR}, {GO, 56}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 36
    {{ERROR}, {GO, 57}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 37
    {{ERROR}, {GO, 58}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 38
    {{ERROR}, {GO, 59}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 39
    {{ERROR}, {GO, 60}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 40
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 24}, {SHIFT, 25}, {ERROR}, {SHIFT, 26}, {ERROR}, {SHIFT, 61}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {ERROR}, {SHIFT, 31}, {SHIFT, 32}, {ERROR}, 
    {SHIFT, 33}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {ERROR}, {ERROR}, {SHIFT, 37}, {ERROR}, {ERROR}, {SHIFT, 38}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 39}, {ERROR}, {ERROR}, {ERROR}, },

    // State 41
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, 
    {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, 
    {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, 
    {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, },

    // State 42
    {{GO, 1}, {ERROR}, {GO, 62}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {ERROR}, {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, {SHIFT, 8}, },

    // State 43
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 8}, {REDUCE, 8}, {ERROR}, {REDUCE, 8}, {ERROR}, {ERROR}, 
    {REDUCE, 8}, {REDUCE, 8}, {ERROR}, {ERROR}, {REDUCE, 8}, {ERROR}, {REDUCE, 8}, },

    // State 44
    {{GO, 1}, {ERROR}, {GO, 63}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {ERROR}, {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, {SHIFT, 8}, },

    // State 45
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 20}, {SHIFT, 25}, {REDUCE, 20}, {SHIFT, 26}, {ERROR}, {REDUCE, 20}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {REDUCE, 20}, {REDUCE, 20}, {SHIFT, 31}, {SHIFT, 32}, {ERROR}, 
    {REDUCE, 20}, {SHIFT, 34}, {SHIFT, 35}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {SHIFT, 37}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, 
    {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, },

    // State 46
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, {SHIFT, 26}, {ERROR}, {REDUCE, 26}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {ERROR}, 
    {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, 
    {REDUCE, 26}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, },

    // State 47
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, 
    {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, },

    // State 48
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, 
    {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, },

    // State 49
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {SHIFT, 26}, {ERROR}, {REDUCE, 14}, 
    {SHIFT, 27}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, {SHIFT, 30}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, 
    {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, 
    {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, },

    // State 50
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {SHIFT, 26}, {ERROR}, {REDUCE, 15}, 
    {SHIFT, 27}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {SHIFT, 30}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, 
    {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, 
    {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, },

    // State 51
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, 
    {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, 
    {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, 
    {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, },

    // State 52
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 21}, {SHIFT, 25}, {REDUCE, 21}, {SHIFT, 26}, {ERROR}, {REDUCE, 21}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 21}, {ERROR}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {SHIFT, 37}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, 
    {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, },

    // State 53
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 23}, {SHIFT, 25}, {REDUCE, 23}, {SHIFT, 26}, {ERROR}, {REDUCE, 23}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {REDUCE, 23}, {REDUCE, 23}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 23}, {ERROR}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {SHIFT, 37}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, 
    {REDUCE, 23}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, },

    // State 54
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 19}, {SHIFT, 25}, {REDUCE, 19}, {SHIFT, 26}, {ERROR}, {REDUCE, 19}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {REDUCE, 19}, {REDUCE, 19}, {SHIFT, 31}, {SHIFT, 32}, {ERROR}, 
    {REDUCE, 19}, {SHIFT, 34}, {SHIFT, 35}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {SHIFT, 37}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, 
    {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, },

    // State 55
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 22}, {SHIFT, 25}, {REDUCE, 22}, {SHIFT, 26}, {ERROR}, {REDUCE, 22}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 22}, {ERROR}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {SHIFT, 37}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, 
    {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, },

    // State 56
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 24}, {SHIFT, 25}, {REDUCE, 24}, {SHIFT, 26}, {ERROR}, {REDUCE, 24}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {REDUCE, 24}, {REDUCE, 24}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 24}, {ERROR}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {SHIFT, 37}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, 
    {REDUCE, 24}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, },

    // State 57
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 24}, {SHIFT, 25}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {SHIFT, 64}, {ERROR}, {SHIFT, 31}, {SHIFT, 32}, {ERROR}, 
    {SHIFT, 33}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {ERROR}, {ERROR}, {SHIFT, 37}, {ERROR}, {ERROR}, {SHIFT, 38}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 39}, {ERROR}, {ERROR}, {ERROR}, },

    // State 58
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 25}, {ERROR}, {REDUCE, 25}, {SHIFT, 26}, {ERROR}, {REDUCE, 25}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {ERROR}, 
    {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {ERROR}, {REDUCE, 25}, {ERROR}, {REDUCE, 25}, 
    {REDUCE, 25}, {REDUCE, 25}, {ERROR}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, },

    // State 59
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 24}, {SHIFT, 25}, {REDUCE, 28}, {SHIFT, 26}, {ERROR}, {REDUCE, 28}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {REDUCE, 28}, {REDUCE, 28}, {SHIFT, 31}, {SHIFT, 32}, {ERROR}, 
    {SHIFT, 33}, {SHIFT, 34}, {SHIFT, 35}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {SHIFT, 37}, {REDUCE, 28}, {ERROR}, {REDUCE, 28}, 
    {REDUCE, 28}, {REDUCE, 28}, {ERROR}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, },

    // State 60
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 24}, {SHIFT, 25}, {REDUCE, 27}, {SHIFT, 26}, {ERROR}, {REDUCE, 27}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {REDUCE, 27}, {REDUCE, 27}, {SHIFT, 31}, {SHIFT, 32}, {ERROR}, 
    {SHIFT, 33}, {SHIFT, 34}, {SHIFT, 35}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {SHIFT, 37}, {REDUCE, 27}, {ERROR}, {SHIFT, 38}, 
    {REDUCE, 27}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, },

    // State 61
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, 
    {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, 
    {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, 
    {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, },

    // State 62
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 9}, {REDUCE, 9}, {ERROR}, {REDUCE, 9}, {ERROR}, {ERROR}, 
    {REDUCE, 9}, {REDUCE, 9}, {ERROR}, {ERROR}, {REDUCE, 9}, {ERROR}, {REDUCE, 9}, },

    // State 63
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 10}, {REDUCE, 10}, {ERROR}, {REDUCE, 10}, {ERROR}, {ERROR}, 
    {REDUCE, 10}, {REDUCE, 10}, {ERROR}, {ERROR}, {REDUCE, 10}, {ERROR}, {REDUCE, 10}, },

    // State 64
    {{ERROR}, {GO, 65}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 65
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 24}, {SHIFT, 25}, {REDUCE, 30}, {SHIFT, 26}, {ERROR}, {REDUCE, 30}, 
    {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, {SHIFT, 30}, {REDUCE, 30}, {REDUCE, 30}, {SHIFT, 31}, {SHIFT, 32}, {ERROR}, 
    {SHIFT, 33}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {REDUCE, 30}, {REDUCE, 30}, {SHIFT, 37}, {REDUCE, 30}, {ERROR}, {SHIFT, 38}, 
    {REDUCE, 30}, {REDUCE, 30}, {ERROR}, {SHIFT, 39}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, },

}; // Parser::table


