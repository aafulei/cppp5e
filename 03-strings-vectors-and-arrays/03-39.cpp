// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.39: Write a program to compare two strings. Now write a program to
// compare the values of two C-style character strings.

#include <cstring>
#include <iostream>

void compare_std_strings(const std::string &s1, const std::string &s2) {
  if (s1 == s2) {
    std::cout << "The two std::strings are the same." << std::endl;
  } else {
    if (s1 > s2) {
      std::cout << "The first std::string is larger." << std::endl;
    } else {
      std::cout << "The second std::string is larger." << std::endl;
    }
  }
}

void compare_c_style_strings(const char s1[], const char s2[]) {
  while (*s1 && (*s1 == *s2)) {
    ++s1;
    ++s2;
  }
  int res = *reinterpret_cast<const unsigned char *>(s1) -
            *reinterpret_cast<const unsigned char *>(s2);
  if (res == 0) {
    std::cout << "The two C-style strings are the same." << std::endl;
  } else {
    if (res > 0) {
      std::cout << "The first C-style string is larger." << std::endl;
    } else {
      std::cout << "The second C-style string is larger." << std::endl;
    }
  }
}

void test() {
  std::string s1 = "Hello";
  std::string s2 = "World";
  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;
  compare_std_strings(s1, s2);
  compare_c_style_strings(s1.c_str(), s2.c_str());
}

int main() {
  test();
  return 0;
}
