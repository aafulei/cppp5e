// 21/12/22 = Wed
// 17/10/20 = Fri

// Exercise 3.2: Write a program to read the standard input a line at a time.
// Modify your program to read a word at a time.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-02-read-lines.cpp && \
./a.out <../data/fox.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-02-read-lines.cpp && ^
a <..\data\fox.txt

=== Input ===
(fox.txt)
quick fox jumps over the lazy brown dog

=== Output ===
(fox.txt)
quick fox jumps over the lazy brown dog
*/

#include <iostream>
#include <string>

int main() {
  std::string line;
  while (std::getline(std::cin, line)) {
    std::cout << line << std::endl;
  }
  return 0;
}
