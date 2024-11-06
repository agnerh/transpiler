#include <iostream>

class Parser {
    public:
        Parser();
        Parser(std::string filePath);
        int Parse(std::string filePath);
};