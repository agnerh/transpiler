#pragma once

#include "../filemanager/filemanager.h"
#include "../analyser/analyser.h"
#include <string>

class Compiler {
    private:
        std::string entry_point;
        FileManager* fm;
        Analyser* analyser;

    public:
        Compiler();
        ~Compiler();
        void SetEntryPoint(std::string entry_point);
        int Compile();
};