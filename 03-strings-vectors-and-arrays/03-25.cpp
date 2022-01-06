// 21/12/23 = Thu
// 17/10/23 = Mon

// Exercise 3.25: Rewrite the grade clustering program from § 3.3.3 (p. 104)
// using iterators instead of subscripts.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-25-grades.cpp && \
./a.out <../data/scores.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-25-grades.cpp && ^
a <..\data\scores.txt

=== Input ===
42 65 95 100 39 67 95 76 88 76 83 92 76 93

=== Output ===
0 0 0 1 1 0 2 3 2 4 1
*/

#include <iostream>
#include <vector>

int main() {
  std::vector<unsigned> grades(11);
  unsigned score;
  while (std::cin >> score) {
    if (score <= 100) {
      auto it = grades.begin() + score / 10;
      ++*it;
    }
  }
  for (auto it = grades.cbegin(); it != grades.cend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  return 0;
}
