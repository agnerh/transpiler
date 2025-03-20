#include "fileinfo.h"
#include "filestatus.h"
#include <string>

FileInfo::FileInfo(std::string path) {
    this->path = path;
    this->status = FileStatus::UNREAD;
}

FileInfo::FileInfo(std::string path, FileStatus status) {
    this->path = path;
    this->status = status;
}

bool FileInfo::operator==(const FileInfo& other) const {
    return this->path == other.path;
}