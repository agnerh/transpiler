#include <string>

class Compiler {
    public:
        Compiler();
        ~Compiler();
        void SetEntryPoint(std::string entry_point);
        int Compile();
};