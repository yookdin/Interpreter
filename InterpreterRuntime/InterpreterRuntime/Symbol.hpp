// Generated Symbol header file

#ifndef symbol_hpp
#define symbol_hpp

#include "bimap.h"

//==========================================================================================================
// The symbols of the language (terminals and nonterminals
//==========================================================================================================
enum Symbol {
	START = -1,
    BLOCK, EXP, FUNC_CALL, NAMED_PARAM, NAMED_PARAMS_LIST, PARAMS_LIST, STATEMENT, STATEMENTS, 
    NE, NO_STR_MATCH, EOI, MOD, LEFT_PAREN, RIGHT_PAREN, MUL, ADD, COMMA, SUB, 
    DIV, COLON, SEMI_COLON, LT, LE, ASSIGN, EQ, GT, GE, QUESTION_MARK, 
    CONDITIONAL_ASSIGN, LEFT_CURLY, RIGHT_CURLY, STR_MATCH, BOOL, ID, NUM, STRING, AND, BREAK, 
    CONTINUE, ELSE, IF, NOT, OR, REPEAT, TIMES, WHILE, 
};

#define NUM_SYMBOLS 46
#define NUM_NON_TERMINALS 8

bool is_nonterminal(Symbol s);
bool is_terminal(Symbol s);

// A bidirectional map of Symbols and their string representation
extern bimap<Symbol, string> symbol_str_map;

#endif // symbol_hpp
