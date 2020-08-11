//
// Created by Sherif Abdou on 8/10/20.
//

#ifndef TYPESCRIPT_NATIVE_INVALIDTOKEN_H
#define TYPESCRIPT_NATIVE_INVALIDTOKEN_H

#include <string>
#include <exception>

using std::string;
using std::exception;

struct InvalidToken: public exception {
    string message = "Unexpected token";
};


#endif //TYPESCRIPT_NATIVE_INVALIDTOKEN_H
