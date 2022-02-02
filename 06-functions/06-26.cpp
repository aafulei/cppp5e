// 22/02/02 = Wed
// 18/02/07 = Wed

// Exercise 6.26: Write a program that accepts the options presented in this
// section. Print the values of the arguments passed to main.

#include <iostream>

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; ++i) {
    std::cout << argv[i] << (i == argc - 1 ? '\n' : ' ');
  }
  return 0;
}
