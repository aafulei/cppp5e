// 22/02/03 = Thu
// 18/02/08 = Thu

// Exercise 6.54: Write a declaration for a function that takes two int
// parameters and returns an int, and declare a vector whose elements have this
// function pointer type.

#include <iostream>
#include <vector>

using F = int(int, int);
using PF = int (*)(int, int);

int foo1(int, int) { return 1; }
int foo2(int, int) { return 2; }

void test(const std::vector<PF> &vec) {
  for (PF pf : vec) {
    std::cout << pf(0, 0) << std::endl;
  }
}

int main() {
  std::vector<PF> vec{foo1, foo2};
  test(vec);
  return 0;
}
