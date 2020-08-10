//
// Created by Sherif Abdou on 8/9/20.
//

#ifndef TYPESCRIPT_NATIVE_TOKEN_H
#define TYPESCRIPT_NATIVE_TOKEN_H

#include <string>

enum TokenType {
    token_eof = -1,
    token_eol = -2,
    token_iden = -3,
    token_num = -4,
    token_fun = -5,
    token_open_parenth = -6,
    token_close_parenth = -7,
    token_comma = -8
};

struct Token {
    TokenType type;
    std::string raw_iden;
    explicit Token(TokenType type, std::string iden);
};


#endif //TYPESCRIPT_NATIVE_TOKEN_H
