// 22/02/17 = Thu

// Exercise 9.2: Define a list that holds elements that are deques that hold
// ints.

#include <deque>
#include <iostream>
#include <list>

void print(const std::list<std::deque<int>> &lst) {
  for (const std::deque<int> &dq : lst) {
    for (bool first = true; int elem : dq) { // C++20
      if (first) {
        first = false;
      } else {
        std::cout << " ";
      }
      std::cout << elem;
    }
    std::cout << std::endl;
  }
}

void test(std::list<std::deque<int>> &lst) {
  lst.push_back(std::deque<int>{4, 5, 6});
  lst.push_front(std::deque<int>{1, 2, 3});
  print(lst);
}

int main() {
  std::list<std::deque<int>> lst;
  test(lst);
  return 0;
}
