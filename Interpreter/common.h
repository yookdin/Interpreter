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

enum Symbol { LEFT_PAREN, RIGHT_PAREN, NUM, OP, EXP, EPSILON };

string symbol_to_string(Symbol sym);


#endif /* common_h */
