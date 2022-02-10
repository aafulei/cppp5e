// 22/02/10 = Thu
// 21/12/22 = Wed
// 17/10/20 = Fri

// Exercise 3.4: Write a program to read two strings and report whether the
// strings are equal. If not, report which of the two is larger. Now, change the
// program to report whether the strings have the same length, and if not,
// report which is longer.

// Compile with macro STRLEN defined to compare string lengths.

#include <iostream>
#include <string>

void compareStr(const std::string &s1, const std::string &s2) {
  if (s1 == s2) {
    std::cout << "Two strings are equal." << std::endl;
  } else {
    if (s1 > s2) {
      std::cout << "The first string is larger." << std::endl;
    } else {
      std::cout << "The second string is larger." << std::endl;
    }
  }
}

void compareStrLen(const std::string &s1, const std::string &s2) {
  if (s1.size() == s2.size()) {
    std::cout << "Two strings have the same length." << std::endl;
  } else {
    if (s1.size() > s2.size()) {
      std::cout << "The first string is longer." << std::endl;
    } else {
      std::cout << "The second string is longer." << std::endl;
    }
  }
}

int main() {
  std::string s1, s2;
  std::cin >> s1 >> s2;
#ifndef STRLEN
  compareStr(s1, s2);
#else
  compareStrLen(s1, s2);
#endif
  return 0;
}
