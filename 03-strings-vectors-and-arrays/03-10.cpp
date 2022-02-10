// 21/12/22 = Wed
// 18/01/26 = Fri
// 17/10/20 = Fri

// Exercise 3.10: Write a program that reads a string of characters including
// punctuation and writes what was read but with the punctuation removed.

#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string line;
  while (std::getline(std::cin, line)) {
    for (unsigned char c : line) {
      if (!std::ispunct(c)) {
        std::cout << c;
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
