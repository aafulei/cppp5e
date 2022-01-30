// 22/01/30 = Sun
// 18/01/16 = Tue

// Exercise 8.11: The program in this section defined its istringstream object
// inside the outer while loop. What changes would you need to make if record
// were defined outside that loop? Rewrite the program, moving the definition of
// record outside the while, and see whether you thought of all the changes that
// are needed.

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo {
  std::string name;
  std::vector<std::string> phones;
};

int main() {
  std::string line, word;
  std::vector<PersonInfo> people;
  std::istringstream record;
  while (std::getline(std::cin, line)) {
    PersonInfo info;
    record.str(line);
    record >> info.name;
    while (record >> word) {
      info.phones.push_back(word);
    }
    people.push_back(info);
    record.clear(); // important
  }
  for (const PersonInfo &info : people) {
    std::cout << info.name << ":";
    for (const std::string &ph : info.phones) {
      std::cout << " " << ph;
    }
    std::cout << std::endl;
  }
  return 0;
}
