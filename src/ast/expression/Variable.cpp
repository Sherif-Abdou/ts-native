//
// Created by Sherif Abdou on 8/10/20.
//

#include "Variable.h"

const string &Variable::getName() const {
    return name;
}

void Variable::setName(const string &name) {
    Variable::name = name;
}

