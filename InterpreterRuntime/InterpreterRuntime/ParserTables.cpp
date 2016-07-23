// Generated parser tables file

#include "Parser.hpp"

//==========================================================================================================
// Table of productions info: Left-hand-side nonterminal and number of symbols on right-hand-side
//==========================================================================================================
vector<ProductionInfo> Parser::production_infos = {
    {START, 1}, {STATEMENTS, 1}, {STATEMENTS, 2}, {STATEMENTS, 3}, {STATEMENT, 3}, {STATEMENT, 1}, {BLOCK, 3}, {STATEMENT, 3}, {STATEMENT, 3}, {STATEMENT, 4}, 
    {STATEMENT, 5}, {STATEMENT, 1}, {EXP, 1}, {EXP, 1}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, 
    {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, 
    {EXP, 2}, {EXP, 5}, {EXP, 1}, {FUNC_CALL, 3}, {FUNC_CALL, 4}, {FUNC_CALL, 4}, {PARAMS_LIST, 1}, {PARAMS_LIST, 3}, {NAMED_PARAM, 3}, {NAMED_PARAMS_LIST, 1}, 
    {NAMED_PARAMS_LIST, 3}, 
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
        case 11: return extract_ast(elements);
        case 12: return new NumAST(elements);
        case 13: return new VarAST(elements);
        case 14: return extract_ast(elements);
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
        case 29: return new BopAST(elements);
        case 30: return new UopAST(elements);
        case 31: return new CondExpAST(elements);
        case 32: return extract_ast(elements);
        case 33: return new FuncAST(elements);
        case 34: return new FuncAST(elements);
        case 35: return new FuncAST(elements);
        case 36: return new ParamsAST(elements);
        case 37: return new ParamsAST(elements);
        case 38: return new NamedParamAST(elements);
        case 39: return new NamedParamsAST(elements);
        case 40: return new NamedParamsAST(elements);
    } // switch

    return nullptr;

} // Parser::gen_ast()


//==========================================================================================================
// Table of actions per (state, symbol) pair
//==========================================================================================================
vector<vector<Action>> Parser::table = {
    // State 0
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 3}, {GO, 4}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, {ERROR}, 
    {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, {ERROR}, {SHIFT, 8}, {ERROR}, 
    {SHIFT, 9}, },

    // State 1
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 5}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 5}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 5}, {REDUCE, 5}, 
    {ERROR}, {REDUCE, 5}, {ERROR}, {ERROR}, {REDUCE, 5}, {REDUCE, 5}, {ERROR}, {ERROR}, {REDUCE, 5}, {ERROR}, 
    {REDUCE, 5}, },

    // State 2
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 11}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 11}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, 
    {ERROR}, {REDUCE, 11}, {ERROR}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {ERROR}, {REDUCE, 11}, {ERROR}, 
    {REDUCE, 11}, },

    // State 3
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 3}, {GO, 10}, {ERROR}, {ERROR}, 
    {REDUCE, 1}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 11}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, {REDUCE, 1}, 
    {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, {ERROR}, {SHIFT, 8}, {ERROR}, 
    {SHIFT, 9}, },

    // State 4
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ACCEPT}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 5
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 3}, {GO, 12}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, {ERROR}, 
    {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, {ERROR}, {SHIFT, 8}, {ERROR}, 
    {SHIFT, 9}, },

    // State 6
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 13}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 7
    {{ERROR}, {GO, 15}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 8
    {{ERROR}, {GO, 21}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 9
    {{ERROR}, {GO, 22}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 10
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 2}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 2}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 11
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 3}, {GO, 23}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, {ERROR}, 
    {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, {ERROR}, {SHIFT, 8}, {ERROR}, 
    {SHIFT, 9}, },

    // State 12
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 13
    {{ERROR}, {GO, 25}, {GO, 16}, {GO, 26}, {GO, 27}, {GO, 28}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {SHIFT, 29}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 30}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 14
    {{ERROR}, {GO, 31}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 15
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 32}, {ERROR}, {SHIFT, 33}, {SHIFT, 34}, 
    {ERROR}, {SHIFT, 35}, {ERROR}, {ERROR}, {SHIFT, 36}, {SHIFT, 37}, {ERROR}, {SHIFT, 38}, {SHIFT, 39}, {ERROR}, 
    {ERROR}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {SHIFT, 44}, {SHIFT, 45}, {SHIFT, 5}, {ERROR}, 
    {SHIFT, 46}, {SHIFT, 6}, {ERROR}, {SHIFT, 47}, {ERROR}, {SHIFT, 7}, {ERROR}, {SHIFT, 48}, {SHIFT, 8}, {ERROR}, 
    {SHIFT, 9}, },

    // State 16
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, 
    {REDUCE, 32}, {REDUCE, 32}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, 
    {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, 
    {REDUCE, 32}, {REDUCE, 32}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, 
    {REDUCE, 32}, },

    // State 17
    {{ERROR}, {GO, 49}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 18
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, 
    {REDUCE, 13}, {REDUCE, 13}, {SHIFT, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, 
    {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, 
    {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, 
    {REDUCE, 13}, },

    // State 19
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, 
    {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, 
    {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, 
    {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, 
    {REDUCE, 12}, },

    // State 20
    {{ERROR}, {GO, 50}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 21
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 33}, {SHIFT, 34}, 
    {ERROR}, {SHIFT, 35}, {ERROR}, {ERROR}, {SHIFT, 36}, {SHIFT, 37}, {ERROR}, {SHIFT, 38}, {SHIFT, 39}, {ERROR}, 
    {ERROR}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {ERROR}, 
    {SHIFT, 46}, {ERROR}, {ERROR}, {SHIFT, 47}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 48}, {ERROR}, {SHIFT, 51}, 
    {ERROR}, },

    // State 22
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 52}, {ERROR}, {SHIFT, 33}, {SHIFT, 34}, 
    {ERROR}, {SHIFT, 35}, {ERROR}, {ERROR}, {SHIFT, 36}, {SHIFT, 37}, {ERROR}, {SHIFT, 38}, {SHIFT, 39}, {ERROR}, 
    {ERROR}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {SHIFT, 44}, {SHIFT, 45}, {SHIFT, 5}, {ERROR}, 
    {SHIFT, 46}, {SHIFT, 6}, {ERROR}, {SHIFT, 47}, {ERROR}, {SHIFT, 7}, {ERROR}, {SHIFT, 48}, {SHIFT, 8}, {ERROR}, 
    {SHIFT, 9}, },

    // State 23
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 3}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 3}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 24
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 6}, {REDUCE, 6}, 
    {ERROR}, {REDUCE, 6}, {ERROR}, {ERROR}, {REDUCE, 6}, {REDUCE, 6}, {ERROR}, {ERROR}, {REDUCE, 6}, {ERROR}, 
    {REDUCE, 6}, },

    // State 25
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 33}, {SHIFT, 34}, 
    {ERROR}, {SHIFT, 35}, {ERROR}, {REDUCE, 36}, {SHIFT, 36}, {SHIFT, 37}, {SHIFT, 53}, {SHIFT, 38}, {SHIFT, 39}, {ERROR}, 
    {ERROR}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {ERROR}, 
    {SHIFT, 46}, {ERROR}, {ERROR}, {SHIFT, 47}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 48}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 26
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 39}, {ERROR}, {ERROR}, {SHIFT, 54}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 27
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 55}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 28
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 56}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 29
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, 
    {REDUCE, 33}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, 
    {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, 
    {REDUCE, 33}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, 
    {REDUCE, 33}, },

    // State 30
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, 
    {REDUCE, 13}, {REDUCE, 13}, {SHIFT, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, 
    {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {SHIFT, 57}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, 
    {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, 
    {REDUCE, 13}, },

    // State 31
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 33}, {SHIFT, 34}, 
    {REDUCE, 4}, {SHIFT, 35}, {ERROR}, {ERROR}, {SHIFT, 36}, {SHIFT, 37}, {ERROR}, {SHIFT, 38}, {SHIFT, 39}, {ERROR}, 
    {REDUCE, 4}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {SHIFT, 44}, {SHIFT, 45}, {REDUCE, 4}, {REDUCE, 4}, 
    {SHIFT, 46}, {REDUCE, 4}, {ERROR}, {SHIFT, 47}, {REDUCE, 4}, {REDUCE, 4}, {ERROR}, {SHIFT, 48}, {REDUCE, 4}, {ERROR}, 
    {REDUCE, 4}, },

    // State 32
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 7}, {REDUCE, 7}, 
    {ERROR}, {REDUCE, 7}, {ERROR}, {ERROR}, {SHIFT, 58}, {REDUCE, 7}, {ERROR}, {ERROR}, {REDUCE, 7}, {ERROR}, 
    {REDUCE, 7}, },

    // State 33
    {{ERROR}, {GO, 59}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 34
    {{ERROR}, {GO, 60}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 35
    {{ERROR}, {GO, 61}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 36
    {{ERROR}, {GO, 62}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 37
    {{ERROR}, {GO, 63}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 38
    {{ERROR}, {GO, 64}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 39
    {{ERROR}, {GO, 65}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 40
    {{ERROR}, {GO, 66}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 41
    {{ERROR}, {GO, 67}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 42
    {{ERROR}, {GO, 68}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 43
    {{ERROR}, {GO, 69}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 44
    {{ERROR}, {GO, 70}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 45
    {{ERROR}, {GO, 71}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 46
    {{ERROR}, {GO, 72}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 47
    {{ERROR}, {GO, 73}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 48
    {{ERROR}, {GO, 74}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 49
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 33}, {SHIFT, 34}, 
    {ERROR}, {SHIFT, 35}, {ERROR}, {SHIFT, 75}, {SHIFT, 36}, {SHIFT, 37}, {ERROR}, {SHIFT, 38}, {SHIFT, 39}, {ERROR}, 
    {ERROR}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {ERROR}, 
    {SHIFT, 46}, {ERROR}, {ERROR}, {SHIFT, 47}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 48}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 50
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 30}, {REDUCE, 30}, 
    {REDUCE, 30}, {REDUCE, 30}, {ERROR}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, 
    {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {ERROR}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, 
    {REDUCE, 30}, {REDUCE, 30}, {ERROR}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {ERROR}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, 
    {REDUCE, 30}, },

    // State 51
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 76}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, {ERROR}, 
    {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, {ERROR}, {SHIFT, 8}, {ERROR}, 
    {SHIFT, 9}, },

    // State 52
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 8}, {REDUCE, 8}, 
    {ERROR}, {REDUCE, 8}, {ERROR}, {ERROR}, {REDUCE, 8}, {REDUCE, 8}, {ERROR}, {ERROR}, {REDUCE, 8}, {ERROR}, 
    {REDUCE, 8}, },

    // State 53
    {{ERROR}, {GO, 25}, {GO, 16}, {ERROR}, {ERROR}, {GO, 77}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 54
    {{ERROR}, {ERROR}, {ERROR}, {GO, 26}, {GO, 78}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 79}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 55
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, 
    {REDUCE, 35}, {REDUCE, 35}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, 
    {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, 
    {REDUCE, 35}, {REDUCE, 35}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, 
    {REDUCE, 35}, },

    // State 56
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, 
    {REDUCE, 34}, {REDUCE, 34}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, 
    {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, 
    {REDUCE, 34}, {REDUCE, 34}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, 
    {REDUCE, 34}, },

    // State 57
    {{ERROR}, {GO, 80}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 58
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 81}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, {ERROR}, 
    {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, {ERROR}, {SHIFT, 8}, {ERROR}, 
    {SHIFT, 9}, },

    // State 59
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 21}, {SHIFT, 34}, 
    {REDUCE, 21}, {SHIFT, 35}, {ERROR}, {REDUCE, 21}, {SHIFT, 36}, {SHIFT, 37}, {REDUCE, 21}, {SHIFT, 38}, {SHIFT, 39}, {REDUCE, 21}, 
    {REDUCE, 21}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {REDUCE, 21}, {SHIFT, 43}, {SHIFT, 44}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, 
    {SHIFT, 46}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, 
    {REDUCE, 21}, },

    // State 60
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 27}, {ERROR}, 
    {REDUCE, 27}, {SHIFT, 35}, {ERROR}, {REDUCE, 27}, {SHIFT, 36}, {SHIFT, 37}, {REDUCE, 27}, {SHIFT, 38}, {SHIFT, 39}, {REDUCE, 27}, 
    {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, 
    {ERROR}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, 
    {REDUCE, 27}, },

    // State 61
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, 
    {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, 
    {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, 
    {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, 
    {REDUCE, 19}, },

    // State 62
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, 
    {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, 
    {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, 
    {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, 
    {REDUCE, 17}, },

    // State 63
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, 
    {REDUCE, 15}, {SHIFT, 35}, {ERROR}, {REDUCE, 15}, {SHIFT, 36}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {SHIFT, 39}, {REDUCE, 15}, 
    {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, 
    {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, 
    {REDUCE, 15}, },

    // State 64
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, 
    {REDUCE, 16}, {SHIFT, 35}, {ERROR}, {REDUCE, 16}, {SHIFT, 36}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {SHIFT, 39}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, 
    {REDUCE, 16}, },

    // State 65
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, },

    // State 66
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 22}, {SHIFT, 34}, 
    {REDUCE, 22}, {SHIFT, 35}, {ERROR}, {REDUCE, 22}, {SHIFT, 36}, {SHIFT, 37}, {REDUCE, 22}, {SHIFT, 38}, {SHIFT, 39}, {REDUCE, 22}, 
    {REDUCE, 22}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 22}, {ERROR}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, 
    {SHIFT, 46}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, 
    {REDUCE, 22}, },

    // State 67
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 24}, {SHIFT, 34}, 
    {REDUCE, 24}, {SHIFT, 35}, {ERROR}, {REDUCE, 24}, {SHIFT, 36}, {SHIFT, 37}, {REDUCE, 24}, {SHIFT, 38}, {SHIFT, 39}, {REDUCE, 24}, 
    {REDUCE, 24}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 24}, {ERROR}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, 
    {SHIFT, 46}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, 
    {REDUCE, 24}, },

    // State 68
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 20}, {SHIFT, 34}, 
    {REDUCE, 20}, {SHIFT, 35}, {ERROR}, {REDUCE, 20}, {SHIFT, 36}, {SHIFT, 37}, {REDUCE, 20}, {SHIFT, 38}, {SHIFT, 39}, {REDUCE, 20}, 
    {REDUCE, 20}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {REDUCE, 20}, {SHIFT, 43}, {SHIFT, 44}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, 
    {SHIFT, 46}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, 
    {REDUCE, 20}, },

    // State 69
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 23}, {SHIFT, 34}, 
    {REDUCE, 23}, {SHIFT, 35}, {ERROR}, {REDUCE, 23}, {SHIFT, 36}, {SHIFT, 37}, {REDUCE, 23}, {SHIFT, 38}, {SHIFT, 39}, {REDUCE, 23}, 
    {REDUCE, 23}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 23}, {ERROR}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, 
    {SHIFT, 46}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, 
    {REDUCE, 23}, },

    // State 70
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 25}, {SHIFT, 34}, 
    {REDUCE, 25}, {SHIFT, 35}, {ERROR}, {REDUCE, 25}, {SHIFT, 36}, {SHIFT, 37}, {REDUCE, 25}, {SHIFT, 38}, {SHIFT, 39}, {REDUCE, 25}, 
    {REDUCE, 25}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 25}, {ERROR}, {ERROR}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, 
    {SHIFT, 46}, {REDUCE, 25}, {ERROR}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {ERROR}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, 
    {REDUCE, 25}, },

    // State 71
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 33}, {SHIFT, 34}, 
    {ERROR}, {SHIFT, 35}, {ERROR}, {ERROR}, {SHIFT, 36}, {SHIFT, 37}, {ERROR}, {SHIFT, 38}, {SHIFT, 39}, {SHIFT, 82}, 
    {ERROR}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {ERROR}, 
    {SHIFT, 46}, {ERROR}, {ERROR}, {SHIFT, 47}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 48}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 72
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 26}, {ERROR}, 
    {REDUCE, 26}, {SHIFT, 35}, {ERROR}, {REDUCE, 26}, {SHIFT, 36}, {SHIFT, 37}, {REDUCE, 26}, {SHIFT, 38}, {SHIFT, 39}, {REDUCE, 26}, 
    {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, 
    {ERROR}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, 
    {REDUCE, 26}, },

    // State 73
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 33}, {SHIFT, 34}, 
    {REDUCE, 29}, {SHIFT, 35}, {ERROR}, {REDUCE, 29}, {SHIFT, 36}, {SHIFT, 37}, {REDUCE, 29}, {SHIFT, 38}, {SHIFT, 39}, {REDUCE, 29}, 
    {REDUCE, 29}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {SHIFT, 44}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, 
    {SHIFT, 46}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, 
    {REDUCE, 29}, },

    // State 74
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 33}, {SHIFT, 34}, 
    {REDUCE, 28}, {SHIFT, 35}, {ERROR}, {REDUCE, 28}, {SHIFT, 36}, {SHIFT, 37}, {REDUCE, 28}, {SHIFT, 38}, {SHIFT, 39}, {REDUCE, 28}, 
    {REDUCE, 28}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {SHIFT, 44}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, 
    {SHIFT, 46}, {REDUCE, 28}, {ERROR}, {SHIFT, 47}, {REDUCE, 28}, {REDUCE, 28}, {ERROR}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, 
    {REDUCE, 28}, },

    // State 75
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, 
    {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, 
    {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, 
    {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, 
    {REDUCE, 14}, },

    // State 76
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 9}, {REDUCE, 9}, 
    {ERROR}, {REDUCE, 9}, {ERROR}, {ERROR}, {REDUCE, 9}, {REDUCE, 9}, {ERROR}, {ERROR}, {REDUCE, 9}, {ERROR}, 
    {REDUCE, 9}, },

    // State 77
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 37}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 78
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 40}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 79
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 57}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 80
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 33}, {SHIFT, 34}, 
    {ERROR}, {SHIFT, 35}, {ERROR}, {REDUCE, 38}, {SHIFT, 36}, {SHIFT, 37}, {REDUCE, 38}, {SHIFT, 38}, {SHIFT, 39}, {ERROR}, 
    {ERROR}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {ERROR}, 
    {SHIFT, 46}, {ERROR}, {ERROR}, {SHIFT, 47}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 48}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 81
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 10}, {REDUCE, 10}, 
    {ERROR}, {REDUCE, 10}, {ERROR}, {ERROR}, {REDUCE, 10}, {REDUCE, 10}, {ERROR}, {ERROR}, {REDUCE, 10}, {ERROR}, 
    {REDUCE, 10}, },

    // State 82
    {{ERROR}, {GO, 83}, {GO, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, },

    // State 83
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 33}, {SHIFT, 34}, 
    {REDUCE, 31}, {SHIFT, 35}, {ERROR}, {REDUCE, 31}, {SHIFT, 36}, {SHIFT, 37}, {REDUCE, 31}, {SHIFT, 38}, {SHIFT, 39}, {REDUCE, 31}, 
    {REDUCE, 31}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {SHIFT, 44}, {SHIFT, 45}, {REDUCE, 31}, {REDUCE, 31}, 
    {SHIFT, 46}, {REDUCE, 31}, {ERROR}, {SHIFT, 47}, {REDUCE, 31}, {REDUCE, 31}, {ERROR}, {SHIFT, 48}, {REDUCE, 31}, {REDUCE, 31}, 
    {REDUCE, 31}, },

}; // Parser::table


