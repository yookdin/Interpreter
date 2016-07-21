//
//  utils.h
//  Interpreter
//
//  Created by Yuval Dinari on 7/18/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef utils_h
#define utils_h

class Operator;

//==========================================================================================================
// Set that support insert(another-set) operation
//==========================================================================================================
template<class T>
class Set: public set<T> {
public:
    Set(){}
    Set(initializer_list<T> il): set<T>(il) {}
    
    void insert(set<T>& other) {
        set<T>::insert(other.begin(), other.end());
    }
    
    void insert(Set<T>& other) {
        set<T>::insert(other.begin(), other.end());
    }
    
    void insert(Set<T>&& other) {
        set<T>::insert(other.begin(), other.end());
    }
    
    
    void insert(T value) {
        set<T>::insert(value);
    }
};


//==========================================================================================================
// Bidirectional map, that enables retreiving value by either of the pair values
//==========================================================================================================
template <class T1, class T2>
class bimap {
public:
    
    typedef pair<T1,T2> value_type;

    bimap(initializer_list<value_type> il) {
        for(auto& p: il) add(p.first, p.second);
    }

    void add(const T1 t1, const T2 t2) {
        map1[t1] = t2;
        map2[t2] = t1;
    }
    
    // Note: this just retrieved if exists, doesn't add
    T2 operator[](const T1 t) {
        if(map1.count(t) != 0)
            return map1[t];
        else
            throw string("Value doesn't exist in bimap");
    }
    
    // Note: this just retrieved if exists, doesn't add
    T1 operator[](const T2 t) {
        if(map2.count(t) != 0)
            return map2[t];
        else
            throw string("Value doesn't exist in bimap");
    }
    
private:
    map<T1,T2> map1;
    map<T2,T1> map2;
};


//==========================================================================================================
// The symbols of the language
//==========================================================================================================
enum Symbol {
    //------------------------------------------------------------------------------------------------------
    // The start symbol. It is a nonterminal but shouldn't appear in internal DFA
    //------------------------------------------------------------------------------------------------------
    START = -1,
    
    //------------------------------------------------------------------------------------------------------
    // Punctuations and keywords (actually it's the same thing)
    //------------------------------------------------------------------------------------------------------
    LEFT_PAREN = 0, RIGHT_PAREN, EOI, ASSIGN, SEMI_COLON, LEFT_CURLY, RIGHT_CURLY,
    IF, ELSE,

    //------------------------------------------------------------------------------------------------------
    // Terminals with values
    //------------------------------------------------------------------------------------------------------    
    NUM, ID,
    
    //------------------------------------------------------------------------------------------------------    
    // Operators
    //------------------------------------------------------------------------------------------------------    
    ADD, SUB, MUL, DIV, MOD, NOT, OR, AND, EQ, NE, GT, LT, GE, LE, STR_MATCH, NO_STR_MATCH, QUESTION_MARK, COLON,    
    
    //------------------------------------------------------------------------------------------------------
    // Nonterminals
    //------------------------------------------------------------------------------------------------------
    EXP, BLOCK, STATEMENT, STATEMENTS
};

#define NUM_TABLE_SYMBOLS (Symbol::STATEMENTS + 1)
#define NONTERMINALS_START (Symbol::EXP)

extern bimap<Symbol, string> symbol_str_map;


bool is_nonterminal(Symbol sym);
bool is_terminal(Symbol sym);
bool is_op(Symbol sym);
Operator* get_op(Symbol sym);
Operator* get_op(string name);

string& trim(string& line);



#endif /* utils_h */















