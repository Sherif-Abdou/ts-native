//
// Created by Sherif Abdou on 8/10/20.
//


#include <boost/test/unit_test.hpp>
#include "../src/lexing/Lexer.h"
#include "../src/parsing/Parser.h"
#include "../src/ast/LetNode.h"
#include "../src/ast/expression/Constant.h"

BOOST_AUTO_TEST_SUITE(parser_tests);

BOOST_AUTO_TEST_CASE(test_parser) {
    Lexer lexer = Lexer("fun main()");
    Parser parser = Parser(lexer);

    parser.parse();

    Scope* root = parser.getRoot();
    BOOST_TEST(root != nullptr);
    BOOST_TEST(root->functions.size() == 1);
    BOOST_TEST(root->functions[0]->getName() == "main");
}

BOOST_AUTO_TEST_CASE(test_parser_variable) {
    Lexer lexer = Lexer("let x = 2");
    Parser parser = Parser(lexer);

    parser.parse();

    Scope* root = parser.getRoot();
    BOOST_TEST(root != nullptr);
    BOOST_TEST(root->commands.size() == 1);
    auto * casted = dynamic_cast<LetNode*>(root->commands[0]);
    BOOST_TEST(casted != nullptr);
    Variable* var = casted->getVariable();
    BOOST_TEST(var->getName() == "x");
    auto * constant = dynamic_cast<Constant*>(casted->getValue());
    BOOST_TEST(constant->integer == 2);
}

BOOST_AUTO_TEST_CASE(test_parser_function_scope) {
    Lexer lexer = Lexer("fun main() {\n let y = 3 \n }");
    Parser parser = Parser(lexer);

    parser.parse();

    Scope* root = parser.getRoot();
    BOOST_TEST(root != nullptr);
    BOOST_TEST(root->functions.size() == 1);
    auto * casted = dynamic_cast<FunctionNode*>(root->functions[0]);
    BOOST_TEST(casted != nullptr);
    BOOST_TEST(casted->getName() == "main");
}

BOOST_AUTO_TEST_SUITE_END();