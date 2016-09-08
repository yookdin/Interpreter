// Generated Symbol header file

#ifndef symbol_hpp
#define symbol_hpp

#include "bimap.h"

//==========================================================================================================
// The symbols of the language (terminals and nonterminals
//==========================================================================================================
enum Symbol {
	START = -1,
    EXP, STATEMENT, 
    EOI, LEFT_PAREN, RIGHT_PAREN, ADD, ASSIGN, BOOL, ID, NUM, STRING, 
};

#define NUM_SYMBOLS 11
#define NUM_NON_TERMINALS 2

bool is_nonterminal(Symbol s);
bool is_terminal(Symbol s);

// A bidirectional map of Symbols and their string representation
extern bimap<Symbol, string> symbol_str_map;

#endif // symbol_hpp
