#ifndef SCRIPTCONTAINERH
#define SCRIPTCONTAINERH

#include "Script.h"
#include <set>
#include <map>
#include <print>
#include <optional>
#include <filesystem>

class ScriptContainer
{
  public:
    ScriptContainer() = default;

    void AddScript(const Script& script);
    //void RemoveScript(const Script& script);

    /// @brief  Get all scripts with a certain character.
    /// @param character official or homebrew character, must be an exact match for the name of the character.
    /// @return A set of scripts (pointers) that include that character, or nullopt.
    std::optional<std::set<const Script*>> GetScriptsWithCharacter(const std::string& character);

    /// @brief Get all scripts written by a certain author.
    /// @param author exact name of the script author.
    /// @returnAa set of scripts (pointers) written by that author, or nullopt.
    std::optional<std::set<const Script*>> GetScriptsByAuthor(const std::string& author);
    
    /// @brief Get a script by its title
    /// @param scriptName 
    /// @return A script with that title, or nullopt. If multiple scripts share a title, the chosen one is arbitrary.
    std::optional<Script> GetScript(const std::string& scriptName);

    /// @brief Uniquely get a script by its file path
    /// @param filename
    /// @return The script that resides at that file, or nullopt for invalid
    std::optional<Script> GetScript(const fs::path& filename);

    std::set<std::string> GetCharacters();
    std::set<std::string> GetAuthors();

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