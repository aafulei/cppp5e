// 21/12/17 = Fri
// 18/02/10 = Sat

// Exercise 7.29: Revise your Screen class so that move, set, and display
// functions return Screen and check your prediction from the previous
// exercise.

// clang++ -std=c++11 07-29-screen.cpp 07-29-test.cpp

#include "07-29-screen.hpp"
#include <iostream>

using namespace std;

int main() {
  Screen myScreen(5, 5, 'X');
  myScreen.move(4, 0).set('#').display(cout);
  cout << "\n";
  myScreen.display(cout);
  cout << "\n";
  return 0;
}
