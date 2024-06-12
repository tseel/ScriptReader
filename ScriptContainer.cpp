#include "ScriptContainer.h"
#include <iterator>

void ScriptContainer::AddScript(const Script& script)
{
  scripts.insert(script);
  GenerateMaps();
}

std::optional<std::set<const Script*>> ScriptContainer::GetScriptsWithCharacter(const std::string& character)
{
  if (characterMap.contains(character))
  {
    return {characterMap[character]};
  }
  return std::nullopt;
}

std::optional<std::set<const Script*>> ScriptContainer::GetScriptsByAuthor(const std::string& author)
{
  if (authorMap.contains(author))
  {
    return {authorMap[author]};
  }
  return std::nullopt;
}

std::optional<Script> ScriptContainer::GetScript(const std::string& scriptName)
{
  for (const Script& script : scripts)
  {
    if (script.GetName() == scriptName)
    {
      return script;
    }
  }
  return std::nullopt;
}

std::optional<Script> ScriptContainer::GetScript(const fs::path& filename)
{
  for (const Script& script : scripts)
  {
    if (script.GetFilename() == filename)
    {
      return script;
    }
  }
  return std::nullopt;
}

std::set<std::string> ScriptContainer::GetCharacters()
{
  std::set<std::string> characters;
  std::transform(characterMap.begin(), characterMap.end(), std::inserter(characters, characters.begin()),
                 [](const auto& pair){return pair.first;});
  return characters;
}

std::set<std::string> ScriptContainer::GetAuthors()
{
  std::set<std::string> authors;
  std::transform(authorMap.begin(), authorMap.end(), std::inserter(authors, authors.begin()),
                 [](const auto& pair){return pair.first;});
  return authors;
}

void ScriptContainer::GenerateMaps()
{
  GenerateCharacterMap();
  GenerateAuthorMap();
}

void ScriptContainer::GenerateCharacterMap()
{
  for (auto& script : scripts)
  {
    for (auto& character : script.GetCharacters())
    {
      characterMap[character].insert(&script);
    }
  }
}

void ScriptContainer::GenerateAuthorMap()
{
  for (auto& script : scripts)
  {
    authorMap[script.GetAuthor()].insert(&script);
  }
}
