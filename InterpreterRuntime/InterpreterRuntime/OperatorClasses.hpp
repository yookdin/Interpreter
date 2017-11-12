
// Generated file, do not change manually!

#ifndef operator_classes_hpp
#define operator_classes_hpp
    
#include "Operator.hpp"
#include "bimap.h"
    
//==========================================================================================================
//==========================================================================================================
class Div: public Operator {
public:
    Div(): Operator(DIV, 2, 3, LEFT) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue( &(*operands[0] / *operands[1]) );
    }
};


//==========================================================================================================
//==========================================================================================================
class Mul: public Operator {
public:
    Mul(): Operator(MUL, 2, 3, LEFT) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue( &(*operands[0] * *operands[1]) );
    }
};


//==========================================================================================================
//==========================================================================================================
class Mod: public Operator {
public:
    Mod(): Operator(MOD, 2, 3, LEFT) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue( &(*operands[0] % *operands[1]) );
    }
};


//==========================================================================================================
//==========================================================================================================
class Add: public Operator {
public:
    Add(): Operator(ADD, 2, 4, LEFT) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue( &(*operands[0] + *operands[1]) );
    }
};


//==========================================================================================================
//==========================================================================================================
class Subtract: public Operator {
public:
    Subtract(): Operator(SUB, 2, 4, LEFT) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue( &(*operands[0] - *operands[1]) );
    }
};


//==========================================================================================================
//==========================================================================================================
class Minus: public Operator {
public:
    Minus(): Operator(SUB, 1, 4, RIGHT) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue(&(-(*operands[0])));
    }
};


//==========================================================================================================
//==========================================================================================================
class And: public Operator {
public:
    And(): Operator(AND, 2, 8, LEFT) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue( &(*operands[0] and *operands[1]) );
    }
};


//==========================================================================================================
//==========================================================================================================
class Or: public Operator {
public:
    Or(): Operator(OR, 2, 9, LEFT) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue( &(*operands[0] or *operands[1]) );
    }
};


//==========================================================================================================
//==========================================================================================================
class Not: public Operator {
public:
    Not(): Operator(NOT, 1, 2, RIGHT) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue(&(not(*operands[0])));
    }
};


//==========================================================================================================
//==========================================================================================================
class Equal: public Operator {
public:
    Equal(): Operator(EQUAL, 2, 7, LEFT) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue( &(*operands[0] == *operands[1]) );
    }
};


//==========================================================================================================
//==========================================================================================================
class NotEqual: public Operator {
public:
    NotEqual(): Operator(NOT_EQUAL, 2, 7, LEFT) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue( &(*operands[0] != *operands[1]) );
    }
};


//==========================================================================================================
//==========================================================================================================
class LessThan: public Operator {
public:
    LessThan(): Operator(LESS_THAN, 2, 6, NONE) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue( &(*operands[0] < *operands[1]) );
    }
};


//==========================================================================================================
//==========================================================================================================
class GreaterThan: public Operator {
public:
    GreaterThan(): Operator(GREATER_THAN, 2, 6, NONE) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue( &(*operands[0] > *operands[1]) );
    }
};


//==========================================================================================================
//==========================================================================================================
class LessThanEqual: public Operator {
public:
    LessThanEqual(): Operator(LESS_THAN_EQUAL, 2, 6, NONE) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue( &(*operands[0] <= *operands[1]) );
    }
};


//==========================================================================================================
//==========================================================================================================
class GreaterThanEqual: public Operator {
public:
    GreaterThanEqual(): Operator(GREATER_THAN_EQUAL, 2, 6, NONE) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue( &(*operands[0] >= *operands[1]) );
    }
};


//==========================================================================================================
//==========================================================================================================
class StrMatch: public Operator {
public:
    StrMatch(): Operator(STR_MATCH, 2, 5, NONE) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue(operands[0]->match(operands[1]));
    }
};


//==========================================================================================================
//==========================================================================================================
class NoStrMatch: public Operator {
public:
    NoStrMatch(): Operator(NO_STR_MATCH, 2, 5, NONE) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue(operands[0]->not_match(operands[1]));
    }
};


//==========================================================================================================
//==========================================================================================================
class QuestionMark: public Operator {
public:
    QuestionMark(): Operator(QUESTION_MARK, 2, 10, RIGHT) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        throw string("Operator QUESTION_MARK should never be executed");
    }
};


//==========================================================================================================
//==========================================================================================================
class Colon: public Operator {
public:
    Colon(): Operator(COLON, 2, 11, LEFT) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        throw string("Operator COLON should never be executed");
    }
};


//==========================================================================================================
//==========================================================================================================
class Dot: public Operator {
public:
    Dot(): Operator(DOT, 2, 0, LEFT) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        throw string("Operator DOT should never be executed");
    }
};


//==========================================================================================================
//==========================================================================================================
class Subscript: public Operator {
public:
    Subscript(): Operator(LEFT_BRACKET, 2, 1, RIGHT) {}
protected:
    SharedValue execute(vector<SharedValue>& operands) const override {
        return SharedValue(operands[0]->subscript(operands[1]));
    }
};



#endif // operator_classes_hpp
