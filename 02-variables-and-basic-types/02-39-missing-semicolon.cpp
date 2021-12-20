// 21/12/21 = Tue
// 18/02/02 = Fri

// Exercise 2.39: Compile the following program to see what happens when you
// forget the semicolon after a class definition. Remember the message for
// future reference.

// Note: This program won't compile.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-39-missing-semicolon.cpp

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-39-missing-semicolon.cpp

=== Compiler Error ===
error: expected ';' after struct
*/

// clang-format off
struct Foo { /* empty */ } // Note: no semicolon

int main() {
  return 0;
}
