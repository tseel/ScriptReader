#ifndef SCRIPTCONTAINERH
#define SCRIPTCONTAINERH

#include "Script.h"
#include <set>
#include <map>
#include <print>

class ScriptContainer
{
  public:

    ScriptContainer() = default;

    void AddScript(const Script& script);
    //void RemoveScript(const Script& script);
    void PrintScriptsWithCharacter(const std::string& character)
    {
      std::println("The following scripts contain {}.", character);
      for (const Script* script : characterMap[character])
      {
        std::println("{}", script->GetName());
      }
    }

    ScriptContainer(const ScriptContainer&) = delete;
    ScriptContainer& operator==(const ScriptContainer&) = delete;
  
  private:

    void GenerateCharacterMap();

    std::set<Script> scripts;
    std::map<std::string, std::set<const Script*>> characterMap;
};

#endif