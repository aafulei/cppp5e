// 21/12/18 = Sat
// 19/05/28 = Tue

// Exercise 1.15: Write programs that contain the common errors discussed in the
// box on page 16. Familiarize yourself with the messages the compiler
// generates.

// Note: This program won't compile.

// clang-format off
#include <iostream>

void print(int a) {
  std::cout << a << std::endl;
}

// Syntax error: missing ) in parameter list for main
int main ( {

  // Syntax error: used colon, not a semicolon, after endl
  std::cout << "Read each file." << std::endl:

  // Syntax error: missing quotes around string literal
  std::cout << Update master. << std::endl;

  // Syntax error: second output operator is missing
  std::cout << "Write new master." std::endl;

  // Type error: passing a string literal to a function that expects an int
  print("Hello, World!");

  // Declaration error: forgetting to use std:: for a name from the library
  cout << "Hello, World!" << endl;

  // Declaration error: misspelling the name of an identifier
  std::count << "Hello, World!" << std::end;

  // Syntax error: missing ; on return statement
  return 0
}
