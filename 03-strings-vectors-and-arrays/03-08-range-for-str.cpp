// 21/12/22 = Wed
// 17/10/20 = Fri

// Exercise 3.8: Rewrite the program in the first exercise, first using a while
// and again using a traditional for loop. Which of the three approaches do you
// prefer and why?

// Exercise 3.6: Use a range for to change all the characters in a string to X.

// Answer: I prefer the range-for approach because it avoids out-of-range
// subscripting.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-08-range-for-str.cpp && ./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-08-range-for-str.cpp && a

=== Output ===
Hello, World!
XXXXXXXXXXXXX
Hello, World!
XXXXXXXXXXXXX
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
  std::string str = "Hello, World!";
  std::cout << str << std::endl;
  decltype(str.size()) index = 0;
  while (index != str.size()) {
    str[index] = 'X';
    index += 1;
  }
  std::cout << str << std::endl;
  str = "Hello, World!";
  std::cout << str << std::endl;
  for (decltype(str.size()) i = 0; i != str.size(); ++i) {
    str[i] = 'X';
  }
  std::cout << str << std::endl;
  return 0;
}
