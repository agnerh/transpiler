#include "compiler.h"
#include "../filemanager/filemanager.h"
#include "../analyser/analyser.h"
#include <string>
#include <iostream>

Compiler::Compiler() {
    fm = new FileManager();
    analyser = new Analyser();
}

Compiler::~Compiler() {
    delete fm;
    delete analyser;
}
    
void Compiler::SetEntryPoint(std::string entry_point) {
    this->entry_point = entry_point;
}

int Compiler::Compile() {
    fm->AddFile(entry_point);

    while(!fm->Empty()) {
        auto file_info = fm->GetNextFile();
        if (!file_info.has_value()) {
            break;
        }

        auto chunk = fm->GetChunk(file_info.value());

        analyser->AnalyseChunk(chunk);

        file_info->status = FileStatus::READ;
    }

    auto tokens = analyser->GetTokens();
    for (auto token : tokens) {
        std::cout << "TOKEN: \n\tTYPE: " 
            << static_cast<int>(token.type) << "\n\tSOURCE: " 
            << token.source << "\n" 
            << std::endl;
    }

    return 0;
}