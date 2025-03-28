#include "compiler/compiler.h"
#include <string>
#include <filesystem>
#include <iostream>
#include <memory>

int main() {
    //TODO: Add CLI arguments
    std::filesystem::path currentPath = std::filesystem::current_path();
    std::filesystem::path testfile = currentPath / "testfiles" / "str_variable.ts";
    // std::string entry_point = "testfiles/test.ts";
    std::string entry_point = testfile.string();
    
    auto cmp = std::make_unique<Compiler>();
    cmp->SetEntryPoint(entry_point);
    cmp->Compile();
}