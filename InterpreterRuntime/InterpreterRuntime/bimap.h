//
//  bimap.h
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/21/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef bimap_h
#define bimap_h

#include <map>
using namespace std;

#include "st_exception.h"

//==========================================================================================================
// Bidirectional map, that enables retreiving value by either of the pair values
//==========================================================================================================
template <class T1, class T2>
class bimap {
public:
    
    typedef pair<T1,T2> value_type;    
    bimap(){}
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    bimap(initializer_list<value_type> il) {
        for(auto& p: il)
            add(p.first, p.second);
    }
    
    //------------------------------------------------------------------------------------------------------
    // Will enable iteration over the pairs where T1 is first
    //------------------------------------------------------------------------------------------------------
    struct iterator {
        iterator(typename map<T1,T2>::iterator _map_iter): map_iter(_map_iter) {}
        
        typename map<T1,T2>::reference operator*() {
            return *map_iter;
        }
        
        bool operator==(const iterator& other) {
            return map_iter == other.map_iter;
        }
        
        bool operator!=(const iterator& other) {
            return map_iter != other.map_iter;
        }
        
        iterator& operator++() {
            ++map_iter; return *this;
        }
        
    private:
        typename map<T1,T2>::iterator map_iter;
    };
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    iterator begin() {
        return iterator(map1.begin());
    }
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    iterator end() {
        return iterator(map1.end());
    }
    
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    bool key_exists(const T1 t1) {
        return map1.count(t1) != 0;
    }
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    bool key_exists(const T2 t2) {
        return map2.count(t2) != 0;
    }
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    void add(const T1 t1, const T2 t2, bool overwrite = false) {
        
        if(not overwrite and (key_exists(t1) or key_exists(t2)))
            THROW << "bimap::add() - trying to add values which already exist";
        
        if(key_exists(t1))
            map2.erase(map1[t1]); // So no key in map2 will point to t1
        
        if(key_exists(t2))
            map1.erase(map2[t2]); // So no key in map1 will point to t2
        
        map1[t1] = t2;
        map2[t2] = t1;
    }
    
    
    //------------------------------------------------------------------------------------------------------
    // Note: this just retrieves if exists, doesn't add
    //------------------------------------------------------------------------------------------------------
    T2 operator[](const T1 t) {
        if(map1.count(t) != 0)
            return map1[t];
        else {
            THROW << "Value '" << t << "' doesn't exist in bimap"; 
        }
    }
    
    //------------------------------------------------------------------------------------------------------
    // Note: this just retrieves if exists, doesn't add
    //------------------------------------------------------------------------------------------------------
    T1 operator[](const T2 t) {
        if(map2.count(t) != 0)
            return map2[t];
        else {
            THROW << "Value '" << t << "' doesn't exist in bimap"; 
        }
    }
    
private:
    map<T1,T2> map1;
    map<T2,T1> map2;
};


#endif /* bimap_h */
