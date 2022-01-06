// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.36: Write a program to compare two arrays for equality. Write a
// similar program to compare two vectors.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-36-compare-arrays.cpp && ./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-36-compare-arrays.cpp && a

=== Output ===
a1 and a2 are the same
a2 and a3 are different
a3 and a4 are different
*/

#include <cstddef>
#include <iostream>

template <typename T, std::size_t M, std::size_t N>
bool compare(const T (&a)[M], const T (&b)[N]) {
  if (M != N) {
    return false;
  }
  for (std::size_t i = 0; i != N; ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  int a1[]{1, 2, 3};
  int a2[]{1, 2, 3};
  int a3[]{4, 5, 6};
  int a4[]{4, 5, 6, 7};
  if (compare(a1, a2)) {
    std::cout << "a1 and a2 are the same" << std::endl;
  } else {
    std::cout << "a1 and a2 are different" << std::endl;
  }
  if (compare(a2, a3)) {
    std::cout << "a2 and a3 are the same" << std::endl;
  } else {
    std::cout << "a2 and a3 are different" << std::endl;
  }
  if (compare(a3, a4)) {
    std::cout << "a3 and a4 are the same" << std::endl;
  } else {
    std::cout << "a3 and a4 are different" << std::endl;
  }
  return 0;
}
