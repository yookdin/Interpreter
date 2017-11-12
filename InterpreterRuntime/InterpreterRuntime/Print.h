//
//  Print.h
//  SIPTester
//
//  Created by Yuval Dinari on 3/30/17.
//  Copyright © 2017 Yuk. All rights reserved.
//

#ifndef Print_h
#define Print_h


#include <iostream>
#include <mutex>
using namespace std;

#include "ThreadConfig.h"

extern thread_local ThreadConfig thread_config;
string get_print_prefix();


//==========================================================================================================
// A thread safe print class. Example:
// Print() << "Hello world!" << endl;
// Prints the current time as a prefix.
//==========================================================================================================
class Print: public ostringstream
{
public:
    Print(bool _print_prefix = true, bool _print_to_stderr = false): print_prefix(_print_prefix), print_to_stderr(_print_to_stderr) {}
    
    ~Print()
    {
        lock_guard<mutex> guard(print_mutex);
        
        ofstream &file_stream = thread_config.get_log_stream();
        string prefix = (print_prefix ? get_print_prefix() : "");
        
        if(print_to_stderr)
            cerr << prefix << this->str();
        else
            cout << prefix << this->str();

        if(file_stream.is_open())
            file_stream << prefix << this->str();
    }
    
private:
    static mutex print_mutex;
    bool print_prefix, print_to_stderr;
};


#endif /* Print_h */
