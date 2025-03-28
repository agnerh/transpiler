#include "filemanager.h"


int FileManager::AddFile(std::string path) {
    FileInfo fi(path);

    if (files.find(fi) != files.end()) {
        return 1;
    }

    files.insert(fi);
    return 0;
}

std::optional<FileInfo> FileManager::GetNextFile() {
    auto it = std::find_if(this->files.begin(), this->files.end(), 
            [](const FileInfo& file) {
                return file.status == FileStatus::UNREAD;
            });

    if (it == this->files.end()) {
        return std::nullopt;
    }

    return *it;
}

std::string FileManager::GetChunk() {
    std::string lines;
    auto info = GetNextFile();

    if (!info.has_value() || info.value().path.empty()) {
        return lines;
    }

    if (!input_stream.is_open()) {
        input_stream.open(info.value().path);
    }

    std::string current_line;
    while(std::getline(input_stream, current_line)) {
        lines.append(current_line);
    }

    return lines;
}