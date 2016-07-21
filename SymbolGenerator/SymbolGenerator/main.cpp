//
//  main.cpp
//  SymbolGenerator
//
//  Created by Yuval Dinari on 7/21/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "SymbolGenerator.hpp"

int main(int argc, const char * argv[]) {

    try {
        SymbolGenerator sg("/Users/ydinari/src/Interpreter/grammar_definition",
                           "/Users/ydinari/src/Interpreter/InterpreterRuntime/InterpreterRuntime/Symbol.hpp",
                           "/Users/ydinari/src/Interpreter/InterpreterRuntime/InterpreterRuntime/Symbol.cpp");
    } catch (string err) {
        cout << "Caught exception: " << err << endl;
    }
    
    return 0;
}
