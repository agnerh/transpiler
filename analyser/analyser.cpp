#include "analyser.h"

Analyser::Analyser() {
    this->fm = std::make_unique<FileManager>();
    this->lexer = std::make_unique<Lexer>();
}

std::vector<LexicalToken> Analyser::GetTokens() {
    return this->tokens;
}

int Analyser::Analyse(FileInfo info) {
    this->fm->AddFile(info.path);

    auto buffer = this->fm->GetChunk();
    uint pos = 0;

    LexicalToken token;

    do {
        token = this->lexer->GetNextToken(buffer, pos);
        pos += token.value.length();

        if (token.type != TokenType::SPACE) {
            this->tokens.push_back(token);
        }

    } while (token.type != TokenType::EOF_);

    return 0;
}