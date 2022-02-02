// 22/02/02 = Wed
// 18/02/06 = Tue

// Exercise 6.9: Write your own versions of the fact.cc and factMain.cc files.
// These files should include your Chapter6.h from the exercises in the previous
// section. Use these files to understand how your compiler supports separate
// compilation.

// fact.cc

#include "Chapter6.h"

int fact(int val) {
  int res = 1;
  for (int i = 1; i <= val; ++i) {
    res *= i;
  }
  return res;
}
