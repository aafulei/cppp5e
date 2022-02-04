// 22/02/04 = Fri
// 18/02/03 = Sat

// Exercise 4.21: Write a program to use a conditional operator to find the
// elements in a vector<int> that have odd value and double the value of each
// such element.

#include <iostream>
#include <vector>

void print(const std::vector<int> &vec) {
  // C++20
  for (decltype(vec.size()) i = 0; int elem : vec) {
    std::cout << elem << (++i == vec.size() ? '\n' : ' ');
  }
}

void doubleOdd(std::vector<int> &vec) {
  for (int &elem : vec) {
    elem = elem % 2 != 0 ? elem * 2 : elem;
  }
}

int main() {
  std::vector<int> vec{8, 0, 9, 2, 4, 1, 3, 5};
  print(vec);
  doubleOdd(vec);
  print(vec);
  return 0;
}
