//
// Created by Sherif Abdou on 8/9/20.
//

#include "Lexer.h"

Lexer::Lexer(std::string str)
    :str(std::move(str)) {
    this->backlog = std::queue<Token>();
}

Token Lexer::next() {
    if (!this->backlog.empty()) {
        auto top_token = this->backlog.back();
        this->backlog.pop();
        return top_token;
    }

    if (this->str.empty()) {
        return Token(TokenType::token_eof, "");
    }

    char c = this->pop();
    while (isblank(c)) {
        c = this->pop();
    }

    if (c == '\n') {
        return Token(TokenType::token_eol, "\n");
    } else if (c == '(') {
        return Token(TokenType::token_open_parenth, "(");
    } else if (c == ')') {
        return Token(TokenType::token_close_parenth, ")");
    } else if (c == ',') {
        return Token(TokenType::token_comma, ",");
    } else if (c == '=') {
        return Token(TokenType::token_equal, "=");
    } else if (c == '{') {
        return Token(TokenType::token_open_curly, "{");
    } else if (c == '}') {
        return Token(TokenType::token_close_curly, "}");
    }

    std::string iden = "";
    if (isnumber(c)) {
        while (isnumber(c)) {
            iden += c;
            c = this->pop();
        }
        if (!isblank(c)) {
            this->str.insert(0, std::string {c});
        }
        return Token(TokenType::token_num, iden);
    }
    if (isalnum(c)) {
        while (isalnum(c)) {
            iden += c;
            c = this->pop();
        }
        if (!isblank(c)) {
            this->str.insert(0, std::string {c});
        }
    }

    if (iden == "fun") {
        return Token(TokenType::token_fun, "\n");
    } else if (iden == "let") {
        return Token(TokenType::token_let, "let");
    } else {
        return Token(TokenType::token_iden, iden);
    }
}

char Lexer::pop() {
    char c = this->str[0];
    this->str.erase(0, 1);
    return c;
}

void Lexer::add_back(const Token& token) {
    this->backlog.push(token);
}
