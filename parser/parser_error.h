#pragma once

#include <string>

class ParserError {
    private:
        std::string message;
    
    public:
        ParserError();
        ParserError(std::string message) {
            this->message = message;
        }
};