// Generated Symbol source file

#include "Symbol.hpp"

bool is_nonterminal(Symbol s) { return s < NUM_NON_TERMINALS; }
bool is_terminal(Symbol s) { return not is_nonterminal(s); }

bimap<Symbol, string> symbol_str_map = {
    {BLOCK, "BLOCK"}, {EXP, "EXP"}, {STATEMENT, "STATEMENT"}, {STATEMENTS, "STATEMENTS"}, 
    {NE, "!="}, {NO_STRING_MATCH, "!~"}, {EOI, "$"}, {MOD, "%"}, {LEFT_PAREN, "("}, {RIGHT_PAREN, ")"}, {MUL, "*"}, {ADD, "+"}, {SUB, "-"}, {DIV, "/"}, 
    {COLON, ":"}, {SEMI_COLON, ";"}, {LT, "<"}, {LE, "<="}, {ASSIGN, "="}, {EQ, "=="}, {GT, ">"}, {GE, ">="}, {QUESTION_MARK, "?"}, {LEFT_CURLY, "{"}, 
    {RIGHT_CURLY, "}"}, {STRING_MATCH, "~"}, {ID, "ID"}, {NUM, "NUM"}, {AND, "and"}, {ELSE, "else"}, {IF, "if"}, {NOT, "not"}, {OR, "or"}, 
};
