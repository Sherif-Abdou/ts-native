//
// Created by Sherif Abdou on 8/10/20.
//

#ifndef TYPESCRIPT_NATIVE_ASTNODE_H
#define TYPESCRIPT_NATIVE_ASTNODE_H

#include <llvm/IR/IRBuilder.h>
class ASTNode {
public:
    virtual void visit(llvm::IRBuilder<>& builder);
};


#endif //TYPESCRIPT_NATIVE_ASTNODE_H
