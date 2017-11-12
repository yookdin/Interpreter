// Generated Symbol source file, do not change manually!

#include "Symbol.hpp"


bool is_nonterminal(Symbol s) {
    return s < NUM_NON_TERMINALS;
}

bool is_terminal(Symbol s) {
    return not is_nonterminal(s);
}

bimap<Symbol, string> symbol_str_map = {
    {START,              "START"},
    {COMMAND_CALL,       "COMMAND_CALL"},
    {EXP,                "EXP"},
    {EXP_LIST,           "EXP_LIST"},
    {FUNC_CALL,          "FUNC_CALL"},
    {PARAM_VAL,          "PARAM_VAL"},
    {PARAM_VALS_LIST,    "PARAM_VALS_LIST"},
    {STATEMENT,          "STATEMENT"},
    {STATEMENTS,         "STATEMENTS"},
    {NOT_EQUAL,          "!="},
    {NO_STR_MATCH,       "!~"},
    {MOD,                "%"},
    {LEFT_PAREN,         "("},
    {RIGHT_PAREN,        ")"},
    {MUL,                "*"},
    {ADD,                "+"},
    {COMMA,              ","},
    {SUB,                "-"},
    {DOT,                "."},
    {DOUBLE_DOT,         ".."},
    {DIV,                "/"},
    {COLON,              ":"},
    {SEMI_COLON,         ";"},
    {LESS_THAN,          "<"},
    {LESS_THAN_EQUAL,    "<="},
    {ASSIGN,             "="},
    {EQUAL,              "=="},
    {GREATER_THAN,       ">"},
    {GREATER_THAN_EQUAL, ">="},
    {QUESTION_MARK,      "?"},
    {CONDITIONAL_ASSIGN, "?="},
    {LEFT_BRACKET,       "["},
    {RIGHT_BRACKET,      "]"},
    {AND,                "and"},
    {BREAK,              "break"},
    {CONTINUE,           "continue"},
    {ELSE,               "else"},
    {FINALLY,            "finally"},
    {FOR,                "for"},
    {IF,                 "if"},
    {IN,                 "in"},
    {NOT,                "not"},
    {OR,                 "or"},
    {REPEAT,             "repeat"},
    {TIMES,              "times"},
    {TRY,                "try"},
    {WHILE,              "while"},
    {LEFT_CURLY,         "{"},
    {RIGHT_CURLY,        "}"},
    {STR_MATCH,          "~"},
    {BOOL,               "BOOL"},
    {EOI,                "EOI"},
    {ID,                 "ID"},
    {NUM,                "NUM"},
    {PARAM,              "PARAM"},
    {STRING,             "STRING"},
};
