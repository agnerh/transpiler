#include "analyser.h"
#include "token.h"
#include <vector>
#include <string>
#include <iostream>

Token Analyser::GetToken(char character) {
    enum TokenType type = TokenType::VARIABLE;

    if (character == end_statement) {
        type = TokenType::END_STATEMENT;
    }

    if (character == space) {
        type = TokenType::SPACE;
    }

    std::string character_string { character };
    return Token(type, character_string);
}

Token Analyser::GetToken(std::string source) {
    enum TokenType type = TokenType::VARIABLE;

    for (auto it = keywords.begin(); it != keywords.end(); it++) {
        if (source == *it) {
            type = TokenType::VARIABLE;
            break;
        }
    }

    return Token(type, source);
}

int Analyser::AnalyseLine(std::string line) {
    std::string current;
    
    for(auto it = line.begin(); it != line.end(); it++) {

        if (!*it) {
            continue;
        }

        if (*it != space && *it != end_statement) {
            current.push_back(*it);
            continue;
        }

        tokens.push_back(GetToken(current));
        tokens.push_back(GetToken(*it));
        current.clear();
    }

    return 0;
}

std::vector<Token> Analyser::GetTokens() {
    return this->tokens;
}

int Analyser::AnalyseChunk(std::vector<std::string> lines) {
    for (auto line : lines) {
        int res = AnalyseLine(line);
        if (!res) {
            return res;
        }
    }

    return 0;
}