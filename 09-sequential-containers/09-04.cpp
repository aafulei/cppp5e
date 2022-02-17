// 22/02/17 = Thu
// 18/02/18 = Sun
// 18/01/16 = Tue
// 17/10/25 = Wed

// Exercise 9.4: Write a function that takes a pair of iterators to a
// vector<int> and an int value. Look for that value in the range and return a
// bool indicating whether it was found.

#include <iostream>
#include <vector>

bool find(std::vector<int>::const_iterator beg,
          std::vector<int>::const_iterator end, int val) {
  while (beg != end) {
    if (val == *beg++) {
      return true;
    }
  }
  return false;
}

void test() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  std::cout << find(vec.begin(), vec.end(), 0) << std::endl;
  std::cout << find(vec.begin(), vec.end(), 1) << std::endl;
  std::cout << find(vec.begin(), vec.end(), 3) << std::endl;
  std::cout << find(vec.begin(), vec.end(), 5) << std::endl;
  std::cout << find(vec.begin(), vec.end(), 6) << std::endl;
}

int main() {
  test();
  return 0;
}
