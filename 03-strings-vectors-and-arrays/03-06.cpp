// 21/12/22 = Wed
// 17/10/20 = Fri

// Exercise 3.6: Use a range for to change all the characters in a string to X.

#include <iostream>
#include <string>

int main() {
  std::string str = "Hello, World!";
  std::cout << str << std::endl;
  for (char &c : str) {
    c = 'X';
  }
  std::cout << str << std::endl;
  return 0;
}
