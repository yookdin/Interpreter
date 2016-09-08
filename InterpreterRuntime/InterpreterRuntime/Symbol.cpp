// Generated Symbol source file

#include "Symbol.hpp"

bool is_nonterminal(Symbol s) { return s < NUM_NON_TERMINALS; }
bool is_terminal(Symbol s) { return not is_nonterminal(s); }

bimap<Symbol, string> symbol_str_map = {
    {START, "START"}, {EXP, "EXP"}, {STATEMENT, "STATEMENT"}, 
    {EOI, "$"}, {LEFT_PAREN, "("}, {RIGHT_PAREN, ")"}, {ADD, "+"}, {ASSIGN, "="}, {BOOL, "BOOL"}, {ID, "ID"}, {NUM, "NUM"}, {STRING, "STRING"}, 
};
