#pragma once

#include "parser_tree.h"
#include "parser_error.h"
#include "memory"

class ParserResult {
    public:
        ParserResult();
        
        ParserResult(ParserTree tree) {
            this->tree = tree;
        }

        ParserResult(ParserError error) {
            this->error = error;
        }

        ParserTree tree;
        ParserError error;
};