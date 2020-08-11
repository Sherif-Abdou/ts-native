//
// Created by Sherif Abdou on 8/10/20.
//

#ifndef TYPESCRIPT_NATIVE_SCOPE_H
#define TYPESCRIPT_NATIVE_SCOPE_H

#include <vector>
#include <memory>
#include "ASTNode.h"
#include "expression/Variable.h"

using std::string;
using std::vector;
using std::unique_ptr;

class FunctionNode;

class Scope: public ASTNode {
public:
    vector<unique_ptr<FunctionNode>> functions;
    vector<unique_ptr<Variable>> variables;
    vector<unique_ptr<ASTNode>> commands;
};


#endif //TYPESCRIPT_NATIVE_SCOPE_H
