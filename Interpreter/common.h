//
//  common.h
//  Interpreter
//
//  Created by Yuval Dinari on 7/6/16.
//  Copyright © 2016 Vonage. All rights reserved.
//
  
#ifndef common_h
#define common_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <regex>
#include <queue>
#include <poll.h>
#include <cmath>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/time.h>

using namespace std;

// EOI - end of input
enum Symbol { START = -1, LEFT_PAREN, RIGHT_PAREN, NUM, OP, EOI, EXP };
#define NUM_TABLE_SYMBOLS 6
#define NONTERMINALS_START 5

string symbol_to_string(int sym);
Symbol string_to_symbol(string str);
bool is_nonterminal(Symbol sym);
bool is_terminal(Symbol sym);
string& trim(string& line);


//==========================================================================================================
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


#endif /* common_h */
