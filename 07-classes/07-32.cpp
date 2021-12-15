// 18/02/10 = Sat
// 21/17/17 = Fri
// 18/02/10 = Sat

// Exericse 7.32: Define your own versions of Screen and Window_mgr in which
// clear is a member of Window_mgr and a friend of Screen.

// clang++ 07-32.cpp

#include "07-32.hpp"
#include <iostream>

using namespace std;

int main() {
  Window_mgr myWinMgr;
  Screen &myScreen = myWinMgr.get(0);
  cout << "\n";
  myScreen.move(4, 0).set('#').display(cout);
  cout << "\n";
  myWinMgr.clear(0);
  myScreen.display(cout);
  cout << "\n";
  return 0;
}
