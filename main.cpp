#include "ScriptFile.h"
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
  fs::path botc = ("C:/Users/Travis/Documents/BOTC");
  if (!botc.empty())
  {
    for (const fs::path& f : fs::directory_iterator(botc))
    {
      if (f.extension() == ".json")
      {
        ScriptFile script(f);
        //script.Print();
      }
    }
  }
}