//
// Created by Sherif Abdou on 8/10/20.
//

#ifndef TYPESCRIPT_NATIVE_CONSTANT_H
#define TYPESCRIPT_NATIVE_CONSTANT_H


#include "Expression.h"

class Constant: public Expression {
public:
    explicit Constant(double floating);

    explicit Constant(int integer);

public:
    union {
        double floating;
        int integer;
    };
};


#endif //TYPESCRIPT_NATIVE_CONSTANT_H
