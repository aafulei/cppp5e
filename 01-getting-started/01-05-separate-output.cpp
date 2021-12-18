// 21/12/18 = Sat
// 18/01/29 = Mon

// Exercise 1.5: We wrote the output in one large statement. Rewrite the program
// to use a separate statement to print each operand.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-05-separate-output.cpp && \
./a.out <../data/two-numbers.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-05-separate-output.cpp && ^
a <..\data\two-numbers.txt

=== Input ====
(two-numbers.txt)
3 5

=== Output ===
(two-numbers.txt)
Enter two numbers:
The sum of 3 and 5 is 8
*/

#include <iostream>

int main() {
  std::cout << "Enter two numbers:";
  std::cout << std::endl;
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  std::cout << "The sum of ";
  std::cout << v1;
  std::cout << " and ";
  std::cout << v2;
  std::cout << " is ";
  std::cout << v1 + v2;
  std::cout << std::endl;
  return 0;
}
