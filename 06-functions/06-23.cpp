// 22/02/02 = Wed
// 18/02/06 = Tue

// Exercise 6.23: Write your own versions of each of the print functions
// presented in this section. Call each of these functions to print i and j
// defined as follows:

// int i = 0, j[2] = {0, 1};

#include <cstddef>
#include <iostream>
#include <iterator>

void print(const int *p) { std::cout << *p << std::endl; }

void print(const int *b, const int *e) {
  while (b != e) {
    std::cout << *b++ << std::endl;
    ;
  }
}

void print(const int a[], std::size_t n) {
  for (std::size_t i = 0; i != n; ++i) {
    std::cout << a[i] << std::endl;
  }
}

void test() {
  int i = 0, j[2] = {0, 1};
  std::cout << "print(&i);" << std::endl;
  print(&i);
  std::cout << "print(&i, &i + 1);" << std::endl;
  print(&i, &i + 1);
  std::cout << "print(&i, 1);" << std::endl;
  print(&i, 1);
  std::cout << "print(j);" << std::endl;
  print(j);
  std::cout << "print(std::begin(j), std::end(j));" << std::endl;
  print(std::begin(j), std::end(j));
  std::cout << "print(j, 2);" << std::endl;
  print(j, 2);
}

int main() {
  test();
  return 0;
}
