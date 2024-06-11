#ifndef SCRIPTFILEH
#define SCRIPTFILEH

#include <vector>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
namespace rng = std::ranges;
class ScriptFile
{
    public:
      ScriptFile(const fs::path filename);
      void Print();
    private:
      std::string name;
      std::string author;
      std::string image;
      std::vector<std::string> characters;
};

#endif