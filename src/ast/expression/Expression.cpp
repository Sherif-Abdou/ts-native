//
// Created by Sherif Abdou on 8/10/20.
//

#include "Expression.h"

const Type &Expression::getType() const {
    return type;
}

void Expression::setType(const Type &type) {
    this->type = type;
}
