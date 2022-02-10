// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.35: Using pointers, write a program to set the elements in an
// array to zero.

#include <cstddef>
#include <iostream>

template <std::size_t N> void print_array(int (&a)[N]) {
  // C++20
  for (int i = 0; int elem : a) {
    std::cout << elem << (i++ == N - 1 ? "\n" : " ");
  }
}

void zero_array(int a[], std::size_t sz) {
  for (int *p = a; p != a + sz; ++p) {
    *p = 0;
  }
}

int main() {
  int a[10];
  print_array(a);
  zero_array(a, 10);
  print_array(a);
  return 0;
}
