// 21/12/23 = Thu
// 18/01/27 = Sat
// 17/10/22 = Sun

// Exercise 3.20: Read a set of integers into a vector. Print the sum of each
// pair of adjacent elements. Change your program so that it prints the sum of
// the first and last elements, followed by the sum of the second and
// second-to-last, and so on.

// Note: Given {1, 2, 3, 4, 5}, should return {3, 5, 7, 9}, not {3, 7, 5}

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-20-sum-symmetric-pairs.cpp && \
./a.out <../data/empty.txt && \
./a.out <../data/one.txt && \
./a.out <../data/one-two.txt && \
./a.out <../data/one-two-three.txt && \
./a.out <../data/one-to-five.txt && \
./a.out <../data/several-numbers.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-20-sum-symmetric-pairs.cpp && ^
a <..\data\empty.txt && ^
a <..\data\one.txt && ^
a <..\data\one-two.txt && ^
a <..\data\one-two-three.txt && ^
a <..\data\one-to-five.txt && ^
a <..\data\several-numbers.txt

=== Input ===
(empty.txt)

(one.txt)
1

(one-two.txt)
1 2

(one-two-three.txt)
1 2 3

(one-to-five.txt)
1 2 3 4 5

(several-numbers.txt)
12 34 56 78

=== Output ===
(empty.txt)

(one.txt)
1

(one-two.txt)
3

(one-two-three.txt)
4 2

(one-to-five.txt)
6 6 3

(several-numbers.txt)
90 90
*/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;
  for (int a = 0; std::cin >> a; /* empty */) {
    vec.push_back(a);
  }
  const auto N = vec.size();
  for (decltype(N + 0) i = 0; i != N / 2; ++i) {
    std::cout << vec[i] + vec[N - 1 - i] << " ";
  }
  if (N % 2 == 1) {
    std::cout << vec[N / 2];
  }
  std::cout << std::endl;
  return 0;
}
