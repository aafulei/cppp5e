// 22/02/23 = Wed
// 18/01/17 = Wed

// Exercise 9.20: Write a program to copy elements from a list<int> into two
// deques. The even-valued elements should go into one deque and the odd ones
// into the other.

#include <deque>
#include <iostream>
#include <list>

template <typename Seq> void print(const Seq &seq) {
  for (int i = 0; int elem : seq) { // C++20
    std::cout << (i++ == 0 ? "" : " ") << elem;
  }
  std::cout << std::endl;
}

int main() {
  std::list<int> lst{1, 6, 3, 7, 8, 0, 4, 2, 5, 9};
  std::deque<int> deq1, deq2;
  for (int elem : lst) {
    if (elem % 2 == 1) {
      deq1.push_back(elem);
    } else {
      deq2.push_back(elem);
    }
  }
  std::cout << "lst : ";
  print(lst);
  std::cout << "deq1: ";
  print(deq1);
  std::cout << "deq2: ";
  print(deq2);
  return 0;
}
