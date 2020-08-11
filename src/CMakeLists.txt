project(TLIB)

file(GLOB CPP_FILES **/*.cpp)

include_directories("/usr/local/opt/llvm/include/")

# LLVM
add_library(llvm SHARED IMPORTED)
set_target_properties(llvm PROPERTIES
        IMPORTED_LOCATION "/usr/local/opt/llvm/lib/libLLVM.dylib"
        INTERFACE_INCLUDE_DIRECTORIES "/usr/local/opt/llvm/include/"
        )

add_library(${PROJECT_NAME} STATIC ast/ASTNode.cpp ast/FunctionNode.cpp ast/Scope.cpp
        ast/expression/Variable.cpp lexing/Token.cpp lexing/Lexer.cpp
        parsing/Parser.cpp parsing/InvalidToken.cpp parsing/InvalidToken.h ast/RootScope.cpp ast/RootScope.h ast/LetNode.cpp ast/LetNode.h ast/expression/Expression.cpp ast/expression/Expression.h ast/expression/Constant.cpp ast/expression/Constant.h ast/helpers/Type.cpp ast/helpers/Type.h parsing/UnexpectedVariable.cpp parsing/UnexpectedVariable.h)

set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_libraries(${PROJECT_NAME} llvm)

set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include
        CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)