// 21/12/22 = Wed
// 18/01/27 = Sat
// 17/10/22 = Sun

// Exercise 3.15: Repeat the previous program but read strings this time.

// Exercise 3.14: Write a program to read a sequence of ints from cin and store
// those values in a vector.

// Modified from 03-14.cpp

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> vec;
  for (std::string str; std::cin >> str; /* empty */) {
    vec.push_back(str);
  }
  for (const std::string &str : vec) {
    std::cout << str << std::endl;
  }
  return 0;
}
