// 22/02/04 = Fri
// 18/02/03 = Sat

// Exercise 4.29: Predict the output of the following code and explain your
// reasoning. Now run the program. Is the output what you expected? If not,
// figure out why.

// int x[10]; int *p = x;
// cout << sizeof(x)/sizeof(*x) << endl;
// cout << sizeof(p)/sizeof(*p) << endl;

#include <iostream>

int main() {
  int x[10];
  int *p = x;
  std::cout << sizeof(x) / sizeof(*x) << std::endl; // 10
  std::cout << sizeof(p) / sizeof(*p) << std::endl; // 2
  return 0;
}
