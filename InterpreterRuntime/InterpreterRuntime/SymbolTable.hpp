//
//  SymbolTable.hpp
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/24/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef SymbolTable_hpp
#define SymbolTable_hpp

#include "common_headers.h"
#include "Value.hpp"

//==========================================================================================================
//==========================================================================================================
class SymbolTable {
public:
    ~SymbolTable() { for(auto& p: symtab) delete p.second; }
    Value* get_val(string var) { return (symtab.count(var) == 0) ? nullptr : symtab[var]; }
    void set_val(string var, Value& val);
    void print();
    
private:
    map<string, Value*> symtab;
};



#endif /* SymbolTable_hpp */
