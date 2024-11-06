#include "compiler.h"
#include "../filemanager/filemanager.h";
#include "../analyser/analyser.h";
#include <string>
#include <iostream>

class Compiler {
    private:
        std::string entry_point;
        FileManager* fm;
        Analyser* analyser;

    public:
        Compiler() {
            fm = new FileManager();
            analyser = new Analyser();
        }

        ~Compiler() {
            delete fm;
            delete analyser;
        }
    
        void SetEntryPoint(std::string entry_point) {
            this->entry_point = entry_point;
        }

        int Compile() {
            fm->AddFile(entry_point);

            while(!fm->Empty()) {
                auto file_info = fm->GetNextFile();
                auto chunk = fm->GetChunk(file_info);

                analyser->AnalyseChunk(chunk);
            }

            auto tokens = analyser->GetTokens();
            for (auto token : tokens) {
                std::cout << "TOKEN: \n\tTYPE: " 
                    << token.type << "\n\tSOURCE: " 
                    << token.source << "\n" 
                    << std::endl;
            }

            return 0;
        }
};