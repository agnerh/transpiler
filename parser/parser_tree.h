#pragma once

#include <string>
#include <memory>
#include <vector>

class ParserTree {
    public:
        ParserTree();
        ParserTree(ParserTreeType type) {
            this->type = type;
        }
        ParserTree(ParserTreeType type, std::string value) {
            this->type = type;
            this->value = value;
        }

        std::string value;
        std::vector<std::unique_ptr<ParserTree>> nodes;

        ParserTreeType type;
};

const enum ParserTreeType {
    FILE,

    DECLARATION,
    EXPRESSION,
    TERM,

    TYPE_SPECIFIER,
    IDENTIFIER,
    ASSIGNMENT,
    LITERAL,
    KEYWORD
};