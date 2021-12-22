// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.39: Write a program to compare two strings. Now write a program to
// compare the values of two C-style character strings.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-39-compare-std-strings.cpp && \
./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-39-compare-std-strings.cpp && a

=== Output ===
s1 < s2
*/

#include <iostream>
#include <string>

int main() {
  std::string s1 = "Hello";
  std::string s2 = "World";
  if (s1 == s2) {
    std::cout << "s1 == s2" << std::endl;
  } else {
    if (s1 < s2) {
      std::cout << "s1 < s2" << std::endl;
    } else {
      std::cout << "s1 > s2" << std::endl;
    }
  }
  return 0;
}
