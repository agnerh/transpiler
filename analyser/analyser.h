#include <token.h>
#include <iostream>
#include <vector>

class Analyser {
    public:
        std::vector<Token> GetTokens();
        int AnalyseChunk(std::vector<std::string> lines);
};