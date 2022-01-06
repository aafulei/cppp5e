// 21/12/25 = Sat
// 18/02/04 = Sun

// Exercise 5.17: Given two vectors of ints, write a program to determine
// whether one vector is a prefix of the other. For vectors of unequal length,
// compare the number of elements of the smaller vector. For example, given the
// vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5, 8, respectively your
// program should return true.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 05-17-prefix.cpp && \
./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 05-17-prefix.cpp && ^
a

=== Output ===
Yes
*/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1 = {0, 1, 1, 2};
  std::vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};
  const auto N = (v1 < v2 ? v1.size() : v2.size());
  bool is_prefix = true;
  for (decltype(N + 0) i = 0; i != N; ++i) {
    if (v1[i] != v2[i]) {
      is_prefix = false;
      break;
    }
  }
  std::cout << (is_prefix ? "Yes" : "No") << std::endl;
  return 0;
}
