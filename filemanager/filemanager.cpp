#include "filemanager.h"
#include "fileinfo.h"
#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <unordered_set>
#include <memory>

bool FileManager::Empty() {
    SetNextFile();
    return this->current_file->status == UNREAD;
}

void FileManager::SetNextFile() {
    if (this->input_stream.is_open()) {
        input_stream.close();
    }

    while (this->current_file->status == READ && current_file != files.end()) {
        current_file++;
    }
}

int FileManager::AddFile(std::string path) {
    FileInfo fi(path);

    if (files.find(fi) == files.end()) {
        return 1;
    }

    files.insert(fi);
    return 0;
}

FileInfo FileManager::GetNextFile() {
    SetNextFile();

    // TODO: Open file and then return it
    return *current_file;
}

std::vector<std::string> FileManager::GetChunk(FileInfo info) {
    // TODO: Keep track of filestreams in this class instead of trusting 
    // FileInfo parameters to be correct

    std::vector<std::string> lines;

    if (info.path.empty()) {
        return lines;
    }

    if (!input_stream.is_open()) {
        input_stream.open(info.path);
    }

    std::string current_line;
    while(std::getline(input_stream, current_line)) {
        lines.push_back(current_line);
    }

    return lines;
}