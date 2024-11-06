#include "analyser.h";
#include <token.h>
#include <vector>
#include <string>
#include <iostream>

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

        Token GetToken(char character) {
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

        Token GetToken(std::string source) {
            enum TokenType type = TokenType::VARIABLE;

            for (auto it = keywords.begin(); it != keywords.end(); it++) {
                if (source == *it) {
                    type = TokenType::VARIABLE;
                    break;
                }
            }

            return Token(type, source);
        }

        int AnalyseLine(std::string line) {
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
        }

    public:
        std::vector<Token> GetTokens() {
            return tokens;
        }
    
        int AnalyseChunk(std::vector<std::string> lines) {
            for (auto line : lines) {
                int res = AnalyseLine(line);
                if (!res) {
                    return res;
                }
            }

            return 0;
        }
};