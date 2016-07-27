//
//  main.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/6/16.
//  Copyright © 2016 Vonage. All rights reserved.
//


#include "Interpreter.hpp"

int main(int argc, const char * argv[]) {
      
    try {
        Interpreter interpreter;
        interpreter.interpret("/Users/ydinari/src/Interpreter/try.scr");
    
    } catch (string err) {
        cout << "Error: " << err << endl;
    }
        
        return 0;
}




























