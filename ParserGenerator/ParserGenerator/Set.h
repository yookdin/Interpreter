//
//  Set.h
//  ParserGenerator
//
//  Created by Yuval Dinari on 7/21/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Set_h
#define Set_h

#include "common_headers.h"

//==========================================================================================================
// Set that support insert(another-set) operation
//==========================================================================================================
template<class T>
class Set: public set<T> {
public:
    Set(){}
    Set(initializer_list<T> il): set<T>(il) {}
    
    void insert(set<T>& other) {
        set<T>::insert(other.begin(), other.end());
    }
    
    void insert(Set<T>& other) {
        set<T>::insert(other.begin(), other.end());
    }
    
    void insert(Set<T>&& other) {
        set<T>::insert(other.begin(), other.end());
    }
    
    
    void insert(T value) {
        set<T>::insert(value);
    }
};

#endif /* Set_h */
