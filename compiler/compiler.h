#pragma once

#include "../filemanager/filemanager.h"
#include "../analyser/analyser.h"
#include <string>
#include <memory>

class Compiler {
    private:
        std::string entry_point;
        std::unique_ptr<Analyser> analyser;

    public:
        Compiler();
        void SetEntryPoint(std::string entry_point);
        int Compile();
};