#include <fileinfo.h>
#include <string>
#include <vector>

class FileManager {
    public:
        bool Empty();
        int AddFile(std::string file);
        FileInfo GetNextFile();
        std::vector<std::string> GetChunk(FileInfo info);
};