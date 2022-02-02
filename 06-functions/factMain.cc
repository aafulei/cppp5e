// 22/02/02 = Wed
// 18/02/06 = Tue

// Exercise 6.9: Write your own versions of the fact.cc and factMain.cc files.
// These files should include your Chapter6.h from the exercises in the previous
// section. Use these files to understand how your compiler supports separate
// compilation.

// factMain.cc

#include "Chapter6.h"
#include <iostream>

void test() {
  for (int i = 0; i <= 10; ++i) {
    std::cout << "fact(" << i << ") = " << fact(i) << std::endl;
  }
}

int main() {
  test();
  return 0;
}
