// 22/02/17 = Thu
// 18/01/17 = Wed

// Exercise 9.15: Write a program to determine whether two vector<int>s are
// equal.

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec1{1, 2, 3};
  std::vector<int> vec2{1, 2, 3};
  std::vector<int> vec3{4, 5, 6};
  std::cout << (vec1 == vec2) << std::endl;
  std::cout << (vec2 == vec3) << std::endl;
  return 0;
}
