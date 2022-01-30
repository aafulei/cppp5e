// 22/01/30 = Sun
// 18/01/30 = Tue
// 18/01/16 = Tue

// Exercise 8.10: Write a program to store each line from a file in a
// vector<string>. Now use an istringstream to read each element from the vector
// a word at a time.

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " file" << std::endl;
    return 1;
  }
  std::vector<std::string> res;
  std::ifstream ifs(argv[1]);
  for (std::string line; std::getline(ifs, line); /* empty */) {
    res.push_back(line);
  }
  for (std::string word; const std::string &line : res) { // C++20
    std::istringstream iss(line);
    while (iss >> word) {
      std::cout << word << ' ';
    }
    std::cout << std::endl;
  }
  return 0;
}
