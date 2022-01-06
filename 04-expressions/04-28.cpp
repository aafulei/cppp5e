// 21/12/25 = Sat
// 18/02/03 = Sat

// Exercise 4.28: Write a program to print the size of each of the built-in
// types.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 04-28-sizeof.cpp && ./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 04-28-sizeof.cpp && a

=== Output ===
(Linux/macOS)
sizeof(bool) = 1
sizeof(char) = 1
sizeof(wchar_t) = 4
sizeof(char16_t) = 2
sizeof(char32_t) = 4
sizeof(short) = 2
sizeof(int) = 4
sizeof(long) = 8
sizeof(long long) = 8
sizeof(float) = 4
sizeof(double) = 8
sizeof(long double) = 16

(Windows)
sizeof(bool) = 1
sizeof(char) = 1
sizeof(wchar_t) = 2
sizeof(char16_t) = 2
sizeof(char32_t) = 4
sizeof(short) = 2
sizeof(int) = 4
sizeof(long) = 4
sizeof(long long) = 8
sizeof(float) = 4
sizeof(double) = 8
sizeof(long double) = 16
*/

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
