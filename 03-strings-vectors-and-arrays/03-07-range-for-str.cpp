// 21/12/22 = Wed
// 17/10/20 = Fri

// Exercise 3.7: What would happen if you define the loop control variable in
// the previous exercise as type char? Predict the results and then change your
// program to use a char to see if you were right.

// Exercise 3.6: Use a range for to change all the characters in a string to X.

// Answer: The string would not be changed.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-07-range-for-str.cpp && ./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-07-range-for-str.cpp && a

== Compiler Warning ===
warning: variable 'c' set but not used

=== Output ===
Hello, World!
Hello, World!
*/

// Modified from 03-06-range-for-str.cpp

#include <iostream>
#include <string>

int main() {
  std::string str = "Hello, World!";
  std::cout << str << std::endl;
  for (char c : str) { // Use char instead of char &
    c = 'X';
  }
  std::cout << str << std::endl;
  return 0;
}
