// 21/12/22 = Wed
// 17/10/20 = Fri

// Exercise 3.2: Write a program to read the standard input a line at a time.
// Modify your program to read a word at a time.

#include <iostream>
#include <string>

int main() {
  std::string line;
  while (std::getline(std::cin, line)) {
    std::cout << line << std::endl;
  }
  return 0;
}
