// 22/02/10 = Thu
// 18/01/28 = Sun

// Exercise 3.37: What does the following program do?

// const char ca[] = {'h', 'e', 'l', 'l', 'o'};
// const char *cp = ca;
// while (*cp) {
//   cout << *cp << endl;
//   ++cp;
// }

// Answer: This program tries to print out all the characters in char array ca,
// each in one line. However, it has a bug. The one element past the end of ca
// has an indeterministic value, not necessarily 0. Therefore, the while loop
// might not terminate as cp loops over ca.

#include <iostream>

int main() {
  const char ca[] = {'h', 'e', 'l', 'l', 'o'};
  const char *cp = ca;
  while (*cp) {
    std::cout << *cp << std::endl;
    ++cp;
  }
  return 0;
}
