//
// Created by Sherif Abdou on 8/10/20.
//

#ifndef TYPESCRIPT_NATIVE_LETNODE_H
#define TYPESCRIPT_NATIVE_LETNODE_H

#include <memory>

#include "expression/Variable.h"
#include "expression/Expression.h"
#include "ASTNode.h"

using std::unique_ptr;

class LetNode: public ASTNode {
private:
    Variable *variable;
    unique_ptr<Expression> value;
public:
    Expression *getValue() const;
    void setValue(const Expression &value);
    Variable *getVariable() const;
    explicit LetNode(Variable *variable, Expression* value);
};


#endif //TYPESCRIPT_NATIVE_LETNODE_H
