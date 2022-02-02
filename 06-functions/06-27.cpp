// 22/02/02 = Wed
// 18/02/07 = Wed

// Exercise 6.27: Write a function that takes an initializer_list<int> and
// produces the sum of the elements in the list.

#include <initializer_list>
#include <iostream>

int sum(const std::initializer_list<int> &il) {
  int res = 0;
  for (int i : il)
    res += i;
  return res;
}

void test() {
  std::cout << sum({}) << std::endl;
  std::cout << sum({1}) << std::endl;
  std::cout << sum({1, 2}) << std::endl;
  std::cout << sum({1, 2, 3}) << std::endl;
  std::cout << sum({1, 2, 3, 4}) << std::endl;
  std::cout << sum({1, 2, 3, 4, 5}) << std::endl;
}

int main() {
  test();
  return 0;
}
