#include "parser.h"

template <TokenType T> bool Parser::IsType(TokenType type) {
    return token.type == type;
}

ParserResult Declaration(LexicalToken token) {
    ParserTree node = ParserTree(ParserTreeType::DECLARATION);
    ParserResult result = ParserResult(node);


    return result;
}

// Use recursive descent parsing
std::shared_ptr<ParserResult> Parser::Parse(std::vector<LexicalToken> tokens) {
    auto tree = std::make_unique<ParserTree>(ParserTreeType::FILE);
    auto result = std::make_shared<ParserResult>(tree);

    for (auto token : tokens) {
        auto type = token.type;

        if (IsType<TokenType::CONST>(type) || IsType<TokenType::LET>(type) || IsType<TokenType::VAR>(type)) {
            auto declarationResult = Declaration(token);
            if (declarationResult.error != nullptr) {
                // TODO: Handle errors
            }

            result->tree->nodes.push_back(declarationResult.tree);
        }
    }    
    
    return result;
}