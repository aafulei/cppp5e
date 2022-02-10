// 21/12/22 = Wed
// 18/01/27 = Sat
// 17/10/22 = Sun

// Exercise 3.14: Write a program to read a sequence of ints from cin and store
// those values in a vector.

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;
  for (int num; std::cin >> num; /* empty */) {
    vec.push_back(num);
  }
  for (int num : vec) {
    std::cout << num << std::endl;
  }
  return 0;
}
