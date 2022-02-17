// 22/02/17 = Thu
// 18/01/17 = Wed
// 17/10/25 = Wed

// Exercise 9.14: Write a program to assign the elements from a list of char *
// pointers to C-style character strings to a vector of strings.

#include <iostream>
#include <list>
#include <string>
#include <vector>

int main() {
  char cs1[] = "Hello";
  char cs2[] = "My";
  char cs3[] = "Friend";
  std::list<char *> lst{cs1, cs2, cs3};
  std::vector<std::string> vec;
  vec.assign(lst.begin(), lst.end());
  for (const std::string &elem : vec) {
    std::cout << elem << std::endl;
  }
  return 0;
}
