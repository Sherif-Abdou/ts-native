//
// Created by Sherif Abdou on 8/10/20.
//

#ifndef TYPESCRIPT_NATIVE_PARSER_H
#define TYPESCRIPT_NATIVE_PARSER_H

#include <stack>

#include "../lexing/Lexer.h"
#include "../ast/FunctionNode.h"
#include "../ast/Scope.h"
#include "../ast/expression/Expression.h"

using std::stack;

class Parser {
private:
    Lexer lexer;

    Token next();

    vector<Scope *> scope_stack;
    Scope *root;
    void parse_fun();
    void parse_let();
    Expression* parse_exp();
    Scope* top();
    Variable* search_variable(string name);
public:
    Scope *getRoot() const;

    explicit Parser(Lexer lexer);

    void parse();
};


#endif //TYPESCRIPT_NATIVE_PARSER_H
