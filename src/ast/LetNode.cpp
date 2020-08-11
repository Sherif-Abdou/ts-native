//
// Created by Sherif Abdou on 8/10/20.
//

#include "LetNode.h"

LetNode::LetNode(Variable* variable, Expression* value)
    :variable(variable), value(value) {
}

Expression * LetNode::getValue() const {
    return value.get();
}

Variable *LetNode::getVariable() const {
    return variable;
}


void LetNode::setValue(const Expression &value) {
    *LetNode::value = value;
}
