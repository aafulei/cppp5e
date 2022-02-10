// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.31: Write a program to define an array of ten ints. Give each
// element the same value as its position in the array.

#include <cstddef>
#include <iostream>

int main() {
  int a[10];
  for (std::size_t i = 0; i != 10; ++i) {
    a[i] = i;
  }
  for (int i : a) {
    std::cout << i << (i == 9 ? "\n" : " ");
  }
  return 0;
}
