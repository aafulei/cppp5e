// 22/02/02 = Wed
// 18/02/06 = Tue

// Exercise 6.17: Write a function to determine whether a string contains any
// capital letters. Write a function to change a string to all lowercase. Do the
// parameters you used in these functions have the same type? If so, why? If
// not, why not?

// Answer: No. The first function does not change the string so the parameter
// should be a reference to const, while the parameter in the second function
// should be a plain reference.

#include <iostream>
#include <string>

bool has_upper(const std::string &s) {
  for (char c : s) {
    if ('A' <= c && c <= 'Z') {
      return true;
    }
  }
  return false;
}

void to_lower(std::string &s) {
  for (char &c : s) {
    if ('A' <= c && c <= 'Z') {
      c = c - 'A' + 'a';
    }
  }
}

void test() {
  std::string s= "Hello, World!";
  std::cout << s << " " << has_upper(s) << std::endl;
  to_lower(s);
  std::cout << s << " " << has_upper(s) << std::endl;
}

int main() {
  test();
  return 0;
}
