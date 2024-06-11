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

      inline const std::string& GetName() const
      {
        return name;
      }

      inline const std::string& GetAuthor() const
      {
        return author;
      }

      inline const std::vector<std::string>& GetCharacters() const
      {
        return characters;
      }

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
      std::string name;
      std::string author;
      std::string image;
      bool oldFormat;
      std::vector<std::string> characters;
};

#endif