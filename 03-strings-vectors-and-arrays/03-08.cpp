// 21/12/22 = Wed
// 17/10/20 = Fri

// Exercise 3.8: Rewrite the program in the first exercise, first using a while
// and again using a traditional for loop. Which of the three approaches do you
// prefer and why?

// Exercise 3.6: Use a range for to change all the characters in a string to X.

// Answer: In this particular example, I prefer the range for approach because
// it is simple and avoids out-of-range subscripting. However, in my opinion,
// range for loop only becomes useful after init-statement was introduced in
// C++20, because it is all too often that we need to know the element position
// in a for loop.

// C++20: print a space between each char in string
// for (int i = 0; char c : str) {
//   std::cout << (i++ == 0 ? "" : " ") << c;
// }
// std::cout << endl;

#include <iostream>
#include <string>

void change_with_while_loop(std::string &str) {
  decltype(str.size()) i = 0;
  while (i != str.size()) {
    str[i] = 'X';
    i += 1;
  }
}

void change_with_traditional_for_loop(std::string &str) {
  for (decltype(str.size()) i = 0; i != str.size(); ++i) {
    str[i] = 'X';
  }
}

int main() {
  std::string str = "Hello, World!";
  std::cout << str << std::endl;
  change_with_while_loop(str);
  std::cout << str << std::endl;
  str = "Hello, World!";
  change_with_traditional_for_loop(str);
  std::cout << str << std::endl;
  return 0;
}
