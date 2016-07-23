// Generated parser tables file

#include "Parser.hpp"

//==========================================================================================================
// Table of productions info: Left-hand-side nonterminal and number of symbols on right-hand-side
//==========================================================================================================
vector<ProductionInfo> Parser::production_infos = {
    {START, 1}, {STATEMENTS, 1}, {STATEMENTS, 2}, {STATEMENTS, 3}, {STATEMENT, 3}, {STATEMENT, 1}, {BLOCK, 3}, {STATEMENT, 3}, {STATEMENT, 3}, {STATEMENT, 4}, 
    {STATEMENT, 5}, {EXP, 1}, {EXP, 1}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, 
    {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 2}, 
    {EXP, 5}, {EXP, 1}, {FUNC_CALL, 3}, {FUNC_CALL, 4}, {FUNC_CALL, 4}, {PARAMS_LIST, 1}, {PARAMS_LIST, 3}, {NAMED_PARAM, 3}, {NAMED_PARAMS_LIST, 1}, {NAMED_PARAMS_LIST, 3}, 
    
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
        case 31: return extract_ast(elements);
        case 32: return new FuncAST(elements);
        case 33: return new FuncAST(elements);
        case 34: return new FuncAST(elements);
        case 35: return new ParamsAST(elements);
        case 36: return new ParamsAST(elements);
        case 37: return new NamedParamAST(elements);
        case 38: return new NamedParamsAST(elements);
        case 39: return new NamedParamsAST(elements);
    } // switch

    return nullptr;

} // Parser::gen_ast()


//==========================================================================================================
// Table of actions per (state, symbol) pair
//==========================================================================================================
vector<vector<Action>> Parser::table = {
    // State 0
    {{GO, 1}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {GO, 2}, {GO, 3}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {ERROR}, 
    {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, 
    {SHIFT, 8}, },

    // State 1
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 5}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 5}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 5}, {REDUCE, 5}, 
    {ERROR}, {REDUCE, 5}, {ERROR}, {ERROR}, {REDUCE, 5}, {REDUCE, 5}, {ERROR}, {ERROR}, {REDUCE, 5}, {ERROR}, 
    {REDUCE, 5}, },

    // State 2
    {{GO, 1}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {GO, 2}, {GO, 9}, {ERROR}, {ERROR}, 
    {REDUCE, 1}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 10}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {REDUCE, 1}, 
    {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, 
    {SHIFT, 8}, },

    // State 3
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ACCEPT}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 4
    {{GO, 1}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {GO, 2}, {GO, 11}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {ERROR}, 
    {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, 
    {SHIFT, 8}, },

    // State 5
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 12}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 6
    {{ERROR}, {GO, 13}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 7
    {{ERROR}, {GO, 19}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 8
    {{ERROR}, {GO, 20}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 9
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 2}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 2}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 10
    {{GO, 1}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {GO, 2}, {GO, 21}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {ERROR}, 
    {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, 
    {SHIFT, 8}, },

    // State 11
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 22}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 12
    {{ERROR}, {GO, 23}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 13
    {{GO, 1}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {GO, 24}, {ERROR}, {SHIFT, 25}, {SHIFT, 26}, 
    {ERROR}, {SHIFT, 27}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {ERROR}, {SHIFT, 30}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {SHIFT, 32}, {SHIFT, 33}, {ERROR}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {SHIFT, 37}, {SHIFT, 4}, {ERROR}, 
    {SHIFT, 38}, {SHIFT, 5}, {ERROR}, {SHIFT, 39}, {ERROR}, {SHIFT, 6}, {ERROR}, {SHIFT, 40}, {SHIFT, 7}, {ERROR}, 
    {SHIFT, 8}, },

    // State 14
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 31}, {REDUCE, 31}, 
    {REDUCE, 31}, {REDUCE, 31}, {ERROR}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, 
    {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {ERROR}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, 
    {REDUCE, 31}, {REDUCE, 31}, {ERROR}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {ERROR}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, 
    {REDUCE, 31}, },

    // State 15
    {{ERROR}, {GO, 41}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 16
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, 
    {REDUCE, 12}, {REDUCE, 12}, {SHIFT, 42}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, 
    {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, 
    {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, 
    {REDUCE, 12}, },

    // State 17
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, 
    {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, 
    {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, 
    {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, 
    {REDUCE, 11}, },

    // State 18
    {{ERROR}, {GO, 43}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 19
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 25}, {SHIFT, 26}, 
    {ERROR}, {SHIFT, 27}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {ERROR}, {SHIFT, 30}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {SHIFT, 32}, {SHIFT, 33}, {ERROR}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {SHIFT, 37}, {ERROR}, {ERROR}, 
    {SHIFT, 38}, {ERROR}, {ERROR}, {SHIFT, 39}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 40}, {ERROR}, {SHIFT, 44}, 
    {ERROR}, },

    // State 20
    {{GO, 1}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {GO, 45}, {ERROR}, {SHIFT, 25}, {SHIFT, 26}, 
    {ERROR}, {SHIFT, 27}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {ERROR}, {SHIFT, 30}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {SHIFT, 32}, {SHIFT, 33}, {ERROR}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {SHIFT, 37}, {SHIFT, 4}, {ERROR}, 
    {SHIFT, 38}, {SHIFT, 5}, {ERROR}, {SHIFT, 39}, {ERROR}, {SHIFT, 6}, {ERROR}, {SHIFT, 40}, {SHIFT, 7}, {ERROR}, 
    {SHIFT, 8}, },

    // State 21
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 3}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 3}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 22
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 6}, {REDUCE, 6}, 
    {ERROR}, {REDUCE, 6}, {ERROR}, {ERROR}, {REDUCE, 6}, {REDUCE, 6}, {ERROR}, {ERROR}, {REDUCE, 6}, {ERROR}, 
    {REDUCE, 6}, },

    // State 23
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 25}, {SHIFT, 26}, 
    {REDUCE, 4}, {SHIFT, 27}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {ERROR}, {SHIFT, 30}, {SHIFT, 31}, {ERROR}, 
    {REDUCE, 4}, {SHIFT, 32}, {SHIFT, 33}, {ERROR}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {SHIFT, 37}, {REDUCE, 4}, {REDUCE, 4}, 
    {SHIFT, 38}, {REDUCE, 4}, {ERROR}, {SHIFT, 39}, {REDUCE, 4}, {REDUCE, 4}, {ERROR}, {SHIFT, 40}, {REDUCE, 4}, {ERROR}, 
    {REDUCE, 4}, },

    // State 24
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 7}, {REDUCE, 7}, 
    {ERROR}, {REDUCE, 7}, {ERROR}, {ERROR}, {SHIFT, 46}, {REDUCE, 7}, {ERROR}, {ERROR}, {REDUCE, 7}, {ERROR}, 
    {REDUCE, 7}, },

    // State 25
    {{ERROR}, {GO, 47}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 26
    {{ERROR}, {GO, 48}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 27
    {{ERROR}, {GO, 49}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 28
    {{ERROR}, {GO, 50}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 29
    {{ERROR}, {GO, 51}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 30
    {{ERROR}, {GO, 52}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 31
    {{ERROR}, {GO, 53}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 32
    {{ERROR}, {GO, 54}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 33
    {{ERROR}, {GO, 55}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 34
    {{ERROR}, {GO, 56}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 35
    {{ERROR}, {GO, 57}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 36
    {{ERROR}, {GO, 58}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 37
    {{ERROR}, {GO, 59}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 38
    {{ERROR}, {GO, 60}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 39
    {{ERROR}, {GO, 61}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 40
    {{ERROR}, {GO, 62}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 41
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 25}, {SHIFT, 26}, 
    {ERROR}, {SHIFT, 27}, {ERROR}, {SHIFT, 63}, {SHIFT, 28}, {SHIFT, 29}, {ERROR}, {SHIFT, 30}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {SHIFT, 32}, {SHIFT, 33}, {ERROR}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {SHIFT, 37}, {ERROR}, {ERROR}, 
    {SHIFT, 38}, {ERROR}, {ERROR}, {SHIFT, 39}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 40}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 42
    {{ERROR}, {GO, 64}, {GO, 14}, {GO, 65}, {GO, 66}, {GO, 67}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {SHIFT, 68}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 69}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 43
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, 
    {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, 
    {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, 
    {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, 
    {REDUCE, 29}, },

    // State 44
    {{GO, 1}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {GO, 70}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {ERROR}, 
    {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, 
    {SHIFT, 8}, },

    // State 45
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 8}, {REDUCE, 8}, 
    {ERROR}, {REDUCE, 8}, {ERROR}, {ERROR}, {REDUCE, 8}, {REDUCE, 8}, {ERROR}, {ERROR}, {REDUCE, 8}, {ERROR}, 
    {REDUCE, 8}, },

    // State 46
    {{GO, 1}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {GO, 71}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {ERROR}, 
    {ERROR}, {SHIFT, 5}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, 
    {SHIFT, 8}, },

    // State 47
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 20}, {SHIFT, 26}, 
    {REDUCE, 20}, {SHIFT, 27}, {ERROR}, {REDUCE, 20}, {SHIFT, 28}, {SHIFT, 29}, {REDUCE, 20}, {SHIFT, 30}, {SHIFT, 31}, {REDUCE, 20}, 
    {REDUCE, 20}, {SHIFT, 32}, {SHIFT, 33}, {ERROR}, {REDUCE, 20}, {SHIFT, 35}, {SHIFT, 36}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, 
    {SHIFT, 38}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, 
    {REDUCE, 20}, },

    // State 48
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 26}, {ERROR}, 
    {REDUCE, 26}, {SHIFT, 27}, {ERROR}, {REDUCE, 26}, {SHIFT, 28}, {SHIFT, 29}, {REDUCE, 26}, {SHIFT, 30}, {SHIFT, 31}, {REDUCE, 26}, 
    {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, 
    {ERROR}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, 
    {REDUCE, 26}, },

    // State 49
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, },

    // State 50
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, 
    {REDUCE, 16}, },

    // State 51
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, 
    {REDUCE, 14}, {SHIFT, 27}, {ERROR}, {REDUCE, 14}, {SHIFT, 28}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {SHIFT, 31}, {REDUCE, 14}, 
    {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, 
    {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, 
    {REDUCE, 14}, },

    // State 52
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, 
    {REDUCE, 15}, {SHIFT, 27}, {ERROR}, {REDUCE, 15}, {SHIFT, 28}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {SHIFT, 31}, {REDUCE, 15}, 
    {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, 
    {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, 
    {REDUCE, 15}, },

    // State 53
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, 
    {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, 
    {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, 
    {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, 
    {REDUCE, 17}, },

    // State 54
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 21}, {SHIFT, 26}, 
    {REDUCE, 21}, {SHIFT, 27}, {ERROR}, {REDUCE, 21}, {SHIFT, 28}, {SHIFT, 29}, {REDUCE, 21}, {SHIFT, 30}, {SHIFT, 31}, {REDUCE, 21}, 
    {REDUCE, 21}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 21}, {ERROR}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, 
    {SHIFT, 38}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, 
    {REDUCE, 21}, },

    // State 55
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 23}, {SHIFT, 26}, 
    {REDUCE, 23}, {SHIFT, 27}, {ERROR}, {REDUCE, 23}, {SHIFT, 28}, {SHIFT, 29}, {REDUCE, 23}, {SHIFT, 30}, {SHIFT, 31}, {REDUCE, 23}, 
    {REDUCE, 23}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 23}, {ERROR}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, 
    {SHIFT, 38}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, 
    {REDUCE, 23}, },

    // State 56
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 19}, {SHIFT, 26}, 
    {REDUCE, 19}, {SHIFT, 27}, {ERROR}, {REDUCE, 19}, {SHIFT, 28}, {SHIFT, 29}, {REDUCE, 19}, {SHIFT, 30}, {SHIFT, 31}, {REDUCE, 19}, 
    {REDUCE, 19}, {SHIFT, 32}, {SHIFT, 33}, {ERROR}, {REDUCE, 19}, {SHIFT, 35}, {SHIFT, 36}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, 
    {SHIFT, 38}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, 
    {REDUCE, 19}, },

    // State 57
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 22}, {SHIFT, 26}, 
    {REDUCE, 22}, {SHIFT, 27}, {ERROR}, {REDUCE, 22}, {SHIFT, 28}, {SHIFT, 29}, {REDUCE, 22}, {SHIFT, 30}, {SHIFT, 31}, {REDUCE, 22}, 
    {REDUCE, 22}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 22}, {ERROR}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, 
    {SHIFT, 38}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, 
    {REDUCE, 22}, },

    // State 58
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 24}, {SHIFT, 26}, 
    {REDUCE, 24}, {SHIFT, 27}, {ERROR}, {REDUCE, 24}, {SHIFT, 28}, {SHIFT, 29}, {REDUCE, 24}, {SHIFT, 30}, {SHIFT, 31}, {REDUCE, 24}, 
    {REDUCE, 24}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 24}, {ERROR}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, 
    {SHIFT, 38}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, 
    {REDUCE, 24}, },

    // State 59
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 25}, {SHIFT, 26}, 
    {ERROR}, {SHIFT, 27}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {ERROR}, {SHIFT, 30}, {SHIFT, 31}, {SHIFT, 72}, 
    {ERROR}, {SHIFT, 32}, {SHIFT, 33}, {ERROR}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {SHIFT, 37}, {ERROR}, {ERROR}, 
    {SHIFT, 38}, {ERROR}, {ERROR}, {SHIFT, 39}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 40}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 60
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 25}, {ERROR}, 
    {REDUCE, 25}, {SHIFT, 27}, {ERROR}, {REDUCE, 25}, {SHIFT, 28}, {SHIFT, 29}, {REDUCE, 25}, {SHIFT, 30}, {SHIFT, 31}, {REDUCE, 25}, 
    {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {ERROR}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, 
    {ERROR}, {REDUCE, 25}, {ERROR}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {ERROR}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, 
    {REDUCE, 25}, },

    // State 61
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 25}, {SHIFT, 26}, 
    {REDUCE, 28}, {SHIFT, 27}, {ERROR}, {REDUCE, 28}, {SHIFT, 28}, {SHIFT, 29}, {REDUCE, 28}, {SHIFT, 30}, {SHIFT, 31}, {REDUCE, 28}, 
    {REDUCE, 28}, {SHIFT, 32}, {SHIFT, 33}, {ERROR}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, 
    {SHIFT, 38}, {REDUCE, 28}, {ERROR}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {ERROR}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, 
    {REDUCE, 28}, },

    // State 62
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 25}, {SHIFT, 26}, 
    {REDUCE, 27}, {SHIFT, 27}, {ERROR}, {REDUCE, 27}, {SHIFT, 28}, {SHIFT, 29}, {REDUCE, 27}, {SHIFT, 30}, {SHIFT, 31}, {REDUCE, 27}, 
    {REDUCE, 27}, {SHIFT, 32}, {SHIFT, 33}, {ERROR}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, 
    {SHIFT, 38}, {REDUCE, 27}, {ERROR}, {SHIFT, 39}, {REDUCE, 27}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, 
    {REDUCE, 27}, },

    // State 63
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, 
    {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, 
    {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, 
    {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, 
    {REDUCE, 13}, },

    // State 64
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 25}, {SHIFT, 26}, 
    {ERROR}, {SHIFT, 27}, {ERROR}, {REDUCE, 35}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 73}, {SHIFT, 30}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {SHIFT, 32}, {SHIFT, 33}, {ERROR}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {SHIFT, 37}, {ERROR}, {ERROR}, 
    {SHIFT, 38}, {ERROR}, {ERROR}, {SHIFT, 39}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 40}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 65
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 38}, {ERROR}, {ERROR}, {SHIFT, 74}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 66
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 75}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 67
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 76}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 68
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, 
    {REDUCE, 32}, {REDUCE, 32}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, 
    {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, 
    {REDUCE, 32}, {REDUCE, 32}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, 
    {REDUCE, 32}, },

    // State 69
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, 
    {REDUCE, 12}, {REDUCE, 12}, {SHIFT, 42}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, 
    {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {SHIFT, 77}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, 
    {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, 
    {REDUCE, 12}, },

    // State 70
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 9}, {REDUCE, 9}, 
    {ERROR}, {REDUCE, 9}, {ERROR}, {ERROR}, {REDUCE, 9}, {REDUCE, 9}, {ERROR}, {ERROR}, {REDUCE, 9}, {ERROR}, 
    {REDUCE, 9}, },

    // State 71
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 10}, {REDUCE, 10}, 
    {ERROR}, {REDUCE, 10}, {ERROR}, {ERROR}, {REDUCE, 10}, {REDUCE, 10}, {ERROR}, {ERROR}, {REDUCE, 10}, {ERROR}, 
    {REDUCE, 10}, },

    // State 72
    {{ERROR}, {GO, 78}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 73
    {{ERROR}, {GO, 64}, {GO, 14}, {ERROR}, {ERROR}, {GO, 79}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 74
    {{ERROR}, {ERROR}, {ERROR}, {GO, 65}, {GO, 80}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 81}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 75
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, 
    {REDUCE, 34}, {REDUCE, 34}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, 
    {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, 
    {REDUCE, 34}, {REDUCE, 34}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, 
    {REDUCE, 34}, },

    // State 76
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, 
    {REDUCE, 33}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, 
    {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, 
    {REDUCE, 33}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, 
    {REDUCE, 33}, },

    // State 77
    {{ERROR}, {GO, 82}, {GO, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 78
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 25}, {SHIFT, 26}, 
    {REDUCE, 30}, {SHIFT, 27}, {ERROR}, {REDUCE, 30}, {SHIFT, 28}, {SHIFT, 29}, {REDUCE, 30}, {SHIFT, 30}, {SHIFT, 31}, {REDUCE, 30}, 
    {REDUCE, 30}, {SHIFT, 32}, {SHIFT, 33}, {ERROR}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {SHIFT, 37}, {REDUCE, 30}, {REDUCE, 30}, 
    {SHIFT, 38}, {REDUCE, 30}, {ERROR}, {SHIFT, 39}, {REDUCE, 30}, {REDUCE, 30}, {ERROR}, {SHIFT, 40}, {REDUCE, 30}, {REDUCE, 30}, 
    {REDUCE, 30}, },

    // State 79
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 36}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 80
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 39}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 81
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 77}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 82
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 25}, {SHIFT, 26}, 
    {ERROR}, {SHIFT, 27}, {ERROR}, {REDUCE, 37}, {SHIFT, 28}, {SHIFT, 29}, {REDUCE, 37}, {SHIFT, 30}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {SHIFT, 32}, {SHIFT, 33}, {ERROR}, {SHIFT, 34}, {SHIFT, 35}, {SHIFT, 36}, {SHIFT, 37}, {ERROR}, {ERROR}, 
    {SHIFT, 38}, {ERROR}, {ERROR}, {SHIFT, 39}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 40}, {ERROR}, {ERROR}, 
    {ERROR}, },

}; // Parser::table


