#include "Script.h"
#include "ScriptContainer.h"
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
  fs::path scriptDir = ("C:/Users/Travis/Documents/BOTC");
  if (!scriptDir.empty())
  {
    ScriptContainer container;
    for (const fs::path& f : fs::directory_iterator(scriptDir))
    {
      if (f.extension() == ".json")
      {
        container.AddScript({f});
      }
    }
    auto sivScripts = container.GetScriptsByAuthor("Siv");
    if (sivScripts)
    {
      std::println("Scripts by Siv:");
      for (auto script : *sivScripts)
      {
        std::println("{}", script->GetName());
      }
    }
  }
}