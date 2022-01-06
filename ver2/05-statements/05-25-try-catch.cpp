// 21/12/25 = Sat
// 18/02/05 = Mon

// Exercise 5.25: Revise your program from the previous exercise to use a try
// block to catch the exception. The catch clause should print a message to the
// user and ask them to supply a new number and repeat the code inside the try.

// Exercise 5.24: Revise your program to throw an exception if the second number
// is zero. Test your program with a zero input to see what happens on your
// system if you don’t catch an exception.

// Exercise 5.23: Write a program that reads two integers from the standard
// input and prints the result of dividing the first number by the second.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 05-25-try-catch.cpp && \
./a.out <../data/divide-by-zero.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 05-25-try-catch.cpp && ^
a <../data/divide-by-zero.txt

=== Input ===
5 0
0 0
7 0
24 6

=== Output ===
Divide by zero
Divide by zero
Divide by zero
4
*/

#include <exception>
#include <iostream>

int main() {
  int a = 0, b = 0;
  try {
    std::cin >> a >> b;
    if (std::cin && b == 0) {
      throw std::runtime_error("Divide by zero");
    }
  } catch (const std::runtime_error &e) {
    do {
      std::cerr << e.what() << std::endl;
      if (std::cin >> a >> b) {
      }
    } while (std::cin && b == 0);
  }
  if (std::cin) {
    std::cout << a / b << std::endl;
  } else {
    std::cerr << "Bad input" << std::endl;
  }
  return 0;
}
