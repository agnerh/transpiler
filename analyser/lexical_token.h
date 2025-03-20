#pragma once

#include "token.h"
#include <string>

class LexicalToken {
    public:
        TokenType type;
        std::string value;

        LexicalToken() {}

        LexicalToken(TokenType type, std::string value) {
            this->type = type;
            this->value = value;
        }
};