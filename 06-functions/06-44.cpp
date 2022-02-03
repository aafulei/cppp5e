// 22/02/03 = Thu
// 18/02/08 = Thu

// Exercise 6.44: Rewrite the isShorter function from § 6.2.2 (p. 211) to be
// inline.

// bool isShorter(const string &s1, const string &s2) {
//   return s1.size() < s2.size();
// }

#include <iostream>
#include <string>

inline bool isShorter(const std::string &s1, const std::string &s2) {
  return s1.size() < s2.size();
}

void test() { std::cout << isShorter("Hello", "World") << std::endl; }

int main() {
  test();
  return 0;
}
