// 22/01/30 = Sun
// 18/01/15 = Mon

// Exercise 8.4: Write a function to open a file for input and read its contents
// into a vector of strings, storing each line as a separate element in the
// vector.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> readFile(const std::string &filename) {
  std::vector<std::string> res;
  std::ifstream ifs(filename);
  for (std::string line; std::getline(ifs, line); /* empty */) {
    res.push_back(line);
  }
  return res;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " file" << std::endl;
    return 1;
  }
  std::vector<std::string> res = readFile(argv[1]);
  for (const std::string &elem : res) {
    std::cout << elem << '\n';
  }
  return 0;
}
