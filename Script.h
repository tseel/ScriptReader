#ifndef SCRIPTH
#define SCRIPTH

#include <vector>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
namespace rng = std::ranges;
class Script
{
    public:
      Script(const fs::path filename);
      void Print();

      inline const fs::path& GetFilename() const;
      inline const std::string& GetName() const;
      inline const std::string& GetAuthor() const;
      inline const std::vector<std::string>& GetCharacters() const;

      bool operator<(const Script rhs) const
      {
        if (name < rhs.name) return true;
        if (author != "" && rhs.author != "" && author < rhs.author) return true;
        if (characters.size() < rhs.characters.size()) return true;

        for (std::size_t i = 0; i < characters.size(); ++i)
        {
          if (characters[i] < rhs.characters[i]) return true;
        }

        return false;
      }

    private:
      fs::path filename;
      std::string name;
      std::string author;
      std::string image;
      std::vector<std::string> characters;

      enum class ScriptType
      {
        NORMAL,
        OLD_FORMAT,
        HOMEBREW
      };

      ScriptType scriptType;
};

inline const fs::path& Script::GetFilename() const
{
  return filename;
}

inline const std::string& Script::GetName() const
{
  return name;
}

inline const std::string& Script::GetAuthor() const
{
  return author;
}

inline const std::vector<std::string>& Script::GetCharacters() const
{
  return characters;
}


#endif