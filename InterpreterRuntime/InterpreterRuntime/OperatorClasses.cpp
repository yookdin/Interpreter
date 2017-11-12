// Generated Operator source file, do not change manually!

#include "OperatorClasses.hpp"

//==========================================================================================================
// Set of operator symbols
//==========================================================================================================
set<Symbol> operators = {
    QUESTION_MARK, NO_STR_MATCH, STR_MATCH, GREATER_THAN_EQUAL, GREATER_THAN, LESS_THAN, MUL, EQUAL, 
    LESS_THAN_EQUAL, NOT, AND, DOT, DIV, OR, LEFT_BRACKET, COLON, ADD, MOD, NOT_EQUAL, SUB, 
};

//==========================================================================================================
// Map of operators. Keys are pair of the operator symbol and the number of operands, to enable operators 
// with the same name (like '-', that is both binary subtract and unary negation)
//==========================================================================================================
map<pair<Symbol, int>, Operator*> sym_op_map = {
    {{ADD, 2},                new Add()},
    {{AND, 2},                new And()},
    {{COLON, 2},              new Colon()},
    {{DIV, 2},                new Div()},
    {{DOT, 2},                new Dot()},
    {{EQUAL, 2},              new Equal()},
    {{GREATER_THAN, 2},       new GreaterThan()},
    {{GREATER_THAN_EQUAL, 2}, new GreaterThanEqual()},
    {{LEFT_BRACKET, 2},       new Subscript()},
    {{LESS_THAN, 2},          new LessThan()},
    {{LESS_THAN_EQUAL, 2},    new LessThanEqual()},
    {{MOD, 2},                new Mod()},
    {{MUL, 2},                new Mul()},
    {{NOT, 1},                new Not()},
    {{NOT_EQUAL, 2},          new NotEqual()},
    {{NO_STR_MATCH, 2},       new NoStrMatch()},
    {{OR, 2},                 new Or()},
    {{QUESTION_MARK, 2},      new QuestionMark()},
    {{STR_MATCH, 2},          new StrMatch()},
    {{SUB, 1},                new Minus()},
    {{SUB, 2},                new Subtract()},
};


//==========================================================================================================
//==========================================================================================================
bool is_op(Symbol s) {
    return operators.count(s) != 0; 
}

//==========================================================================================================
//==========================================================================================================
Operator* get_op(Symbol s, int num_operands) {
    return sym_op_map[{s, num_operands}];
} 

