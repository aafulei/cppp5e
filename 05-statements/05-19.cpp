// 22/01/29 = Sat
// 21/12/25 = Sat
// 18/02/04 = Sun

// Exercise 5.19: Write a program that uses a do while loop to repetitively
// request two strings from the user and report which string is less than the
// other.

#include <iostream>
#include <string>

int main() {
  std::string s1, s2;
  do {
    std::cout << "Enter two strings: ";
    if (std::cin >> s1 >> s2) {
      if (s1 < s2) {
        std::cout << -1 << std::endl;
      } else if (s1 == s2) {
        std::cout << 0 << std::endl;
      } else {
        std::cout << 1 << std::endl;
      }
    }
  } while (std::cin);
  return 0;
}
