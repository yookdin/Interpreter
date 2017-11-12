// Generated Symbol header file, do not change manually!

#ifndef symbol_hpp
#define symbol_hpp

#include "bimap.h"

//============================================================================================================
// The symbols of the language (terminals and nonterminals).
// The nonterminals appear first.
//============================================================================================================
enum Symbol {
    // Nonterminals
    START = -1, COMMAND_CALL, EXP, EXP_LIST, FUNC_CALL, PARAM_VAL, PARAM_VALS_LIST, STATEMENT, STATEMENTS, 

    // Terminals
    NOT_EQUAL, NO_STR_MATCH, MOD, LEFT_PAREN, RIGHT_PAREN, MUL, ADD, COMMA, SUB, DOT, DOUBLE_DOT, DIV, COLON, 
    SEMI_COLON, LESS_THAN, LESS_THAN_EQUAL, ASSIGN, EQUAL, GREATER_THAN, GREATER_THAN_EQUAL, QUESTION_MARK, 
    CONDITIONAL_ASSIGN, LEFT_BRACKET, RIGHT_BRACKET, AND, BREAK, CONTINUE, ELSE, FINALLY, FOR, IF, IN, NOT, 
    OR, REPEAT, TIMES, TRY, WHILE, LEFT_CURLY, RIGHT_CURLY, STR_MATCH, BOOL, EOI, ID, NUM, PARAM, STRING, 
};

#define NUM_SYMBOLS 55
#define NUM_NON_TERMINALS 8

bool is_nonterminal(Symbol s);
bool is_terminal(Symbol s);

// A bidirectional map of Symbols and their string representation
extern bimap<Symbol, string> symbol_str_map;

#endif // symbol_hpp
