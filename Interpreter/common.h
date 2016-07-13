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
enum Symbol { REAL_START = -2, START = -1, EOI, LEFT_PAREN, RIGHT_PAREN, NUM, OP, EXP };
#define NUM_TABLE_SYMBOLS 6
#define NONTERMINALS_START 5

string symbol_to_string(int sym);
bool is_nonterminal(Symbol sym);
bool is_terminal(Symbol sym);


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
