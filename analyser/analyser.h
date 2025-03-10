#pragma once

#include "token.h"
#include <iostream>
#include <vector>
#include <string>

class Analyser {
    private:
        std::vector<std::string> keywords {
            "if", "else", 
            "for", "of", "in", 
            "var", "let", "const", 
            "while", "do",
            "try", "catch", "finally",
            "function", "()", "=>"
        };

        std::vector<Token> tokens;

        char end_statement = ';';
        char space = ' ';

        Token GetToken(char character);
        Token GetToken(std::string source);
        int AnalyseLine(std::string line);
    
    public:
        std::vector<Token> GetTokens();
        int AnalyseChunk(std::vector<std::string> lines);
};