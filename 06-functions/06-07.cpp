// 22/02/02 = Wed
// 18/02/06 = Tue

// Exercise 6.7: Write a function that returns 0 when it is first called and
// then generates numbers in sequence each time it is called again.

#include <iostream>

int generate() {
  static int num = 0;
  return num++;
}

int main() {
  for (int i = 0; i < 10; ++i) {
    std::cout << generate() << std::endl;
  }
  return 0;
}
