#include <filesystem>
#include <iostream>
#include <string>

int main() {
  for (const auto &entry : std::filesystem::directory_iterator(".")) {
    auto oldpath = entry.path();
    auto oldname = oldpath.filename().string();
    if (oldname[0] == '0' && oldname.ends_with(".cpp")) {
      std::cout << oldpath << std::endl;
      auto newname = oldname.substr(0, 5) + ".cpp";
      if (std::filesystem::is_regular_file(newname)) {
        std::cout << "[WARN] " << oldpath << std::endl;
        continue;
      }
      std::filesystem::rename(oldpath, newname);
    }
    else if (oldname[0] == '0' && oldname.ends_with(".hpp")) {
      std::cout << oldpath << std::endl;
      auto newname = oldname.substr(0, 5) + ".hpp";
      if (std::filesystem::is_regular_file(newname)) {
        std::cout << "[WARN] " << oldpath << std::endl;
        continue;
      }
      std::filesystem::rename(oldpath, newname);
    }
  }
  return 0;
}
