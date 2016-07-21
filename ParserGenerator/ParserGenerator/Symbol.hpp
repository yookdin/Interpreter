// Generated Symbol header file

#include "bimap.h"

//==========================================================================================================
// The symbols of the language (terminals and nonterminals
//==========================================================================================================
enum Symbol {
	START = -1,
    BLOCK, EXP, STATEMENT, STATEMENTS, 
    NE, NO_STRING_MATCH, EOI, MOD, LEFT_PAREN, RIGHT_PAREN, MUL, ADD, SUB, DIV, 
    COLON, SEMI_COLON, LT, LE, ASSIGN, EQ, GT, GE, QUESTION_MARK, LEFT_CURLY, 
    RIGHT_CURLY, STRING_MATCH, ID, NUM, AND, ELSE, IF, NOT, OR, 
};

#define NUM_SYMBOLS 33
#define NUM_NON_TERMINALS 4

bool is_nonterminal(Symbol s);
bool is_terminal(Symbol s);

// A bidirectional map of Symbols and their string representation
extern bimap<Symbol, string> symbol_str_map;
