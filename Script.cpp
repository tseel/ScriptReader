#include "Script.h"
#include "nlohmann/json.hpp"
#include <algorithm>
#include <print>
#include <fstream>
#include <ranges>

Script::Script(const fs::path filename) : filename(filename)
{
  nlohmann::json js = nlohmann::json::parse(std::ifstream{filename});

  for (const auto& entry : js)
  {
    std::string charId;
    if (entry.is_object() && entry.contains("id") && entry["id"] == "_meta")
    {
      name = entry.value("name", "");
      author = entry.value("author", "");
    }
    else if (entry.is_object())
    {
      // use "name" key for homebrew, "id" key otherwise
      if (entry.contains("name"))
      {
        charId = entry["name"];
        scriptType = ScriptType::HOMEBREW;
      }
      else
      {
        charId = entry["id"];
        scriptType = ScriptType::OLD_FORMAT;
      }
    }
    else if (entry.is_string())
    {
      charId = entry;
      scriptType = ScriptType::NORMAL;
    }

    rng::replace(charId, '_', ' ');
    // TODO: convert charId to title case
    characters.push_back(charId);
  }

  if (name == "")
  {
    name = filename.stem().string();
  }
}

void Script::Print()
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
