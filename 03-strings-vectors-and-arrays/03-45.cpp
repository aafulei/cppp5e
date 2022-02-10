// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.45: Rewrite the programs again, this time using auto.

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
#include <iterator>

int main() {
  int ia[3][4]{{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
  // 1. range for
  for (const auto &row : ia) {
    for (auto elem : row) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }
  // 2. traditional for loop and subscripts
  for (auto i = 0; i != 3; ++i) {
    for (auto j = 0; j != 4; ++j) {
      std::cout << ia[i][j] << " ";
    }
    std::cout << std::endl;
  }
  // 3. traditional for loop and pointers
  for (auto p = std::cbegin(ia); p != std::cend(ia); ++p) {   // C++14
    for (auto q = std::cbegin(*p); q != std::cend(*p); ++q) { // C++14
      std::cout << *q << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
