//
//  common_utils.hpp
//  SIPTester
//
//  Created by Yuval Dinari on 7/23/17.
//  Copyright © 2017 Yuk. All rights reserved.
//

#ifndef common_utils_hpp
#define common_utils_hpp

#include <string>
#include <vector>
using namespace std;

#include "Symbol.hpp"
#include "Address.hpp"
#include "parser_generator_utils.hpp"
 

bool stob(string);
int string_to_int(const string& s);
long string_to_long(const string& s);
string to_string(bool);
string get_time_string();
string get_log_time_string();
string get_extension(string &path);
string to_lower(string s);
void usleep2(int microseconds);
int gen_random_num(int low, int high, vector<int> avoids);
void create_directories(string path);
bool is_directory(string path);
string dirname(string path, int level = 1);
string basename(string path);
int64_t get_cur_time_ms();
string errno_to_string(int err_code);
bool flip();
string operator+ (const string& lhs, const int& rhs);
bool regular_file_exists(string path);
bool dir_exists(string path);
string join_strings(vector<string>& v, string delim);
string func_name(const string &pretty_func_name);

//==========================================================================================================
// Info about a language production, used by the parser
//==========================================================================================================
struct ProductionInfo {
    Symbol lhs;
    int rhs_size;
};


//==========================================================================================================
//==========================================================================================================
#define FUNC_NAME func_name(__PRETTY_FUNCTION__)



#endif /* common_utils_hpp */
