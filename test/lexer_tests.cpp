//
// Created by Sherif Abdou on 8/10/20.
//


#include <string>
#include <boost/test/unit_test.hpp>
#include "../src/lexing/Lexer.h"

BOOST_AUTO_TEST_SUITE(lexer_tests)

BOOST_AUTO_TEST_CASE (test_test_function)
{
    BOOST_TEST(true);
};

BOOST_AUTO_TEST_CASE(test_lexer_works) {
    using std::string;
    string test_str = "fun main()\n";
    Lexer lexer = Lexer(test_str);
    BOOST_ASSERT_MSG(lexer.next().type == TokenType::token_fun, "Didn't recognize fun");
    BOOST_ASSERT_MSG(lexer.next().type == TokenType::token_iden, "Didn't recognize identifier 'main'");
    BOOST_ASSERT_MSG(lexer.next().type == TokenType::token_open_parenth, "Didn't recognize token (");
    BOOST_ASSERT_MSG(lexer.next().type == TokenType::token_close_parenth, "Didn't recognize the token )");
    BOOST_ASSERT_MSG(lexer.next().type == TokenType::token_eol, "Didn't recognize end of line");
    BOOST_ASSERT_MSG(lexer.next().type == TokenType::token_eof, "Didn't recognize end of str");
}

BOOST_AUTO_TEST_SUITE_END();