//
//  main.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/6/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "Parser.hpp"

int main(int argc, const char * argv[]) {

    vector<Token> tokens = {{NUM}, {OP}, {LEFT_PAREN}, {NUM}, {OP}, {NUM}, {RIGHT_PAREN}, {EOI}};
    
    try {
        Parser parser("/Users/ydinari/src/Interpreter/Interpreter/grammar_definition");
        parser.parse(tokens);
        
    } catch (string err) {
        cout << "Error: " << err << endl;
    }
    
    return 0;
}




























