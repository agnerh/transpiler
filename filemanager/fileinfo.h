#pragma once

#include "filestatus.h"
#include <string>

class FileInfo {
    public:
        std::string path;
        FileStatus status;

        FileInfo(std::string path);
        FileInfo(std::string path, FileStatus status);

        bool operator==(const FileInfo& other) const;
};

namespace std {
    template <>
    struct hash<FileInfo> {
        std::size_t operator()(const FileInfo& fi) const {
            return std::hash<std::string>()(fi.path);
        }
    };
}