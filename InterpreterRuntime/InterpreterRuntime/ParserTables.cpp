// Generated parser tables file

#include "Parser.hpp"

//==========================================================================================================
// Table of productions info: Left-hand-side nonterminal and number of symbols on right-hand-side
//==========================================================================================================
vector<ProductionInfo> Parser::production_infos = {
    {START, 1}, {STATEMENTS, 1}, {STATEMENTS, 2}, {STATEMENTS, 3}, {STATEMENT, 3}, {STATEMENT, 1}, {BLOCK, 3}, {STATEMENT, 3}, {STATEMENT, 5}, {EXP, 1}, 
    {EXP, 1}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, 
    {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 2}, {EXP, 5}, 
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
        case 8: return new IfElseAST(elements);
        case 9: return new NumAST(elements);
        case 10: return new VarAST(elements);
        case 11: return extract_ast(elements);
        case 12: return new BopAST(elements);
        case 13: return new BopAST(elements);
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
        case 27: return new UopAST(elements);
        case 28: return new CondExpAST(elements);
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
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {ERROR}, {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 6}, {ERROR}, {ERROR}, },

    // State 1
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 5}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 5}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 5}, {REDUCE, 5}, {ERROR}, {REDUCE, 5}, {ERROR}, {ERROR}, {REDUCE, 5}, 
    {REDUCE, 5}, {ERROR}, {ERROR}, },

    // State 2
    {{GO, 1}, {ERROR}, {GO, 2}, {GO, 7}, {ERROR}, {ERROR}, {REDUCE, 1}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {REDUCE, 1}, {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 6}, {ERROR}, {ERROR}, },

    // State 3
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ACCEPT}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, },

    // State 4
    {{GO, 1}, {ERROR}, {GO, 2}, {GO, 9}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {ERROR}, {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 6}, {ERROR}, {ERROR}, },

    // State 5
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 10}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, },

    // State 6
    {{ERROR}, {GO, 11}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 7
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 2}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 2}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, },

    // State 8
    {{GO, 1}, {ERROR}, {GO, 2}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {ERROR}, {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 6}, {ERROR}, {ERROR}, },

    // State 9
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, },

    // State 10
    {{ERROR}, {GO, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 11
    {{GO, 1}, {ERROR}, {GO, 19}, {ERROR}, {SHIFT, 20}, {SHIFT, 21}, {ERROR}, {SHIFT, 22}, {ERROR}, {ERROR}, 
    {SHIFT, 23}, {SHIFT, 24}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {ERROR}, {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, 
    {SHIFT, 30}, {SHIFT, 31}, {SHIFT, 32}, {SHIFT, 4}, {ERROR}, {SHIFT, 33}, {SHIFT, 5}, {ERROR}, {SHIFT, 34}, {ERROR}, 
    {SHIFT, 6}, {ERROR}, {SHIFT, 35}, },

    // State 12
    {{ERROR}, {GO, 36}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 13
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {ERROR}, {REDUCE, 10}, 
    {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {ERROR}, {REDUCE, 10}, 
    {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {ERROR}, {REDUCE, 10}, {REDUCE, 10}, 
    {REDUCE, 10}, {ERROR}, {REDUCE, 10}, },

    // State 14
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {ERROR}, {REDUCE, 9}, 
    {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {ERROR}, {REDUCE, 9}, 
    {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {ERROR}, {REDUCE, 9}, {REDUCE, 9}, 
    {REDUCE, 9}, {ERROR}, {REDUCE, 9}, },

    // State 15
    {{ERROR}, {GO, 37}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 16
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 3}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 3}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, },

    // State 17
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 6}, {REDUCE, 6}, {ERROR}, {REDUCE, 6}, {ERROR}, {ERROR}, {REDUCE, 6}, 
    {REDUCE, 6}, {ERROR}, {ERROR}, },

    // State 18
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {SHIFT, 21}, {REDUCE, 4}, {SHIFT, 22}, {ERROR}, {ERROR}, 
    {SHIFT, 23}, {SHIFT, 24}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {REDUCE, 4}, {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, 
    {SHIFT, 30}, {SHIFT, 31}, {SHIFT, 32}, {REDUCE, 4}, {REDUCE, 4}, {SHIFT, 33}, {REDUCE, 4}, {ERROR}, {SHIFT, 34}, {REDUCE, 4}, 
    {REDUCE, 4}, {ERROR}, {SHIFT, 35}, },

    // State 19
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 7}, {REDUCE, 7}, {ERROR}, {REDUCE, 7}, {ERROR}, {ERROR}, {SHIFT, 38}, 
    {REDUCE, 7}, {ERROR}, {ERROR}, },

    // State 20
    {{ERROR}, {GO, 39}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 21
    {{ERROR}, {GO, 40}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 22
    {{ERROR}, {GO, 41}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 23
    {{ERROR}, {GO, 42}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 24
    {{ERROR}, {GO, 43}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 25
    {{ERROR}, {GO, 44}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 26
    {{ERROR}, {GO, 45}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 27
    {{ERROR}, {GO, 46}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 28
    {{ERROR}, {GO, 47}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 29
    {{ERROR}, {GO, 48}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 30
    {{ERROR}, {GO, 49}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 31
    {{ERROR}, {GO, 50}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 32
    {{ERROR}, {GO, 51}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 33
    {{ERROR}, {GO, 52}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 34
    {{ERROR}, {GO, 53}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 35
    {{ERROR}, {GO, 54}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 36
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {SHIFT, 21}, {ERROR}, {SHIFT, 22}, {ERROR}, {SHIFT, 55}, 
    {SHIFT, 23}, {SHIFT, 24}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {ERROR}, {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, 
    {SHIFT, 30}, {SHIFT, 31}, {SHIFT, 32}, {ERROR}, {ERROR}, {SHIFT, 33}, {ERROR}, {ERROR}, {SHIFT, 34}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 35}, },

    // State 37
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, 
    {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, 
    {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, {REDUCE, 27}, 
    {REDUCE, 27}, {ERROR}, {REDUCE, 27}, },

    // State 38
    {{GO, 1}, {ERROR}, {GO, 56}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {ERROR}, {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 6}, {ERROR}, {ERROR}, },

    // State 39
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 18}, {SHIFT, 21}, {REDUCE, 18}, {SHIFT, 22}, {ERROR}, {REDUCE, 18}, 
    {SHIFT, 23}, {SHIFT, 24}, {SHIFT, 25}, {SHIFT, 26}, {REDUCE, 18}, {REDUCE, 18}, {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {REDUCE, 18}, 
    {SHIFT, 30}, {SHIFT, 31}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {SHIFT, 33}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, {ERROR}, {REDUCE, 18}, },

    // State 40
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {SHIFT, 22}, {ERROR}, {REDUCE, 24}, 
    {SHIFT, 23}, {SHIFT, 24}, {SHIFT, 25}, {SHIFT, 26}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, 
    {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, 
    {REDUCE, 24}, {ERROR}, {REDUCE, 24}, },

    // State 41
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, 
    {REDUCE, 16}, {ERROR}, {REDUCE, 16}, },

    // State 42
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, 
    {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, 
    {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, 
    {REDUCE, 14}, {ERROR}, {REDUCE, 14}, },

    // State 43
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {SHIFT, 22}, {ERROR}, {REDUCE, 12}, 
    {SHIFT, 23}, {REDUCE, 12}, {REDUCE, 12}, {SHIFT, 26}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, 
    {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, 
    {REDUCE, 12}, {ERROR}, {REDUCE, 12}, },

    // State 44
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {SHIFT, 22}, {ERROR}, {REDUCE, 13}, 
    {SHIFT, 23}, {REDUCE, 13}, {REDUCE, 13}, {SHIFT, 26}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, 
    {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, 
    {REDUCE, 13}, {ERROR}, {REDUCE, 13}, },

    // State 45
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, 
    {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, 
    {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, 
    {REDUCE, 15}, {ERROR}, {REDUCE, 15}, },

    // State 46
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 19}, {SHIFT, 21}, {REDUCE, 19}, {SHIFT, 22}, {ERROR}, {REDUCE, 19}, 
    {SHIFT, 23}, {SHIFT, 24}, {SHIFT, 25}, {SHIFT, 26}, {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 19}, 
    {ERROR}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {SHIFT, 33}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, 
    {REDUCE, 19}, {ERROR}, {REDUCE, 19}, },

    // State 47
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 21}, {SHIFT, 21}, {REDUCE, 21}, {SHIFT, 22}, {ERROR}, {REDUCE, 21}, 
    {SHIFT, 23}, {SHIFT, 24}, {SHIFT, 25}, {SHIFT, 26}, {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 21}, 
    {ERROR}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {SHIFT, 33}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, 
    {REDUCE, 21}, {ERROR}, {REDUCE, 21}, },

    // State 48
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 17}, {SHIFT, 21}, {REDUCE, 17}, {SHIFT, 22}, {ERROR}, {REDUCE, 17}, 
    {SHIFT, 23}, {SHIFT, 24}, {SHIFT, 25}, {SHIFT, 26}, {REDUCE, 17}, {REDUCE, 17}, {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {REDUCE, 17}, 
    {SHIFT, 30}, {SHIFT, 31}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {SHIFT, 33}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, 
    {REDUCE, 17}, {ERROR}, {REDUCE, 17}, },

    // State 49
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 20}, {SHIFT, 21}, {REDUCE, 20}, {SHIFT, 22}, {ERROR}, {REDUCE, 20}, 
    {SHIFT, 23}, {SHIFT, 24}, {SHIFT, 25}, {SHIFT, 26}, {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 20}, 
    {ERROR}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {SHIFT, 33}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, 
    {REDUCE, 20}, {ERROR}, {REDUCE, 20}, },

    // State 50
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 22}, {SHIFT, 21}, {REDUCE, 22}, {SHIFT, 22}, {ERROR}, {REDUCE, 22}, 
    {SHIFT, 23}, {SHIFT, 24}, {SHIFT, 25}, {SHIFT, 26}, {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 22}, 
    {ERROR}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {SHIFT, 33}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, 
    {REDUCE, 22}, {ERROR}, {REDUCE, 22}, },

    // State 51
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {SHIFT, 21}, {ERROR}, {SHIFT, 22}, {ERROR}, {ERROR}, 
    {SHIFT, 23}, {SHIFT, 24}, {SHIFT, 25}, {SHIFT, 26}, {SHIFT, 57}, {ERROR}, {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, 
    {SHIFT, 30}, {SHIFT, 31}, {SHIFT, 32}, {ERROR}, {ERROR}, {SHIFT, 33}, {ERROR}, {ERROR}, {SHIFT, 34}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 35}, },

    // State 52
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, {SHIFT, 22}, {ERROR}, {REDUCE, 23}, 
    {SHIFT, 23}, {SHIFT, 24}, {SHIFT, 25}, {SHIFT, 26}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, 
    {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, 
    {REDUCE, 23}, {ERROR}, {REDUCE, 23}, },

    // State 53
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {SHIFT, 21}, {REDUCE, 26}, {SHIFT, 22}, {ERROR}, {REDUCE, 26}, 
    {SHIFT, 23}, {SHIFT, 24}, {SHIFT, 25}, {SHIFT, 26}, {REDUCE, 26}, {REDUCE, 26}, {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, 
    {SHIFT, 30}, {SHIFT, 31}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {SHIFT, 33}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, {REDUCE, 26}, 
    {REDUCE, 26}, {ERROR}, {REDUCE, 26}, },

    // State 54
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {SHIFT, 21}, {REDUCE, 25}, {SHIFT, 22}, {ERROR}, {REDUCE, 25}, 
    {SHIFT, 23}, {SHIFT, 24}, {SHIFT, 25}, {SHIFT, 26}, {REDUCE, 25}, {REDUCE, 25}, {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, 
    {SHIFT, 30}, {SHIFT, 31}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {SHIFT, 33}, {REDUCE, 25}, {ERROR}, {SHIFT, 34}, {REDUCE, 25}, 
    {REDUCE, 25}, {ERROR}, {REDUCE, 25}, },

    // State 55
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {REDUCE, 11}, 
    {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {REDUCE, 11}, 
    {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, 
    {REDUCE, 11}, {ERROR}, {REDUCE, 11}, },

    // State 56
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 8}, {REDUCE, 8}, {ERROR}, {REDUCE, 8}, {ERROR}, {ERROR}, {REDUCE, 8}, 
    {REDUCE, 8}, {ERROR}, {ERROR}, },

    // State 57
    {{ERROR}, {GO, 58}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 13}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, },

    // State 58
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {SHIFT, 21}, {REDUCE, 28}, {SHIFT, 22}, {ERROR}, {REDUCE, 28}, 
    {SHIFT, 23}, {SHIFT, 24}, {SHIFT, 25}, {SHIFT, 26}, {REDUCE, 28}, {REDUCE, 28}, {SHIFT, 27}, {SHIFT, 28}, {ERROR}, {SHIFT, 29}, 
    {SHIFT, 30}, {SHIFT, 31}, {SHIFT, 32}, {REDUCE, 28}, {REDUCE, 28}, {SHIFT, 33}, {REDUCE, 28}, {ERROR}, {SHIFT, 34}, {REDUCE, 28}, 
    {REDUCE, 28}, {ERROR}, {SHIFT, 35}, },

}; // Parser::table


