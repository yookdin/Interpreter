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
        vector<SharedValue> args;
        Interpreter interpreter;
        interpreter.run("/Users/ydinari/src/Interpreter/try.scr", args);
    
    } catch(string& err) {
        cout << "Error: " << err << endl;
    }
        
        return 0;
}




























