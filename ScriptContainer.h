#ifndef SCRIPTCONTAINERH
#define SCRIPTCONTAINERH

#include "Script.h"
#include <set>
#include <map>
#include <print>
#include <optional>

class ScriptContainer
{
  public:

    ScriptContainer() = default;

    void AddScript(const Script& script);
    //void RemoveScript(const Script& script);
    std::optional<std::set<const Script*>> GetScriptsWithCharacter(const std::string& character)
    {
      if (characterMap.contains(character))
      {
        return {characterMap[character]};
      }
      return std::nullopt;
    }

    std::optional<std::set<const Script*>> GetScriptsByAuthor(const std::string& author)
    {
      if (authorMap.contains(author))
      {
        return {authorMap[author]};
      }
      return std::nullopt;
    }


    ScriptContainer(const ScriptContainer&) = delete;
    ScriptContainer& operator==(const ScriptContainer&) = delete;
  
  private:

    void GenerateMaps();
    void GenerateCharacterMap();
    void GenerateAuthorMap();

    std::set<Script> scripts;
    std::map<std::string, std::set<const Script*>> characterMap;
    std::map<std::string, std::set<const Script*>> authorMap;

};

#endif