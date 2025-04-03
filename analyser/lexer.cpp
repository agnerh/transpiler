#include "lexer.h"

bool Lexer::IsNumber(char c) {
    return isdigit(c);
}

bool Lexer::IsSpecialCharacter(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/'
        || c == '.' || c == '%' || c == '<' || c == '>'
        || c == '=' || c == '&' || c == '!' || c == '|'
        || c == '~' || c == '?' || c == ';';
}

bool Lexer::IsStrValue(char c) {
    return  c == '"' || c == '\'';
}

bool Lexer::IsIdentifierCharacter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || c == '$';
}

bool Lexer::IsWhiteSpace(char c) {
    return isspace(c);
}

bool Lexer::IsEOF(char c) {
    return c == EOF;
}

bool Lexer::IsEndline(char c) {
    return c == '\n' || c == '\r';
}

LexicalToken Lexer::GetNumberToken(std::string buffer, uint pos) {
    auto endPos = pos + 1;
    char endChar = buffer.at(endPos);

    while (IsNumber(endChar)) {
        endPos++;
        endChar = buffer.at(endPos);
    }

    auto numberOfChars = endPos - pos;
    auto value = buffer.substr(pos, numberOfChars);

    return LexicalToken(TokenType::NUMERICAL_VALUE, value);
}

LexicalToken Lexer::GetIdentifierToken(std::string buffer, uint pos) {
    auto endPos = pos + 1;
    char endChar = buffer.at(endPos);

    while (IsIdentifierCharacter(endChar)) {
        endPos++;
        endChar = buffer.at(endPos);
    }

    auto numberOfChars = endPos - pos;
    auto value = buffer.substr(pos, numberOfChars);

    auto type = reserved_keywords.find(value);
    if (type != reserved_keywords.end()) {
        return LexicalToken(type->second, value);
    }

    return LexicalToken(TokenType::IDENTIFIER, value);
}

LexicalToken Lexer::GetSpecialCharacterToken(std::string buffer, uint pos) {
    if (buffer.at(pos) == ';') {
        return LexicalToken(TokenType::SEMICOLON, std::string(1, buffer.at(pos)));
    }
    
    auto endPos = pos + 1;
    auto endChar = buffer.at(endPos);

    while (IsSpecialCharacter(endChar)) {
        endPos++;
        endChar = buffer.at(endPos);
    }

    auto numberOfChars = endPos - pos;
    auto value = buffer.substr(pos, numberOfChars);

    auto type = operators.find(value);
    if (type != operators.end()) {
        return LexicalToken(type->second, value);
    }

    if (value == "//") {
        return GetSingleLineCommentValue(buffer, pos);
    }

    if (value == "/*") {
        return GetMultiLineCommentValue(buffer, pos);
    }

    return LexicalToken(TokenType::INVALID, value);
}

LexicalToken Lexer::GetSingleLineCommentValue(std::string buffer, uint pos) {
    auto endPos = pos + 2;
    auto endChar = buffer.at(endPos);

    while (!IsEndline(endChar) && !IsEOF(endChar)) {
        endPos++;
        endChar = buffer.at(endPos);
    }

    auto numberOfChars = endPos - pos;
    auto value = buffer.substr(pos, numberOfChars);
    
    return LexicalToken(TokenType::SINGLELINE_COMMENT, value);
}

LexicalToken Lexer::GetMultiLineCommentValue(std::string buffer, uint pos) {
    auto endPos = pos + 2;
    auto endChar = buffer.at(endPos);

    while (!IsEOF(endChar)) {
        if (endChar == '*' && buffer.at(endPos + 1) == '/') {
            auto numberOfChars = (endPos + 1) - pos;
            auto value = buffer.substr(pos, numberOfChars);
            return LexicalToken(TokenType::MULTILINE_COMMENT, value);
        }

        endPos++;
        endChar = buffer.at(endPos);
    }

    auto numberOfChars = endPos - pos;
    auto value = buffer.substr(pos, numberOfChars);
    return LexicalToken(TokenType::INVALID, value);
}

LexicalToken Lexer::GetStrValue(std::string buffer, uint pos) {
    auto startChar = buffer.at(pos);
    auto endPos = pos + 1;
    auto endChar = buffer.at(endPos);

    while (startChar != endChar) {
        endPos++;
        endChar = buffer.at(endPos);

        // Skip escaped characters
        if (endChar == '\\') {
            endPos++;
        }
    }

    auto numberOfChars = (endPos + 1) - pos;
    auto value = buffer.substr(pos, numberOfChars);

    return LexicalToken(TokenType::STRING_VALUE, value);
}

LexicalToken Lexer::GetNextToken(std::string buffer, uint pos) {
    if (pos >= buffer.length()) {
        return LexicalToken(TokenType::EOF_, "");
    }
    
    char c = buffer.at(pos);
    
    if (IsEOF (c)) {
        return LexicalToken(TokenType::EOF_, std::string(1, c));
    } else if (IsWhiteSpace(c)) {
        return LexicalToken(TokenType::SPACE, std::string(1, c));
    } else if (IsEndline(c)) {
        return LexicalToken(TokenType::ENDLINE, std::string(1, c));
    } else if (IsNumber(c)) {
        return GetNumberToken(buffer, pos);
    } else if (IsSpecialCharacter(c)) {
        return GetSpecialCharacterToken(buffer, pos);
    } else if (IsStrValue(c)) {
        return GetStrValue(buffer, pos);
    } else if (IsIdentifierCharacter(c)) {
        return GetIdentifierToken(buffer, pos);
    }

    return LexicalToken(TokenType::INVALID, std::string(1, c));
}