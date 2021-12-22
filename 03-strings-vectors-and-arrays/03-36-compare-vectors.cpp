// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.36: Write a program to compare two arrays for equality. Write a
// similar program to compare two vectors.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-36-compare-vectors.cpp && ./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-36-compare-vectors.cpp && a

=== Output ===
v1 and v2 are the same
v2 and v3 are different
v3 and v4 are different
*/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v3{4, 5, 6};
  std::vector<int> v4{4, 5, 6, 7};
  if (v1 == v2) {
    std::cout << "v1 and v2 are the same" << std::endl;
  } else {
    std::cout << "v1 and v2 are different" << std::endl;
  }
  if (v2 == v3) {
    std::cout << "v2 and v3 are the same" << std::endl;
  } else {
    std::cout << "v2 and v3 are different" << std::endl;
  }
  if (v3 == v4) {
    std::cout << "v3 and v4 are the same" << std::endl;
  } else {
    std::cout << "v3 and v4 are different" << std::endl;
  }
  return 0;
}
