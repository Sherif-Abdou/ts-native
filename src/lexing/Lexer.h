//
// Created by Sherif Abdou on 8/9/20.
//

#ifndef TYPESCRIPT_NATIVE_LEXER_H
#define TYPESCRIPT_NATIVE_LEXER_H

#include <string>
#include "Token.h"

class Lexer {
private:
    std::string str;
    char pop();
public:
    explicit Lexer(std::string str);
    Token next();
};


#endif //TYPESCRIPT_NATIVE_LEXER_H
