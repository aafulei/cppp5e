// 21/12/21 = Tue

// Exercise 2.35: Determine the types deduced in each of the following
// definitions. Once you've figured out the types, write a program to see
// whether you were correct.

// const int i = 42;
// auto j = i;
// const auto &k = i;
// auto *p = &i;
// const auto j2 = i, &k2 = i;

// Answer:
//
// | Variable | Type        |
// | -------- | ----------- |
// | i        | const int   |
// | j        | int         |
// | k        | const int & |
// | p        | const int * |
// | j2       | const int   |
// | k2       | const int & |

#include <type_traits>

int main() {
  const int i = 42;
  auto j = i;
  const auto &k = i;
  auto *p = &i;
  const auto j2 = i, &k2 = i;
  static_assert(std::is_same<decltype(i), const int>::value,
                "i is not a const int");
  static_assert(std::is_same<decltype(j), int>::value, "j is not an int");
  static_assert(std::is_same<decltype(k), const int &>::value,
                "k is not a const int &");
  static_assert(std::is_same<decltype(p), const int *>::value,
                "p is not a const int *");
  static_assert(std::is_same<decltype(j2), const int>::value,
                "j2 is not a const int");
  static_assert(std::is_same<decltype(k2), const int &>::value,
                "k2 is not a const int &");
  return 0;
}
