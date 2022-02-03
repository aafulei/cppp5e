// 22/02/03 = Thu
// 18/02/08 = Thu

// Exercise 6.47: Revise the program you wrote in the exercises in § 6.3.2 (p.
// 228) that used recursion to print the contents of a vector to conditionally
// print information about its execution. For example, you might print the size
// of the vector on each call. Compile and run the program with debugging turned
// on and again with it turned off.

// Exercise 6.33: Write a recursive function to print the contents of a vector.

// To turn on debug information, compile as usual
// To turn it off: clang++ -D NDEBUG 06-47.cpp

// Modified from 06-33.cpp

#include <iostream>
#include <vector>

void print(std::vector<int>::const_iterator b,
           std::vector<int>::const_iterator e) {
#ifndef NDEBUG
  std::clog << "[DEBUG] size of vector = " << (e - b) << std::endl;
#endif
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
