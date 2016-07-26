//
//  FunctionTable.hpp
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/25/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef FunctionTable_hpp
#define FunctionTable_hpp

#include <boost/any.hpp>
#include "common_headers.h"
#include "Value.hpp"
#include "FuncCallers.h"



//==========================================================================================================
//==========================================================================================================
class FunctionTable {
public:
    FunctionTable();
    Value* call(string func, vector<Value*> args);
    
private:
    map<string, BaseFuncCaller*> funcs;
};





#endif /* FunctionTable_hpp */














