// 22/02/10 = Thu
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

// Modified from 03-43.cpp

#include <cstddef>
#include <iostream>

int main() {
  int ia[3][4]{{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
  // type alias
  using Int4 = int[4];
  // 1. range for
  for (const Int4 &row : ia) {
    for (int i = 0; int elem : row) { // C++20
      std::cout << elem << (i++ == 3 ? "\n" : " ");
    }
  }
  // 2. traditional for loop and subscripts
  for (std::size_t i = 0; i != 3; ++i) {
    for (std::size_t j = 0; j != 4; ++j) {
      std::cout << ia[i][j] << (j == 3 ? "\n" : " ");
    }
  }
  // 3. traditional for loop and pointers
  for (const Int4 *p = ia; p != ia + 3; ++p) {
    for (const int *q = *p; q != *p + 4; ++q) {
      std::cout << *q << (q == *p + 3 ? "\n" : " ");
    }
  }
  return 0;
}
