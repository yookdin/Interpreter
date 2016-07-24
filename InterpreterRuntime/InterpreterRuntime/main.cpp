//
//  main.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/6/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "Lexer.hpp"
#include "Parser.hpp"

int main(int argc, const char * argv[]) {
      
    try {
        vector<Token*> tokens;
        Lexer lex;
        lex.lex("/Users/ydinari/src/Interpreter/InterpreterRuntime/InterpreterRuntime/try.scr", tokens);
        Parser parser;
        AST* ast = parser.parse(tokens);
        if(ast != nullptr) {
            ast->print();
            ast->eval();
        }
    } catch (string err) {
        cout << "Error: " << err << endl;
    }
        
        return 0;
}




























