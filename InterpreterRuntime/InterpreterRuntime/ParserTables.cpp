// Generated parser tables file, do not change manually!

#include "Parser.hpp"

//============================================================================================================
// Table of productions info: Left-hand-side nonterminal and number of symbols on right-hand-side
//============================================================================================================
vector<ProductionInfo> Parser::production_infos = {
    {START, 1}, {STATEMENTS, 1}, {STATEMENTS, 2}, {STATEMENTS, 3}, {STATEMENT, 3}, {STATEMENT, 3}, 
    {STATEMENT, 3}, {STATEMENT, 2}, {STATEMENT, 3}, {STATEMENT, 5}, {STATEMENT, 4}, {STATEMENT, 3}, 
    {STATEMENT, 4}, {STATEMENT, 5}, {STATEMENT, 1}, {STATEMENT, 1}, {STATEMENT, 1}, {STATEMENT, 1}, 
    {FUNC_CALL, 3}, {FUNC_CALL, 4}, {FUNC_CALL, 4}, {COMMAND_CALL, 2}, {EXP_LIST, 1}, {EXP_LIST, 3}, 
    {PARAM_VALS_LIST, 1}, {PARAM_VALS_LIST, 3}, {PARAM_VALS_LIST, 2}, {PARAM_VAL, 2}, {EXP, 5}, {EXP, 1}, 
    {EXP, 1}, {EXP, 1}, {EXP, 1}, {EXP, 3}, {EXP, 4}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, 
    {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, 
    {EXP, 3}, {EXP, 2}, {EXP, 2}, {EXP, 5}, {EXP, 2}, {EXP, 3}, {EXP, 2}, {EXP, 3}, {EXP, 1}, 
};


//==========================================================================================================
// Generate an AST acording to production number
//==========================================================================================================
AST* Parser::gen_ast(int production, vector<ParseElement*>& elements) {
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
        case 10: return new TryFinallyAST(elements);
        case 11: return new WhileAST(elements);
        case 12: return new RepeatAST(elements);
        case 13: return new ForAST(elements);
        case 14: return new BreakAST(elements);
        case 15: return new ContinueAST(elements);
        case 16: return extract_ast(elements);
        case 17: return extract_ast(elements);
        case 18: return new FuncAST(elements);
        case 19: return new FuncAST(elements);
        case 20: return new FuncAST(elements);
        case 21: return new CommandAST(elements);
        case 22: return new NakedListAST(elements);
        case 23: return new NakedListAST(elements);
        case 24: return new ParamValsAST(elements);
        case 25: return new ParamValsAST(elements);
        case 26: return new ParamValsAST(elements);
        case 27: return new ParamValAST(elements);
        case 28: return new RangeAST(elements);
        case 29: return new NumAST(elements);
        case 30: return new BoolAST(elements);
        case 31: return new StringAST(elements);
        case 32: return new VarAST(elements);
        case 33: return extract_ast(elements);
        case 34: return gen_bop_ast(elements);
        case 35: return new DotAccessAST(elements);
        case 36: return gen_bop_ast(elements);
        case 37: return gen_bop_ast(elements);
        case 38: return gen_bop_ast(elements);
        case 39: return gen_bop_ast(elements);
        case 40: return gen_bop_ast(elements);
        case 41: return gen_bop_ast(elements);
        case 42: return gen_bop_ast(elements);
        case 43: return gen_bop_ast(elements);
        case 44: return gen_bop_ast(elements);
        case 45: return gen_bop_ast(elements);
        case 46: return gen_bop_ast(elements);
        case 47: return gen_bop_ast(elements);
        case 48: return gen_bop_ast(elements);
        case 49: return gen_bop_ast(elements);
        case 50: return gen_bop_ast(elements);
        case 51: return new UopAST(elements);
        case 52: return new UopAST(elements);
        case 53: return new CondExpAST(elements);
        case 54: return new ListAST(elements);
        case 55: return new ListAST(elements);
        case 56: return new ParamValsAST(elements);
        case 57: return new ParamValsAST(elements);
        case 58: return extract_ast(elements);
    } // switch

    return nullptr;

} // Parser::gen_ast()


//==========================================================================================================
// Table of actions per (state, symbol) pair
//==========================================================================================================
vector<vector<Action>> Parser::table = {
    // State 0
    {{SHIFT, 1}, {ERROR}, {ERROR}, {SHIFT, 2}, {ERROR}, {ERROR}, {SHIFT, 3}, {SHIFT, 4}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 9}, {ERROR}, {SHIFT, 10}, {SHIFT, 11}, {SHIFT, 12}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 13}, {ERROR}, {ERROR}, {ERROR}, },

    // State 1
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {ERROR}, 
    {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {ERROR}, {ERROR}, },

    // State 2
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {ERROR}, 
    {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {ERROR}, {ERROR}, },

    // State 3
    {{SHIFT, 1}, {ERROR}, {ERROR}, {SHIFT, 2}, {ERROR}, {ERROR}, {SHIFT, 3}, {SHIFT, 14}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 9}, {ERROR}, {SHIFT, 10}, {SHIFT, 11}, {SHIFT, 12}, {REDUCE, 1}, {ERROR}, {ERROR}, 
    {REDUCE, 1}, {SHIFT, 13}, {ERROR}, {ERROR}, {ERROR}, },

    // State 4
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ACCEPT}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 5
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {ERROR}, 
    {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {ERROR}, {ERROR}, },

    // State 6
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {ERROR}, 
    {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {ERROR}, {ERROR}, },

    // State 7
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 16}, {ERROR}, {ERROR}, {ERROR}, },

    // State 8
    {{ERROR}, {SHIFT, 17}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 9
    {{ERROR}, {SHIFT, 28}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 10
    {{SHIFT, 1}, {ERROR}, {ERROR}, {SHIFT, 2}, {ERROR}, {ERROR}, {SHIFT, 29}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 9}, {ERROR}, {SHIFT, 10}, {SHIFT, 11}, {SHIFT, 12}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 13}, {ERROR}, {ERROR}, {ERROR}, },

    // State 11
    {{ERROR}, {SHIFT, 30}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 12
    {{SHIFT, 1}, {ERROR}, {ERROR}, {SHIFT, 2}, {ERROR}, {ERROR}, {SHIFT, 3}, {SHIFT, 31}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 9}, {ERROR}, {SHIFT, 10}, {SHIFT, 11}, {SHIFT, 12}, {SHIFT, 32}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 13}, {ERROR}, {ERROR}, {ERROR}, },

    // State 13
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 33}, {SHIFT, 34}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 35}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 36}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 37}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 38}, {ERROR}, },

    // State 14
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 2}, {ERROR}, {ERROR}, 
    {REDUCE, 2}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 15
    {{SHIFT, 1}, {ERROR}, {ERROR}, {SHIFT, 2}, {ERROR}, {ERROR}, {SHIFT, 3}, {SHIFT, 39}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 9}, {ERROR}, {SHIFT, 10}, {SHIFT, 11}, {SHIFT, 12}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 13}, {ERROR}, {ERROR}, {ERROR}, },

    // State 16
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 40}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 17
    {{SHIFT, 1}, {ERROR}, {ERROR}, {SHIFT, 2}, {ERROR}, {ERROR}, {SHIFT, 41}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {ERROR}, {SHIFT, 45}, {SHIFT, 46}, {ERROR}, {SHIFT, 47}, {SHIFT, 48}, {ERROR}, {SHIFT, 49}, 
    {ERROR}, {ERROR}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 54}, {SHIFT, 55}, {ERROR}, 
    {SHIFT, 56}, {ERROR}, {SHIFT, 57}, {SHIFT, 5}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {ERROR}, {SHIFT, 58}, {SHIFT, 9}, {ERROR}, {SHIFT, 10}, {SHIFT, 11}, {SHIFT, 12}, {ERROR}, {SHIFT, 59}, {ERROR}, 
    {ERROR}, {SHIFT, 13}, {ERROR}, {ERROR}, {ERROR}, },

    // State 18
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 58}, {REDUCE, 58}, 
    {REDUCE, 58}, {ERROR}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, 
    {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {ERROR}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {ERROR}, 
    {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {ERROR}, 
    {ERROR}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {REDUCE, 58}, {ERROR}, 
    {REDUCE, 58}, {REDUCE, 58}, {ERROR}, {REDUCE, 58}, {ERROR}, },

    // State 19
    {{ERROR}, {SHIFT, 60}, {ERROR}, {SHIFT, 18}, {SHIFT, 33}, {SHIFT, 61}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {SHIFT, 62}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {SHIFT, 38}, {SHIFT, 27}, },

    // State 20
    {{ERROR}, {SHIFT, 63}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 21
    {{ERROR}, {SHIFT, 64}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 22
    {{ERROR}, {SHIFT, 65}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 23
    {{ERROR}, {SHIFT, 66}, {SHIFT, 67}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {SHIFT, 68}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 24
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 30}, {REDUCE, 30}, 
    {REDUCE, 30}, {ERROR}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, 
    {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {ERROR}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {ERROR}, 
    {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {ERROR}, 
    {ERROR}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {ERROR}, 
    {REDUCE, 30}, {REDUCE, 30}, {ERROR}, {REDUCE, 30}, {ERROR}, },

    // State 25
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, 
    {REDUCE, 32}, {SHIFT, 35}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, 
    {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {ERROR}, 
    {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {ERROR}, 
    {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {ERROR}, 
    {REDUCE, 32}, {REDUCE, 32}, {ERROR}, {REDUCE, 32}, {ERROR}, },

    // State 26
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, 
    {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, 
    {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, 
    {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, 
    {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, 
    {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {ERROR}, },

    // State 27
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 31}, {REDUCE, 31}, 
    {REDUCE, 31}, {ERROR}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, 
    {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {ERROR}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {ERROR}, 
    {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {ERROR}, 
    {ERROR}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {ERROR}, 
    {REDUCE, 31}, {REDUCE, 31}, {ERROR}, {REDUCE, 31}, {ERROR}, },

    // State 28
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {ERROR}, {SHIFT, 45}, {SHIFT, 46}, {ERROR}, {SHIFT, 47}, {SHIFT, 48}, {ERROR}, {SHIFT, 49}, 
    {ERROR}, {ERROR}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 54}, {SHIFT, 55}, {ERROR}, 
    {SHIFT, 56}, {ERROR}, {SHIFT, 57}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 58}, {ERROR}, {SHIFT, 69}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 59}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 29
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 70}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 30
    {{SHIFT, 1}, {ERROR}, {ERROR}, {SHIFT, 2}, {ERROR}, {ERROR}, {SHIFT, 71}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {ERROR}, {SHIFT, 45}, {SHIFT, 46}, {ERROR}, {SHIFT, 47}, {SHIFT, 48}, {ERROR}, {SHIFT, 49}, 
    {ERROR}, {ERROR}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 54}, {SHIFT, 55}, {ERROR}, 
    {SHIFT, 56}, {ERROR}, {SHIFT, 57}, {SHIFT, 5}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {ERROR}, {SHIFT, 58}, {SHIFT, 9}, {ERROR}, {SHIFT, 10}, {SHIFT, 11}, {SHIFT, 12}, {ERROR}, {SHIFT, 59}, {ERROR}, 
    {ERROR}, {SHIFT, 13}, {ERROR}, {ERROR}, {ERROR}, },

    // State 31
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 72}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 32
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 7}, {REDUCE, 7}, {REDUCE, 7}, {REDUCE, 7}, {REDUCE, 7}, {REDUCE, 7}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 7}, {ERROR}, {REDUCE, 7}, {REDUCE, 7}, {REDUCE, 7}, {REDUCE, 7}, {ERROR}, {ERROR}, 
    {REDUCE, 7}, {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, },

    // State 33
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 33}, {SHIFT, 73}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 24}, {ERROR}, {ERROR}, {SHIFT, 74}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 24}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {ERROR}, {ERROR}, 
    {REDUCE, 24}, {REDUCE, 24}, {ERROR}, {SHIFT, 38}, {ERROR}, },

    // State 34
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {ERROR}, 
    {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {ERROR}, {ERROR}, },

    // State 35
    {{ERROR}, {SHIFT, 66}, {SHIFT, 75}, {SHIFT, 18}, {SHIFT, 33}, {SHIFT, 76}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {SHIFT, 77}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {SHIFT, 38}, {SHIFT, 27}, },

    // State 36
    {{ERROR}, {SHIFT, 78}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 37
    {{ERROR}, {SHIFT, 79}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 38
    {{ERROR}, {SHIFT, 80}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 39
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 3}, {ERROR}, {ERROR}, 
    {REDUCE, 3}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 40
    {{ERROR}, {SHIFT, 81}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 41
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 8}, {REDUCE, 8}, {SHIFT, 82}, {REDUCE, 8}, {REDUCE, 8}, {REDUCE, 8}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 8}, {ERROR}, {REDUCE, 8}, {REDUCE, 8}, {REDUCE, 8}, {REDUCE, 8}, {ERROR}, {ERROR}, 
    {REDUCE, 8}, {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, },

    // State 42
    {{ERROR}, {SHIFT, 83}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 43
    {{ERROR}, {SHIFT, 84}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 44
    {{ERROR}, {SHIFT, 85}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 45
    {{ERROR}, {SHIFT, 86}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 46
    {{ERROR}, {SHIFT, 87}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 47
    {{ERROR}, {SHIFT, 88}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 48
    {{ERROR}, {ERROR}, {ERROR}, {SHIFT, 89}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 90}, {ERROR}, {ERROR}, {ERROR}, },

    // State 49
    {{ERROR}, {SHIFT, 91}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 50
    {{ERROR}, {SHIFT, 92}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 51
    {{ERROR}, {SHIFT, 93}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 52
    {{ERROR}, {SHIFT, 94}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 53
    {{ERROR}, {SHIFT, 95}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 54
    {{ERROR}, {SHIFT, 96}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 55
    {{ERROR}, {SHIFT, 97}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 56
    {{ERROR}, {SHIFT, 98}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 57
    {{ERROR}, {SHIFT, 99}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 58
    {{ERROR}, {SHIFT, 100}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 59
    {{ERROR}, {SHIFT, 101}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 60
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {SHIFT, 102}, {SHIFT, 45}, {SHIFT, 46}, {ERROR}, {SHIFT, 47}, {SHIFT, 48}, {ERROR}, {SHIFT, 49}, 
    {ERROR}, {ERROR}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 54}, {SHIFT, 55}, {ERROR}, 
    {SHIFT, 56}, {ERROR}, {SHIFT, 57}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 58}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 59}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 61
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 103}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 62
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 56}, {REDUCE, 56}, 
    {REDUCE, 56}, {ERROR}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, 
    {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {ERROR}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {ERROR}, 
    {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {ERROR}, 
    {ERROR}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {REDUCE, 56}, {ERROR}, 
    {REDUCE, 56}, {REDUCE, 56}, {ERROR}, {REDUCE, 56}, {ERROR}, },

    // State 63
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 52}, {REDUCE, 52}, 
    {SHIFT, 44}, {ERROR}, {REDUCE, 52}, {SHIFT, 45}, {SHIFT, 46}, {REDUCE, 52}, {SHIFT, 47}, {SHIFT, 48}, {REDUCE, 52}, {SHIFT, 49}, 
    {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {ERROR}, {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {ERROR}, 
    {ERROR}, {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {ERROR}, 
    {REDUCE, 52}, {REDUCE, 52}, {ERROR}, {REDUCE, 52}, {ERROR}, },

    // State 64
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {ERROR}, {SHIFT, 45}, {SHIFT, 46}, {ERROR}, {SHIFT, 47}, {SHIFT, 48}, {SHIFT, 104}, {SHIFT, 49}, 
    {ERROR}, {ERROR}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 54}, {SHIFT, 55}, {ERROR}, 
    {SHIFT, 56}, {ERROR}, {SHIFT, 57}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 58}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 59}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 65
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 51}, {REDUCE, 51}, 
    {REDUCE, 51}, {ERROR}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {SHIFT, 48}, {REDUCE, 51}, {REDUCE, 51}, 
    {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {ERROR}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {ERROR}, 
    {ERROR}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {ERROR}, 
    {REDUCE, 51}, {REDUCE, 51}, {ERROR}, {REDUCE, 51}, {ERROR}, },

    // State 66
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {REDUCE, 22}, {SHIFT, 45}, {SHIFT, 46}, {SHIFT, 105}, {SHIFT, 47}, {SHIFT, 48}, {ERROR}, {SHIFT, 49}, 
    {ERROR}, {ERROR}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 54}, {SHIFT, 55}, {ERROR}, 
    {SHIFT, 56}, {ERROR}, {SHIFT, 57}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 58}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 22}, {SHIFT, 59}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 67
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 106}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 68
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 54}, {REDUCE, 54}, 
    {REDUCE, 54}, {ERROR}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, 
    {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {ERROR}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {ERROR}, 
    {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {ERROR}, 
    {ERROR}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {REDUCE, 54}, {ERROR}, 
    {REDUCE, 54}, {REDUCE, 54}, {ERROR}, {REDUCE, 54}, {ERROR}, },

    // State 69
    {{SHIFT, 1}, {ERROR}, {ERROR}, {SHIFT, 2}, {ERROR}, {ERROR}, {SHIFT, 107}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 9}, {ERROR}, {SHIFT, 10}, {SHIFT, 11}, {SHIFT, 12}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 13}, {ERROR}, {ERROR}, {ERROR}, },

    // State 70
    {{SHIFT, 1}, {ERROR}, {ERROR}, {SHIFT, 2}, {ERROR}, {ERROR}, {SHIFT, 108}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 9}, {ERROR}, {SHIFT, 10}, {SHIFT, 11}, {SHIFT, 12}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 13}, {ERROR}, {ERROR}, {ERROR}, },

    // State 71
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 11}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 11}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {ERROR}, 
    {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {ERROR}, {ERROR}, },

    // State 72
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 6}, {REDUCE, 6}, {REDUCE, 6}, {REDUCE, 6}, {REDUCE, 6}, {REDUCE, 6}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 6}, {ERROR}, {REDUCE, 6}, {REDUCE, 6}, {REDUCE, 6}, {REDUCE, 6}, {ERROR}, {ERROR}, 
    {REDUCE, 6}, {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, },

    // State 73
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {ERROR}, {ERROR}, 
    {REDUCE, 26}, {REDUCE, 26}, {ERROR}, {ERROR}, {ERROR}, },

    // State 74
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 33}, {SHIFT, 109}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 38}, {ERROR}, },

    // State 75
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 110}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 76
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 111}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 77
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, 
    {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, 
    {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, 
    {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, 
    {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, {ERROR}, },

    // State 78
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {ERROR}, {SHIFT, 45}, {SHIFT, 46}, {ERROR}, {SHIFT, 47}, {SHIFT, 48}, {ERROR}, {SHIFT, 49}, 
    {ERROR}, {REDUCE, 4}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 54}, {SHIFT, 55}, {ERROR}, 
    {SHIFT, 56}, {ERROR}, {SHIFT, 57}, {REDUCE, 4}, {REDUCE, 4}, {REDUCE, 4}, {REDUCE, 4}, {REDUCE, 4}, {REDUCE, 4}, {ERROR}, 
    {ERROR}, {SHIFT, 58}, {REDUCE, 4}, {ERROR}, {REDUCE, 4}, {REDUCE, 4}, {REDUCE, 4}, {REDUCE, 4}, {SHIFT, 59}, {ERROR}, 
    {REDUCE, 4}, {REDUCE, 4}, {ERROR}, {ERROR}, {ERROR}, },

    // State 79
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {ERROR}, {SHIFT, 45}, {SHIFT, 46}, {ERROR}, {SHIFT, 47}, {SHIFT, 48}, {ERROR}, {SHIFT, 49}, 
    {ERROR}, {REDUCE, 5}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 54}, {SHIFT, 55}, {ERROR}, 
    {SHIFT, 56}, {ERROR}, {SHIFT, 57}, {REDUCE, 5}, {REDUCE, 5}, {REDUCE, 5}, {REDUCE, 5}, {REDUCE, 5}, {REDUCE, 5}, {ERROR}, 
    {ERROR}, {SHIFT, 58}, {REDUCE, 5}, {ERROR}, {REDUCE, 5}, {REDUCE, 5}, {REDUCE, 5}, {REDUCE, 5}, {SHIFT, 59}, {ERROR}, 
    {REDUCE, 5}, {REDUCE, 5}, {ERROR}, {ERROR}, {ERROR}, },

    // State 80
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {REDUCE, 27}, {SHIFT, 45}, {SHIFT, 46}, {REDUCE, 27}, {SHIFT, 47}, {SHIFT, 48}, {ERROR}, {SHIFT, 49}, 
    {ERROR}, {REDUCE, 27}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 54}, {SHIFT, 55}, {ERROR}, 
    {SHIFT, 56}, {ERROR}, {SHIFT, 57}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {ERROR}, 
    {ERROR}, {SHIFT, 58}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {SHIFT, 59}, {ERROR}, 
    {REDUCE, 27}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, {ERROR}, },

    // State 81
    {{SHIFT, 1}, {ERROR}, {ERROR}, {SHIFT, 2}, {ERROR}, {ERROR}, {SHIFT, 112}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {ERROR}, {SHIFT, 45}, {SHIFT, 46}, {ERROR}, {SHIFT, 47}, {SHIFT, 48}, {ERROR}, {SHIFT, 49}, 
    {ERROR}, {ERROR}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 54}, {SHIFT, 55}, {ERROR}, 
    {SHIFT, 56}, {ERROR}, {SHIFT, 57}, {SHIFT, 5}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {ERROR}, {SHIFT, 58}, {SHIFT, 9}, {ERROR}, {SHIFT, 10}, {SHIFT, 11}, {SHIFT, 12}, {ERROR}, {SHIFT, 59}, {ERROR}, 
    {ERROR}, {SHIFT, 13}, {ERROR}, {ERROR}, {ERROR}, },

    // State 82
    {{SHIFT, 1}, {ERROR}, {ERROR}, {SHIFT, 2}, {ERROR}, {ERROR}, {SHIFT, 113}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 5}, {SHIFT, 6}, {ERROR}, {ERROR}, {SHIFT, 7}, {SHIFT, 8}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 9}, {ERROR}, {SHIFT, 10}, {SHIFT, 11}, {SHIFT, 12}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 13}, {ERROR}, {ERROR}, {ERROR}, },

    // State 83
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {REDUCE, 42}, {SHIFT, 45}, {SHIFT, 46}, {REDUCE, 42}, {SHIFT, 47}, {SHIFT, 48}, {REDUCE, 42}, {SHIFT, 49}, 
    {REDUCE, 42}, {REDUCE, 42}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {REDUCE, 42}, {SHIFT, 53}, {SHIFT, 54}, {REDUCE, 42}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 42}, {REDUCE, 42}, {REDUCE, 42}, {REDUCE, 42}, {REDUCE, 42}, {REDUCE, 42}, {REDUCE, 42}, {REDUCE, 42}, {ERROR}, 
    {ERROR}, {REDUCE, 42}, {REDUCE, 42}, {REDUCE, 42}, {REDUCE, 42}, {REDUCE, 42}, {REDUCE, 42}, {REDUCE, 42}, {SHIFT, 59}, {ERROR}, 
    {REDUCE, 42}, {REDUCE, 42}, {ERROR}, {REDUCE, 42}, {ERROR}, },

    // State 84
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 48}, {ERROR}, 
    {SHIFT, 44}, {ERROR}, {REDUCE, 48}, {SHIFT, 45}, {SHIFT, 46}, {REDUCE, 48}, {SHIFT, 47}, {SHIFT, 48}, {REDUCE, 48}, {SHIFT, 49}, 
    {REDUCE, 48}, {REDUCE, 48}, {REDUCE, 48}, {REDUCE, 48}, {ERROR}, {REDUCE, 48}, {REDUCE, 48}, {REDUCE, 48}, {REDUCE, 48}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 48}, {REDUCE, 48}, {REDUCE, 48}, {REDUCE, 48}, {REDUCE, 48}, {REDUCE, 48}, {REDUCE, 48}, {REDUCE, 48}, {ERROR}, 
    {ERROR}, {REDUCE, 48}, {REDUCE, 48}, {REDUCE, 48}, {REDUCE, 48}, {REDUCE, 48}, {REDUCE, 48}, {REDUCE, 48}, {ERROR}, {ERROR}, 
    {REDUCE, 48}, {REDUCE, 48}, {ERROR}, {REDUCE, 48}, {ERROR}, },

    // State 85
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 40}, {REDUCE, 40}, 
    {REDUCE, 40}, {ERROR}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {SHIFT, 48}, {REDUCE, 40}, {REDUCE, 40}, 
    {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {ERROR}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {ERROR}, 
    {ERROR}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {ERROR}, 
    {REDUCE, 40}, {REDUCE, 40}, {ERROR}, {REDUCE, 40}, {ERROR}, },

    // State 86
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 38}, {REDUCE, 38}, 
    {REDUCE, 38}, {ERROR}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {SHIFT, 48}, {REDUCE, 38}, {REDUCE, 38}, 
    {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {ERROR}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {ERROR}, 
    {ERROR}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {ERROR}, 
    {REDUCE, 38}, {REDUCE, 38}, {ERROR}, {REDUCE, 38}, {ERROR}, },

    // State 87
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 36}, {REDUCE, 36}, 
    {SHIFT, 44}, {ERROR}, {REDUCE, 36}, {SHIFT, 45}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {SHIFT, 48}, {REDUCE, 36}, {SHIFT, 49}, 
    {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {ERROR}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {ERROR}, 
    {ERROR}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {ERROR}, 
    {REDUCE, 36}, {REDUCE, 36}, {ERROR}, {REDUCE, 36}, {ERROR}, },

    // State 88
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 37}, {REDUCE, 37}, 
    {SHIFT, 44}, {ERROR}, {REDUCE, 37}, {SHIFT, 45}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {SHIFT, 48}, {REDUCE, 37}, {SHIFT, 49}, 
    {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {ERROR}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {ERROR}, 
    {ERROR}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {ERROR}, 
    {REDUCE, 37}, {REDUCE, 37}, {ERROR}, {REDUCE, 37}, {ERROR}, },

    // State 89
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, 
    {REDUCE, 35}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, 
    {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {ERROR}, 
    {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {ERROR}, 
    {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {ERROR}, 
    {REDUCE, 35}, {REDUCE, 35}, {ERROR}, {REDUCE, 35}, {ERROR}, },

    // State 90
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 35}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 91
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 39}, {REDUCE, 39}, 
    {REDUCE, 39}, {ERROR}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {SHIFT, 48}, {REDUCE, 39}, {REDUCE, 39}, 
    {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {ERROR}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {ERROR}, 
    {ERROR}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {ERROR}, 
    {REDUCE, 39}, {REDUCE, 39}, {ERROR}, {REDUCE, 39}, {ERROR}, },

    // State 92
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 43}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {REDUCE, 43}, {SHIFT, 45}, {SHIFT, 46}, {REDUCE, 43}, {SHIFT, 47}, {SHIFT, 48}, {REDUCE, 43}, {SHIFT, 49}, 
    {REDUCE, 43}, {REDUCE, 43}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 43}, {ERROR}, {ERROR}, {REDUCE, 43}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {ERROR}, 
    {ERROR}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {SHIFT, 59}, {ERROR}, 
    {REDUCE, 43}, {REDUCE, 43}, {ERROR}, {REDUCE, 43}, {ERROR}, },

    // State 93
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 45}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {REDUCE, 45}, {SHIFT, 45}, {SHIFT, 46}, {REDUCE, 45}, {SHIFT, 47}, {SHIFT, 48}, {REDUCE, 45}, {SHIFT, 49}, 
    {REDUCE, 45}, {REDUCE, 45}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 45}, {ERROR}, {ERROR}, {REDUCE, 45}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {ERROR}, 
    {ERROR}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {SHIFT, 59}, {ERROR}, 
    {REDUCE, 45}, {REDUCE, 45}, {ERROR}, {REDUCE, 45}, {ERROR}, },

    // State 94
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 41}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {REDUCE, 41}, {SHIFT, 45}, {SHIFT, 46}, {REDUCE, 41}, {SHIFT, 47}, {SHIFT, 48}, {REDUCE, 41}, {SHIFT, 49}, 
    {REDUCE, 41}, {REDUCE, 41}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {REDUCE, 41}, {SHIFT, 53}, {SHIFT, 54}, {REDUCE, 41}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {ERROR}, 
    {ERROR}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {SHIFT, 59}, {ERROR}, 
    {REDUCE, 41}, {REDUCE, 41}, {ERROR}, {REDUCE, 41}, {ERROR}, },

    // State 95
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 44}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {REDUCE, 44}, {SHIFT, 45}, {SHIFT, 46}, {REDUCE, 44}, {SHIFT, 47}, {SHIFT, 48}, {REDUCE, 44}, {SHIFT, 49}, 
    {REDUCE, 44}, {REDUCE, 44}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 44}, {ERROR}, {ERROR}, {REDUCE, 44}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {ERROR}, 
    {ERROR}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {SHIFT, 59}, {ERROR}, 
    {REDUCE, 44}, {REDUCE, 44}, {ERROR}, {REDUCE, 44}, {ERROR}, },

    // State 96
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 46}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {REDUCE, 46}, {SHIFT, 45}, {SHIFT, 46}, {REDUCE, 46}, {SHIFT, 47}, {SHIFT, 48}, {REDUCE, 46}, {SHIFT, 49}, 
    {REDUCE, 46}, {REDUCE, 46}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 46}, {ERROR}, {ERROR}, {REDUCE, 46}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {ERROR}, 
    {ERROR}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {SHIFT, 59}, {ERROR}, 
    {REDUCE, 46}, {REDUCE, 46}, {ERROR}, {REDUCE, 46}, {ERROR}, },

    // State 97
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {ERROR}, {SHIFT, 45}, {SHIFT, 46}, {ERROR}, {SHIFT, 47}, {SHIFT, 48}, {ERROR}, {SHIFT, 49}, 
    {SHIFT, 114}, {ERROR}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 54}, {SHIFT, 55}, {ERROR}, 
    {SHIFT, 56}, {ERROR}, {SHIFT, 57}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 58}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 59}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 98
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {ERROR}, {SHIFT, 45}, {SHIFT, 46}, {ERROR}, {SHIFT, 47}, {SHIFT, 48}, {ERROR}, {SHIFT, 49}, 
    {ERROR}, {ERROR}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 54}, {SHIFT, 55}, {ERROR}, 
    {SHIFT, 56}, {SHIFT, 115}, {SHIFT, 57}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 58}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 59}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 99
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {REDUCE, 50}, {SHIFT, 45}, {SHIFT, 46}, {REDUCE, 50}, {SHIFT, 47}, {SHIFT, 48}, {REDUCE, 50}, {SHIFT, 49}, 
    {REDUCE, 50}, {REDUCE, 50}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 54}, {REDUCE, 50}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 50}, {REDUCE, 50}, {REDUCE, 50}, {REDUCE, 50}, {REDUCE, 50}, {REDUCE, 50}, {REDUCE, 50}, {REDUCE, 50}, {ERROR}, 
    {ERROR}, {REDUCE, 50}, {REDUCE, 50}, {REDUCE, 50}, {REDUCE, 50}, {REDUCE, 50}, {REDUCE, 50}, {REDUCE, 50}, {SHIFT, 59}, {ERROR}, 
    {REDUCE, 50}, {REDUCE, 50}, {ERROR}, {REDUCE, 50}, {ERROR}, },

    // State 100
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {REDUCE, 49}, {SHIFT, 45}, {SHIFT, 46}, {REDUCE, 49}, {SHIFT, 47}, {SHIFT, 48}, {REDUCE, 49}, {SHIFT, 49}, 
    {REDUCE, 49}, {REDUCE, 49}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 54}, {REDUCE, 49}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 49}, {SHIFT, 57}, {REDUCE, 49}, {REDUCE, 49}, {REDUCE, 49}, {REDUCE, 49}, {REDUCE, 49}, {REDUCE, 49}, {ERROR}, 
    {ERROR}, {REDUCE, 49}, {REDUCE, 49}, {REDUCE, 49}, {REDUCE, 49}, {REDUCE, 49}, {REDUCE, 49}, {REDUCE, 49}, {SHIFT, 59}, {ERROR}, 
    {REDUCE, 49}, {REDUCE, 49}, {ERROR}, {REDUCE, 49}, {ERROR}, },

    // State 101
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 47}, {ERROR}, 
    {SHIFT, 44}, {ERROR}, {REDUCE, 47}, {SHIFT, 45}, {SHIFT, 46}, {REDUCE, 47}, {SHIFT, 47}, {SHIFT, 48}, {REDUCE, 47}, {SHIFT, 49}, 
    {REDUCE, 47}, {REDUCE, 47}, {REDUCE, 47}, {REDUCE, 47}, {ERROR}, {REDUCE, 47}, {REDUCE, 47}, {REDUCE, 47}, {REDUCE, 47}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 47}, {REDUCE, 47}, {REDUCE, 47}, {REDUCE, 47}, {REDUCE, 47}, {REDUCE, 47}, {REDUCE, 47}, {REDUCE, 47}, {ERROR}, 
    {ERROR}, {REDUCE, 47}, {REDUCE, 47}, {REDUCE, 47}, {REDUCE, 47}, {REDUCE, 47}, {REDUCE, 47}, {REDUCE, 47}, {ERROR}, {ERROR}, 
    {REDUCE, 47}, {REDUCE, 47}, {ERROR}, {REDUCE, 47}, {ERROR}, },

    // State 102
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, 
    {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, 
    {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {ERROR}, 
    {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {ERROR}, 
    {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {ERROR}, 
    {REDUCE, 33}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {ERROR}, },

    // State 103
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 57}, {REDUCE, 57}, 
    {REDUCE, 57}, {ERROR}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, 
    {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {ERROR}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {ERROR}, 
    {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {ERROR}, 
    {ERROR}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {REDUCE, 57}, {ERROR}, 
    {REDUCE, 57}, {REDUCE, 57}, {ERROR}, {REDUCE, 57}, {ERROR}, },

    // State 104
    {{ERROR}, {SHIFT, 116}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 105
    {{ERROR}, {SHIFT, 66}, {SHIFT, 117}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 106
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 55}, {REDUCE, 55}, 
    {REDUCE, 55}, {ERROR}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, 
    {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {ERROR}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {ERROR}, 
    {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {ERROR}, 
    {ERROR}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {REDUCE, 55}, {ERROR}, 
    {REDUCE, 55}, {REDUCE, 55}, {ERROR}, {REDUCE, 55}, {ERROR}, },

    // State 107
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 12}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {ERROR}, 
    {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {ERROR}, {ERROR}, },

    // State 108
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 10}, {ERROR}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {ERROR}, {ERROR}, 
    {REDUCE, 10}, {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, },

    // State 109
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 25}, {ERROR}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {ERROR}, {ERROR}, 
    {REDUCE, 25}, {REDUCE, 25}, {ERROR}, {ERROR}, {ERROR}, },

    // State 110
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, 
    {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, 
    {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {ERROR}, 
    {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {ERROR}, 
    {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {ERROR}, 
    {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, {ERROR}, },

    // State 111
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, 
    {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, 
    {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {ERROR}, 
    {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {ERROR}, 
    {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {ERROR}, 
    {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {ERROR}, },

    // State 112
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 13}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {ERROR}, 
    {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {ERROR}, {ERROR}, },

    // State 113
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 9}, {ERROR}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {ERROR}, {ERROR}, 
    {REDUCE, 9}, {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, },

    // State 114
    {{ERROR}, {SHIFT, 118}, {ERROR}, {SHIFT, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, {SHIFT, 24}, 
    {ERROR}, {SHIFT, 25}, {SHIFT, 26}, {ERROR}, {SHIFT, 27}, },

    // State 115
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, 
    {REDUCE, 34}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, 
    {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {ERROR}, 
    {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {ERROR}, 
    {ERROR}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {ERROR}, 
    {REDUCE, 34}, {REDUCE, 34}, {ERROR}, {REDUCE, 34}, {ERROR}, },

    // State 116
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {ERROR}, {SHIFT, 45}, {SHIFT, 46}, {ERROR}, {SHIFT, 47}, {SHIFT, 48}, {ERROR}, {SHIFT, 49}, 
    {ERROR}, {ERROR}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 54}, {SHIFT, 55}, {ERROR}, 
    {SHIFT, 56}, {SHIFT, 119}, {SHIFT, 57}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 58}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 59}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 117
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 23}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 23}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, },

    // State 118
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 42}, {SHIFT, 43}, 
    {SHIFT, 44}, {ERROR}, {REDUCE, 53}, {SHIFT, 45}, {SHIFT, 46}, {REDUCE, 53}, {SHIFT, 47}, {SHIFT, 48}, {REDUCE, 53}, {SHIFT, 49}, 
    {REDUCE, 53}, {REDUCE, 53}, {SHIFT, 50}, {SHIFT, 51}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 54}, {SHIFT, 55}, {ERROR}, 
    {SHIFT, 56}, {REDUCE, 53}, {SHIFT, 57}, {REDUCE, 53}, {REDUCE, 53}, {REDUCE, 53}, {REDUCE, 53}, {REDUCE, 53}, {REDUCE, 53}, {ERROR}, 
    {ERROR}, {SHIFT, 58}, {REDUCE, 53}, {REDUCE, 53}, {REDUCE, 53}, {REDUCE, 53}, {REDUCE, 53}, {REDUCE, 53}, {SHIFT, 59}, {ERROR}, 
    {REDUCE, 53}, {REDUCE, 53}, {ERROR}, {REDUCE, 53}, {ERROR}, },

    // State 119
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 28}, {REDUCE, 28}, 
    {REDUCE, 28}, {ERROR}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, 
    {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {ERROR}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {ERROR}, 
    {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {ERROR}, 
    {ERROR}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {ERROR}, 
    {REDUCE, 28}, {REDUCE, 28}, {ERROR}, {REDUCE, 28}, {ERROR}, },

}; // Parser::table


