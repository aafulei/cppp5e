// 22/02/10 = Thu
// 21/12/22 = Wed
// 17/10/20 = Fri

// Exercise 3.2: Write a program to read the standard input a line at a time.
// Modify your program to read a word at a time.

// Compile with macro READWORD defined to read a word at a time.

#include <iostream>
#include <string>

void readWord() {
  std::string word;
  while (std::cin >> word) {
    std::cout << word << std::endl;
  }
}

void readLine() {
  std::string line;
  while (std::getline(std::cin, line)) {
    std::cout << line << std::endl;
  }
}

int main() {
#ifndef READWORD
  readLine();
#else
  readWord();
#endif
  return 0;
}
