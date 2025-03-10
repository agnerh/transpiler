#pragma once

#include <string>

enum TokenType {
    VARIABLE = 1,
    KEYWORD,
    SPACE,
    END_STATEMENT,
    UNKNOWN,
};

class Token {
    public:
        enum TokenType type;
        std::string source;

        Token() {}
        Token(TokenType type, std::string source) {
            this->type = type;
            this->source = source;
        }
};