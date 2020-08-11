//
// Created by Sherif Abdou on 8/9/20.
//

#ifndef TYPESCRIPT_NATIVE_LEXER_H
#define TYPESCRIPT_NATIVE_LEXER_H

#include <string>
#include <queue>
#include "Token.h"

class Lexer {
private:
    std::string str;
    std::queue<Token> backlog;
    char pop();
public:
    explicit Lexer(std::string str);
    Token next();
    void add_back(const Token& token);
};


#endif //TYPESCRIPT_NATIVE_LEXER_H
