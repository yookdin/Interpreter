//
//  Lexer.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/6/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "Lexer.hpp"


//==========================================================================================================
//==========================================================================================================
//Lexer::Lexer() {
//    //enum TokenKind { KEYWORD, IDENTIFIER, NUMBER, STRING, OPERATOR, PUNCTUATOR };
//    matchers.push_back({regex("if|else|elseif|while|repeat|for|end|continue|break"), KEYWORD});
//    matchers.push_back({regex("[_[:alpha:]]\\w*"), IDENTIFIER});
//    matchers.push_back({regex("\\d+"), NUMBER});
//    matchers.push_back({regex("\"((\\\\\"|[^\"])*)\""), STRING});
//    matchers.push_back({regex("==|!=|!~|<=|>=|=|<|>|+|-|*|/|%|~|?|:"), OPERATOR});
//    matchers.push_back({regex("(|)|,"), PUNCTUATOR});
//}
