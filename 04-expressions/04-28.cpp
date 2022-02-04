// 21/12/25 = Sat
// 18/02/03 = Sat

// Exercise 4.28: Write a program to print the size of each of the built-in
// types.

// | sizeof      | Linux/macOS | Windows |
// | ----------- | ----------- | ------- |
// | bool        | 1           | 1       |
// | char        | 1           | 1       |
// | wchar_t     | 4           | 2       |
// | char16_t    | 2           | 2       |
// | char32_t    | 4           | 4       |
// | short       | 2           | 2       |
// | int         | 4           | 4       |
// | long        | 8           | 4       |
// | long long   | 8           | 8       |
// | float       | 4           | 4       |
// | double      | 8           | 8       |
// | long double | 16          | 16      |

#include <iostream>

int main() {
  std::cout << "sizeof(bool) = " << sizeof(bool) << std::endl;
  std::cout << "sizeof(char) = " << sizeof(char) << std::endl;
  std::cout << "sizeof(wchar_t) = " << sizeof(wchar_t) << std::endl;
  std::cout << "sizeof(char16_t) = " << sizeof(char16_t) << std::endl;
  std::cout << "sizeof(char32_t) = " << sizeof(char32_t) << std::endl;
  std::cout << "sizeof(short) = " << sizeof(short) << std::endl;
  std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
  std::cout << "sizeof(long) = " << sizeof(long) << std::endl;
  std::cout << "sizeof(long long) = " << sizeof(long long) << std::endl;
  std::cout << "sizeof(float) = " << sizeof(float) << std::endl;
  std::cout << "sizeof(double) = " << sizeof(double) << std::endl;
  std::cout << "sizeof(long double) = " << sizeof(long double) << std::endl;
  return 0;
}
