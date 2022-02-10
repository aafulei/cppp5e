// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.40: Write a program to define two character arrays initialized
// from string literals. Now define a third character array to hold the
// concatenation of the two arrays. Use strcpy and strcat to copy the two arrays
// into the third.

#include <cstring>
#include <iostream>

int main() {
  char a[] = "Hello, ";
  char b[] = "World!";
  char c[100];
  std::strcpy(c, a);
  std::strcat(c, b);
  std::cout << c << std::endl;
  return 0;
}
