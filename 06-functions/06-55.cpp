// 22/02/03 = Thu
// 18/02/08 = Thu

// Exercise 6.55: Write four functions that add, subtract, multiply, and divide
// two int values. Store pointers to these functions in your vector from the
// previous exercise.

#include <iostream>
#include <vector>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

using PF = int (*)(int, int);

// 66 18 1008 1
void test() {
  std::vector<PF> calc{add, subtract, multiply, divide};
  // C++20
  for (decltype(calc.size()) i = 0; PF pf : calc) {
    std::cout << pf(42, 24) << (i++ == calc.size() - 1 ? '\n' : ' ');
  }
}

int main() {
  test();
  return 0;
}
