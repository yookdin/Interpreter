//
//  sip_tester_utils.cpp
//  SIPTester
//
//  Created by Yuval Dinari on 7/23/17.
//  Copyright © 2017 Yuk. All rights reserved.
//


#include <netdb.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <net/if.h>

#include "IP_Address.hpp"
#include "sip_tester_utils.hpp"


//======================================================================================================================
// SiptesterLib struct is responsible for doing initialization (and shutdown if it will be necessary) for the entire
// lib. The constructor should perform initializations and the destructor shutdowns.
// It is put in an anonymous namespace, so it is not known outside this file.
//======================================================================================================================
namespace {
    struct SiptesterLib {
        SiptesterLib() {
            srand(time(nullptr));
        }
    } siptester_lib;
}


//======================================================================================================================
//======================================================================================================================
thread_local ThreadConfig thread_config;


//======================================================================================================================
// Instantiaion of the Print class mutex 
//======================================================================================================================
mutex Print::print_mutex;


//==========================================================================================================
//==========================================================================================================
string to_string(ProtocolKind kind) {
    switch(kind) {
        case UDP: return "UDP";
        case TCP: return "TCP";
        case TLS: return "TLS";
    }
}


//==========================================================================================================
//==========================================================================================================
ProtocolKind string_to_protocol_kind(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    
    if(str == "UDP")
        return UDP;
    if(str == "TCP")
        return TCP;
    if(str == "TLS")
        return TLS;
    
    THROW << "Can't convert string \"" + str + "\" to ProtocolKind";
}

//==========================================================================================================
//==========================================================================================================
string to_string(Direction dir) {
    switch(dir) {
        case INCOMING: return "INCOMING";
        case OUTGOING: return "OUTGOING";
        case ANY: return "ANY";
    }
}


//==========================================================================================================
//==========================================================================================================
Direction string_to_direction(string dir_str) {
    transform(dir_str.begin(), dir_str.end(), dir_str.begin(), ::tolower);
    
    if(dir_str == "INCOMING") return INCOMING;
    if(dir_str == "OUTGOING") return OUTGOING;
    if(dir_str.empty() or dir_str == "any") return ANY;
    
    THROW << "String \"" + dir_str + "\" can't be converted to Direction";
}


//==========================================================================================================
// Return a vector containing the names from a comma separated list of names
//==========================================================================================================
vector<string> extract_names(string s) {
    vector<string> res;     
    stringstream sts(s);
    string name;
    
    while(getline(sts, name, ',')) {
        trim(name);
        res.push_back(name);
    }
    
    return res;
}


//======================================================================================================================
//======================================================================================================================
string get_print_prefix() {
    string thread_name = thread_config.get_thread_name();
    return "[" + thread_name + " " + get_time_string() + "] ";
}


//======================================================================================================================
//======================================================================================================================
AudioCodecType string_to_audio_codec_type(string s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    
    if(s == "PCMU")
        return PCMU;
    if(s == "OPUS")
        return OPUS;
    if(s == "OPUS2")
        return OPUS2;
    if(s == "ISAC")
        return ISAC;
    if(s == "ILBC")
        return ILBC;
    else
        THROW << "Unsupported audio codec: " + s;
}


//======================================================================================================================
// NTP timestamp is 32 bits of seconds since 1.1.1900, and another 32 bits for the fraction of a second.
// timeval struct has seconds since 1.1.1970 and microseconds. So it's needed to add the offset between the dates, and
// convert the microseconds into a fraction of the total number of different values that can be represented in the
// fractional part:
// frac = (u / 1,000,000) * 2^32
//======================================================================================================================
uint64_t get_ntp_timestamp() {
    uint64_t res;
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    
    // Put the seconds value in the upper 32 bits, and add the fractional part. Note: in the fractional part calculation the
    // shift operator is for multiplying by 2^32.
    res = ((tv.tv_sec + 2208988800) << 32) + ((uint64_t)tv.tv_usec << 32) / 1000000;
    
    return res;
}


//======================================================================================================================
//======================================================================================================================
string resolve_url(string url) {
    hostent *he = gethostbyname(url.c_str());
    
    if(he == nullptr) {
        string err;
        switch (h_errno)
        {
            case HOST_NOT_FOUND:
                err = "The host was not found";
                break;
            case NO_ADDRESS:
                err = "The name is valid but it has no address";
                break;
            case NO_RECOVERY:
                err = "A non-recoverable name server error occurred";
                break;
            case TRY_AGAIN:
                err = "The name server is temporarily unavailable";
                break;
        }
        
        THROW << "gethostbyname(\"" << url << "\") failed: " << err;
    }
    
    return inet_ntoa(*((in_addr*)he->h_addr_list[0]));
}


//==========================================================================================================
// Return the first "normal" IP. Skip interfaces with point-to-point flag, as this indicates a VPN interface
//==========================================================================================================
string get_local_ip() {
    
    string res;
    ifaddrs *ifap = nullptr, *it;
    
    if(getifaddrs(&ifap) != 0)
        THROW << "getifaddrs() failed";
    
    //------------------------------------------------------------------------------------------------------
    // Go over all network interfaces
    //------------------------------------------------------------------------------------------------------
    for(it = ifap; it != nullptr; it = it->ifa_next)
    {
        if(it->ifa_addr == nullptr or it->ifa_addr->sa_family != AF_INET) // Currently support only IP4
            continue;
        
        IP_Address addr = IP_Address::from_sockaddr(it->ifa_addr);
        
        if(addr.is_link_local() or addr.is_loopback())
            continue;
        
        if(it->ifa_flags & IFF_POINTOPOINT)
            continue;
        
        res = addr.to_string(); // A good IP was found
        break;
    }
    
    freeifaddrs(ifap);
    
    if(res.empty()) {
        THROW << "No suitable network interface found";
    }
    
    return res;
}


//==========================================================================================================
// Generate a random string, no smaller than min_len. If input str isn't empty append generated chars.
// If char_set isn't null, use it to choose the chars from.
//==========================================================================================================
void gen_random_string(string& str, int min_len, const string* char_set) {
    int max_len = 30; // Arbitrary
    
    if(min_len < 1 || min_len > max_len)
    {
        THROW << "gen_random_string(): min_len must be in [1.." << max_len << "]";
    }
    
    min_len -= str.length(); // Reduce because string may already contains data
    
    if(min_len < 1) {
        THROW << "gen_random_string(): min_len must be bigger than the length of input string";
    }
    
    int len_range = max_len - min_len + 1;  // Number of values from min_len to max_len
    int len = rand() % len_range + min_len; // add min_len because [rand() % x] is [0..x-1]
    
    for(int i = 0; i < len; ++i)
    {
        if(char_set != nullptr)
        {
            int index = rand() % char_set->length();
            str += (*char_set)[index];
        }
        else
        {
            int char_range = (126-33+1); // ASCII table printables are between 33 and 126
            char c = rand() % char_range + 33;
            str += c;
        }
    }
}

//==========================================================================================================
//==========================================================================================================
void check_valid_file(string var_name, string path, bool is_dir) {
    if(path.empty())
        THROW << var_name << " is empty";
    
    if(is_dir) {
        if(not dir_exists(path))
            THROW << var_name << " \"" << path << "\" doesn't exist or is not a directory";
    }
    else {
        if(not regular_file_exists(path))
            THROW << var_name << " \"" << path << "\" doesn't exist or is not a regular file";
    }
}
