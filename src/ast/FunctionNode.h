//
// Created by Sherif Abdou on 8/10/20.
//

#ifndef TYPESCRIPT_NATIVE_FUNCTIONNODE_H
#define TYPESCRIPT_NATIVE_FUNCTIONNODE_H

#include <string>
#include "ASTNode.h"
#include "Scope.h"

using std::string;

class FunctionNode: public Scope {
private:
    string name;
    bool declare = false;
public:
    bool isDeclare() const;

    void setDeclare(bool declare);

public:
    const string &getName() const;

    void setName(const string &name);
};


#endif //TYPESCRIPT_NATIVE_FUNCTIONNODE_H
