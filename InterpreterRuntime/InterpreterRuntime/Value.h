//
//  Value.h
//  Interpreter
//
//  Created by Yuval Dinari on 7/18/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#ifndef Value_h
#define Value_h

//==========================================================================================================
//==========================================================================================================
enum ValueType {NUMBER, BOOL, STRING};


//==========================================================================================================
//==========================================================================================================
class Value {
public:
    Value(ValueType t): type(t) {} 
protected:
    ValueType type;
};


#endif /* Value_h */
