// 21/12/15 = Wed
// 18/02/10 = Sat

// Exercise 7.24: Give your Screen class three constructors: a default
// constructor; a constructor that takes values for height and width and
// initializes the contents to hold the given number of blanks; and a
// constructor that takes values for height, width, and a character to use as
// the contents of the screen.

// clang++ -std=c++11 -pedantic -Wall -Wextra 07-23-test.cpp -o 07-24-test

#include "07-24-screen.hpp"
#include <iostream>

using namespace std;

int main() {
  Screen scr1;
  cout << "scr1 size = " << scr1.get_size() << endl; // 0
  // note that can't call scr1.get() as it is an empty screen

  Screen scr2(24, 80);
  cout << "scr2 size = " << scr2.get_size() << endl;        // 1920
  cout << "scr2 cursor at '" << scr2.get() << '\'' << endl; // ' '

  Screen scr3(3840, 2160, '*');
  cout << "scr2 size = " << scr3.get_size() << endl;        // 8294400
  cout << "scr3 cursor at '" << scr3.get() << '\'' << endl; // '*'

  return 0;
}
