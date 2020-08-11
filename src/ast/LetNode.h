//
// Created by Sherif Abdou on 8/10/20.
//

#ifndef TYPESCRIPT_NATIVE_LETNODE_H
#define TYPESCRIPT_NATIVE_LETNODE_H


#include "expression/Variable.h"
#include "expression/Expression.h"
#include "ASTNode.h"

class LetNode: public ASTNode {
private:
    Variable *variable;
    Expression* value;
public:
    Expression *getValue() const;
    void setValue(Expression *value);
    Variable *getVariable() const;
    explicit LetNode(Variable *variable, Expression* value);
};


#endif //TYPESCRIPT_NATIVE_LETNODE_H
