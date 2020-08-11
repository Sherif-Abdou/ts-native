//
// Created by Sherif Abdou on 8/10/20.
//

#include "Parser.h"
#include "InvalidToken.h"
#include "../ast/RootScope.h"
#include "UnexpectedVariable.h"
#include "../ast/expression/Constant.h"
#include "../ast/LetNode.h"

Parser::Parser(Lexer lexer)
    :lexer(std::move(lexer)) {
    this->root = new RootScope();
    this->scope_stack = vector<Scope*>();
    this->scope_stack.push_back(this->root);
}

void Parser::parse() {
    Token token = this->lexer.next();
    while (token.type != TokenType::token_eof) {
        switch (token.type) {
            case token_fun:
                this->parse_fun();
                break;
            case token_let:
                this->parse_let();
                break;
            case token_close_curly:
                this->scope_stack.pop_back();
                break;
            default:
                break;
       }
       token = this->lexer.next();
    }
}

Token Parser::next() {
    return this->lexer.next();
}

void Parser::parse_fun() {
    Token token = this->next();
    auto * func = new FunctionNode();
    if (token.type == TokenType::token_iden) {
        func->setName(token.raw_iden);
    }
    token = this->next();
    if (token.type != TokenType::token_open_parenth) {
        throw InvalidToken();
    }
    token = this->next();
    if (token.type != TokenType::token_close_parenth) {
        throw InvalidToken();
    }
    token = this->next();
    this->top()->functions.push_back(func);
    if (token.type == TokenType::token_open_curly) {
        this->scope_stack.push_back(static_cast<Scope*>(func));
    } else if (token.type == TokenType::token_eol || token.type == TokenType::token_eof) {
        func->setDeclare(true);
    } else {
        throw InvalidToken();
    }
}

Scope *Parser::getRoot() const {
    return root;
}

void Parser::parse_let() {
    Token token = this->next();
    if (token.type != TokenType::token_iden) {
        throw InvalidToken();
    }
    Variable* variable;
    string name = token.raw_iden;
    if (!(variable = this->search_variable(token.raw_iden))) {
        variable = new Variable();
        variable->setName(name);
    }
    token = this->next();
    if (token.type != TokenType::token_equal) {
        throw InvalidToken();
    }
    Expression* exp = this->parse_exp();

    auto* letNode = new LetNode(variable, exp);

    this->top()->commands.push_back(letNode);
}

Expression* Parser::parse_exp() {
    Token token = this->next();
    if (token.type == TokenType::token_num) {
        auto con = new Constant(std::stoi(token.raw_iden));
        return con;
    } else if (token.type == TokenType::token_iden) {
        Variable* var = this->search_variable(token.raw_iden);
        if (var == nullptr) {
            throw UnexpectedVariable();
        }
        return var;
    } else {
        throw InvalidToken();
    }
}

Scope *Parser::top() {
    return this->scope_stack[this->scope_stack.size()-1];
}

Variable *Parser::search_variable(string name) {
    Variable* output = nullptr;
    std::for_each(this->scope_stack.crbegin(), this->scope_stack.crend(), [&](const Scope* scope){
        std::for_each(scope->variables.begin(), scope->variables.end(), [&](Variable* var) {
            if (var->getName() == name) {
                output = var;
            }
        });
    });
    return output;
}
