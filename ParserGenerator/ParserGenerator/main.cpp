//
//  main.cpp
//  ParserGenerator
//
//  Created by Yuval Dinari on 7/21/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "SLR_Table.hpp"

int main(int argc, const char * argv[]) {

    SLR_Table table("/Users/ydinari/src/Interpreter/grammar_definition", "/Users/ydinari/src/Interpreter/InterpreterRuntime/InterpreterRuntime/ParserTables.cpp");
    
    return 0;
}
