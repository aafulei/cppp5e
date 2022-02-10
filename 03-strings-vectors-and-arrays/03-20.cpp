// 22/02/10 = Thu
// 21/12/23 = Thu
// 18/01/27 = Sat
// 17/10/22 = Sun

// Exercise 3.20: Read a set of integers into a vector. Print the sum of each
// pair of adjacent elements. Change your program so that it prints the sum of
// the first and last elements, followed by the sum of the second and
// second-to-last, and so on.

#include <iostream>
#include <vector>

// Note: Given {1, 2, 3, 4, 5}, should return {3, 5, 7, 9}, not {3, 7, 5}
void sum_adjacent_elements(const std::vector<int> &vec) {
  for (std::vector<int>::size_type i = 1; i < vec.size(); ++i) {
    std::cout << vec[i - 1] + vec[i] << " ";
  }
  std::cout << std::endl;
}

// Note: Given {1, 2, 3, 4, 5}, should return {6, 6, 3}, not {6, 6, 6}
void sum_symmetric_elements(const std::vector<int> &vec) {
  const std::vector<int>::size_type N = vec.size();
  // decltype(N) --> const size_type, decltype(N + 0) --> size_type
  for (decltype(N + 0) i = 0; i != N / 2; ++i) {
    std::cout << vec[i] + vec[N - 1 - i] << " ";
  }
  if (N % 2 == 1) {
    std::cout << vec[N / 2];
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> vec;
  for (int a = 0; std::cin >> a; /* empty */) {
    vec.push_back(a);
  }
  sum_adjacent_elements(vec);
  sum_symmetric_elements(vec);
  return 0;
}
