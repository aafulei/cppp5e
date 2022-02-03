// 22/02/03 = Thu
// 18/02/08 = Thu

// Exercise 6.51: Write all four versions of f. Each function should print a
// distinguishing message. Check your answers for the previous exercise. If your
// answers were incorrect, study this section until you understand why your
// answers were wrong.

// Exercise 6.50: Given the declarations for f from *page 242*, list the viable
// functions, if any for each of the following calls. Indicate which function is
// the best match, or if the call is illegal whether there is no match or why
// the call is ambiguous.

// (a) f(2.56, 42)
// (b) f(42)
// (c) f(42, 0)
// (d) f(2.56, 3.14)

// void f();
// void f(int);
// void f(int, int);
// void f(double, double = 3.14);

#include <iostream>

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

void f() {
#ifndef NDEBUG
  std::clog << "void f();" << std::endl;
#endif
}

void f(int) {
#ifndef NDEBUG
  std::clog << "void f(int);" << std::endl;
#endif
}

void f(int, int) {
#ifndef NDEBUG
  std::clog << "void f(int, int);" << std::endl;
#endif
}

void f(double, double) {
#ifndef NDEBUG
  std::clog << "void f(double, double = 3.14);" << std::endl;
#endif
}

void test() {
  // f(2.56, 42); // error: call to 'f' is ambiguous
  f(42);         // void f(int);
  f(42, 0);      // void f(int, int);
  f(2.56, 3.14); // void f(double, double = 3.14);
}

int main() {
  test();
  return 0;
}
