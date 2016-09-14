// Generated parser tables file

#include "Parser.hpp"

//==========================================================================================================
// Table of productions info: Left-hand-side nonterminal and number of symbols on right-hand-side
//==========================================================================================================
vector<ProductionInfo> Parser::production_infos = {
    {START, 1}, {STATEMENTS, 1}, {STATEMENTS, 2}, {STATEMENTS, 3}, {STATEMENT, 3}, {STATEMENT, 3}, {STATEMENT, 1}, {BLOCK, 3}, {STATEMENT, 3}, {STATEMENT, 5}, 
    {STATEMENT, 3}, {STATEMENT, 4}, {STATEMENT, 1}, {STATEMENT, 1}, {STATEMENT, 1}, {STATEMENT, 1}, {STATEMENT, 1}, {COMMAND_CALL, 2}, {SEND_COMMAND, 2}, {SEND_COMMAND, 3}, 
    {EXP, 1}, {EXP, 1}, {EXP, 1}, {EXP, 1}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, 
    {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, {EXP, 3}, 
    {EXP, 2}, {EXP, 2}, {EXP, 5}, {EXP, 1}, {FUNC_CALL, 3}, {FUNC_CALL, 4}, {FUNC_CALL, 4}, {PARAMS_LIST, 1}, {PARAMS_LIST, 3}, {NAMED_PARAMS_LIST, 1}, 
    {NAMED_PARAMS_LIST, 3}, {NAMED_PARAMS_LIST, 2}, {NAMED_PARAM, 2}, 
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
        case 15: return extract_ast(elements);
        case 16: return extract_ast(elements);
        case 17: return new CommandAST(elements);
        case 18: return new SendCommandAST(elements);
        case 19: return new SendCommandAST(elements);
        case 20: return new NumAST(elements);
        case 21: return new BoolAST(elements);
        case 22: return new StringAST(elements);
        case 23: return new VarAST(elements);
        case 24: return extract_ast(elements);
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
        case 35: return new BopAST(elements);
        case 36: return new BopAST(elements);
        case 37: return new BopAST(elements);
        case 38: return new BopAST(elements);
        case 39: return new BopAST(elements);
        case 40: return new UopAST(elements);
        case 41: return new UopAST(elements);
        case 42: return new CondExpAST(elements);
        case 43: return extract_ast(elements);
        case 44: return new FuncAST(elements);
        case 45: return new FuncAST(elements);
        case 46: return new FuncAST(elements);
        case 47: return new ParamsAST(elements);
        case 48: return new ParamsAST(elements);
        case 49: return new NamedParamsAST(elements);
        case 50: return new NamedParamsAST(elements);
        case 51: return new NamedParamsAST(elements);
        case 52: return new NamedParamAST(elements);
    } // switch

    return nullptr;

} // Parser::gen_ast()


//==========================================================================================================
// Table of actions per (state, symbol) pair
//==========================================================================================================
vector<vector<Action>> Parser::table = {
    // State 0
    {{SHIFT, 1}, {SHIFT, 2}, {ERROR}, {SHIFT, 3}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {SHIFT, 5}, {SHIFT, 6}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 7}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 9}, {SHIFT, 10}, {ERROR}, {SHIFT, 11}, {ERROR}, {ERROR}, {SHIFT, 12}, {SHIFT, 13}, {ERROR}, {SHIFT, 14}, 
    },

    // State 1
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 6}, {REDUCE, 6}, {ERROR}, {ERROR}, {REDUCE, 6}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 6}, {REDUCE, 6}, {REDUCE, 6}, {REDUCE, 6}, {ERROR}, {ERROR}, {REDUCE, 6}, {REDUCE, 6}, {ERROR}, {REDUCE, 6}, 
    },

    // State 2
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {ERROR}, {REDUCE, 15}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {ERROR}, {REDUCE, 15}, {REDUCE, 15}, {ERROR}, {REDUCE, 15}, 
    },

    // State 3
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {ERROR}, {REDUCE, 14}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {ERROR}, {REDUCE, 14}, {REDUCE, 14}, {ERROR}, {REDUCE, 14}, 
    },

    // State 4
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {ERROR}, {REDUCE, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {ERROR}, {REDUCE, 16}, {REDUCE, 16}, {ERROR}, {REDUCE, 16}, 
    },

    // State 5
    {{SHIFT, 1}, {SHIFT, 2}, {ERROR}, {SHIFT, 3}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {SHIFT, 5}, {SHIFT, 15}, 
    {ERROR}, {ERROR}, {REDUCE, 1}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 16}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 7}, {REDUCE, 1}, {ERROR}, {ERROR}, {SHIFT, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 9}, {SHIFT, 10}, {ERROR}, {SHIFT, 11}, {ERROR}, {ERROR}, {SHIFT, 12}, {SHIFT, 13}, {ERROR}, {SHIFT, 14}, 
    },

    // State 6
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ACCEPT}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 7
    {{SHIFT, 1}, {SHIFT, 2}, {ERROR}, {SHIFT, 3}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {SHIFT, 5}, {SHIFT, 17}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 7}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 9}, {SHIFT, 10}, {ERROR}, {SHIFT, 11}, {ERROR}, {ERROR}, {SHIFT, 12}, {SHIFT, 13}, {ERROR}, {SHIFT, 14}, 
    },

    // State 8
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {SHIFT, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 20}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 21}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 22}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 9
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 12}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 12}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {ERROR}, {REDUCE, 12}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {ERROR}, {REDUCE, 12}, {REDUCE, 12}, {ERROR}, {REDUCE, 12}, 
    },

    // State 10
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 13}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 13}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {ERROR}, {REDUCE, 13}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {ERROR}, {REDUCE, 13}, {REDUCE, 13}, {ERROR}, {REDUCE, 13}, 
    },

    // State 11
    {{ERROR}, {ERROR}, {SHIFT, 24}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 12
    {{ERROR}, {ERROR}, {SHIFT, 33}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 13
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {SHIFT, 34}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {SHIFT, 35}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 14
    {{ERROR}, {ERROR}, {SHIFT, 36}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 15
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 2}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 2}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 16
    {{SHIFT, 1}, {SHIFT, 2}, {ERROR}, {SHIFT, 3}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {SHIFT, 5}, {SHIFT, 37}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 7}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 9}, {SHIFT, 10}, {ERROR}, {SHIFT, 11}, {ERROR}, {ERROR}, {SHIFT, 12}, {SHIFT, 13}, {ERROR}, {SHIFT, 14}, 
    },

    // State 17
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {SHIFT, 38}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 18
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {SHIFT, 39}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 49}, {ERROR}, {ERROR}, {REDUCE, 49}, {ERROR}, {ERROR}, {SHIFT, 40}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 49}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 49}, {REDUCE, 49}, {ERROR}, {ERROR}, {REDUCE, 49}, {ERROR}, {SHIFT, 23}, {REDUCE, 49}, {ERROR}, 
    {REDUCE, 49}, {REDUCE, 49}, {REDUCE, 49}, {REDUCE, 49}, {ERROR}, {ERROR}, {REDUCE, 49}, {REDUCE, 49}, {ERROR}, {REDUCE, 49}, 
    },

    // State 19
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {ERROR}, {REDUCE, 17}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {ERROR}, {REDUCE, 17}, {REDUCE, 17}, {ERROR}, {REDUCE, 17}, 
    },

    // State 20
    {{ERROR}, {ERROR}, {SHIFT, 41}, {SHIFT, 25}, {SHIFT, 18}, {SHIFT, 42}, {SHIFT, 43}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {SHIFT, 44}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {SHIFT, 23}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 21
    {{ERROR}, {ERROR}, {SHIFT, 45}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 22
    {{ERROR}, {ERROR}, {SHIFT, 46}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 23
    {{ERROR}, {ERROR}, {SHIFT, 47}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 24
    {{SHIFT, 1}, {SHIFT, 2}, {ERROR}, {SHIFT, 3}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {SHIFT, 48}, {ERROR}, 
    {SHIFT, 49}, {SHIFT, 50}, {ERROR}, {SHIFT, 51}, {ERROR}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {ERROR}, {SHIFT, 54}, 
    {SHIFT, 55}, {ERROR}, {ERROR}, {SHIFT, 56}, {SHIFT, 57}, {ERROR}, {SHIFT, 58}, {SHIFT, 59}, {SHIFT, 60}, {SHIFT, 61}, 
    {ERROR}, {SHIFT, 7}, {ERROR}, {SHIFT, 62}, {ERROR}, {SHIFT, 8}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 63}, 
    {SHIFT, 9}, {SHIFT, 10}, {ERROR}, {SHIFT, 11}, {ERROR}, {SHIFT, 64}, {SHIFT, 12}, {SHIFT, 13}, {ERROR}, {SHIFT, 14}, 
    },

    // State 25
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {ERROR}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, 
    {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {ERROR}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, 
    {ERROR}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {ERROR}, {REDUCE, 43}, {ERROR}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, 
    {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {ERROR}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, {REDUCE, 43}, 
    },

    // State 26
    {{ERROR}, {ERROR}, {SHIFT, 65}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 27
    {{ERROR}, {ERROR}, {SHIFT, 66}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 28
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, 
    {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, 
    {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, 
    {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {ERROR}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, {REDUCE, 21}, 
    },

    // State 29
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {SHIFT, 20}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, 
    {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, 
    {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, 
    {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {ERROR}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, {REDUCE, 23}, 
    },

    // State 30
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, 
    {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, 
    {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, 
    {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {ERROR}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, {REDUCE, 20}, 
    },

    // State 31
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, 
    {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, 
    {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, 
    {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {ERROR}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, {REDUCE, 22}, 
    },

    // State 32
    {{ERROR}, {ERROR}, {SHIFT, 67}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 33
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 49}, {SHIFT, 50}, {ERROR}, {SHIFT, 51}, {ERROR}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {ERROR}, {SHIFT, 54}, 
    {SHIFT, 55}, {ERROR}, {ERROR}, {SHIFT, 56}, {SHIFT, 57}, {ERROR}, {SHIFT, 58}, {SHIFT, 59}, {SHIFT, 60}, {SHIFT, 61}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 62}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 63}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 64}, {ERROR}, {ERROR}, {SHIFT, 68}, {ERROR}, 
    },

    // State 34
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 69}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 35
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {ERROR}, {REDUCE, 18}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {ERROR}, {REDUCE, 18}, {REDUCE, 18}, {ERROR}, {REDUCE, 18}, 
    },

    // State 36
    {{SHIFT, 1}, {SHIFT, 2}, {ERROR}, {SHIFT, 3}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {SHIFT, 70}, {ERROR}, 
    {SHIFT, 49}, {SHIFT, 50}, {ERROR}, {SHIFT, 51}, {ERROR}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {ERROR}, {SHIFT, 54}, 
    {SHIFT, 55}, {ERROR}, {ERROR}, {SHIFT, 56}, {SHIFT, 57}, {ERROR}, {SHIFT, 58}, {SHIFT, 59}, {SHIFT, 60}, {SHIFT, 61}, 
    {ERROR}, {SHIFT, 7}, {ERROR}, {SHIFT, 62}, {ERROR}, {SHIFT, 8}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 63}, 
    {SHIFT, 9}, {SHIFT, 10}, {ERROR}, {SHIFT, 11}, {ERROR}, {SHIFT, 64}, {SHIFT, 12}, {SHIFT, 13}, {ERROR}, {SHIFT, 14}, 
    },

    // State 37
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 3}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 3}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 38
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 7}, {REDUCE, 7}, {ERROR}, {ERROR}, {REDUCE, 7}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 7}, {REDUCE, 7}, {REDUCE, 7}, {REDUCE, 7}, {ERROR}, {ERROR}, {REDUCE, 7}, {REDUCE, 7}, {ERROR}, {REDUCE, 7}, 
    },

    // State 39
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 51}, {ERROR}, {ERROR}, {REDUCE, 51}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 51}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 51}, {REDUCE, 51}, {ERROR}, {ERROR}, {REDUCE, 51}, {ERROR}, {ERROR}, {REDUCE, 51}, {ERROR}, 
    {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {REDUCE, 51}, {ERROR}, {ERROR}, {REDUCE, 51}, {REDUCE, 51}, {ERROR}, {REDUCE, 51}, 
    },

    // State 40
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 18}, {SHIFT, 71}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 23}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 41
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 49}, {SHIFT, 50}, {ERROR}, {SHIFT, 51}, {ERROR}, {REDUCE, 47}, {SHIFT, 52}, {SHIFT, 53}, {SHIFT, 72}, {SHIFT, 54}, 
    {SHIFT, 55}, {ERROR}, {ERROR}, {SHIFT, 56}, {SHIFT, 57}, {ERROR}, {SHIFT, 58}, {SHIFT, 59}, {SHIFT, 60}, {SHIFT, 61}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 62}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 63}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 64}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 42
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 73}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 43
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 74}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 44
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {ERROR}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, 
    {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {ERROR}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, 
    {ERROR}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {ERROR}, {REDUCE, 44}, {ERROR}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, 
    {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {ERROR}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, {REDUCE, 44}, 
    },

    // State 45
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 49}, {SHIFT, 50}, {REDUCE, 4}, {SHIFT, 51}, {ERROR}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {ERROR}, {SHIFT, 54}, 
    {SHIFT, 55}, {ERROR}, {REDUCE, 4}, {SHIFT, 56}, {SHIFT, 57}, {ERROR}, {SHIFT, 58}, {SHIFT, 59}, {SHIFT, 60}, {SHIFT, 61}, 
    {ERROR}, {REDUCE, 4}, {REDUCE, 4}, {SHIFT, 62}, {ERROR}, {REDUCE, 4}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 63}, 
    {REDUCE, 4}, {REDUCE, 4}, {REDUCE, 4}, {REDUCE, 4}, {ERROR}, {SHIFT, 64}, {REDUCE, 4}, {REDUCE, 4}, {ERROR}, {REDUCE, 4}, 
    },

    // State 46
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 49}, {SHIFT, 50}, {REDUCE, 5}, {SHIFT, 51}, {ERROR}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {ERROR}, {SHIFT, 54}, 
    {SHIFT, 55}, {ERROR}, {REDUCE, 5}, {SHIFT, 56}, {SHIFT, 57}, {ERROR}, {SHIFT, 58}, {SHIFT, 59}, {SHIFT, 60}, {SHIFT, 61}, 
    {ERROR}, {REDUCE, 5}, {REDUCE, 5}, {SHIFT, 62}, {ERROR}, {REDUCE, 5}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 63}, 
    {REDUCE, 5}, {REDUCE, 5}, {REDUCE, 5}, {REDUCE, 5}, {ERROR}, {SHIFT, 64}, {REDUCE, 5}, {REDUCE, 5}, {ERROR}, {REDUCE, 5}, 
    },

    // State 47
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 49}, {SHIFT, 50}, {REDUCE, 52}, {SHIFT, 51}, {ERROR}, {REDUCE, 52}, {SHIFT, 52}, {SHIFT, 53}, {REDUCE, 52}, {SHIFT, 54}, 
    {SHIFT, 55}, {ERROR}, {REDUCE, 52}, {SHIFT, 56}, {SHIFT, 57}, {ERROR}, {SHIFT, 58}, {SHIFT, 59}, {SHIFT, 60}, {SHIFT, 61}, 
    {ERROR}, {REDUCE, 52}, {REDUCE, 52}, {SHIFT, 62}, {ERROR}, {REDUCE, 52}, {ERROR}, {REDUCE, 52}, {REDUCE, 52}, {SHIFT, 63}, 
    {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {REDUCE, 52}, {ERROR}, {SHIFT, 64}, {REDUCE, 52}, {REDUCE, 52}, {ERROR}, {REDUCE, 52}, 
    },

    // State 48
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 8}, {REDUCE, 8}, {ERROR}, {ERROR}, {REDUCE, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 8}, {REDUCE, 8}, {SHIFT, 75}, {REDUCE, 8}, {ERROR}, {ERROR}, {REDUCE, 8}, {REDUCE, 8}, {ERROR}, {REDUCE, 8}, 
    },

    // State 49
    {{ERROR}, {ERROR}, {SHIFT, 76}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 50
    {{ERROR}, {ERROR}, {SHIFT, 77}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 51
    {{ERROR}, {ERROR}, {SHIFT, 78}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 52
    {{ERROR}, {ERROR}, {SHIFT, 79}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 53
    {{ERROR}, {ERROR}, {SHIFT, 80}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 54
    {{ERROR}, {ERROR}, {SHIFT, 81}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 55
    {{ERROR}, {ERROR}, {SHIFT, 82}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 56
    {{ERROR}, {ERROR}, {SHIFT, 83}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 57
    {{ERROR}, {ERROR}, {SHIFT, 84}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 58
    {{ERROR}, {ERROR}, {SHIFT, 85}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 59
    {{ERROR}, {ERROR}, {SHIFT, 86}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 60
    {{ERROR}, {ERROR}, {SHIFT, 87}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 61
    {{ERROR}, {ERROR}, {SHIFT, 88}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 62
    {{ERROR}, {ERROR}, {SHIFT, 89}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 63
    {{ERROR}, {ERROR}, {SHIFT, 90}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 64
    {{ERROR}, {ERROR}, {SHIFT, 91}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 65
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 49}, {SHIFT, 50}, {ERROR}, {SHIFT, 51}, {ERROR}, {SHIFT, 92}, {SHIFT, 52}, {SHIFT, 53}, {ERROR}, {SHIFT, 54}, 
    {SHIFT, 55}, {ERROR}, {ERROR}, {SHIFT, 56}, {SHIFT, 57}, {ERROR}, {SHIFT, 58}, {SHIFT, 59}, {SHIFT, 60}, {SHIFT, 61}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 62}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 63}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 64}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 66
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {SHIFT, 51}, {ERROR}, {REDUCE, 41}, {SHIFT, 52}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, 
    {SHIFT, 55}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {ERROR}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, 
    {ERROR}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {ERROR}, {REDUCE, 41}, {ERROR}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, 
    {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {ERROR}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, {REDUCE, 41}, 
    },

    // State 67
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {ERROR}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, 
    {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {ERROR}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, 
    {ERROR}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {ERROR}, {REDUCE, 40}, {ERROR}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, 
    {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {ERROR}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, {REDUCE, 40}, 
    },

    // State 68
    {{SHIFT, 1}, {SHIFT, 2}, {ERROR}, {SHIFT, 3}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {SHIFT, 93}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 7}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 9}, {SHIFT, 10}, {ERROR}, {SHIFT, 11}, {ERROR}, {ERROR}, {SHIFT, 12}, {SHIFT, 13}, {ERROR}, {SHIFT, 14}, 
    },

    // State 69
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {ERROR}, {REDUCE, 19}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {ERROR}, {REDUCE, 19}, {REDUCE, 19}, {ERROR}, {REDUCE, 19}, 
    },

    // State 70
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 10}, {REDUCE, 10}, {ERROR}, {ERROR}, {REDUCE, 10}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {REDUCE, 10}, {ERROR}, {ERROR}, {REDUCE, 10}, {REDUCE, 10}, {ERROR}, {REDUCE, 10}, 
    },

    // State 71
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 50}, {ERROR}, {ERROR}, {REDUCE, 50}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 50}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 50}, {REDUCE, 50}, {ERROR}, {ERROR}, {REDUCE, 50}, {ERROR}, {ERROR}, {REDUCE, 50}, {ERROR}, 
    {REDUCE, 50}, {REDUCE, 50}, {REDUCE, 50}, {REDUCE, 50}, {ERROR}, {ERROR}, {REDUCE, 50}, {REDUCE, 50}, {ERROR}, {REDUCE, 50}, 
    },

    // State 72
    {{ERROR}, {ERROR}, {SHIFT, 41}, {SHIFT, 25}, {ERROR}, {ERROR}, {SHIFT, 94}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 73
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {ERROR}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, 
    {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {ERROR}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, 
    {ERROR}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {ERROR}, {REDUCE, 46}, {ERROR}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, 
    {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {ERROR}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, {REDUCE, 46}, 
    },

    // State 74
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {ERROR}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, 
    {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {ERROR}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, 
    {ERROR}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {ERROR}, {REDUCE, 45}, {ERROR}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, 
    {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {ERROR}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, {REDUCE, 45}, 
    },

    // State 75
    {{SHIFT, 1}, {SHIFT, 2}, {ERROR}, {SHIFT, 3}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 4}, {SHIFT, 95}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {SHIFT, 7}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 8}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 9}, {SHIFT, 10}, {ERROR}, {SHIFT, 11}, {ERROR}, {ERROR}, {SHIFT, 12}, {SHIFT, 13}, {ERROR}, {SHIFT, 14}, 
    },

    // State 76
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 31}, {SHIFT, 50}, {REDUCE, 31}, {SHIFT, 51}, {ERROR}, {REDUCE, 31}, {SHIFT, 52}, {SHIFT, 53}, {REDUCE, 31}, {SHIFT, 54}, 
    {SHIFT, 55}, {REDUCE, 31}, {REDUCE, 31}, {SHIFT, 56}, {SHIFT, 57}, {ERROR}, {REDUCE, 31}, {SHIFT, 59}, {SHIFT, 60}, {REDUCE, 31}, 
    {ERROR}, {REDUCE, 31}, {REDUCE, 31}, {SHIFT, 62}, {ERROR}, {REDUCE, 31}, {ERROR}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, 
    {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {ERROR}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, {REDUCE, 31}, 
    },

    // State 77
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 37}, {ERROR}, {REDUCE, 37}, {SHIFT, 51}, {ERROR}, {REDUCE, 37}, {SHIFT, 52}, {SHIFT, 53}, {REDUCE, 37}, {SHIFT, 54}, 
    {SHIFT, 55}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {ERROR}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, 
    {ERROR}, {REDUCE, 37}, {REDUCE, 37}, {ERROR}, {ERROR}, {REDUCE, 37}, {ERROR}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, 
    {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {ERROR}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, {REDUCE, 37}, 
    },

    // State 78
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, 
    {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, 
    {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, 
    {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {ERROR}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, {REDUCE, 29}, 
    },

    // State 79
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, 
    {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, 
    {ERROR}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, 
    {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {ERROR}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, {REDUCE, 27}, 
    },

    // State 80
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {SHIFT, 51}, {ERROR}, {REDUCE, 25}, {SHIFT, 52}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, 
    {SHIFT, 55}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {ERROR}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, 
    {ERROR}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {ERROR}, {REDUCE, 25}, {ERROR}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, 
    {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {ERROR}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, {REDUCE, 25}, 
    },

    // State 81
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {SHIFT, 51}, {ERROR}, {REDUCE, 26}, {SHIFT, 52}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, 
    {SHIFT, 55}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, 
    {ERROR}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, 
    {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {ERROR}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, {REDUCE, 26}, 
    },

    // State 82
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {ERROR}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, 
    {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {ERROR}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, 
    {ERROR}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {ERROR}, {REDUCE, 28}, {ERROR}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, 
    {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {ERROR}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, {REDUCE, 28}, 
    },

    // State 83
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 32}, {SHIFT, 50}, {REDUCE, 32}, {SHIFT, 51}, {ERROR}, {REDUCE, 32}, {SHIFT, 52}, {SHIFT, 53}, {REDUCE, 32}, {SHIFT, 54}, 
    {SHIFT, 55}, {REDUCE, 32}, {REDUCE, 32}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 32}, {ERROR}, {ERROR}, {REDUCE, 32}, 
    {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {SHIFT, 62}, {ERROR}, {REDUCE, 32}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, 
    {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {ERROR}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, {REDUCE, 32}, 
    },

    // State 84
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 34}, {SHIFT, 50}, {REDUCE, 34}, {SHIFT, 51}, {ERROR}, {REDUCE, 34}, {SHIFT, 52}, {SHIFT, 53}, {REDUCE, 34}, {SHIFT, 54}, 
    {SHIFT, 55}, {REDUCE, 34}, {REDUCE, 34}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 34}, {ERROR}, {ERROR}, {REDUCE, 34}, 
    {ERROR}, {REDUCE, 34}, {REDUCE, 34}, {SHIFT, 62}, {ERROR}, {REDUCE, 34}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, 
    {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {ERROR}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, {REDUCE, 34}, 
    },

    // State 85
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 30}, {SHIFT, 50}, {REDUCE, 30}, {SHIFT, 51}, {ERROR}, {REDUCE, 30}, {SHIFT, 52}, {SHIFT, 53}, {REDUCE, 30}, {SHIFT, 54}, 
    {SHIFT, 55}, {REDUCE, 30}, {REDUCE, 30}, {SHIFT, 56}, {SHIFT, 57}, {ERROR}, {REDUCE, 30}, {SHIFT, 59}, {SHIFT, 60}, {REDUCE, 30}, 
    {ERROR}, {REDUCE, 30}, {REDUCE, 30}, {SHIFT, 62}, {ERROR}, {REDUCE, 30}, {ERROR}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, 
    {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {ERROR}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, {REDUCE, 30}, 
    },

    // State 86
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 33}, {SHIFT, 50}, {REDUCE, 33}, {SHIFT, 51}, {ERROR}, {REDUCE, 33}, {SHIFT, 52}, {SHIFT, 53}, {REDUCE, 33}, {SHIFT, 54}, 
    {SHIFT, 55}, {REDUCE, 33}, {REDUCE, 33}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 33}, {ERROR}, {ERROR}, {REDUCE, 33}, 
    {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {SHIFT, 62}, {ERROR}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, 
    {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {ERROR}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, {REDUCE, 33}, 
    },

    // State 87
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 35}, {SHIFT, 50}, {REDUCE, 35}, {SHIFT, 51}, {ERROR}, {REDUCE, 35}, {SHIFT, 52}, {SHIFT, 53}, {REDUCE, 35}, {SHIFT, 54}, 
    {SHIFT, 55}, {REDUCE, 35}, {REDUCE, 35}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 35}, {ERROR}, {ERROR}, {REDUCE, 35}, 
    {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {SHIFT, 62}, {ERROR}, {REDUCE, 35}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, 
    {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {ERROR}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, {REDUCE, 35}, 
    },

    // State 88
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 49}, {SHIFT, 50}, {ERROR}, {SHIFT, 51}, {ERROR}, {ERROR}, {SHIFT, 52}, {SHIFT, 53}, {ERROR}, {SHIFT, 54}, 
    {SHIFT, 55}, {SHIFT, 96}, {ERROR}, {SHIFT, 56}, {SHIFT, 57}, {ERROR}, {SHIFT, 58}, {SHIFT, 59}, {SHIFT, 60}, {SHIFT, 61}, 
    {ERROR}, {ERROR}, {ERROR}, {SHIFT, 62}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 63}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 64}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 89
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 36}, {ERROR}, {REDUCE, 36}, {SHIFT, 51}, {ERROR}, {REDUCE, 36}, {SHIFT, 52}, {SHIFT, 53}, {REDUCE, 36}, {SHIFT, 54}, 
    {SHIFT, 55}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {ERROR}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, 
    {ERROR}, {REDUCE, 36}, {REDUCE, 36}, {ERROR}, {ERROR}, {REDUCE, 36}, {ERROR}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, 
    {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {ERROR}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, {REDUCE, 36}, 
    },

    // State 90
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 49}, {SHIFT, 50}, {REDUCE, 39}, {SHIFT, 51}, {ERROR}, {REDUCE, 39}, {SHIFT, 52}, {SHIFT, 53}, {REDUCE, 39}, {SHIFT, 54}, 
    {SHIFT, 55}, {REDUCE, 39}, {REDUCE, 39}, {SHIFT, 56}, {SHIFT, 57}, {ERROR}, {SHIFT, 58}, {SHIFT, 59}, {SHIFT, 60}, {REDUCE, 39}, 
    {ERROR}, {REDUCE, 39}, {REDUCE, 39}, {SHIFT, 62}, {ERROR}, {REDUCE, 39}, {ERROR}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, 
    {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {ERROR}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, {REDUCE, 39}, 
    },

    // State 91
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 49}, {SHIFT, 50}, {REDUCE, 38}, {SHIFT, 51}, {ERROR}, {REDUCE, 38}, {SHIFT, 52}, {SHIFT, 53}, {REDUCE, 38}, {SHIFT, 54}, 
    {SHIFT, 55}, {REDUCE, 38}, {REDUCE, 38}, {SHIFT, 56}, {SHIFT, 57}, {ERROR}, {SHIFT, 58}, {SHIFT, 59}, {SHIFT, 60}, {REDUCE, 38}, 
    {ERROR}, {REDUCE, 38}, {REDUCE, 38}, {SHIFT, 62}, {ERROR}, {REDUCE, 38}, {ERROR}, {REDUCE, 38}, {REDUCE, 38}, {SHIFT, 63}, 
    {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {ERROR}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, {REDUCE, 38}, 
    },

    // State 92
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, 
    {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, 
    {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, 
    {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {ERROR}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, {REDUCE, 24}, 
    },

    // State 93
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 11}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 11}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {ERROR}, {REDUCE, 11}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {ERROR}, {REDUCE, 11}, {REDUCE, 11}, {ERROR}, {REDUCE, 11}, 
    },

    // State 94
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {REDUCE, 48}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 95
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {REDUCE, 9}, {REDUCE, 9}, {ERROR}, {ERROR}, {REDUCE, 9}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {REDUCE, 9}, {ERROR}, {ERROR}, {REDUCE, 9}, {REDUCE, 9}, {ERROR}, {REDUCE, 9}, 
    },

    // State 96
    {{ERROR}, {ERROR}, {SHIFT, 97}, {SHIFT, 25}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 26}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 27}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 28}, {SHIFT, 29}, {SHIFT, 30}, {ERROR}, {SHIFT, 31}, {ERROR}, 
    {ERROR}, {ERROR}, {ERROR}, {ERROR}, {SHIFT, 32}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    },

    // State 97
    {{ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, {ERROR}, 
    {SHIFT, 49}, {SHIFT, 50}, {REDUCE, 42}, {SHIFT, 51}, {ERROR}, {REDUCE, 42}, {SHIFT, 52}, {SHIFT, 53}, {REDUCE, 42}, {SHIFT, 54}, 
    {SHIFT, 55}, {REDUCE, 42}, {REDUCE, 42}, {SHIFT, 56}, {SHIFT, 57}, {ERROR}, {SHIFT, 58}, {SHIFT, 59}, {SHIFT, 60}, {SHIFT, 61}, 
    {ERROR}, {REDUCE, 42}, {REDUCE, 42}, {SHIFT, 62}, {ERROR}, {REDUCE, 42}, {ERROR}, {REDUCE, 42}, {REDUCE, 42}, {SHIFT, 63}, 
    {REDUCE, 42}, {REDUCE, 42}, {REDUCE, 42}, {REDUCE, 42}, {ERROR}, {SHIFT, 64}, {REDUCE, 42}, {REDUCE, 42}, {REDUCE, 42}, {REDUCE, 42}, 
    },

}; // Parser::table


