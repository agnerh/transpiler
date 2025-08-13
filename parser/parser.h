#pragma once

#include "../analyser/lexical_token.h"
#include "../analyser/token.h"
#include "parser_result.h"
#include "parser_tree.h"
#include <iostream>
#include <vector>
#include <memory>

class Parser {
    private:
        std::unique_ptr<ParserTree> root;
        template <TokenType T> bool IsType(TokenType type);

        ParserResult Declaration(LexicalToken token);
        
    public:
        Parser() {
            this->root = std::make_unique<ParserTree>();
        }

        std::shared_ptr<ParserResult> Parse(std::vector<LexicalToken> tokens);
};