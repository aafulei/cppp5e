// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.31: Write a program to define an array of ten ints. Give each
// element the same value as its position in the array.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-31-array-of-10.cpp && ./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-31-array-of-10.cpp && a

=== Output ===
0 1 2 3 4 5 6 7 8 9
*/
#include <cstddef>
#include <iostream>

int main() {
  int a[10];
  for (std::size_t i = 0; i != 10; ++i)
    a[i] = i;
  for (auto i : a)
    std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}
