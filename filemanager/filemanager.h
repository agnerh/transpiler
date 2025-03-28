#pragma once

#include "fileinfo.h"
#include <string>
#include <unordered_set>
#include <fstream>
#include <memory>
#include <vector>
#include <optional>
#include <algorithm>

class FileManager {
    private:
        std::unordered_set<FileInfo> files;
        std::ifstream input_stream;

        std::optional<FileInfo> GetNextFile();

    public:
        int AddFile(std::string file);
        std::string GetChunk();
};