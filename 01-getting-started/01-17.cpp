// 21/12/18 = Sat
// 19/07/02 = Tue
// 19/05/28 = Tue
// 18/01/29 = Mon

// Exercise 1.17: What happens in the program presented in this section if the
// input values are all equal? What if there are no duplicated values?

// Note: This program is the same as the one in the textbook.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-17-count-numbers.cpp && \
./a.out <../data/same-numbers.txt && ./a.out <../data/several-numbers.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-17-count-numbers.cpp && ^
a <..\data\same-numbers.txt && a <..\data\several-numbers.txt

=== Input ===
(same-numbers.txt)
42 42 42

(several-numbers.txt)
12 34 56 78

=== Output ===
(same-numbers.txt)
42 occurs 3 times

(several-numbers.txt)
12 occurs 1 times
34 occurs 1 times
56 occurs 1 times
78 occurs 1 times
*/

#include <iostream>

int main() {
  int currVal = 0, val = 0;
  if (std::cin >> currVal) {
    int cnt = 1;
    while (std::cin >> val) {
      if (val == currVal) {
        ++cnt;
      } else {
        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
        currVal = val;
        cnt = 1;
      }
    }
    std::cout << currVal << " occurs " << cnt << " times" << std::endl;
  }
  return 0;
}
