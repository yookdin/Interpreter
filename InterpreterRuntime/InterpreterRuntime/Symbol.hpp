// Generated Symbol header file

#ifndef symbol_hpp
#define symbol_hpp

#include "bimap.h"

//==========================================================================================================
// The symbols of the language (terminals and nonterminals
//==========================================================================================================
enum Symbol {
	START = -1,
    BLOCK, EXP, STATEMENT, STATEMENTS, 
    NE, NO_STR_MATCH, EOI, MOD, LEFT_PAREN, RIGHT_PAREN, MUL, ADD, COMMA, SUB, 
    DIV, COLON, SEMI_COLON, LT, LE, ASSIGN, EQ, GT, GE, QUESTION_MARK, 
    LEFT_CURLY, RIGHT_CURLY, STR_MATCH, ID, NUM, AND, ELSE, IF, NOT, OR, 
    REPEAT, TIMES, WHILE, 
};

#define NUM_SYMBOLS 37
#define NUM_NON_TERMINALS 4

bool is_nonterminal(Symbol s);
bool is_terminal(Symbol s);

// A bidirectional map of Symbols and their string representation
extern bimap<Symbol, string> symbol_str_map;

#endif // symbol_hpp
