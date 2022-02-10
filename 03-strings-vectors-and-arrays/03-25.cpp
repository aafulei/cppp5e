// 21/12/23 = Thu
// 17/10/23 = Mon

// Exercise 3.25: Rewrite the grade clustering program from § 3.3.3 (p. 104)
// using iterators instead of subscripts.

#include <iostream>
#include <vector>

int main() {
  std::vector<unsigned> grades(11);
  unsigned score;
  while (std::cin >> score) {
    if (score <= 100) {
      std::vector<unsigned>::iterator it = grades.begin() + score / 10;
      ++*it;
    }
  }
  for (std::vector<unsigned>::const_iterator it = grades.cbegin();
       it != grades.cend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  return 0;
}
