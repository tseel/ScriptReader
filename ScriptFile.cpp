#include "ScriptFile.h"
#include "nlohmann/json.hpp"
#include <algorithm>
#include <print>
#include <fstream>
#include <ranges>

ScriptFile::ScriptFile(const fs::path filename)
{
  nlohmann::json js = nlohmann::json::parse(std::ifstream{filename});
  auto iter = js.cbegin();
  if (js[0].is_object() && js[0]["id"] == "_meta")
  {
    nlohmann::json& meta = js[0];
    name = meta["name"];
    author = meta["author"];
    image = meta.value("image", "");
    ++iter;
  }

  if (name == "")
  {
    name = filename.stem().string();
  }

  bool oldScriptWarning = false;
  for (; iter != js.cend(); ++iter)
  {
    std::string charId;
    if (iter->is_object()) // old style / homebrew, character name is ID
    {
      // use "name" key for homebrew, "id" key otherwise
      if (iter->contains("name"))
      {
        charId = (*iter)["name"];
      }
      else
      {
        charId = (*iter)["id"];
        if (!oldScriptWarning)
        {
          std::println("{}: Old script format! Recommend using the script tool to update this script to the current format, otherwise some character names might show weirdly!", filename.stem().string());
        }
        oldScriptWarning = true;
      }
    }
    else if (iter->is_string())
    {
      charId = *iter;
    }

    rng::replace(charId, '_', ' ');
    // TODO: convert charId to title case
    characters.push_back(charId);
  }
}

void ScriptFile::Print()
{
  if (author != "")
  {
    std::println("{} by {}", name, author);
  }
  else
  {
    std::println("{}", name);
  }
  rng::for_each(characters, [](const auto& str){std::println("{}", str);});
  std::println("");
}
