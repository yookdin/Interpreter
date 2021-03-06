//
//  Set.h
//  ParserGenerator
//
//  Created by Yuval Dinari on 7/21/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Set_h
#define Set_h

#include <unordered_set>
using namespace std;


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
    
    void insert(const set<T>& other) {
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
    
    //------------------------------------------------------------------------------------------------------
    // Return whether the difference of this and other (the set of elements in this and not in other) is empty
    //------------------------------------------------------------------------------------------------------
    bool is_difference_empty(Set<T>& other) {
        for(auto& t: *this)
            if(other.find(t) == other.end())
                return false;
        return true;
    }
};


//==========================================================================================================
// Unordered set that support insert(another-set) operation
//==========================================================================================================
template<class T>
class UnorderedSet: public unordered_set<T> {
public:
    UnorderedSet(){}
    UnorderedSet(initializer_list<T> il): unordered_set<T>(il) {}
    
    void insert(unordered_set<T>& other) {
        unordered_set<T>::insert(other.begin(), other.end());
    }
    
    void insert(UnorderedSet<T>& other) {
        unordered_set<T>::insert(other.begin(), other.end());
    }
    
    void insert(UnorderedSet<T>&& other) {
        unordered_set<T>::insert(other.begin(), other.end());
    }
    
    const T& insert(const T& value) {
        return *unordered_set<T>::insert(value).first;
    }
};

#endif /* Set_h */
