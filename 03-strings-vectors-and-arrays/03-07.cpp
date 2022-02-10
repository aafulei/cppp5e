// 21/12/22 = Wed
// 17/10/20 = Fri

// Exercise 3.7: What would happen if you define the loop control variable in
// the previous exercise as type char? Predict the results and then change your
// program to use a char to see if you were right.

// Exercise 3.6: Use a range for to change all the characters in a string to X.

// Answer: The string would not be changed.

// Modified from 03-06.cpp

#include <iostream>
#include <string>

int main() {
  std::string str = "Hello, World!";
  std::cout << str << std::endl;
  // use char instead of char &
  for (char c : str) {
    c = 'X';
  }
  std::cout << str << std::endl;
  return 0;
}
