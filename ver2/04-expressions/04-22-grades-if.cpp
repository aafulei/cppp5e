// 21/12/25 = Sat
// 18/02/03 = Sat

// Exercise 4.22: Extend the program that assigned high pass, pass, and fail
// grades to also assign low pass for grades between 60 and 75 inclusive. Write
// two versions: One version that uses only conditional operators; the other
// should use one or more if statements. Which version do you think is easier to
// understand and why?

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 04-22-grades-if.cpp && \
./a.out <../data/scores2.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 04-22-grades-if.cpp && ^
a <..\data\scores2.txt

=== Input ===
42
65
95
100
39
67
95
76
88
76
83
92
76
93

=== Output ===
fail
low pass
high pass
high pass
fail
low pass
high pass
pass
pass
pass
pass
high pass
pass
high pass
*/

#include <iostream>

int main() {
  for (int grade; std::cin >> grade; /* empty */) {
    if (grade >= 90)
      std::cout << "high pass";
    else if (grade > 75)
      std::cout << "pass";
    else if (grade >= 60)
      std::cout << "low pass";
    else
      std::cout << "fail";
    std::cout << std::endl;
  }
  return 0;
}
