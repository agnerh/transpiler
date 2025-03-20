#pragma once

#include <string>

enum class TokenType {
    // Invalid
    INVALID,

    // Whitespace
    ENDLINE,
    SPACE,
    SEMICOLON,
    EOF_,

    //Identifier
    IDENTIFIER,
    STRING_VALUE,
    NUMERICAL_VALUE,
    
    // Keywords
    ABSTRACT,
    AS,
    ASSERTS,
    ASYNC,
    AWAIT,
    BREAK,
    CASE,
    // CATCH,
    // CLASS,
    CONST,
    CONTINUE,
    DEBUGGER,
    DECLARE,
    DEFAULT,
    DELETE,
    DO,
    // ELSE,
    ENUM,
    EXPORT,
    EXTENDS,
    FALSE_,
    FINALLY,
    // FOR,
    FROM,
    // FUNCTION,
    GET,
    // IF,
    IMPLEMENTS,
    IMPORT,
    IN,
    INFER,
    INSTANCEOF,
    // INTERFACE,
    IS,
    KEYOF,
    LET,
    MODULE,
    NAMESPACE,
    NEVER,
    NEW,
    NULL_,
    OF,
    PACKAGE,
    PRIVATE,
    PROTECTED,
    PUBLIC,
    READONLY,
    REQUIRE,
    RETURN,
    SET,
    STATIC,
    STRING,
    SUPER,
    // SWITCH,
    SYMBOL,
    THIS,
    THROW,
    TRUE_,
    // TRY,
    TYPE,
    TYPEOF,
    UNDEFINED,
    UNIQUE,
    UNKNOWN,
    VAR,
    VOID,
    // WHILE,
    WITH,
    YIELD,

    // Statements
    CONSOLE_LOG,
    ALERT,
    PROMPT,
    CONFIRM,
    TRY,
    CATCH,
    IF_STATEMENT,
    ELSE_STATEMENT,
    FOR_LOOP,
    WHILE_LOOP,
    SWITCH_STATEMENT,
    FUNCTION_DECLARATION,
    CLASS_DECLARATION,
    INTERFACE_DECLARATION,

    //Operators
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    MODULUS,
    EXPONENTIATION,
    INCREMENT,
    DECREMENT, 
    ASSIGN, 
    PLUS_ASSIGN, 
    MINUS_ASSIGN, 
    MULTIPLY_ASSIGN,
    DIVIDE_ASSIGN, 
    MODULUS_ASSIGN, 
    EXPONENTIATION_ASSIGN, 
    EQUALS, 
    NOT_EQUALS,
    STRICT_EQUALS, 
    STRICT_NOT_EQUALS, 
    GREATER_THAN, 
    LESS_THAN,
    GREATER_EQUAL, 
    LESS_EQUAL, 
    LOGICAL_AND, 
    LOGICAL_OR, 
    LOGICAL_NOT,
    BITWISE_AND, 
    BITWISE_OR, 
    BITWISE_XOR, 
    BITWISE_NOT, 
    LEFT_SHIFT,
    RIGHT_SHIFT, 
    UNSIGNED_RIGHT_SHIFT, 
    TERNARY, 
    OPTIONAL_CHAINING,
    NULLISH_COALESCING,
    DOT,
    SPEAD
};

enum class TokenGroup {
    UNKNOWN,
    KEYWORD,
    STATEMENT,
    OPERATOR,
    IDENTIFIER,
    ENDLINE,
};

class Token {
    public:
        enum TokenType type;
        std::string source;
        enum TokenGroup group = TokenGroup::UNKNOWN;

        Token() {}
        Token(TokenType type, TokenGroup group, std::string source) {
            this->type = type;
            this->source = source;
        }
};