// 21/12/22 = Wed
// 18/01/27 = Sat
// 17/10/22 = Sun

// Exercise 3.14: Write a program to read a sequence of ints from cin and store
// those values in a vector.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-14-vector-int.cpp && \
./a.out <../data/several-numbers.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-14-vector-int.cpp && ^
a <..\data\several-numbers.txt

=== Input ===
(several-numbers.txt)
12 34 56 78

=== Output ===
(several-numbers.txt)
12
34
56
78
*/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;
  for (int i = 0; std::cin >> i; /* empty */) {
    vec.push_back(i);
  }
  for (int i : vec) {
    std::cout << i << std::endl;
  }
  return 0;
}
