#pragma once

#include "lexical_token.h"
#include "operators.h"
#include "keywords.h"
#include <string>
#include <ctype.h>

class Lexer {
    private:
        bool IsNumber(char c);
        bool IsSpecialCharacter(char c);
        bool IsIdentifierCharacter(char c);
        bool IsWhiteSpace(char c);
        bool IsEOF(char c);

        LexicalToken GetNumberToken(std::string buffer, uint pos);
        LexicalToken GetIdentifierToken(std::string buffer, uint pos);
        LexicalToken GetSpecialCharacterToken(std::string buffer, uint pos);
        
        public:
        LexicalToken GetNextToken(std::string buffer, uint pos);
};