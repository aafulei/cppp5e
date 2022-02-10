// 22/02/10 = Thu
// 21/12/22 = Wed
// 18/01/26 = Fri
// 17/10/20 = Fri

// Exercise 3.5: Write a program to read strings from the standard input,
// concatenating what is read into one large string. Print the concatenated
// string. Next, change the program to separate adjacent input strings by a
// space.

// Compile with macro ADDSPACE defined to separate input strings by a space.

#include <iostream>
#include <string>

std::string read_and_concat() {
  std::string res, str;
  while (std::cin >> str) {
    res += str;
  }
  return res;
}

std::string read_and_concat_with_spaces() {
  std::string res, str;
  while (std::cin >> str) {
    if (!res.empty()) {
      res += " ";
    }
    res += str;
  }
  return res;
}

int main() {
  std::string res;
#ifndef ADDSPACE
  res = read_and_concat();
#else
  res = read_and_concat_with_spaces();
#endif
  std::cout << res << std::endl;
  return 0;
}
