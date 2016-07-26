//
//  FuncCallers.h
//  InterpreterRuntime
//
//  Created by Yuval Dinari on 7/26/16.
//  Copyright © 2016 Vonage. All rights reserved.
//
//  All the template shit needed to call functions at runtime.
//  Note: it's not possible to call function at runtime unless their signature is known in compile time (in C++).
//  However, you can do it for selected functions. Easiest is to just do:
//  if(func_name == "foo") foo();
//  However this is annoying.
//  It is possible to have a map of function wrapper objects. In principle you need a derived wrapper per function signature.
//  Using some templates magic, you need only wrapper per return type. However, you need different wrappers for non-static member
//  functions.

#ifndef FuncCallers_h
#define FuncCallers_h

//======================================================================================================================
// This will always be called with list<boost::any>, and yet it needs to be a template, o/w the pop_front() doesn't
// work...
//======================================================================================================================
template <typename T>
auto fetch_front(T& t) -> typename std::remove_reference<decltype(t.front())>::type {
    typename std::remove_reference<decltype(t.front())>::type ret = t.front();
    t.pop_front();
    return ret;
}


//======================================================================================================================
//======================================================================================================================
template <typename X>
struct any_ref_cast {
    X do_cast(boost::any y) {
        return boost::any_cast<X>(y);
    }
};

//======================================================================================================================
//======================================================================================================================
template <typename X>
struct any_ref_cast<X&> {
    X& do_cast(boost::any y) {
        std::reference_wrapper<X> ref = boost::any_cast<std::reference_wrapper<X>>(y);
        return ref.get();
    }
};

//======================================================================================================================
//======================================================================================================================
template <typename X>
struct any_ref_cast<const X&> {
    const X& do_cast(boost::any y) {
        std::reference_wrapper<const X> ref = boost::any_cast<std::reference_wrapper<const X>>(y);
        return ref.get();
    }
};

//======================================================================================================================
// Call a global function with arguements conatained in a list
//======================================================================================================================
template <typename Ret, typename...Args>
Ret call_func(Ret (*func)(Args...), std::list<boost::any> args)
{
    if (sizeof...(Args) != args.size())
        throw "Argument number mismatch!";
    
    // boost::any_cast for some reason doesn't know how to automatically handle reference types,
    // that's why the any_ref_cast is needed
    return func(any_ref_cast<Args>().do_cast(fetch_front(args))...);
}

//======================================================================================================================
// Call a class non-static member function with arguements conatained in a list. Must receive a class object.
//======================================================================================================================
template <typename Class, typename Ret, typename...Args>
Ret call_class_func(Class obj, Ret (Class::*func)(Args...), std::list<boost::any> args)
{
    if (sizeof...(Args) != args.size())
        throw "Argument number mismatch!";
    
    return (obj.*func)(any_ref_cast<Args>().do_cast(fetch_front(args))...);
}


//======================================================================================================================
// Base for all func callers
//======================================================================================================================
class BaseFuncCaller {
public:
    virtual Value* operator()(vector<Value*> args) = 0; 

protected:
    list<boost::any> convert_to_any_args(vector<Value*> args) {
        list<boost::any> any_args;
        
        for(auto v: args) {
            switch (v->get_type()) {
                case Value::BOOL:
                    any_args.push_back(bool(*v));
                    break;
                case Value::NUMBER:
                    any_args.push_back(int(*v));
                    break;
                case Value::STRING:
                    any_args.push_back(string(*v));
                    break;
                case Value::NO_VAL:
                    throw string("NO_VAL can't be used as a value for a function argument");
            }
        }
        return any_args;
    }
};


//======================================================================================================================
// Base for global function callers
//======================================================================================================================
template <typename Ret, typename... Args>
class FuncCaller: public BaseFuncCaller {
public:
    FuncCaller(Ret (*_func)(Args...)): func(_func) {}
    Ret (*func)(Args...);
};


//======================================================================================================================
// int returning global functions
//======================================================================================================================
template<typename... Args>
class IntFuncCaller: public FuncCaller<int, Args...> {
public:
    IntFuncCaller(int (*_func)(Args...)): FuncCaller<int, Args...>(_func) {}
    
    Value* operator()(vector<Value*> args) {
        // Note: this-> is used because the supid compiler has some stupid reason to need it
        return new Num(call_func(this->func, this->convert_to_any_args(args))); 
    }
};


//======================================================================================================================
// bool returning global functions
//======================================================================================================================
template<typename... Args>
class BoolFuncCaller: public FuncCaller<int, Args...> {
public:
    BoolFuncCaller(int (*_func)(Args...)): FuncCaller<bool, Args...>(_func) {}
    
    Value* operator()(vector<Value*> args) {
        return new Bool(call_func(this->func, this->convert_to_any_args(args))); 
    }
};


//======================================================================================================================
// string returning global functions
//======================================================================================================================
template<typename... Args>
class StringFuncCaller: public FuncCaller<string, Args...> {
public:
    StringFuncCaller(string (*_func)(Args...)): FuncCaller<string, Args...>(_func) {}
    
    Value* operator()(vector<Value*> args) {
        return new String(call_func(this->func, this->convert_to_any_args(args))); 
    }
};


//======================================================================================================================
// void returning global functions
//======================================================================================================================
template<typename... Args>
class VoidFuncCaller: public FuncCaller<string, Args...> {
public:
    VoidFuncCaller(void(*_func)(Args...)): FuncCaller<void, Args...>(_func) {}
    
    Value* operator()(vector<Value*> args) {
        call_func(this->func, this->convert_to_any_args(args));
        return &no_value;
    }
};



//======================================================================================================================
// Base to class member function callers. Note: this receives an object in its constructor. There shouldn't be two
// func-callers for the same class and function with two different objects, because we locate the functions just by
// their names, and it is not necessary for the purpose of invoking built-in functions in the language.
//======================================================================================================================
template <typename Class, typename Ret, typename... Args>
class ClassFuncCaller: public BaseFuncCaller {
public:
    ClassFuncCaller(Class& _obj, Ret (Class::*_func)(Args...)): func(_func), obj(_obj) {}
    Ret (Class::*func)(Args...);
    Class& obj;
};


//======================================================================================================================
// int returning class functions
//======================================================================================================================
template<typename Class, typename... Args>
class IntClassFuncCaller: public ClassFuncCaller<Class, int, Args...> {
public:
    IntClassFuncCaller(Class& _obj, int (Class::*_func)(Args...)): ClassFuncCaller<Class, int, Args...>(_obj, _func) {}
    
    Value* operator()(vector<Value*> args) {
        return new Num(call_class_func(this->obj, this->func, this->convert_to_any_args(args)));
    }
};


//======================================================================================================================
// bool returning class functions
//======================================================================================================================
template<typename Class, typename... Args>
class BoolClassFuncCaller: public ClassFuncCaller<Class, bool, Args...> {
public:
    BoolClassFuncCaller(Class& _obj, int (Class::*_func)(Args...)): ClassFuncCaller<Class, bool, Args...>(_obj, _func) {}
    
    Value* operator()(vector<Value*> args) {
        return new Bool(call_class_func(this->obj, this->func, this->convert_to_any_args(args)));
    }
};


//======================================================================================================================
// string returning class functions
//======================================================================================================================
template<typename Class, typename... Args>
class StringClassFuncCaller: public ClassFuncCaller<Class, string, Args...> {
public:
    StringClassFuncCaller(Class& _obj, int (Class::*_func)(Args...)): ClassFuncCaller<Class, string, Args...>(_obj, _func) {}
    
    Value* operator()(vector<Value*> args) {
        return new String(call_class_func(this->obj, this->func, this->convert_to_any_args(args)));
    }
};

//======================================================================================================================
// void returning global functions
//======================================================================================================================
template<typename Class, typename... Args>
class VoidClassFuncCaller: public ClassFuncCaller<Class, void, Args...> {
public:
    VoidClassFuncCaller(Class& _obj, void(*_func)(Args...)): ClassFuncCaller<Class, void, Args...>(_func) {}
    
    Value* operator()(vector<Value*> args) {
        call_class_func(this->obj, this->func, this->convert_to_any_args(args));
        return &no_value;
    }
};




#endif /* FuncCallers_h */
