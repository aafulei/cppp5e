// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.42: Write a program to copy a vector of ints into an array of
// ints.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-42-copy-vector-into-array.cpp && \
./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-42-copy-vector-into-array.cpp && a

=== Output ===
1 2 3 4 5
1 2 3 4 5
*/

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <vector>

template <typename Seq> void print(Seq const &seq) {
  for (auto elem : seq)
    std::cout << elem << " ";
  std::cout << std::endl;
}

int main() {
  std::vector<int> v{1, 2, 3, 4, 5};
  constexpr int N = 5;
  int a[N];
  int b[N];
  std::copy(v.begin(), v.end(), std::begin(a));
  for (std::size_t i = 0; i != N; ++i) {
    b[i] = v[i];
  }
  print(a);
  print(b);
  return 0;
}
