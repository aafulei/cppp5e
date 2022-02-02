// 22/02/02 = Wed
// 18/02/06 = Tue

// Exercise 6.3: Write and test your own version of fact.

#include <iostream>

int fact(int val) {
  if (val == 0) {
    return 1;
  }
  int res = 1;
  for (int i = 1; i <= val; ++i) {
    res *= i;
  }
  return res;
}

void test() {
  for (int i = 0; i <= 10; ++i) {
    std::cout << "fact(" << i << ") = " << fact(i) << std::endl;
  }
}

int main() {
  test();
  return 0;
}
