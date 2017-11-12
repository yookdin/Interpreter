//
//  st_exception.h
//  SIPTester
//
//  Created by Yuval Dinari on 10/8/17.
//  Copyright © 2017 Yuk. All rights reserved.
//

#ifndef st_exception_h
#define st_exception_h


#include <sstream>
using namespace std;

#include "sip_tester_types.h"

//==========================================================================================================
// An exception to be thrown inside siptester. Enables using operator<<() like so:
// throw st_exception() << "Expected x but got " << y << ...
//==========================================================================================================
class st_exception {
public:
    st_exception(){}
    
    //------------------------------------------------------------------------------------------------------
    // Copy constructor
    //------------------------------------------------------------------------------------------------------
    st_exception(const st_exception& e) {
        o << e.o.str();
    }
    
    //------------------------------------------------------------------------------------------------------
    // Copy assignment operator
    //------------------------------------------------------------------------------------------------------
    st_exception& operator=(const st_exception& rhs) {
        o << rhs.o.str();
        return *this;
    }

    //------------------------------------------------------------------------------------------------------
    // This is for functions such as endl()
    //------------------------------------------------------------------------------------------------------
    st_exception& operator<<(basic_ostream<char>& (*__pf)(basic_ostream<char>&)) {
        o << __pf;
        return *this;
    }
    
    st_exception& operator<<(bool __n) {
        o << __n;
        return *this;
    }
    
    st_exception& operator<<(short __n) {
        o << __n;
        return *this;
    }
    
    st_exception& operator<<(unsigned short __n) {
        o << __n;
        return *this;
    }
    
    st_exception& operator<<(int __n) {
        o << __n;
        return *this;
    }
    
    st_exception& operator<<(unsigned int __n) {
        o << __n;
        return *this;
    }
    
    st_exception& operator<<(long __n) {
        o << __n;
        return *this;
    }
    
    st_exception& operator<<(unsigned long __n)  {
        o << __n;
        return *this;
    }
    
    st_exception& operator<<(long long __n)  {
        o << __n;
        return *this;
    }
    
    st_exception& operator<<(unsigned long long __n)  {
        o << __n;
        return *this;
    }
    
    st_exception& operator<<(float __f)  {
        o << __f;
        return *this;
    }
    
    st_exception& operator<<(double __f)  {
        o << __f;
        return *this;
    }
    
    st_exception& operator<<(long double __f)  {
        o << __f;
        return *this;
    }
    
    st_exception& operator<<(const void* __p)  {
        o << __p;
        return *this;
    }
    
    st_exception& operator<<(string s)  {
        o << s;
        return *this;
    }
    
    st_exception& operator<<(const char* s) {
        o << s;
        return *this;
    }
    
    st_exception& operator<<(const char c) {
        o << c;
        return *this;
    }

    st_exception& operator<<(ProtocolKind p) {
        o << to_string(p);
        return *this;
    }
    
    string str() const {
        return o.str();
    }
    
    bool empty() const {
        return o.str().empty();
    }
    
private:
    ostringstream o;
};


//==========================================================================================================
// Since we only throw st_exception, can use this macro for bravity.
//==========================================================================================================
#define THROW throw st_exception()


#endif /* st_exception_h */
