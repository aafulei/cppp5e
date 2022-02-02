// 22/02/02 = Wed
// 18/02/07 = Wed

// Exercise 6.33: Write a recursive function to print the contents of a vector.

#include <iostream>
#include <vector>

void print(std::vector<int>::const_iterator b,
           std::vector<int>::const_iterator e) {
  if (b == e) {
    return;
  }
  std::cout << *b++ << std::endl;
  print(b, e);
}

void test() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  print(vec.begin(), vec.end());
}

int main() {
  test();
  return 0;
}
