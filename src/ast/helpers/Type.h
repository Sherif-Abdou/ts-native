//
// Created by Sherif Abdou on 8/10/20.
//

#ifndef TYPESCRIPT_NATIVE_TYPE_H
#define TYPESCRIPT_NATIVE_TYPE_H

enum BuiltinTypes {
    unknown = 0,
    integer = -1,
    floating = -2
};


struct Type {
    BuiltinTypes type;
};


#endif //TYPESCRIPT_NATIVE_TYPE_H
