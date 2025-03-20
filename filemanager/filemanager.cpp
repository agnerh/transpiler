#include "filemanager.h"


int FileManager::AddFile(std::string path) {
    FileInfo fi(path);

    if (files.find(fi) != files.end()) {
        return 1;
    }

    files.insert(fi);
    return 0;
}

FileInfo FileManager::GetNextFile() {
    // Find first unread file
}

std::string FileManager::GetChunk() {
    // TODO: Keep track of filestreams in this class instead of trusting 
    // FileInfo parameters to be correct

    std::string lines;
    auto info = GetNextFile();

    if (info.path.empty()) {
        return lines;
    }

    if (!input_stream.is_open()) {
        input_stream.open(info.path);
    }

    std::string current_line;
    while(std::getline(input_stream, current_line)) {
        lines.append(current_line);
    }

    return lines;
}