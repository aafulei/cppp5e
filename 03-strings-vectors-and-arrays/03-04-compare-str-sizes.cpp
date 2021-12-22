// 21/12/22 = Wed
// 17/10/20 = Fri

// Exercise 3.4: Write a program to read two strings and report whether the
// strings are equal. If not, report which of the two is larger. Now, change the
// program to report whether the strings have the same length, and if not,
// report which is longer.

// Note: This program assumes valid input: two strings.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-04-compare-str-sizes.cpp && \
./a.out <../data/two-strings.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-04-compare-str-sizes.cpp && ^
a <..\data\two-strings.txt && ^
a <..\data\two-strings-different-sizes.txt

=== Input ===
(two-strings.txt)
clock watch

(two-strings-different-sizes.txt)
clock timepiece

=== Output ===
(two-strings.txt)
Two strings have the same length

(two-strings-different-sizes.txt)
Second string is longer
*/

#include <iostream>
#include <string>

int main() {
  std::string s1, s2;
  std::cin >> s1 >> s2;
  std::string::size_type z1 = s1.size(), z2 = s2.size();
  if (z1 == z2) {
    std::cout << "Two strings have the same length" << std::endl;
  } else {
    if (z1 > z2) {
      std::cout << "First string is longer" << std::endl;
    } else {
      std::cout << "Second string is longer" << std::endl;
    }
  }
  return 0;
}
