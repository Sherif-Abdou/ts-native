//
// Created by Sherif Abdou on 8/10/20.
//

#ifndef TYPESCRIPT_NATIVE_SCOPE_H
#define TYPESCRIPT_NATIVE_SCOPE_H

#include <vector>
#include "ASTNode.h"
#include "expression/Variable.h"

using std::string;
using std::vector;

class FunctionNode;

class Scope: public ASTNode {
public:
    vector<FunctionNode*> functions;
    vector<Variable*> variables;
    vector<ASTNode*> commands;
};


#endif //TYPESCRIPT_NATIVE_SCOPE_H
