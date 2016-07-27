// Generated parser tables file

#include "Parser.hpp"

//==========================================================================================================
// Table of productions info: Left-hand-side nonterminal and number of symbols on right-hand-side
//==========================================================================================================
vector<ProductionInfo> Parser::production_infos = {
    {START, 1}, {STATEMENTS, 1}, {STATEMENTS, 2}, {STATEMENTS, 3}, {STATEMENT, 3}, {STATEMENT, 3}, {STATEMENT, 1}, {BLOCK, 3}, {STATEMENT, 3}, {STATEMENT, 3}, 
    {STATEMENT, 4}, {STATEMENT, 5}, {STATEMENT, 1}, {EXP, 1}, {EXP, 1}, {EXP, 1}, {EXP, 1}, {EXP, 3}, {EXP, 3}, {EXP, 3}, 
    {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, 
    {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 2}, {EXP, 5}, {EXP, 1}, {FUNC_CALL, 3}, {FUNC_CALL, 4}, {FUNC_CALL, 4}, {PARAMS_LIST, 1}, 
    {PARAMS_LIST, 3}, {NAMED_PARAM, 3}, {NAMED_PARAMS_LIST, 1}, {NAMED_PARAMS_LIST, 3}, 
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
        case 5: return new AssignmentAST(elements);
        case 6: return new StatementsAST(elements);
        case 7: return new StatementsAST(elements);
        case 8: return new IfAST(elements);
        case 9: return new WhileAST(elements);
        case 10: return new RepeatAST(elements);
        case 11: return new IfElseAST(elements);
        case 12: return extract_ast(elements);
        case 13: return new NumAST(elements);
        case 14: return new BoolAST(elements);
        case 15: return new StringAST(elements);
        case 16: return new VarAST(elements);
        case 17: return extract_ast(elements);
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
        case 30: return new BopAST(elements);
        case 31: return new BopAST(elements);
        case 32: return new BopAST(elements);
        case 33: return new UopAST(elements);
        case 34: return new CondExpAST(elements);
        case 35: return extract_ast(elements);
        case 36: return new FuncAST(elements);
        case 37: return new FuncAST(elements);
        case 38: return new FuncAST(elements);
        case 39: return new ParamsAST(elements);
        case 40: return new ParamsAST(elements);
        case 41: return new NamedParamAST(elements);
        case 42: return new NamedParamsAST(elements);
        case 43: return new NamedParamsAST(elements);
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
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, 
    {ERROR}, {SHIFT, 8}, {ERROR}, {SHIFT, 9}, },

    // State 1
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 6}, 
    {REDUCE, 6}, {ERROR}, {ERROR}, {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 6}, {REDUCE, 6}, {ERROR}, 
    {ERROR}, {REDUCE, 6}, {ERROR}, {REDUCE, 6}, },

    // State 2
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 12}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 12}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 12}, 
    {REDUCE, 12}, {ERROR}, {ERROR}, {REDUCE, 12}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {ERROR}, 
    {ERROR}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, },

    // State 3
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 3}, {GO, 10}, {ERROR}, {ERROR}, 
    {REDUCE, 1}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 11}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, 
    {REDUCE, 1}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, 
    {ERROR}, {SHIFT, 8}, {ERROR}, {SHIFT, 9}, },

    // State 4
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ACCEPT}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 5
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 3}, {GO, 12}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, 
    {ERROR}, {SHIFT, 8}, {ERROR}, {SHIFT, 9}, },

    // State 6
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 13}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 7
    {{ERROR}, {GO, 16}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 8
    {{ERROR}, {GO, 24}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 9
    {{ERROR}, {GO, 25}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 10
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 2}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 2}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 11
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 3}, {GO, 26}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, 
    {ERROR}, {SHIFT, 8}, {ERROR}, {SHIFT, 9}, },

    // State 12
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 27}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 13
    {{ERROR}, {GO, 28}, {GO, 17}, {GO, 29}, {GO, 30}, {GO, 31}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 33}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 14
    {{ERROR}, {GO, 34}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 15
    {{ERROR}, {GO, 35}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 16
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 36}, {ERROR}, {SHIFT, 37}, {SHIFT, 38}, 
    {ERROR}, {SHIFT, 39}, {ERROR}, {ERROR}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {ERROR}, 
    {ERROR}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {SHIFT, 48}, {SHIFT, 49}, {ERROR}, {SHIFT, 5}, 
    {ERROR}, {SHIFT, 50}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 51}, {ERROR}, {SHIFT, 7}, {ERROR}, 
    {SHIFT, 52}, {SHIFT, 8}, {ERROR}, {SHIFT, 9}, },

    // State 17
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, 
    {REDUCE, 35}, {REDUCE, 35}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, 
    {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {ERROR}, {REDUCE, 35}, 
    {REDUCE, 35}, {REDUCE, 35}, {ERROR}, {REDUCE, 35}, {ERROR}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {ERROR}, 
    {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, },

    // State 18
    {{ERROR}, {GO, 53}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 19
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, 
    {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, 
    {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, 
    {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, {ERROR}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, 
    {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, },

    // State 20
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {SHIFT, 13}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {ERROR}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, 
    {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, },

    // State 21
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, 
    {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, 
    {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, 
    {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, {ERROR}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, 
    {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, },

    // State 22
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, 
    {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, 
    {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, 
    {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {ERROR}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, 
    {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, },

    // State 23
    {{ERROR}, {GO, 54}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 24
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 37}, {SHIFT, 38}, 
    {ERROR}, {SHIFT, 39}, {ERROR}, {ERROR}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {ERROR}, 
    {ERROR}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {SHIFT, 48}, {SHIFT, 49}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 50}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 51}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 52}, {ERROR}, {SHIFT, 55}, {ERROR}, },

    // State 25
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 56}, {ERROR}, {SHIFT, 37}, {SHIFT, 38}, 
    {ERROR}, {SHIFT, 39}, {ERROR}, {ERROR}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {ERROR}, 
    {ERROR}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {SHIFT, 48}, {SHIFT, 49}, {ERROR}, {SHIFT, 5}, 
    {ERROR}, {SHIFT, 50}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 51}, {ERROR}, {SHIFT, 7}, {ERROR}, 
    {SHIFT, 52}, {SHIFT, 8}, {ERROR}, {SHIFT, 9}, },

    // State 26
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 3}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 3}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 27
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 7}, 
    {REDUCE, 7}, {ERROR}, {ERROR}, {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 7}, {REDUCE, 7}, {ERROR}, 
    {ERROR}, {REDUCE, 7}, {ERROR}, {REDUCE, 7}, },

    // State 28
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 37}, {SHIFT, 38}, 
    {ERROR}, {SHIFT, 39}, {ERROR}, {REDUCE, 39}, {SHIFT, 40}, {SHIFT, 41}, {SHIFT, 57}, {SHIFT, 42}, {SHIFT, 43}, {ERROR}, 
    {ERROR}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {SHIFT, 48}, {SHIFT, 49}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 50}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 51}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 52}, {ERROR}, {ERROR}, {ERROR}, },

    // State 29
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 42}, {ERROR}, {ERROR}, {SHIFT, 58}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 30
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 59}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 31
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 60}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 32
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 36}, {REDUCE, 36}, 
    {REDUCE, 36}, {REDUCE, 36}, {ERROR}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, 
    {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {ERROR}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {ERROR}, {REDUCE, 36}, 
    {REDUCE, 36}, {REDUCE, 36}, {ERROR}, {REDUCE, 36}, {ERROR}, {ERROR}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {ERROR}, 
    {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, },

    // State 33
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {SHIFT, 13}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {SHIFT, 61}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {ERROR}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, 
    {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, },

    // State 34
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 37}, {SHIFT, 38}, 
    {REDUCE, 4}, {SHIFT, 39}, {ERROR}, {ERROR}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {ERROR}, 
    {REDUCE, 4}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {SHIFT, 48}, {SHIFT, 49}, {ERROR}, {REDUCE, 4}, 
    {REDUCE, 4}, {SHIFT, 50}, {ERROR}, {REDUCE, 4}, {ERROR}, {ERROR}, {SHIFT, 51}, {REDUCE, 4}, {REDUCE, 4}, {ERROR}, 
    {SHIFT, 52}, {REDUCE, 4}, {ERROR}, {REDUCE, 4}, },

    // State 35
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 37}, {SHIFT, 38}, 
    {REDUCE, 5}, {SHIFT, 39}, {ERROR}, {ERROR}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {ERROR}, 
    {REDUCE, 5}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {SHIFT, 48}, {SHIFT, 49}, {ERROR}, {REDUCE, 5}, 
    {REDUCE, 5}, {SHIFT, 50}, {ERROR}, {REDUCE, 5}, {ERROR}, {ERROR}, {SHIFT, 51}, {REDUCE, 5}, {REDUCE, 5}, {ERROR}, 
    {SHIFT, 52}, {REDUCE, 5}, {ERROR}, {REDUCE, 5}, },

    // State 36
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 8}, 
    {REDUCE, 8}, {ERROR}, {ERROR}, {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 62}, {REDUCE, 8}, {ERROR}, 
    {ERROR}, {REDUCE, 8}, {ERROR}, {REDUCE, 8}, },

    // State 37
    {{ERROR}, {GO, 63}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 38
    {{ERROR}, {GO, 64}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 39
    {{ERROR}, {GO, 65}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 40
    {{ERROR}, {GO, 66}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 41
    {{ERROR}, {GO, 67}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 42
    {{ERROR}, {GO, 68}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 43
    {{ERROR}, {GO, 69}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 44
    {{ERROR}, {GO, 70}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 45
    {{ERROR}, {GO, 71}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 46
    {{ERROR}, {GO, 72}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 47
    {{ERROR}, {GO, 73}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 48
    {{ERROR}, {GO, 74}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 49
    {{ERROR}, {GO, 75}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 50
    {{ERROR}, {GO, 76}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 51
    {{ERROR}, {GO, 77}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 52
    {{ERROR}, {GO, 78}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 53
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 37}, {SHIFT, 38}, 
    {ERROR}, {SHIFT, 39}, {ERROR}, {SHIFT, 79}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {ERROR}, 
    {ERROR}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {SHIFT, 48}, {SHIFT, 49}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 50}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 51}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 52}, {ERROR}, {ERROR}, {ERROR}, },

    // State 54
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, 
    {REDUCE, 33}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, 
    {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, 
    {REDUCE, 33}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {ERROR}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {ERROR}, 
    {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, },

    // State 55
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 80}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, 
    {ERROR}, {SHIFT, 8}, {ERROR}, {SHIFT, 9}, },

    // State 56
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 9}, 
    {REDUCE, 9}, {ERROR}, {ERROR}, {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 9}, {REDUCE, 9}, {ERROR}, 
    {ERROR}, {REDUCE, 9}, {ERROR}, {REDUCE, 9}, },

    // State 57
    {{ERROR}, {GO, 28}, {GO, 17}, {ERROR}, {ERROR}, {GO, 81}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 58
    {{ERROR}, {ERROR}, {ERROR}, {GO, 29}, {GO, 82}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 83}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 59
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 38}, {REDUCE, 38}, 
    {REDUCE, 38}, {REDUCE, 38}, {ERROR}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, 
    {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {ERROR}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {ERROR}, {REDUCE, 38}, 
    {REDUCE, 38}, {REDUCE, 38}, {ERROR}, {REDUCE, 38}, {ERROR}, {ERROR}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {ERROR}, 
    {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, },

    // State 60
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 37}, {REDUCE, 37}, 
    {REDUCE, 37}, {REDUCE, 37}, {ERROR}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, 
    {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {ERROR}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {ERROR}, {REDUCE, 37}, 
    {REDUCE, 37}, {REDUCE, 37}, {ERROR}, {REDUCE, 37}, {ERROR}, {ERROR}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {ERROR}, 
    {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, },

    // State 61
    {{ERROR}, {GO, 84}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 62
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 85}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {ERROR}, 
    {ERROR}, {SHIFT, 8}, {ERROR}, {SHIFT, 9}, },

    // State 63
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 24}, {SHIFT, 38}, 
    {REDUCE, 24}, {SHIFT, 39}, {ERROR}, {REDUCE, 24}, {SHIFT, 40}, {SHIFT, 41}, {REDUCE, 24}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 24}, 
    {REDUCE, 24}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {REDUCE, 24}, {SHIFT, 47}, {SHIFT, 48}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, 
    {REDUCE, 24}, {SHIFT, 50}, {ERROR}, {REDUCE, 24}, {ERROR}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {ERROR}, 
    {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, },

    // State 64
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 30}, {ERROR}, 
    {REDUCE, 30}, {SHIFT, 39}, {ERROR}, {REDUCE, 30}, {SHIFT, 40}, {SHIFT, 41}, {REDUCE, 30}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 30}, 
    {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {ERROR}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {ERROR}, {REDUCE, 30}, 
    {REDUCE, 30}, {ERROR}, {ERROR}, {REDUCE, 30}, {ERROR}, {ERROR}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {ERROR}, 
    {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, },

    // State 65
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, 
    {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, 
    {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, 
    {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {ERROR}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {ERROR}, 
    {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, },

    // State 66
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, 
    {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, 
    {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, 
    {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {ERROR}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {ERROR}, 
    {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, },

    // State 67
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, {SHIFT, 39}, {ERROR}, {REDUCE, 18}, {SHIFT, 40}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {SHIFT, 43}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {ERROR}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, 
    {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, },

    // State 68
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, 
    {REDUCE, 19}, {SHIFT, 39}, {ERROR}, {REDUCE, 19}, {SHIFT, 40}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {SHIFT, 43}, {REDUCE, 19}, 
    {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, 
    {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {ERROR}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {ERROR}, 
    {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, },

    // State 69
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, 
    {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, 
    {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, 
    {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {ERROR}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {ERROR}, 
    {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, },

    // State 70
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 25}, {SHIFT, 38}, 
    {REDUCE, 25}, {SHIFT, 39}, {ERROR}, {REDUCE, 25}, {SHIFT, 40}, {SHIFT, 41}, {REDUCE, 25}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 25}, 
    {REDUCE, 25}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 25}, {ERROR}, {ERROR}, {REDUCE, 25}, {ERROR}, {REDUCE, 25}, 
    {REDUCE, 25}, {SHIFT, 50}, {ERROR}, {REDUCE, 25}, {ERROR}, {ERROR}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {ERROR}, 
    {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, },

    // State 71
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 27}, {SHIFT, 38}, 
    {REDUCE, 27}, {SHIFT, 39}, {ERROR}, {REDUCE, 27}, {SHIFT, 40}, {SHIFT, 41}, {REDUCE, 27}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 27}, 
    {REDUCE, 27}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 27}, {ERROR}, {ERROR}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, 
    {REDUCE, 27}, {SHIFT, 50}, {ERROR}, {REDUCE, 27}, {ERROR}, {ERROR}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {ERROR}, 
    {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, },

    // State 72
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 23}, {SHIFT, 38}, 
    {REDUCE, 23}, {SHIFT, 39}, {ERROR}, {REDUCE, 23}, {SHIFT, 40}, {SHIFT, 41}, {REDUCE, 23}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 23}, 
    {REDUCE, 23}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {REDUCE, 23}, {SHIFT, 47}, {SHIFT, 48}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, 
    {REDUCE, 23}, {SHIFT, 50}, {ERROR}, {REDUCE, 23}, {ERROR}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {ERROR}, 
    {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, },

    // State 73
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 26}, {SHIFT, 38}, 
    {REDUCE, 26}, {SHIFT, 39}, {ERROR}, {REDUCE, 26}, {SHIFT, 40}, {SHIFT, 41}, {REDUCE, 26}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 26}, 
    {REDUCE, 26}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 26}, {ERROR}, {ERROR}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, 
    {REDUCE, 26}, {SHIFT, 50}, {ERROR}, {REDUCE, 26}, {ERROR}, {ERROR}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {ERROR}, 
    {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, },

    // State 74
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 28}, {SHIFT, 38}, 
    {REDUCE, 28}, {SHIFT, 39}, {ERROR}, {REDUCE, 28}, {SHIFT, 40}, {SHIFT, 41}, {REDUCE, 28}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 28}, 
    {REDUCE, 28}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 28}, {ERROR}, {ERROR}, {REDUCE, 28}, {ERROR}, {REDUCE, 28}, 
    {REDUCE, 28}, {SHIFT, 50}, {ERROR}, {REDUCE, 28}, {ERROR}, {ERROR}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {ERROR}, 
    {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, },

    // State 75
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 37}, {SHIFT, 38}, 
    {ERROR}, {SHIFT, 39}, {ERROR}, {ERROR}, {SHIFT, 40}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {SHIFT, 86}, 
    {ERROR}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {SHIFT, 48}, {SHIFT, 49}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 50}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 51}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 52}, {ERROR}, {ERROR}, {ERROR}, },

    // State 76
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 29}, {ERROR}, 
    {REDUCE, 29}, {SHIFT, 39}, {ERROR}, {REDUCE, 29}, {SHIFT, 40}, {SHIFT, 41}, {REDUCE, 29}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 29}, 
    {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, 
    {REDUCE, 29}, {ERROR}, {ERROR}, {REDUCE, 29}, {ERROR}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, 
    {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, },

    // State 77
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 37}, {SHIFT, 38}, 
    {REDUCE, 32}, {SHIFT, 39}, {ERROR}, {REDUCE, 32}, {SHIFT, 40}, {SHIFT, 41}, {REDUCE, 32}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 32}, 
    {REDUCE, 32}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {SHIFT, 48}, {REDUCE, 32}, {ERROR}, {REDUCE, 32}, 
    {REDUCE, 32}, {SHIFT, 50}, {ERROR}, {REDUCE, 32}, {ERROR}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {ERROR}, 
    {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, },

    // State 78
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 37}, {SHIFT, 38}, 
    {REDUCE, 31}, {SHIFT, 39}, {ERROR}, {REDUCE, 31}, {SHIFT, 40}, {SHIFT, 41}, {REDUCE, 31}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 31}, 
    {REDUCE, 31}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {SHIFT, 48}, {REDUCE, 31}, {ERROR}, {REDUCE, 31}, 
    {REDUCE, 31}, {SHIFT, 50}, {ERROR}, {REDUCE, 31}, {ERROR}, {ERROR}, {SHIFT, 51}, {REDUCE, 31}, {REDUCE, 31}, {ERROR}, 
    {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, },

    // State 79
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, 
    {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, 
    {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, 
    {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {ERROR}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, 
    {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, },

    // State 80
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 10}, 
    {REDUCE, 10}, {ERROR}, {ERROR}, {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 10}, {REDUCE, 10}, {ERROR}, 
    {ERROR}, {REDUCE, 10}, {ERROR}, {REDUCE, 10}, },

    // State 81
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 40}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 82
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 43}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 83
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 61}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 84
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 37}, {SHIFT, 38}, 
    {ERROR}, {SHIFT, 39}, {ERROR}, {REDUCE, 41}, {SHIFT, 40}, {SHIFT, 41}, {REDUCE, 41}, {SHIFT, 42}, {SHIFT, 43}, {ERROR}, 
    {ERROR}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {SHIFT, 48}, {SHIFT, 49}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 50}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 51}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 52}, {ERROR}, {ERROR}, {ERROR}, },

    // State 85
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 11}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 11}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 11}, 
    {REDUCE, 11}, {ERROR}, {ERROR}, {REDUCE, 11}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, {ERROR}, 
    {ERROR}, {REDUCE, 11}, {ERROR}, {REDUCE, 11}, },

    // State 86
    {{ERROR}, {GO, 87}, {GO, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 19}, {SHIFT, 20}, {SHIFT, 21}, {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 87
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 37}, {SHIFT, 38}, 
    {REDUCE, 34}, {SHIFT, 39}, {ERROR}, {REDUCE, 34}, {SHIFT, 40}, {SHIFT, 41}, {REDUCE, 34}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 34}, 
    {REDUCE, 34}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {SHIFT, 48}, {SHIFT, 49}, {ERROR}, {REDUCE, 34}, 
    {REDUCE, 34}, {SHIFT, 50}, {ERROR}, {REDUCE, 34}, {ERROR}, {ERROR}, {SHIFT, 51}, {REDUCE, 34}, {REDUCE, 34}, {ERROR}, 
    {SHIFT, 52}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, },

}; // Parser::table


