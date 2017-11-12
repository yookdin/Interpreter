//
//  sip_tester_utils.hpp
//  SIPTester
//
//  Created by Yuval Dinari on 7/23/17.
//  Copyright © 2017 Yuk. All rights reserved.
//

#ifndef sip_tester_utils_hpp
#define sip_tester_utils_hpp

#include "common_utils.hpp"
#include "ThreadConfig.h"
#include "Print.h"
#include "sip_tester_types.h"


//==========================================================================================================
// Constants
//==========================================================================================================
#define MAX_RTP_PACKET_SIZE 2000
#define CONTROL_BUFFER_SIZE 500
#define CRLF "\r\n"
#define UDP_ID 17  // ID of UDP protocol in an IP header
#define MAX_CSEQ 4294967295  // 2^32 - 1
#define TELEPHONE_EVENT_PAYLOAD_TYPE 101
#define RED_PAYLOAD_TYPE 126


//==========================================================================================================
//==========================================================================================================
#define ASSERT_NOT_NULL(kind, x)\
if(x == nullptr) {\
    THROW << FUNC_NAME << ": " << kind << " '" << #x << "' mustn't be null";\
}


//==========================================================================================================
//==========================================================================================================
#define ASSERT_NOT_NEGATIVE(kind, x)\
if(x < 0) {\
    THROW << FUNC_NAME << ": " << kind << " '" << #x << "' mustn't be negative";\
}


//==========================================================================================================
// Prepend a list of arguments with a vector of strings containing their names. Macros don't support this,
// so quote the entire list, then call extract_names() to turn it into a string vector.
//==========================================================================================================
#define PREPEND_WITH_NAMES_LIST(...) extract_names(#__VA_ARGS__), __VA_ARGS__


//==========================================================================================================
// Call the set_vars() template function after preparing the parameters and adding the current function name
// (for debugging purposes)
//==========================================================================================================
#define SET_VARS(args, ...) set_vars(__func__, args, PREPEND_WITH_NAMES_LIST(__VA_ARGS__))


//==========================================================================================================
// Call set_exact_vars() - like set_vars() but require all variables to have corresponding arguments
//==========================================================================================================
#define SET_EXACT_VARS(args, ...) set_exact_vars(__func__, args, PREPEND_WITH_NAMES_LIST(__VA_ARGS__))


vector<string> extract_names(string s);
uint64_t get_ntp_timestamp();
string get_local_ip();
string resolve_url(string url);
void gen_random_string(string& str, int min_len, const string* char_set);
void check_valid_file(string var_name, string path, bool is_dir = false);


#endif /* sip_tester_utils_hpp */
