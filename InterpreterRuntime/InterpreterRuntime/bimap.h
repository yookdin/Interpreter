//
//  bimap.h
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/21/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef bimap_h
#define bimap_h

#include "common_headers.h"

//==========================================================================================================
// Bidirectional map, that enables retreiving value by either of the pair values
//==========================================================================================================
template <class T1, class T2>
class bimap {
public:
    
    typedef pair<T1,T2> value_type;
    
    bimap(initializer_list<value_type> il) {
        for(auto& p: il) add(p.first, p.second);
    }
    
    void add(const T1 t1, const T2 t2) {
        map1[t1] = t2;
        map2[t2] = t1;
    }
    
    // Note: this just retrieved if exists, doesn't add
    T2 operator[](const T1 t) {
        if(map1.count(t) != 0)
            return map1[t];
        else
            throw string("Value doesn't exist in bimap");
    }
    
    // Note: this just retrieved if exists, doesn't add
    T1 operator[](const T2 t) {
        if(map2.count(t) != 0)
            return map2[t];
        else
            throw string("Value doesn't exist in bimap");
    }
    
private:
    map<T1,T2> map1;
    map<T2,T1> map2;
};


#endif /* bimap_h */
