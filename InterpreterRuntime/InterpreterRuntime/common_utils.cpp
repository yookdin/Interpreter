//
//  common_utils.cpp
//  SIPTester
//
//  Created by Yuval Dinari on 7/23/17.
//  Copyright © 2017 Yuk. All rights reserved.
//

#include <iomanip>
#include <future>
#include <vector>
#include <fstream>
#include <regex>
using namespace std;

#include <sys/time.h>
#include <sys/stat.h>

#include "common_utils.hpp"


//==========================================================================================================
// String to boolean
//==========================================================================================================
bool stob(string s)
{
    if(s == "true")
    {
        return true;
    }
    else if(s == "false")
    {
        return false;
    }
    else
    {
        THROW << "Wrong format of string for stob(): " << s;
    }
}


//==========================================================================================================
// Like stoi(), but fails if not entire string can be converted to a number
//==========================================================================================================
int string_to_int(const string& s) {
    if(s.empty())
        THROW << "Can't convert an empty string to int";
    
    size_t idx;
    int res = stoi(s, &idx);
    
    if(idx != s.size())
        THROW << "Can't convert \"" << s << "\" to int";
    
    return res;
}


//==========================================================================================================
// Like stol(), but fails if not entire string can be converted to a number
//==========================================================================================================
long string_to_long(const string& s) {
    if(s.empty())
        THROW << "Can't convert an empty string to long";
    
    size_t idx;
    long res = stol(s, &idx);
    
    if(idx != s.size())
        THROW << "Can't convert \"" << s << "\" to long";
    
    return res;
}


//==========================================================================================================
//==========================================================================================================
string to_string(bool b) { return (b ? "true" : "false"); }


//======================================================================================================================
// Return the extension if exists (without the dot)
//======================================================================================================================
string get_extension(string &path) {
    for(long i = path.length() - 1; i >= 0; --i)
    {
        if(path[i] == '.') return path.substr(i+1);
        if(path[i] == '/') break;
    }
    
    return "";
}


//==========================================================================================================
// Return a string representing the current time in format: hh:mm:ss.milli
//==========================================================================================================
string get_time_string()
{
    struct timeval  tv;
    struct tm       *plocalTime;
    gettimeofday(&tv, NULL);
    plocalTime = localtime(&tv.tv_sec);
    int h       = plocalTime->tm_hour;
    int m       = plocalTime->tm_min;
    int s       = plocalTime->tm_sec;
    int milli   = tv.tv_usec / 1000;
    
    ostringstream oss;
    oss << setfill('0') << setw(2) << h << ":"
    << setfill('0') << setw(2) << m << ":"
    << setfill('0') << setw(2) << s << "."
    << setfill('0') << setw(3) << milli;
    
    return oss.str();
}


//======================================================================================================================
//======================================================================================================================
string get_log_time_string()
{
    return "[" + get_time_string() + "] ";
}


//======================================================================================================================
//======================================================================================================================
void usleep2(int microseconds)
{
    this_thread::sleep_until(chrono::system_clock::now() + chrono::microseconds(microseconds));
}


//======================================================================================================================
//======================================================================================================================
string to_lower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}


//======================================================================================================================
//======================================================================================================================
int gen_random_num(int low, int high, vector<int> avoids) {
    int n;
    
    do {
        n = rand() % (high - low + 1) + low;
    } while(find(avoids.begin(), avoids.end(), n) != avoids.end());
    
    return n;
}


//======================================================================================================================
//======================================================================================================================
string operator+ (const string& lhs, const int& rhs) {
    return lhs + to_string(rhs);
}


//======================================================================================================================
//======================================================================================================================
void create_directories(string path) {
    if(ifstream(path)) {
        if(not is_directory(path))
            THROW << "Can't create directory " << path << ". File exists and is not a directory";
    }
    else {
        create_directories(dirname(path));
        
        if(mkdir(path.c_str(), 0777) != 0)
        {
            THROW << "Couldn't create directory " << path << ", strerror(): " << strerror(errno);
        }
    }
}


//======================================================================================================================
//======================================================================================================================
bool is_directory(string path) {
    struct stat buf;
    stat(path.c_str(), &buf);
    return S_ISDIR(buf.st_mode);
}


//======================================================================================================================
// Return the <level> dirname of the path (e.g. if level is 2, return the dirname of the dirname of the path).
//======================================================================================================================
string dirname(string path, int level)
{
    if(level <= 0)
    {
        THROW << "level should be positive";
    }
    
    // Replace consecutive slashes with a single one
    string res = path;
    res = regex_replace(res, regex("/+"), "/");
    
    for(int i = 0; i < level; ++i)
    {
        unsigned long pos = res.find_last_of('/');
        
        if(pos == string::npos)
        {
            return ".";
        }
        else
        {
            res = path.substr(0, pos);
        }
    }
    
    return res;
}


//======================================================================================================================
// Return the file name part of a path
//======================================================================================================================
string basename(string path)
{
    // This works even if no / in path, becaue string::npos + 1 = 0
    return path.substr(path.find_last_of('/') + 1);
}


//======================================================================================================================
//======================================================================================================================
int64_t get_cur_time_ms() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    
}


//======================================================================================================================
//======================================================================================================================
string errno_to_string(int err_code) {
    switch (err_code) {
        case EPERM: return "EPERM";
        case ENOENT: return "ENOENT";
        case ESRCH: return "ESRCH";
        case EINTR: return "EINTR";
        case EIO: return "EIO";
        case ENXIO: return "ENXIO";
        case E2BIG: return "E2BIG"; 
        case ENOEXEC: return "ENOEXEC"; 
        case EBADF: return "EBADF"; 
        case ECHILD: return "ECHILD"; 
        case EDEADLK: return "EDEADLK"; 
        case ENOMEM: return "ENOMEM"; 
        case EACCES: return "EACCES"; 
        case EFAULT: return "EFAULT"; 
        case ENOTBLK: return "ENOTBLK";
        case EBUSY: return "EBUSY";
        case EEXIST: return "EEXIST";
        case EXDEV: return "EXDEV";
        case ENODEV: return "ENODEV";
        case ENOTDIR: return "ENOTDIR";
        case EISDIR: return "EISDIR";
        case EINVAL: return "EINVAL";
        case ENFILE: return "ENFILE";
        case EMFILE: return "EMFILE";
        case ENOTTY: return "ENOTTY";
        case ETXTBSY: return "ETXTBSY";
        case EFBIG: return "EFBIG";
        case ENOSPC: return "ENOSPC";
        case ESPIPE: return "ESPIPE";
        case EROFS: return "EROFS";
        case EMLINK: return "EMLINK";
        case EPIPE: return "EPIPE";
        case EDOM: return "EDOM";
        case ERANGE: return "ERANGE";
        case EAGAIN: return "EAGAIN/EWOULDBLOCK";
        case EINPROGRESS: return "EINPROGRESS";
        case EALREADY: return "EALREADY";
        case ENOTSOCK: return "ENOTSOCK";
        case EDESTADDRREQ: return "EDESTADDRREQ";
        case EMSGSIZE: return "EMSGSIZE";
        case EPROTOTYPE: return "EPROTOTYPE";
        case ENOPROTOOPT: return "ENOPROTOOPT";
        case EPROTONOSUPPORT: return "EPROTONOSUPPORT";
        case ESOCKTNOSUPPORT: return "ESOCKTNOSUPPORT";
        case EOPNOTSUPP: return "EOPNOTSUPP";
        case EPFNOSUPPORT: return "EPFNOSUPPORT";
        case EAFNOSUPPORT: return "EAFNOSUPPORT";
        case EADDRINUSE: return "EADDRINUSE";
        case EADDRNOTAVAIL: return "EADDRNOTAVAIL";
        case ENETDOWN: return "ENETDOWN";
        case ENETUNREACH: return "ENETUNREACH";
        case ENETRESET: return "ENETRESET";
        case ECONNABORTED: return "ECONNABORTED";
        case ECONNRESET: return "ECONNRESET";
        case ENOBUFS: return "ENOBUFS";
        case EISCONN: return "EISCONN";
        case ENOTCONN: return "ENOTCONN";
        case ESHUTDOWN: return "ESHUTDOWN";
        case ETOOMANYREFS: return "ETOOMANYREFS";
        case ETIMEDOUT: return "ETIMEDOUT";
        case ECONNREFUSED: return "ECONNREFUSED";
        case ELOOP: return "ELOOP";
        case ENAMETOOLONG: return "ENAMETOOLONG";
        case EHOSTDOWN: return "EHOSTDOWN";
        case EHOSTUNREACH: return "EHOSTUNREACH";
        case ENOTEMPTY: return "ENOTEMPTY";
            
#ifdef __APPLE__
        case EPROCLIM: return "EPROCLIM";
        case EBADRPC: return "EBADRPC";
        case ERPCMISMATCH: return "ERPCMISMATCH";
        case EPROGUNAVAIL: return "EPROGUNAVAIL";
        case EPROGMISMATCH: return "EPROGMISMATCH";
        case EPROCUNAVAIL: return "EPROCUNAVAIL";
        case EFTYPE: return "EFTYPE";
        case EAUTH: return "EAUTH";
        case ENEEDAUTH: return "ENEEDAUTH";
        case EPWROFF: return "EPWROFF";
        case EDEVERR: return "EDEVERR";
        case EBADEXEC: return "EBADEXEC";
        case EBADARCH: return "EBADARCH";
        case ESHLIBVERS: return "ESHLIBVERS";
        case EBADMACHO: return "EBADMACHO";
        case ENOATTR: return "ENOATTR";
#endif
            
        case EUSERS: return "EUSERS";
        case EDQUOT: return "EDQUOT";
        case ESTALE: return "ESTALE";
        case EREMOTE: return "EREMOTE";
        case ENOLCK: return "ENOLCK";
        case ENOSYS: return "ENOSYS";
        case EOVERFLOW: return "EOVERFLOW";
        case ECANCELED: return "ECANCELED";
        case EIDRM: return "EIDRM";
        case ENOMSG: return "ENOMSG";
        case EILSEQ: return "EILSEQ";
        case EBADMSG: return "EBADMSG";
        case EMULTIHOP: return "EMULTIHOP";
        case ENODATA: return "ENODATA";
        case ENOLINK: return "ENOLINK";
        case ENOSR: return "ENOSR";
        case ENOSTR: return "ENOSTR";
        case EPROTO: return "EPROTO";
        case ETIME: return "ETIME";
        default: THROW << "Unknown error code: " << err_code;
    }
}


//======================================================================================================================
//======================================================================================================================
bool regular_file_exists(string path) {
    struct stat file_stat;
    return (stat(path.c_str(), &file_stat) == 0 and S_ISREG(file_stat.st_mode));
}


//======================================================================================================================
//======================================================================================================================
bool dir_exists(string path) {
    struct stat file_stat;
    return (stat(path.c_str(), &file_stat) == 0 and S_ISDIR(file_stat.st_mode));
}


//======================================================================================================================
// Flip a coin - return true or false in a probablity of half
//======================================================================================================================
bool flip() {
    return (rand() % 2); 
}


//======================================================================================================================
//======================================================================================================================
string join_strings(vector<string>& v, string delim) {
    string res;
    
    if(not v.empty()) {
        int size = 0;
        
        for(auto& s: v)
            size += s.length();
        
        size += (v.size() - 1) * delim.length();
        res.reserve(size);
        res.append(v[0]);
        
        for(int i = 1; i < v.size(); ++i) {
            res.append(delim);
            res.append(v[i]);
        }
    }
    
    return res;
}


//==========================================================================================================
// Extract just the function name from string __PRETTY_FUNCTION__, that contains return value and parameters
//==========================================================================================================
string func_name(const string &pretty_func_name) {
    size_t left_paren_pos = pretty_func_name.find('(');
    size_t begin = pretty_func_name.rfind(' ', left_paren_pos) + 1; // first character which isn't a space before left paren
    return pretty_func_name.substr(begin, left_paren_pos - begin + 1) + ')';
}




