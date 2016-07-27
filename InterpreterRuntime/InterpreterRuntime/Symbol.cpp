// Generated Symbol source file

#include "Symbol.hpp"

bool is_nonterminal(Symbol s) { return s < NUM_NON_TERMINALS; }
bool is_terminal(Symbol s) { return not is_nonterminal(s); }

bimap<Symbol, string> symbol_str_map = {
    {START, "START"}, {BLOCK, "BLOCK"}, {EXP, "EXP"}, {FUNC_CALL, "FUNC_CALL"}, {NAMED_PARAM, "NAMED_PARAM"}, {NAMED_PARAMS_LIST, "NAMED_PARAMS_LIST"}, {PARAMS_LIST, "PARAMS_LIST"}, {STATEMENT, "STATEMENT"}, {STATEMENTS, "STATEMENTS"}, 
    {NE, "!="}, {NO_STR_MATCH, "!~"}, {EOI, "$"}, {MOD, "%"}, {LEFT_PAREN, "("}, {RIGHT_PAREN, ")"}, {MUL, "*"}, {ADD, "+"}, {COMMA, ","}, {SUB, "-"}, 
    {DIV, "/"}, {COLON, ":"}, {SEMI_COLON, ";"}, {LT, "<"}, {LE, "<="}, {ASSIGN, "="}, {EQ, "=="}, {GT, ">"}, {GE, ">="}, {QUESTION_MARK, "?"}, 
    {CONDITIONAL_ASSIGN, "?="}, {LEFT_CURLY, "{"}, {RIGHT_CURLY, "}"}, {STR_MATCH, "~"}, {BOOL, "BOOL"}, {ID, "ID"}, {NUM, "NUM"}, {STRING, "STRING"}, {AND, "and"}, {ELSE, "else"}, 
    {IF, "if"}, {NOT, "not"}, {OR, "or"}, {REPEAT, "repeat"}, {TIMES, "times"}, {WHILE, "while"}, 
};
