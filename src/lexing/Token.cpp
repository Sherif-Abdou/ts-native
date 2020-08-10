//
// Created by Sherif Abdou on 8/9/20.
//

#include "Token.h"

Token::Token(TokenType type, std::string iden)
    :type(type), raw_iden(std::move(iden)) {

}
