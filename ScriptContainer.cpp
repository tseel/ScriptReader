#include "ScriptContainer.h"

void ScriptContainer::AddScript(const Script& script)
{
  scripts.insert(script);
  GenerateMaps();
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
