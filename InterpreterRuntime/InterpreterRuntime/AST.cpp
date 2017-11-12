//
//  AST.cpp
//  Interpreter
//
//  Created by Yuval Dinari on 7/16/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "AST.hpp"
#include "AstVisitor.hpp"
#include "Interpreter.hpp"


//==========================================================================================================
// Traverse the tree in pre-order walk (parent before children), perform the visitor action for each node.
//==========================================================================================================
void AST::pre_order_traverse(AstVisitor& visitor) {
    visitor.visit(*this);
    visitor.before_descending(*this);
    for(auto c: children) c->pre_order_traverse(visitor);
    visitor.after_descending(*this);
}


//==========================================================================================================
// Traverse the tree in post-order walk (parent after children), perform the visitor action for each node.
//==========================================================================================================
void AST::post_order_traverse(AstVisitor& visitor) {
    visitor.before_descending(*this);
    for(auto c: children) c->post_order_traverse(visitor);
    visitor.after_descending(*this);
    visitor.visit(*this);
}


//==========================================================================================================
//==========================================================================================================
void AST::print() {
    AstPrintVisitor print_visitor;
    pre_order_traverse(print_visitor);
}


//==========================================================================================================
//==========================================================================================================
void AST::free() {
    DeleteVisitor delete_visitor;
    post_order_traverse(delete_visitor);
}


//==========================================================================================================
//==========================================================================================================
void AST::eval_children(int start) {
    for(int i = start; i < children.size(); ++i)
        children[i]->eval();
}


//==========================================================================================================
//==========================================================================================================
vector<SharedValue> AST::get_children_vals() {
    vector<SharedValue> res;
    for(auto c: children)
        res.push_back(c->eval());
    return res;
}


//==========================================================================================================
// If a child is parameter list return the list values. Note: this isn't recursive, only first level
// parameter list will be flatten.
//==========================================================================================================
vector<SharedValue> AST::get_children_as_parameters() {
    vector<SharedValue> args;
    
    for(auto c: children) {
        SharedValue val = c->eval();
        ParamValsList *params_list = val->get<ParamValsList>();
        
        if(params_list != nullptr) {
            for(auto v: params_list->get_values())
                args.push_back(v);
        }
        else {
            args.push_back(val);
        }
    }
    
    for(auto v: args) {
        if(v->is_no_value())
            THROW << "Can't use a no_value as a parameter";
    }
    
    return args;
}


//==========================================================================================================
//==========================================================================================================
void AST::add_flat_statements(AST *ast) {
    if(typeid(*ast) == typeid(StatementsAST))
        for(auto c: ast->children)
            add_child(c);
    else
        add_child(ast);
}


//==========================================================================================================
//==========================================================================================================
SharedValue StringAST::eval() {
    return SharedValue(new String(val)); 
}


//==========================================================================================================
//==========================================================================================================
ListAST::ListAST(vector<ParseElement*>& elements) {
    for(auto& e: elements) {
        if(not e->is_token()) { // Skip commas and curly braces
            AST* ast = e->get_ast();
            
            if(typeid(*ast) == typeid(NakedListAST))
                for(auto c: ast->children) add_child(c);
            else
                add_child(ast);
        }
    }
}


//==========================================================================================================
//==========================================================================================================
SharedValue ListAST::eval() {
    return SharedValue(new List(get_children_vals()));
}


//==========================================================================================================
//==========================================================================================================
NakedListAST::NakedListAST(vector<ParseElement*>& elements) {
    for(auto& e: elements) {
        if(not e->is_token()) { // Skip commas, add everything else
            AST* ast = e->get_ast();
            
            // Because of naked list grammar definition, there will be naked-list ASTs here, need to extract
            // their children so only one list will be created
            if(typeid(*ast) == typeid(NakedListAST))
                for(auto c: ast->children) add_child(c);
            else
                add_child(ast);
        }
    }
}


//==========================================================================================================
//==========================================================================================================
BopAST::BopAST(vector<ParseElement*>& elements): OpAST(get_op(elements[1]->get_token()->sym, 2)) {
    add_child(elements[0]->get_ast());
    add_child(elements[2]->get_ast());
}


//==========================================================================================================
// Some binary operations can be concatenated (e.g. a+b+c...). In those cases the tree is optimized to have
// more than two children.
//==========================================================================================================
SharedValue BopAST::eval() {
    SharedValue first_val = children[0]->eval();
    
    if(op->sym == OR or op->sym == AND) {
        bool val = first_val->to_bool();

        if((op->sym == OR and val == true) or (op->sym == AND and val == false))
            return first_val;
    }

    SharedValue second_val = children[1]->eval();
    return op->eval({first_val, second_val});
}


//==========================================================================================================
//==========================================================================================================
SharedValue DotAccessAST::eval() {
    SharedValue lvalue = children[0]->eval();
    string name = children[1]->get_name();
    name = name.substr(0, name.length() - 2); // Remove last "()"
    return lvalue->call_func(name, children[1]->get_children_as_parameters());
}


//==========================================================================================================
//==========================================================================================================
UopAST::UopAST(vector<ParseElement*>& elements): OpAST(get_op(elements[0]->get_token()->sym, 1)) {
    add_child(elements[1]->get_ast());
}


//==========================================================================================================
//==========================================================================================================
SharedValue UopAST::eval() {
    return op->eval(get_children_vals());
}


//==========================================================================================================
//==========================================================================================================
CondExpAST::CondExpAST(vector<ParseElement*>& elements) {
    add_child(elements[0]->get_ast());
    add_child(elements[2]->get_ast());
    add_child(elements[4]->get_ast());
}


//==========================================================================================================
//==========================================================================================================
SharedValue CondExpAST::eval() {
    if(children[0]->eval()->to_bool())
        return children[1]->eval();
    else
        return children[2]->eval();
}


//==========================================================================================================
//==========================================================================================================
SharedValue VarAST::eval() {
    SharedValue val = interpreter->get_val(name);
    
    if(val->is_no_value())
        THROW << "Variable " << name << " is not defined";
    
    return val;
}


//==========================================================================================================
//==========================================================================================================
AssignmentAST::AssignmentAST(vector<ParseElement*>& elements): conditional(elements[1]->get_token()->sym == CONDITIONAL_ASSIGN) {
    add_child(new VarAST(elements));
    add_child(elements[2]->get_ast());
}


//==========================================================================================================
//==========================================================================================================
SharedValue AssignmentAST::eval() {
    string var = ((VarAST*)children[0])->name;
    
    if(not conditional or not interpreter->var_exists(var)) {
        SharedValue val = children[1]->eval();
        
        if(val->is_no_value())
            THROW << "Cannot assign a no_value to a variable";
        
        // If the value is shared, copy it so each variable will have its own instance of the value
        if(not val.unique())
            interpreter->set_val(var, SharedValue(val->copy()));
        else
            interpreter->set_val(var, val);
    }
        
    return no_value;
}


//==========================================================================================================
//==========================================================================================================
StatementsAST::StatementsAST(vector<ParseElement*>& elements) {
    // Make children "flat", each shall be an actual statemet and statements nodes will be discarded
    for(auto e: elements) {
        if(e->is_token())
            continue; // Probably a semi colon or curly brace
        
        add_flat_statements(e->get_ast());
    }
}


//==========================================================================================================
//==========================================================================================================
SharedValue StatementsAST::eval() {
    eval_children(0);
    return no_value;
}


//==========================================================================================================
// First child will be the expression to evaluate. Rest will be the statements in the body
//==========================================================================================================
IfAST::IfAST(vector<ParseElement*>& elements) {
    add_child(elements[1]->get_ast());
    add_flat_statements(elements[2]->get_ast());
}


//==========================================================================================================
//==========================================================================================================
SharedValue IfAST::eval() {
    if(children[0]->eval()->to_bool())
        eval_children(1);
    
    return no_value;
}


//==========================================================================================================
//==========================================================================================================
IfElseAST::IfElseAST(vector<ParseElement*>& elements) {
    add_child(elements[1]->get_ast());
    add_child(elements[2]->get_ast());
    add_child(elements[4]->get_ast());
}


//==========================================================================================================
//==========================================================================================================
SharedValue IfElseAST::eval() {
    if(children[0]->eval()->to_bool())
        children[1]->eval();
    else
        children[2]->eval();
    
    return no_value;
}


//==========================================================================================================
//==========================================================================================================
WhileAST::WhileAST(vector<ParseElement*>& elements) {
    add_child(elements[1]->get_ast());
    add_flat_statements(elements[2]->get_ast());
}


//==========================================================================================================
//==========================================================================================================
SharedValue WhileAST::eval() {
    while(children[0]->eval()->to_bool()) {
        try {
            eval_children(1);
        } catch (AST::JumpKind jump_kind) {
            if(jump_kind == BREAK)
                break;
            else
                continue;
        }
    }
    
    return no_value;
}


//==========================================================================================================
// Each time this tree is executed, it will evaluate the expression (first child), then repeat the body that
// number of times. However, the next time the tree is evaluated the 'times' expression can have another
// value
//==========================================================================================================
RepeatAST::RepeatAST(vector<ParseElement*>& elements) {
    add_child(elements[1]->get_ast());
    add_flat_statements(elements[3]->get_ast());
}


//==========================================================================================================
//==========================================================================================================
SharedValue RepeatAST::eval() {
    int times = children[0]->eval()->to_int();
    ASSERT_NOT_NEGATIVE("variable", times);
    
    for(int i = 0; i < times; ++i) {
        try {
            eval_children(1);
        } catch (AST::JumpKind jump_kind) {
            if(jump_kind == BREAK)
                break;
            else
                continue;
        }
    }

    return no_value;
}


//==========================================================================================================
// Syntax: for ID in EXP STATEMENT
// First child will be the expression, second the statement.
//==========================================================================================================
ForAST::ForAST(vector<ParseElement*>& elements) {
    item_name =  ((IdentifierToken*)elements[1]->get_token())->name;
    add_child(elements[3]->get_ast());
    add_flat_statements(elements[4]->get_ast());
}


//==========================================================================================================
//==========================================================================================================
SharedValue ForAST::eval() {
    SharedValue val = children[0]->eval();
    
    for(int i = 0; i < val->length(); ++i) {
        interpreter->set_val(item_name, val->subscript(i));
        
        for(int j = 1; j < children.size(); ++j)
            children[j]->eval();
    }
    
    return no_value;
}


//==========================================================================================================
//==========================================================================================================
ParamValAST::ParamValAST(vector<ParseElement*>& elements): name(((ParamToken*)elements[0]->get_token())->name) {
    add_child(elements[1]->get_ast());
}


//==========================================================================================================
//==========================================================================================================
SharedValue ParamValAST::eval() {
    return SharedValue(new ParamVal(name, children[0]->eval()));
}


//==========================================================================================================
//==========================================================================================================
ParamValsAST::ParamValsAST(vector<ParseElement*>& elements) {
    for(auto& e: elements) {
        if(not e->is_token()) { // Skip commas, parenthesis, add everything else
            AST* ast = e->get_ast();
            if(typeid(*ast) == typeid(ParamValsAST))
                for(auto c: ast->children)
                    add_child(c);
            else
                add_child(ast);
        }
    }
}


//==========================================================================================================
//==========================================================================================================
SharedValue ParamValsAST::eval() {
    return SharedValue(new ParamValsList(get_children_vals()));
}


//==========================================================================================================
//==========================================================================================================
SharedValue CallableAST::eval() {
    vector<SharedValue> args = get_children_as_parameters();    
    return interpreter->call_func(name, args);
}


//==========================================================================================================
// The children are the function parameters
//==========================================================================================================
FuncAST::FuncAST(vector<ParseElement*>& elements): CallableAST(elements) {
    if(elements.size() != 3) { // 3 means no parameters : "ID ( )"
        // Get the children of the parameter list
        for(auto c: elements[2]->get_ast()->children)
            add_child(c);
    }
}


//==========================================================================================================
// The children are the command parameters
//==========================================================================================================
CommandAST::CommandAST(vector<ParseElement*>& elements): CallableAST(elements) {
    if(elements.size() > 1)
        for(auto c: elements[1]->get_ast()->children)
            add_child(c);
}


//==========================================================================================================
//==========================================================================================================
TryFinallyAST::TryFinallyAST(vector<ParseElement*>& elements) {
    add_child(elements[1]->get_ast());
    add_child(elements[3]->get_ast());
}


//==========================================================================================================
//==========================================================================================================
SharedValue TryFinallyAST::eval() {
    st_exception exception;
    
    // Evaluate the try section
    try {
        children[0]->eval();
    } catch (st_exception &e) {
        exception = e;
    }
    
    // Evaluate the finally section
    children[1]->eval();
    
    if(not exception.empty())
        throw exception;
    
    return no_value;
}
    

//==========================================================================================================
// Note: class Range represents a range, but the range may be specified with exprssions and not constants.
// Therefore, in the general case will keep the two expression as children of this node.
//==========================================================================================================
RangeAST::RangeAST(vector<ParseElement*>& elements) {
    add_child(elements[1]->get_ast());
    add_child(elements[3]->get_ast());
}


//==========================================================================================================
//==========================================================================================================
SharedValue RangeAST::eval() {
    return SharedValue(new Range(children[0]->eval(), children[1]->eval()));
}
 
