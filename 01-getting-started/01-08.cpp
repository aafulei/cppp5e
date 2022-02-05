// 21/12/18 = Sat
// 19/05/28 = Tue

// Exercise 1.8: Indicate which, if any, of the following output statements are
// legal:

// std::cout << "/*";
// std::cout << "*/";
// std::cout << /* "*/" */;
// std::cout << /*  "*/" /* "/*"  */;

// After you’ve predicted what will happen, test your answers by compiling a
// program with each of these statements. Correct any errors you encounter.

// clang-format off
#include <iostream>

int main() {
  std::cout << "/*";                  // legal: /*
  std::cout << "*/";                  // legal: */
  // std::cout << /* "*/" */;         // illegal: won't compile
  std::cout << /*  "*/" /* "/*"  */;  // legal: (space)/*(space)
}
