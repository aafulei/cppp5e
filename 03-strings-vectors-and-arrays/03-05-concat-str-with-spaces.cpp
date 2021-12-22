// 21/12/22 = Wed
// 18/01/26 = Fri
// 17/10/20 = Fri

// Exercise 3.5: Write a program to read strings from the standard input,
// concatenating what is read into one large string. Print the concatenated
// string. Next, change the program to separate adjacent input strings by a
// space.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-05-concat-str-with-spaces.cpp && \
./a.out <../data/several-strings.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-05-concat-str-with-spaces.cpp && ^
a <..\data\several-strings.txt

=== Input ===
(several-strings.txt)
clock watch
timepiece timekeeper
chronograph chronometer
stopwatch sandglass

=== Output ===
(several-strings.txt)
clock watch timepiece timekeeper chronograph chronometer stopwatch sandglass
*/

#include <iostream>
#include <string>

int main() {
  std::string s, sum;
  while (std::cin >> s) {
    if (!sum.empty()) {
      sum += " ";
    }
    sum += s;
  }
  std::cout << sum << std::endl;
  return 0;
}
