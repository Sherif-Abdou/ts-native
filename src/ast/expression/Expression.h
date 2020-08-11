//
// Created by Sherif Abdou on 8/10/20.
//

#ifndef TYPESCRIPT_NATIVE_EXPRESSION_H
#define TYPESCRIPT_NATIVE_EXPRESSION_H


#include "../helpers/Type.h"

class Expression {
protected:
    Type type;
public:
    virtual const Type &getType() const;

    virtual void setType(const Type &type);
};


#endif //TYPESCRIPT_NATIVE_EXPRESSION_H
