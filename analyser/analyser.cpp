#include "analyser.h"

Analyser::Analyser() {
    this->fm = std::unique_ptr<FileManager>();
    this->lexer = std::unique_ptr<Lexer>();
}

std::vector<LexicalToken> Analyser::GetTokens() {
    return this->tokens;
}

int Analyser::Analyse() {
    auto buffer = this->fm->GetChunk();
    uint pos = 0;

    LexicalToken token;

    do {
        token = this->lexer->GetNextToken(buffer, pos);
        this->tokens.push_back(token);
    } while (token.type != TokenType::EOF_);

    return 0;
}