// 22/02/10 = Thu
// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.42: Write a program to copy a vector of ints into an array of
// ints.

#include <cstddef>
#include <iostream>
#include <vector>

template <typename Seq> void print(Seq const &seq) {
  // C++20
  for (int i = 0; auto elem : seq) {
    std::cout << (i++ == 0 ? "" : " ") << elem;
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> v{1, 2, 3, 4, 5};
  constexpr int N = 5;
  int a[N];
  for (std::size_t i = 0; i != N; ++i) {
    a[i] = v[i];
  }
  print(v);
  print(a);
  return 0;
}
