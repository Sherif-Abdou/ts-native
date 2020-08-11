//
// Created by Sherif Abdou on 8/10/20.
//

#include "FunctionNode.h"

const string &FunctionNode::getName() const {
    return name;
}

void FunctionNode::setName(const string &name) {
    this->name = name;
}
