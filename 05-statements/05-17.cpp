// 22/01/29 = Sat
// 21/12/25 = Sat
// 18/02/04 = Sun

// Exercise 5.17: Given two vectors of ints, write a program to determine
// whether one vector is a prefix of the other. For vectors of unequal length,
// compare the number of elements of the smaller vector. For example, given the
// vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5, 8, respectively your
// program should return true.

#include <algorithm>
#include <iostream>
#include <vector>

bool is_prefix(const std::vector<int> &v1, const std::vector<int> &v2) {
  for (decltype(v1.size()) i = 0; i != std::min(v1.size(), v2.size()); ++i) {
    if (v1[i] != v2[i]) {
      return false;
    }
  }
  return true;
}

void test() {
  std::cout << is_prefix({0, 1, 1, 2}, {0, 1, 1, 2, 3, 5, 8}) << std::endl; // 1
  std::cout << is_prefix({0, 1, 1, 2, 3, 5, 8}, {0, 1, 1, 2}) << std::endl; // 1
  std::cout << is_prefix({0, 1, 1, 2}, {0, 1, 2, 2}) << std::endl;          // 0
}

int main() {
  test();
  return 0;
}
