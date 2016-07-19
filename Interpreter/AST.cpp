//
//  AST.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/16/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "AST.hpp"


/************************************************************************************************************
 ************************************************************************************************************
 ************************************************************************************************************
 **                                                                                                        **
 **                                              AST                                                       **
 **                                                                                                        **
 ************************************************************************************************************
 ************************************************************************************************************
 ************************************************************************************************************/



//==========================================================================================================
//==========================================================================================================
void AST::print() {
    recursive_print(0);
}

//==========================================================================================================
//==========================================================================================================
void AST::recursive_print(int indentation_level) {
    cout << setw(indentation_level * 3) << "";
    print_node();
    for(auto& c: children) c->recursive_print(indentation_level + 1);
}




/************************************************************************************************************
 ************************************************************************************************************
 ************************************************************************************************************
 **                                                                                                        **
 **                                           NumAST                                                       **
 **                                                                                                        **
 ************************************************************************************************************
 ************************************************************************************************************
 ************************************************************************************************************/


//==========================================================================================================
//==========================================================================================================
NumAST::NumAST(vector<TokenOrAST>& elements): AST(NUM), num(extract_num(elements)) {}

//==========================================================================================================
//==========================================================================================================
int NumAST::extract_num(vector<TokenOrAST>& elements) {
    return ((NumToken*)elements[0].get_token())->val;
}


//==========================================================================================================
//==========================================================================================================
void NumAST::execute() {}


//==========================================================================================================
//==========================================================================================================
void NumAST::print_node() {
    cout << num << endl; 
}



/************************************************************************************************************
 ************************************************************************************************************
 ************************************************************************************************************
 **                                                                                                        **
 **                                            BopAST                                                      **
 **                                                                                                        **
 ************************************************************************************************************
 ************************************************************************************************************
 ************************************************************************************************************/



//==========================================================================================================
//==========================================================================================================
BopAST::BopAST(vector<TokenOrAST>& elements): OpAST(elements[1].get_token()->sym, sym_op_map[sym]) {
    children.push_back(elements[0].get_ast());
    children.push_back(elements[2].get_ast());
}


//==========================================================================================================
//==========================================================================================================
void BopAST::execute() {}



/************************************************************************************************************
 ************************************************************************************************************
 ************************************************************************************************************
 **                                                                                                        **
 **                                            UopAST                                                      **
 **                                                                                                        **
 ************************************************************************************************************
 ************************************************************************************************************
 ************************************************************************************************************/



//==========================================================================================================
//==========================================================================================================
UopAST::UopAST(vector<TokenOrAST>& elements): OpAST(elements[0].get_token()->sym, sym_op_map[sym]) {
    children.push_back(elements[1].get_ast());
}


//==========================================================================================================
//==========================================================================================================
void UopAST::execute() {}


/************************************************************************************************************
 ************************************************************************************************************
 ************************************************************************************************************
 **                                                                                                        **
 **                                            CondExpAST                                                  **
 **                                                                                                        **
 ************************************************************************************************************
 ************************************************************************************************************
 ************************************************************************************************************/



//==========================================================================================================
//==========================================================================================================
CondExpAST::CondExpAST(vector<TokenOrAST>& elements): OpAST(COND_EXP, sym_op_map[COND_EXP]) {
    children.push_back(elements[0].get_ast());
    children.push_back(elements[2].get_ast());
    children.push_back(elements[4].get_ast());
}


//==========================================================================================================
//==========================================================================================================
void CondExpAST::execute() {}


