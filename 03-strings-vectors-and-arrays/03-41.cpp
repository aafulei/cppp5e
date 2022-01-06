// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.41: Write a program to initialize a vector from an array of ints.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-41-init-vector-from-array.cpp && \
./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-41-init-vector-from-array.cpp && a

=== Output ===
1 2 3 4 5
1 2 3 4 5
*/

#include <iostream>
#include <iterator>
#include <vector>

template <typename Seq> void print(Seq const &seq) {
  for (auto elem : seq)
    std::cout << elem << " ";
  std::cout << std::endl;
}

int main() {
  int a[]{1, 2, 3, 4, 5};
  std::vector<int> v(std::begin(a), std::end(a));
  print(a);
  print(v);
  return 0;
}
