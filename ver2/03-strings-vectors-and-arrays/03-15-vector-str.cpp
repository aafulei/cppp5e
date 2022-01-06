// 21/12/22 = Wed
// 18/01/27 = Sat
// 17/10/22 = Sun

// Exercise 3.15: Repeat the previous program but read strings this time.

// Exercise 3.14: Write a program to read a sequence of ints from cin and store
// those values in a vector.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-15-vector-str.cpp && \
./a.out <../data/several-strings.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-15-vector-str.cpp && ^
a <..\data\several-strings.txt

=== Input ===
(several-strings.txt)
clock watch
timepiece timekeeper
chronograph chronometer
stopwatch sandglass

=== Output ===
(several-strings.txt)
clock
watch
timepiece
timekeeper
chronograph
chronometer
stopwatch
sandglass
*/

// Modified from 03-14-vector-int.cpp

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> vec;
  for (std::string s; std::cin >> s; /* empty */) {
    vec.push_back(s);
  }
  for (const std::string &s : vec) {
    std::cout << s << std::endl;
  }
  return 0;
}
