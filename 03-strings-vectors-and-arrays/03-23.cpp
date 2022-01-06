// 21/12/23 = Thu
// 18/01/27 = Sat
// 17/10/23 = Mon

// Exercise 3.23: Write a program to create a vector with ten int elements.
// Using an iterator, assign each element a value that is twice its current
// value. Test your program by printing the vector.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-23-vector-int.cpp && ./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-23-vector-int.cpp && a

=== Output ===
1 2 3 4 5 6 7 8 9 10
2 4 6 8 10 12 14 16 18 20
*/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (const auto &elem : vec) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    *it *= 2;
  }
  for (const auto &elem : vec) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
  return 0;
}
