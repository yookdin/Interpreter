//
//  ParseElement.h
//  MockServer
//
//  Created by Yuval Dinari on 11/30/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef ParseElement_h
#define ParseElement_h

class Token;
class AST;

class ParseElement {
public:
    virtual Token* get_token() { THROW << "Shouldn't call ParseElement::get_token()"; }
    virtual AST*   get_ast() { THROW << "Shouldn't call ParseElement::get_ast()"; }
    virtual bool is_token()  { THROW << "Shouldn't call ParseElement::is_token()"; }
};

#endif /* ParseElement_h */
