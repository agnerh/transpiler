#include <filemanager.h>
#include <fileinfo.h>
#include <vector>
#include <string>
#include <unordered_set>
#include <iterator>
#include <iostream>
#include <sstream>
#include <fstream>

class FileManager {
    private:

        std::unordered_set<FileInfo> files;
        std::unordered_set<FileInfo>::iterator current_file = files.begin();
        std::ifstream input_stream;

        void SetNextFile() {
            if (input_stream.is_open()) {
                input_stream.close();
            }
            
            while (this->current_file->status == READ && current_file != files.end()) {
                this->current_file++;
            }
        }

    public:
        int AddFile(std::string file) {
            if (files.find(file) == files.end()) {
                return 1;
            }

            files.insert(file);
            return 0;
        }

        bool Empty() {
            SetNextFile();
            return this->current_file->status == UNREAD;
        }

        FileInfo GetNextFile() {
            SetNextFile();

            // TODO: Open file and then return it
            return *current_file;
        }

        std::vector<std::string> GetChunk(FileInfo info) {
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
};