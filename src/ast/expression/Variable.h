//
// Created by Sherif Abdou on 8/10/20.
//

#ifndef TYPESCRIPT_NATIVE_VARIABLE_H
#define TYPESCRIPT_NATIVE_VARIABLE_H

#include <string>
#include "Expression.h"

using std::string;

class Variable: public Expression {
private:
    string name;
public:
    const string &getName() const;

    void setName(const string &name);
};


#endif //TYPESCRIPT_NATIVE_VARIABLE_H
