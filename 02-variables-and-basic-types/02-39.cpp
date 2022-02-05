// 21/12/21 = Tue
// 18/02/02 = Fri

// Exercise 2.39: Compile the following program to see what happens when you
// forget the semicolon after a class definition. Remember the message for
// future reference.

// Note: This program won't compile.

// clang-format off
struct Foo { /* empty */ } // Note: no semicolon

int main() {
  return 0;
}
