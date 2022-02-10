// 22/02/10 = Thu
// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.32: Copy the array you defined in the previous exercise into
// another array. Rewrite your program to use vectors.

// Exercise 3.31: Write a program to define an array of ten ints. Give each
// element the same value as its position in the array.

#include <cstddef>
#include <iostream>
#include <vector>

template <std::size_t N> void print_array(int (&a)[N]) {
  for (int i = 0; int elem : a) {
    std::cout << elem << (i++ == N - 1 ? "\n" : " ");
  }
}

void copy_array(int *src, int *dest, std::size_t sz) {
  for (std::size_t i = 0; i != sz; ++i) {
    dest[i] = src[i];
  }
}

void print_vector(const std::vector<int> &vec) {
  for (std::vector<int>::size_type i = 0; int elem : vec) {
    std::cout << elem << (i++ == vec.size() - 1 ? "\n" : " ");
  }
}

void copy_vector(const std::vector<int> &src, std::vector<int> &dest) {
  dest = src;
}

int main() {
  // array
  int a[10], b[10];
  for (std::size_t i = 0; i != 10; ++i) {
    a[i] = i;
  }
  print_array(a);
  copy_array(a, b, 10);
  print_array(b);
  // vector
  std::vector<int> u(10), v(10);
  for (int i = 0; i != 10; ++i) {
    u[i] = i;
  }
  print_vector(u);
  copy_vector(u, v);
  print_vector(v);
  return 0;
}
