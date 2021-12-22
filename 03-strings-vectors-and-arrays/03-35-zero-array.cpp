// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.35: Using pointers, write a program to set the elements in an
// array to zero.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-35-zero-array.cpp && ./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-35-zero-array.cpp && a

=== Output ===
0 0 0 0 0 0 0 0 0 0
*/

#include <cstddef>
#include <iostream>

int main() {
  int arr[10];
  for (int *p = arr; p != arr + 10; ++p) {
    *p = 0;
  }
  for (auto elem : arr)
    std::cout << elem << " ";
  std::cout << std::endl;
  return 0;
}
