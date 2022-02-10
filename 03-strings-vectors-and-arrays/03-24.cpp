// 22/02/10 = Thu
// 21/12/23 = Thu
// 18/01/27 = Sat
// 17/10/22 = Sun

// Exercise 3.24: Redo the last exercise from § 3.3.3 (p. 105) using iterators.

// Exercise 3.20: Read a set of integers into a vector. Print the sum of each
// pair of adjacent elements. Change your program so that it prints the sum of
// the first and last elements, followed by the sum of the second and
// second-to-last, and so on.

// Modified from 03-20.cpp

#include <iostream>
#include <vector>

// Note: Given {1, 2, 3, 4, 5}, should return {3, 5, 7, 9}, not {3, 7, 5}
void sum_adjacent_elements(const std::vector<int> &vec) {
  if (vec.empty()) {
    return;
  }
  for (std::vector<int>::const_iterator it = vec.cbegin() + 1; it != vec.cend();
       ++it) {
    std::cout << *(it - 1) + *it << " ";
  }
  std::cout << std::endl;
}

// Note: Given {1, 2, 3, 4, 5}, should return {6, 6, 3}, not {6, 6, 6}
void sum_symmetric_elements(const std::vector<int> &vec) {
  if (vec.empty()) {
    return;
  }
  std::vector<int>::const_iterator b = vec.cbegin(), e = vec.cend() - 1;
  for (/* empty */; b < e; ++b, --e) {
    std::cout << *b + *e << " ";
  }
  if (b == e) {
    std::cout << *b;
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> vec;
  for (int a = 0; std::cin >> a; /* empty */) {
    vec.push_back(a);
  }
  sum_adjacent_elements(vec);
  sum_symmetric_elements(vec);
  return 0;
}
