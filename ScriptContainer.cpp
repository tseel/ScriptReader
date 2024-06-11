#include "ScriptContainer.h"

void ScriptContainer::AddScript(const Script& script)
{
  scripts.insert(script);
  GenerateCharacterMap();
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

