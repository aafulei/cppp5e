// 21/12/17 = Fri
// 18/02/10 = Sat

// Exercise 7.31: Define a pair of classes X and Y, in which X has a pointer to
// Y, and Y has an object of type X.

// clang++ 07-31.cpp

class Y;

class X {
  Y *py;
};

class Y {
  X x;
};

int main() {
  X x;
  Y y;
  return 0;
}
