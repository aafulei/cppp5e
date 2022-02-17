// Exercise 9.5: Rewrite the previous program to return an iterator to the
// requested element. Note that the program must handle the case where the
// element is not found.

// Exercise 9.4: Write a function that takes a pair of iterators to a
// vector<int> and an int value. Look for that value in the range and return a
// bool indicating whether it was found.

// Modified from 09-04.cpp

#include <iostream>
#include <iterator>
#include <vector>

std::vector<int>::const_iterator find(std::vector<int>::const_iterator beg,
                                      std::vector<int>::const_iterator end,
                                      int val) {
  for (; beg != end; ++beg) {
    if (val == *beg) {
      return beg;
    }
  }
  return end;
}

void test_one(const std::vector<int> &vec, int val) {
  std::vector<int>::const_iterator it = find(vec.begin(), vec.end(), val);
  if (it == vec.end()) {
    std::cout << val << " is not found" << std::endl;
  } else {
    std::cout << val << " is found at position "
              << std::distance(vec.begin(), it) << std::endl;
  }
}

void test() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  test_one(vec, 0);
  test_one(vec, 1);
  test_one(vec, 3);
  test_one(vec, 5);
  test_one(vec, 6);
}

int main() {
  test();
  return 0;
}
