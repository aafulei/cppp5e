// 22/02/24 = Thu
// 18/02/19 = Mon

// Exercise 9.33: In the final example in this section what would happen if we
// did not assign the result of insert to begin? Write a program that omits this
// assignment to see if your expectation was correct.

// Note: This program has problems.

#include <iostream>
#include <vector>

void print(const std::vector<int> &vec) {
  for (int i = 0; int elem : vec) {
    std::cout << (i++ == 0 ? "" : " ") << elem;
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> v{0, 1, 2, 3, 4, 5};
  print(v);
  auto begin = v.begin();
  while (begin != v.end()) {
    ++begin;
    v.insert(begin, 42); // error - should assign result to begin
    ++begin;
  }
  print(v);
  return 0;
}
