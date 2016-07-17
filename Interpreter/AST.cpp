//
//  AST.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/16/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "AST.hpp"


//==========================================================================================================
//==========================================================================================================
void AST::print() {
    recursive_print(0);
}

//==========================================================================================================
//==========================================================================================================
void AST::recursive_print(int indentation_level) {
    cout << setw(indentation_level * 3) << "";
    cout << symbol_to_string(sym) << endl;
    for(auto& c: children) c->recursive_print(indentation_level + 1);
}
