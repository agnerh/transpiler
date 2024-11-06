#include "parser.h";
#include "analyser.h";
#include <iostream>
#include <sstream>
#include <fstream>

/*
You're going to have to write a lexical analyzer to split your input into the "words" of your language 
(often refered to as "tokens" or "lexemes"). This can be as simple as a while loop with some string comparisons or regular expressions.

Then a parser will take a list/stream of those tokens and create an Abstract Syntax Tree (often abbreviated to AST) 
according to a grammar, to represent the meaning of your program. A common approach is recursive descent.

Then a backend will translate this AST to the language you want to target. 
Either translate it to an AST for your target language to be consumed by an implementation of your target language, 
or directly generate code from your source AST and run it through its native tools.
*/

class Parser {

    std::string filePath;

    int Read() {
    }

public:
    Parser() {

    }

    Parser(std::string filePath) {
        this->filePath = filePath;
    }

    int Parse(std::string filePath) {
        this->filePath = filePath;
        
        int res = this->Read();
        return res;
    }
};