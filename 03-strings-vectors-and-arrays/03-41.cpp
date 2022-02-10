// 22/02/10 = Thu
// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.41: Write a program to initialize a vector from an array of ints.

#include <iostream>
#include <vector>

template <typename Seq> void print(const Seq &seq) {
  // C++20
  for (int i = 0; auto elem : seq) {
    std::cout << (i++ == 0 ? "" : " ") << elem;
  }
  std::cout << std::endl;
}

int main() {
  int a[]{1, 2, 3, 4, 5};
  std::vector<int> v(a, a + sizeof a / sizeof a[0]);
  print(a);
  print(v);
  return 0;
}
