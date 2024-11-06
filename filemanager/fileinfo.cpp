#include <fileinfo.h>
#include <filestatus.h>
#include <string>

class FileInfo {
    public:
        std::string path;
        FileStatus status;

        FileInfo(std::string path) {
            this->path = path;
        }

        FileInfo(std::string path, FileStatus status) {
            this->path = path;
            this->status = status;
        }
};