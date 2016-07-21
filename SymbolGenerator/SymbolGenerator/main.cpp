//
//  main.cpp
//  SymbolGenerator
//
//  Created by Yuval Dinari on 7/21/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "SymbolGenerator.hpp"

int main(int argc, const char * argv[]) {

    SymbolGenerator sg("/Users/ydinari/src/Interpreter/grammar_definition",
                       "/Users/ydinari/src/Interpreter/ParserGenerator/ParserGenerator/Symbol.hpp",
                       "/Users/ydinari/src/Interpreter/ParserGenerator/ParserGenerator/Symbol.cpp");
    
    return 0;
}
