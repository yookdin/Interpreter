//
//  FunctionTable.cpp
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/25/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "FunctionTable.hpp"


int foo() { cout << "foo()" << endl; return 11; }
    
//==========================================================================================================
//==========================================================================================================
FunctionTable::FunctionTable() {
    funcs["foo"] = new IntFuncCaller<>(foo);
}


//==========================================================================================================
//==========================================================================================================
Value* FunctionTable::call(string func_name, vector<Value*> args) {
    if(funcs.count(func_name) == 0)
        throw string("Function " + func_name + " not recognized");
    return (*funcs[func_name])(args);
}
