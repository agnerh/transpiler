#pragma once

#include <iostream>

class Parser {
    private:
        std::string filePath;
        int Read();
        
    public:
        Parser();
        Parser(std::string filePath);
        int Parse(std::string filePath);
};