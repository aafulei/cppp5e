// 21/12/22 = Wed
// 17/10/20 = Fri

// Exercise 3.6: Use a range for to change all the characters in a string to X.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-06-range-for-str.cpp && ./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-06-range-for-str.cpp && a

=== Output ===
Hello, World!
XXXXXXXXXXXXX
*/

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
