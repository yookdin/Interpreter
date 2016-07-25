//
//  SymbolTable.cpp
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/24/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "SymbolTable.hpp"


//==========================================================================================================
//==========================================================================================================
void SymbolTable::set_val(string var, Value& val) { 
    if(symtab.count(var) != 0)
        delete symtab[var]; // Delete old value
    symtab[var] = &val; 
}


//==========================================================================================================
//==========================================================================================================
void SymbolTable::print() {
    for(auto& p: symtab) {
        cout << p.first << " = ";
        p.second->print();
    }
}