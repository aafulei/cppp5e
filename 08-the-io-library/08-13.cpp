// 22/01/30 = Sun
// 18/01/16 = Tue

// Exercise 8.13: Rewrite the phone number program from this section to read
// from a named file rather than from cin.

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo {
  std::string name;
  std::vector<std::string> phones;
};

void read(std::istream &is, std::vector<PersonInfo> &people) {
  for (std::string line; std::getline(is, line); /* empty */) {
    PersonInfo info;
    std::istringstream record(line);
    record >> info.name;
    for (std::string word; record >> word; /* empty */) {
      info.phones.push_back(word);
    }
    people.push_back(info);
  }
}

void print(const std::vector<PersonInfo> &people) {
  for (const PersonInfo &info : people) {
    std::cout << info.name << ":";
    for (const std::string &ph : info.phones) {
      std::cout << " " << ph;
    }
    std::cout << std::endl;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " file" << std::endl;
    return 1;
  }
  std::vector<PersonInfo> people;
  std::ifstream ifs(argv[1]);
  read(ifs, people);
  print(people);
  return 0;
}
