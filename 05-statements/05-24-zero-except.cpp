// 21/12/25 = Sat
// 18/02/05 = Mon

// Exercise 5.24: Revise your program to throw an exception if the second number
// is zero. Test your program with a zero input to see what happens on your
// system if you don’t catch an exception.

// Exercise 5.23: Write a program that reads two integers from the standard
// input and prints the result of dividing the first number by the second.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 05-24-zero-except.cpp && \
./a.out <../data/two-numbers.txt && \
./a.out <../data/two-numbers-2.txt && \
./a.out <../data/two-numbers-with-zero.txt


(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 05-24-zero-except.cpp && ^
a <..\data\two-numbers.txt && ^
a <..\data\two-numbers-2.txt && ^
a <..\data\two-numbers-with-zero.txt

=== Input ===
5 0
0 0
7 0
24 6

=== Output ===
(two-numbers.txt)
0

(two-numbers-2.txt)
9

(two-numbers-with-zero.txt)
terminate called after throwing an instance of 'std::runtime_error'
  what():  Divide by zero
*/

#include <exception>
#include <iostream>

int main() {
  int a = 0, b = 0;
  if (std::cin >> a >> b) {
    if (b == 0) {
      throw std::runtime_error("Divide by zero");
    }
    std::cout << a / b << std::endl;
  } else {
    std::cerr << "No data?!" << std::endl;
  }
  return 0;
}
