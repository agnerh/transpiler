#include <filestatus.h>
#include <string>

class FileInfo {
    public:
        std::string path;
        FileStatus status;

        FileInfo(std::string path);
        FileInfo(std::string path, FileStatus status);
};