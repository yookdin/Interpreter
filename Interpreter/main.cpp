//
//  main.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/6/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "Parser.hpp"

int main(int argc, const char * argv[]) {

    try {
        Parser parser("/Users/ydinari/src/Interpreter/Interpreter/grammar_definition");

    } catch (string err) {
        cout << "Error: " << err << endl;
    }
    
    return 0;
}




























