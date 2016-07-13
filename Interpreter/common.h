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

enum Symbol { START = -1, LEFT_PAREN, RIGHT_PAREN, NUM, OP, EXP };
#define NUM_TABLE_SYMBOLS 5
#define NONTERMINALS_START 4

string symbol_to_string(int sym);
bool is_nonterminal(Symbol sym);


#endif /* common_h */
