// Generated parser tables file

#include "Parser.hpp"

//==========================================================================================================
// Table of productions info: Left-hand-side nonterminal and number of symbols on right-hand-side
//==========================================================================================================
vector<ProductionInfo> Parser::production_infos = {
    {START, 1}, {STATEMENTS, 1}, {STATEMENTS, 2}, {STATEMENTS, 3}, {STATEMENT, 3}, {STATEMENT, 3}, {STATEMENT, 1}, {BLOCK, 3}, {STATEMENT, 3}, {STATEMENT, 5}, 
    {STATEMENT, 3}, {STATEMENT, 4}, {STATEMENT, 1}, {STATEMENT, 1}, {STATEMENT, 1}, {EXP, 1}, {EXP, 1}, {EXP, 1}, {EXP, 1}, {EXP, 3}, 
    {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, 
    {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 2}, {EXP, 5}, {EXP, 1}, {FUNC_CALL, 3}, {FUNC_CALL, 4}, 
    {FUNC_CALL, 4}, {PARAMS_LIST, 1}, {PARAMS_LIST, 3}, {NAMED_PARAM, 3}, {NAMED_PARAMS_LIST, 1}, {NAMED_PARAMS_LIST, 3}, 
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
        case 9: return new IfElseAST(elements);
        case 10: return new WhileAST(elements);
        case 11: return new RepeatAST(elements);
        case 12: return new BreakAST(elements);
        case 13: return new ContinueAST(elements);
        case 14: return extract_ast(elements);
        case 15: return new NumAST(elements);
        case 16: return new BoolAST(elements);
        case 17: return new StringAST(elements);
        case 18: return new VarAST(elements);
        case 19: return extract_ast(elements);
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
        case 33: return new BopAST(elements);
        case 34: return new BopAST(elements);
        case 35: return new UopAST(elements);
        case 36: return new CondExpAST(elements);
        case 37: return extract_ast(elements);
        case 38: return new FuncAST(elements);
        case 39: return new FuncAST(elements);
        case 40: return new FuncAST(elements);
        case 41: return new ParamsAST(elements);
        case 42: return new ParamsAST(elements);
        case 43: return new NamedParamAST(elements);
        case 44: return new NamedParamsAST(elements);
        case 45: return new NamedParamsAST(elements);
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
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {SHIFT, 9}, {ERROR}, {ERROR}, {SHIFT, 10}, {ERROR}, {SHIFT, 11}, },

    // State 1
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 6}, 
    {REDUCE, 6}, {ERROR}, {ERROR}, {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 6}, {REDUCE, 6}, {REDUCE, 6}, 
    {REDUCE, 6}, {ERROR}, {ERROR}, {REDUCE, 6}, {ERROR}, {REDUCE, 6}, },

    // State 2
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 14}, 
    {REDUCE, 14}, {ERROR}, {ERROR}, {REDUCE, 14}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, 
    {REDUCE, 14}, {ERROR}, {ERROR}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, },

    // State 3
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 3}, {GO, 12}, {ERROR}, {ERROR}, 
    {REDUCE, 1}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 13}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, 
    {REDUCE, 1}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {SHIFT, 9}, {ERROR}, {ERROR}, {SHIFT, 10}, {ERROR}, {SHIFT, 11}, },

    // State 4
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ACCEPT}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 5
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 3}, {GO, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {SHIFT, 9}, {ERROR}, {ERROR}, {SHIFT, 10}, {ERROR}, {SHIFT, 11}, },

    // State 6
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 17}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 7
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 12}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 12}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 12}, 
    {REDUCE, 12}, {ERROR}, {ERROR}, {REDUCE, 12}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, 
    {REDUCE, 12}, {ERROR}, {ERROR}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, },

    // State 8
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 13}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 13}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 13}, 
    {REDUCE, 13}, {ERROR}, {ERROR}, {REDUCE, 13}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, 
    {REDUCE, 13}, {ERROR}, {ERROR}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, },

    // State 9
    {{ERROR}, {GO, 18}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 10
    {{ERROR}, {GO, 26}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 11
    {{ERROR}, {GO, 27}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 12
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 2}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 2}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 13
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 3}, {GO, 28}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {SHIFT, 9}, {ERROR}, {ERROR}, {SHIFT, 10}, {ERROR}, {SHIFT, 11}, },

    // State 14
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 29}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 15
    {{ERROR}, {GO, 30}, {GO, 19}, {GO, 31}, {GO, 32}, {GO, 33}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {SHIFT, 34}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 35}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 16
    {{ERROR}, {GO, 36}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 17
    {{ERROR}, {GO, 37}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 18
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 38}, {ERROR}, {SHIFT, 39}, {SHIFT, 40}, 
    {ERROR}, {SHIFT, 41}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {ERROR}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, 
    {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {ERROR}, {SHIFT, 48}, {SHIFT, 49}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 5}, 
    {ERROR}, {SHIFT, 52}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 53}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {SHIFT, 9}, {ERROR}, {SHIFT, 54}, {SHIFT, 10}, {ERROR}, {SHIFT, 11}, },

    // State 19
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 37}, {REDUCE, 37}, 
    {REDUCE, 37}, {REDUCE, 37}, {ERROR}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, 
    {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {ERROR}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {ERROR}, {REDUCE, 37}, 
    {REDUCE, 37}, {REDUCE, 37}, {ERROR}, {REDUCE, 37}, {ERROR}, {ERROR}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, 
    {REDUCE, 37}, {ERROR}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, },

    // State 20
    {{ERROR}, {GO, 55}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 21
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, 
    {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {ERROR}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, 
    {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, },

    // State 22
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {SHIFT, 15}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {ERROR}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, },

    // State 23
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, 
    {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, 
    {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, 
    {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {ERROR}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, 
    {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, },

    // State 24
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, 
    {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, 
    {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, 
    {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {ERROR}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, 
    {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, },

    // State 25
    {{ERROR}, {GO, 56}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 26
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 39}, {SHIFT, 40}, 
    {ERROR}, {SHIFT, 41}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {ERROR}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, 
    {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {ERROR}, {SHIFT, 48}, {SHIFT, 49}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 52}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 53}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 54}, {ERROR}, {SHIFT, 57}, {ERROR}, },

    // State 27
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 58}, {ERROR}, {SHIFT, 39}, {SHIFT, 40}, 
    {ERROR}, {SHIFT, 41}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {ERROR}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, 
    {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {ERROR}, {SHIFT, 48}, {SHIFT, 49}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 5}, 
    {ERROR}, {SHIFT, 52}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 53}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {SHIFT, 9}, {ERROR}, {SHIFT, 54}, {SHIFT, 10}, {ERROR}, {SHIFT, 11}, },

    // State 28
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 3}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 3}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 29
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 7}, 
    {REDUCE, 7}, {ERROR}, {ERROR}, {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 7}, {REDUCE, 7}, {REDUCE, 7}, 
    {REDUCE, 7}, {ERROR}, {ERROR}, {REDUCE, 7}, {ERROR}, {REDUCE, 7}, },

    // State 30
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 39}, {SHIFT, 40}, 
    {ERROR}, {SHIFT, 41}, {ERROR}, {REDUCE, 41}, {SHIFT, 42}, {SHIFT, 43}, {SHIFT, 59}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, 
    {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {ERROR}, {SHIFT, 48}, {SHIFT, 49}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 52}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 53}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 54}, {ERROR}, {ERROR}, {ERROR}, },

    // State 31
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 44}, {ERROR}, {ERROR}, {SHIFT, 60}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 32
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 61}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 33
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 62}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 34
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 38}, {REDUCE, 38}, 
    {REDUCE, 38}, {REDUCE, 38}, {ERROR}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, 
    {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {ERROR}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {ERROR}, {REDUCE, 38}, 
    {REDUCE, 38}, {REDUCE, 38}, {ERROR}, {REDUCE, 38}, {ERROR}, {ERROR}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, 
    {REDUCE, 38}, {ERROR}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, },

    // State 35
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {SHIFT, 15}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {SHIFT, 63}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {ERROR}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, },

    // State 36
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 39}, {SHIFT, 40}, 
    {REDUCE, 4}, {SHIFT, 41}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {ERROR}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, 
    {REDUCE, 4}, {SHIFT, 46}, {SHIFT, 47}, {ERROR}, {SHIFT, 48}, {SHIFT, 49}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {REDUCE, 4}, 
    {REDUCE, 4}, {SHIFT, 52}, {ERROR}, {REDUCE, 4}, {ERROR}, {ERROR}, {SHIFT, 53}, {REDUCE, 4}, {REDUCE, 4}, {REDUCE, 4}, 
    {REDUCE, 4}, {ERROR}, {SHIFT, 54}, {REDUCE, 4}, {ERROR}, {REDUCE, 4}, },

    // State 37
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 39}, {SHIFT, 40}, 
    {REDUCE, 5}, {SHIFT, 41}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {ERROR}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, 
    {REDUCE, 5}, {SHIFT, 46}, {SHIFT, 47}, {ERROR}, {SHIFT, 48}, {SHIFT, 49}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {REDUCE, 5}, 
    {REDUCE, 5}, {SHIFT, 52}, {ERROR}, {REDUCE, 5}, {ERROR}, {ERROR}, {SHIFT, 53}, {REDUCE, 5}, {REDUCE, 5}, {REDUCE, 5}, 
    {REDUCE, 5}, {ERROR}, {SHIFT, 54}, {REDUCE, 5}, {ERROR}, {REDUCE, 5}, },

    // State 38
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 8}, 
    {REDUCE, 8}, {ERROR}, {ERROR}, {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 8}, {REDUCE, 8}, {SHIFT, 64}, 
    {REDUCE, 8}, {ERROR}, {ERROR}, {REDUCE, 8}, {ERROR}, {REDUCE, 8}, },

    // State 39
    {{ERROR}, {GO, 65}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 40
    {{ERROR}, {GO, 66}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 41
    {{ERROR}, {GO, 67}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 42
    {{ERROR}, {GO, 68}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 43
    {{ERROR}, {GO, 69}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 44
    {{ERROR}, {GO, 70}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 45
    {{ERROR}, {GO, 71}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 46
    {{ERROR}, {GO, 72}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 47
    {{ERROR}, {GO, 73}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 48
    {{ERROR}, {GO, 74}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 49
    {{ERROR}, {GO, 75}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 50
    {{ERROR}, {GO, 76}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 51
    {{ERROR}, {GO, 77}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 52
    {{ERROR}, {GO, 78}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 53
    {{ERROR}, {GO, 79}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 54
    {{ERROR}, {GO, 80}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 55
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 39}, {SHIFT, 40}, 
    {ERROR}, {SHIFT, 41}, {ERROR}, {SHIFT, 81}, {SHIFT, 42}, {SHIFT, 43}, {ERROR}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, 
    {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {ERROR}, {SHIFT, 48}, {SHIFT, 49}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 52}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 53}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 54}, {ERROR}, {ERROR}, {ERROR}, },

    // State 56
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, 
    {REDUCE, 35}, {REDUCE, 35}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, 
    {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {ERROR}, {REDUCE, 35}, 
    {REDUCE, 35}, {REDUCE, 35}, {ERROR}, {REDUCE, 35}, {ERROR}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, 
    {REDUCE, 35}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, },

    // State 57
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 82}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {SHIFT, 9}, {ERROR}, {ERROR}, {SHIFT, 10}, {ERROR}, {SHIFT, 11}, },

    // State 58
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 10}, 
    {REDUCE, 10}, {ERROR}, {ERROR}, {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, 
    {REDUCE, 10}, {ERROR}, {ERROR}, {REDUCE, 10}, {ERROR}, {REDUCE, 10}, },

    // State 59
    {{ERROR}, {GO, 30}, {GO, 19}, {ERROR}, {ERROR}, {GO, 83}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 60
    {{ERROR}, {ERROR}, {ERROR}, {GO, 31}, {GO, 84}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 85}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 61
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 40}, {REDUCE, 40}, 
    {REDUCE, 40}, {REDUCE, 40}, {ERROR}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, 
    {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {ERROR}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {ERROR}, {REDUCE, 40}, 
    {REDUCE, 40}, {REDUCE, 40}, {ERROR}, {REDUCE, 40}, {ERROR}, {ERROR}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, 
    {REDUCE, 40}, {ERROR}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, },

    // State 62
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 39}, {REDUCE, 39}, 
    {REDUCE, 39}, {REDUCE, 39}, {ERROR}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, 
    {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {ERROR}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {ERROR}, {REDUCE, 39}, 
    {REDUCE, 39}, {REDUCE, 39}, {ERROR}, {REDUCE, 39}, {ERROR}, {ERROR}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, 
    {REDUCE, 39}, {ERROR}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, },

    // State 63
    {{ERROR}, {GO, 86}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 64
    {{GO, 1}, {ERROR}, {GO, 2}, {ERROR}, {ERROR}, {ERROR}, {GO, 87}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 6}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {SHIFT, 9}, {ERROR}, {ERROR}, {SHIFT, 10}, {ERROR}, {SHIFT, 11}, },

    // State 65
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 26}, {SHIFT, 40}, 
    {REDUCE, 26}, {SHIFT, 41}, {ERROR}, {REDUCE, 26}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 26}, {SHIFT, 44}, {SHIFT, 45}, {REDUCE, 26}, 
    {REDUCE, 26}, {SHIFT, 46}, {SHIFT, 47}, {ERROR}, {REDUCE, 26}, {SHIFT, 49}, {SHIFT, 50}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, 
    {REDUCE, 26}, {SHIFT, 52}, {ERROR}, {REDUCE, 26}, {ERROR}, {ERROR}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, 
    {REDUCE, 26}, {ERROR}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, },

    // State 66
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 32}, {ERROR}, 
    {REDUCE, 32}, {SHIFT, 41}, {ERROR}, {REDUCE, 32}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 32}, {SHIFT, 44}, {SHIFT, 45}, {REDUCE, 32}, 
    {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {ERROR}, {REDUCE, 32}, 
    {REDUCE, 32}, {ERROR}, {ERROR}, {REDUCE, 32}, {ERROR}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, 
    {REDUCE, 32}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, },

    // State 67
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, 
    {REDUCE, 24}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, 
    {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, 
    {REDUCE, 24}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {ERROR}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, 
    {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, },

    // State 68
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, 
    {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, 
    {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, 
    {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {ERROR}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, 
    {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, },

    // State 69
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, 
    {REDUCE, 20}, {SHIFT, 41}, {ERROR}, {REDUCE, 20}, {SHIFT, 42}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {SHIFT, 45}, {REDUCE, 20}, 
    {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, 
    {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {ERROR}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, 
    {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, },

    // State 70
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, 
    {REDUCE, 21}, {SHIFT, 41}, {ERROR}, {REDUCE, 21}, {SHIFT, 42}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {SHIFT, 45}, {REDUCE, 21}, 
    {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, 
    {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {ERROR}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, 
    {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, },

    // State 71
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, 
    {REDUCE, 23}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, 
    {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, 
    {REDUCE, 23}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, {ERROR}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, 
    {REDUCE, 23}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, },

    // State 72
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 27}, {SHIFT, 40}, 
    {REDUCE, 27}, {SHIFT, 41}, {ERROR}, {REDUCE, 27}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 27}, {SHIFT, 44}, {SHIFT, 45}, {REDUCE, 27}, 
    {REDUCE, 27}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 27}, {ERROR}, {ERROR}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, 
    {REDUCE, 27}, {SHIFT, 52}, {ERROR}, {REDUCE, 27}, {ERROR}, {ERROR}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, 
    {REDUCE, 27}, {ERROR}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, },

    // State 73
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 29}, {SHIFT, 40}, 
    {REDUCE, 29}, {SHIFT, 41}, {ERROR}, {REDUCE, 29}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 29}, {SHIFT, 44}, {SHIFT, 45}, {REDUCE, 29}, 
    {REDUCE, 29}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 29}, {ERROR}, {ERROR}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, 
    {REDUCE, 29}, {SHIFT, 52}, {ERROR}, {REDUCE, 29}, {ERROR}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, 
    {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, },

    // State 74
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 25}, {SHIFT, 40}, 
    {REDUCE, 25}, {SHIFT, 41}, {ERROR}, {REDUCE, 25}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 25}, {SHIFT, 44}, {SHIFT, 45}, {REDUCE, 25}, 
    {REDUCE, 25}, {SHIFT, 46}, {SHIFT, 47}, {ERROR}, {REDUCE, 25}, {SHIFT, 49}, {SHIFT, 50}, {REDUCE, 25}, {ERROR}, {REDUCE, 25}, 
    {REDUCE, 25}, {SHIFT, 52}, {ERROR}, {REDUCE, 25}, {ERROR}, {ERROR}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, 
    {REDUCE, 25}, {ERROR}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, },

    // State 75
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 28}, {SHIFT, 40}, 
    {REDUCE, 28}, {SHIFT, 41}, {ERROR}, {REDUCE, 28}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 28}, {SHIFT, 44}, {SHIFT, 45}, {REDUCE, 28}, 
    {REDUCE, 28}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 28}, {ERROR}, {ERROR}, {REDUCE, 28}, {ERROR}, {REDUCE, 28}, 
    {REDUCE, 28}, {SHIFT, 52}, {ERROR}, {REDUCE, 28}, {ERROR}, {ERROR}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, 
    {REDUCE, 28}, {ERROR}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, },

    // State 76
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 30}, {SHIFT, 40}, 
    {REDUCE, 30}, {SHIFT, 41}, {ERROR}, {REDUCE, 30}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 30}, {SHIFT, 44}, {SHIFT, 45}, {REDUCE, 30}, 
    {REDUCE, 30}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 30}, {ERROR}, {ERROR}, {REDUCE, 30}, {ERROR}, {REDUCE, 30}, 
    {REDUCE, 30}, {SHIFT, 52}, {ERROR}, {REDUCE, 30}, {ERROR}, {ERROR}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, 
    {REDUCE, 30}, {ERROR}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, },

    // State 77
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 39}, {SHIFT, 40}, 
    {ERROR}, {SHIFT, 41}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, {ERROR}, {SHIFT, 44}, {SHIFT, 45}, {SHIFT, 88}, 
    {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {ERROR}, {SHIFT, 48}, {SHIFT, 49}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 52}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 53}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 54}, {ERROR}, {ERROR}, {ERROR}, },

    // State 78
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 31}, {ERROR}, 
    {REDUCE, 31}, {SHIFT, 41}, {ERROR}, {REDUCE, 31}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 31}, {SHIFT, 44}, {SHIFT, 45}, {REDUCE, 31}, 
    {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {ERROR}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {ERROR}, {REDUCE, 31}, 
    {REDUCE, 31}, {ERROR}, {ERROR}, {REDUCE, 31}, {ERROR}, {ERROR}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, 
    {REDUCE, 31}, {ERROR}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, },

    // State 79
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 39}, {SHIFT, 40}, 
    {REDUCE, 34}, {SHIFT, 41}, {ERROR}, {REDUCE, 34}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 34}, {SHIFT, 44}, {SHIFT, 45}, {REDUCE, 34}, 
    {REDUCE, 34}, {SHIFT, 46}, {SHIFT, 47}, {ERROR}, {SHIFT, 48}, {SHIFT, 49}, {SHIFT, 50}, {REDUCE, 34}, {ERROR}, {REDUCE, 34}, 
    {REDUCE, 34}, {SHIFT, 52}, {ERROR}, {REDUCE, 34}, {ERROR}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, 
    {REDUCE, 34}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, },

    // State 80
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 39}, {SHIFT, 40}, 
    {REDUCE, 33}, {SHIFT, 41}, {ERROR}, {REDUCE, 33}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 33}, {SHIFT, 44}, {SHIFT, 45}, {REDUCE, 33}, 
    {REDUCE, 33}, {SHIFT, 46}, {SHIFT, 47}, {ERROR}, {SHIFT, 48}, {SHIFT, 49}, {SHIFT, 50}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, 
    {REDUCE, 33}, {SHIFT, 52}, {ERROR}, {REDUCE, 33}, {ERROR}, {ERROR}, {SHIFT, 53}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, 
    {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, },

    // State 81
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, 
    {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, 
    {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, 
    {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {ERROR}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, 
    {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, },

    // State 82
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 11}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 11}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 11}, 
    {REDUCE, 11}, {ERROR}, {ERROR}, {REDUCE, 11}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, 
    {REDUCE, 11}, {ERROR}, {ERROR}, {REDUCE, 11}, {ERROR}, {REDUCE, 11}, },

    // State 83
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 42}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 84
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 45}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 85
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 63}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 86
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 39}, {SHIFT, 40}, 
    {ERROR}, {SHIFT, 41}, {ERROR}, {REDUCE, 43}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 43}, {SHIFT, 44}, {SHIFT, 45}, {ERROR}, 
    {ERROR}, {SHIFT, 46}, {SHIFT, 47}, {ERROR}, {SHIFT, 48}, {SHIFT, 49}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 52}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 53}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 54}, {ERROR}, {ERROR}, {ERROR}, },

    // State 87
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 9}, 
    {REDUCE, 9}, {ERROR}, {ERROR}, {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, 
    {REDUCE, 9}, {ERROR}, {ERROR}, {REDUCE, 9}, {ERROR}, {REDUCE, 9}, },

    // State 88
    {{ERROR}, {GO, 89}, {GO, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 21}, {SHIFT, 22}, {SHIFT, 23}, {SHIFT, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 89
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 39}, {SHIFT, 40}, 
    {REDUCE, 36}, {SHIFT, 41}, {ERROR}, {REDUCE, 36}, {SHIFT, 42}, {SHIFT, 43}, {REDUCE, 36}, {SHIFT, 44}, {SHIFT, 45}, {REDUCE, 36}, 
    {REDUCE, 36}, {SHIFT, 46}, {SHIFT, 47}, {ERROR}, {SHIFT, 48}, {SHIFT, 49}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {REDUCE, 36}, 
    {REDUCE, 36}, {SHIFT, 52}, {ERROR}, {REDUCE, 36}, {ERROR}, {ERROR}, {SHIFT, 53}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, 
    {REDUCE, 36}, {ERROR}, {SHIFT, 54}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, },

}; // Parser::table


