// 21/12/22 = Wed
// 17/10/20 = Fri

// Exercise 3.11: Is the following range for legal? If so, what is the type of
// c?

// const string s = "Keep out!";
// for (auto &c : s) { /* ...  */ }

// Answer: Yes, the range for is legal. The type of c is const char &.

#include <iostream>
#include <string>

int main() {
  const std::string s = "Keep out!";
  for (auto &c : s) {
    std::cout << c;
  }
  std::cout << std::endl;
  return 0;
}
