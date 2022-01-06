// 21/12/25 = Sat
// 18/02/03 = Sat

// Exercise 4.31: The program in this section used the prefix increment and
// decrement operators. Explain why we used prefix and not postfix. What changes
// would have to be made to use the postfix versions? Rewrite the program using
// postfix operators.

// vector<int>::size_type cnt = ivec.size();
// for(vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
//   ivec[ix] = cnt;

// Answer: There is no difference between prefix and postfix increment in
// standalone expression.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 04-31-postfix.cpp && ./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 04-31-postfix.cpp && a

=== Output ===
10 9 8 7 6 5 4 3 2 1
*/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> ivec(10);
  std::vector<int>::size_type cnt = ivec.size();
  for (std::vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--) {
    ivec[ix] = cnt;
  }
  for (auto i : ivec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
