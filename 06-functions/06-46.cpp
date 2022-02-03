// 22/02/03 = Thu
// 18/02/08 = Thu

// Exercise 6.46: Would it be possible to define isShorter as a constexpr? If so
// do so. If not, explain why not.

// bool isShorter(const string &s1, const string &s2) {
//   return s1.size() < s2.size();
// }

// clang++ -std=c++11 -pedantic -Wall -Wextra 06-46.cpp
// g++ -std=c++11 -pedantic -Wall -Wextra 06-46.cpp

// Note: The programs compiles with clang++-12, but won't compile with g++-11,
// which shows:

// error: call to non-'constexpr' function 'std::__cxx11::basic_string<_CharT,
// _Traits, _Alloc>::size_type std::__cxx11::basic_string<_CharT, _Traits,
// _Alloc>::size() const [with _CharT = char; _Traits = std::char_traits<char>;
// _Alloc = std::allocator<char>; std::__cxx11::basic_string<_CharT, _Traits,
// _Alloc>::size_type = long unsigned int]'

#include <iostream>
#include <string>

constexpr bool isShorter(const std::string &s1, const std::string &s2) {
  return s1.size() < s2.size();
}

void test() { std::cout << isShorter("Hello", "World") << std::endl; }

int main() {
  test();
  return 0;
}
