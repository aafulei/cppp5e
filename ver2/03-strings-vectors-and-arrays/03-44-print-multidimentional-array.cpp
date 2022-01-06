// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.44: Rewrite the programs from the previous exercises using a type
// alias for the type of the loop control variables.

// Exercise 3.43: Write three different versions of a program to print the
// elements of ia. One version should use a range for to manage the iteration,
// the other two should use an ordinary for loop in one case using subscripts
// and in the other using pointers. In all three programs write all the types
// directly. That is, do not use a type alias, auto, or decltype to simplify the
// code.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra \
03-44-print-multidimentional-array.cpp && ./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra ^
03-44-print-multidimentional-array.cpp && a

=== Output ===
0 1 2 3
4 5 6 7
8 9 10 11
0 1 2 3
4 5 6 7
8 9 10 11
0 1 2 3
4 5 6 7
8 9 10 11
*/

// Modified from 03-43-print-multidimentional-array.cpp

#include <iostream>
#include <iterator>

int main() {
  int ia[3][4]{{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
  // type aliases
  using R = const int(&)[4];
  using S = std::size_t;
  using P = const int(*)[4];
  using Q = const int *;
  // 1. range for
  for (R row : ia) {
    for (int elem : row) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }
  // 2. traditional for and subscripts
  for (S i = 0; i != 3; ++i) {
    for (S j = 0; j != 4; ++j) {
      std::cout << ia[i][j] << " ";
    }
    std::cout << std::endl;
  }
  // 3. traditional for and pointers
  for (P p = ia; p != ia + 3; ++p) {
    for (Q q = *p; q != *p + 4; ++q) {
      std::cout << *q << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
