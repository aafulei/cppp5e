// 21/12/22 = Wed
// 17/10/20 = Fri

// Exercise 3.4: Write a program to read two strings and report whether the
// strings are equal. If not, report which of the two is larger. Now, change the
// program to report whether the strings have the same length, and if not,
// report which is longer.

// Note: This program assumes valid input: two strings.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-04-compare-str.cpp && \
./a.out <../data/two-strings.txt && \
./a.out <../data/two-strings-reversed.txt && \
./a.out <../data/two-strings-same.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-04-compare-str.cpp && ^
a <..\data\two-strings.txt && ^
a <..\data\two-strings-reversed.txt && ^
a <..\data\two-strings-same.txt

=== Input ===
(two-strings.txt)
clock watch

(two-strings-reversed.txt)
watch clock

(two-strings-same.txt)
clock clock

=== Output ===
(two-strings.txt)
Second string is larger

(two-strings-reversed.txt)
First string is larger

(two-strings-same.txt)
Two strings are equal
*/

#include <iostream>
#include <string>

int main() {
  std::string s1, s2;
  std::cin >> s1 >> s2;
  if (s1 == s2) {
    std::cout << "Two strings are equal" << std::endl;
  } else {
    if (s1 > s2) {
      std::cout << "First string is larger" << std::endl;
    } else {
      std::cout << "Second string is larger" << std::endl;
    }
  }
  return 0;
}
