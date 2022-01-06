// 21/12/15 = Wed
// 18/02/10 = Sat

// Exercise 7.23: Write your own version of the Screen class.

// clang++ -std=c++11 -pedantic -Wall -Wextra 07-23-test.cpp -o 07-23-test

#include "07-23-screen.hpp"
#include <iostream>

using namespace std;

int main() {
  Screen scr(24, 80, '*');
  cout << scr.get() << endl;              // *
  cout << scr.get_size() << endl;         // 1920 (= 24 * 80)
  cout << scr.move(10, 10).get() << endl; // *
  cout << scr.get_cursor() << endl;       // 810 (= 10 * 80 + 10)

  const Screen scr2(100, 100, '.');    // note that scr2 is const
  cout << scr2.access_count() << endl; // 1 (called once)
  cout << scr2.access_count() << endl; // 2 (called twice)

  return 0;
}
