#pragma once

#include "token.h"
#include "keywords.h"
#include "operators.h"
#include "lexical_token.h"
#include "lexer.h"
#include "../filemanager/filemanager.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Analyser {
    private:
        std::vector<LexicalToken> tokens;
        std::unique_ptr<FileManager> fm;
        std::unique_ptr<Lexer> lexer;
    
    public:
        std::vector<LexicalToken> GetTokens();
        int Analyse();
};