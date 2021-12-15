// 21/12/15 = Wed
// 18/02/10 = Sat

// Exercise 7.27: Add the move, set, and display operations to your version of
// Screen. Test your class by executing the following code:

// Screen myScreen(5, 5, 'X');
// myScreen.move(4,0).set('#').display(cout);
// cout << "\n";
// myScreen.display(cout);
// cout << "\n";

// clang-format off
// clang++ -std=c++11 07-27-screen.cpp 07-27-test.cpp -o 07-27-test && 07-27-test
// clang-format on

#include "07-27-screen.hpp"
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
