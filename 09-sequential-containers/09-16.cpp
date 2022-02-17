// 18/01/17 = Wed

// Exercise 9.16: Repeat the previous program, but compare elements in a
// list<int> to a vector<int>.

#include <iostream>
#include <list>
#include <vector>

bool equal(const std::vector<int> &vec, const std::list<int> &lst) {
  return vec == std::vector<int>(lst.begin(), lst.end());
}

int main() {
  std::vector<int> vec{1, 2, 3};
  std::list<int> lst1{1, 2, 3};
  std::list<int> lst2{4, 5, 6};
  std::cout << equal(vec, lst1) << std::endl; // 1
  std::cout << equal(vec, lst2) << std::endl; // 0
  return 0;
}
