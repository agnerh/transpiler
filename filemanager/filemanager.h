#pragma once

#include "fileinfo.h"
#include <string>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <memory>

class FileManager {
    private:
        std::unordered_set<FileInfo> files;
        std::unordered_set<FileInfo>::iterator current_file = files.begin();
        std::ifstream input_stream;

        void SetNextFile();

    public:
        bool Empty();
        int AddFile(std::string file);
        FileInfo GetNextFile();
        std::vector<std::string> GetChunk(FileInfo info);
};