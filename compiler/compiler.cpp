#include "compiler.h"

Compiler::Compiler() {
    this->analyser = std::make_unique<Analyser>();
    this->parser = std::make_unique<Parser>();
}
    
void Compiler::SetEntryPoint(std::string entry_point) {
    this->entry_point = entry_point;
}

int Compiler::Compile() {
    this->analyser->Analyse(this->entry_point);

    auto tokens = analyser->GetTokens();
    // for (auto token : tokens) {
    //     std::cout << "TOKEN: \n\tTYPE: " 
    //         << static_cast<int>(token.type) << "\n\tSOURCE: " 
    //         << token.value << "\n" 
    //         << std::endl;
    // }

    this->parser->Parse(tokens);

    return 0;
}