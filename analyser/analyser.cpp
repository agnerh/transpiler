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
        this->tokens.push_back(token);
        pos += token.value.length();
    } while (token.type != TokenType::EOF_);

    return 0;
}