//
//  ThreadConfig.h
//  SIPTester
//
//  Created by Yuval Dinari on 3/30/17.
//  Copyright © 2017 Yuk. All rights reserved.
//

#ifndef ThreadConfig_h
#define ThreadConfig_h

#include <fstream>
using namespace std;

void create_directories(string path);


//==========================================================================================================
// A class to hold thread specific stuff. Will be instantiated with thread_local specifier, which will make
// it unique for each thread. It is the thread's responsibility to config it.
//==========================================================================================================
class ThreadConfig {
public:
    //======================================================================================================
    //======================================================================================================
    ~ThreadConfig() {
        if(file_stream.is_open())
            file_stream.close();
    }
    
    //======================================================================================================
    //======================================================================================================
    void config_with_test_dir(string name, string test_dir) {
        string log_file = (test_dir.empty() ? "" : test_dir + "/" + name + ".log");
        config_with_log(name, log_file);
    }
    
    //======================================================================================================
    //======================================================================================================
    void config_with_log(string name, string log_file) {
        thread_name = name; 
        log_file_name = log_file;            
        
        if(not log_file_name.empty()) {
            file_stream.open(log_file_name.c_str());
            
            if(not file_stream.is_open())
                THROW << "Failed to open file " << log_file_name;
        }
    }    
    
    //======================================================================================================
    //======================================================================================================
    bool printing_to_file() {
        return file_stream.is_open();
    }
    
    string get_thread_name() { return thread_name; }
    string get_log_file_name() { return log_file_name; }
    ofstream& get_log_stream() { return file_stream; }
    
private:
    string thread_name = "main";
    string log_file_name;
    ofstream file_stream;
};


#endif /* ThreadConfig_h */



























