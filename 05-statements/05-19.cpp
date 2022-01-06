// 21/12/25 = Sat
// 18/02/04 = Sun

// Exercise 5.19: Write a program that uses a do while loop to repetitively
// request two strings from the user and report which string is less than the
// other.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 05-19-compare-str.cpp && \
./a.out <../data/compare-str.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 05-19-compare-str.cpp && ^
a <..\data\compare-str.txt

=== Input ===
(compare-str.txt)
apple apple
apple banana
blueberry strawberry
cranberry blackberry
grape orange
grapefruit grape

=== Output ===
(compare-str.txt)
Enter two strings:
s1 == s2
Enter two strings:
s1 == s2
Enter two strings:
s1 < s2
Enter two strings:
s1 < s2
Enter two strings:
s1 > s2
Enter two strings:
s1 < s2
Enter two strings:
s1 > s2
Enter two strings:
*/

#include <iostream>
#include <string>

bool report(std::istream &is, const std::string &s1, const std::string &s2) {
  if (!is) {
    return false;
  }
  if (s1 < s2) {
    std::cout << s1 << " is less than " << s2 << std::endl;
  } else if (s1 > s2) {
    std::cout << s2 << " is less than " << s1 << std::endl;
  } else {
    std::cout << s1 << " is equal to " << s2 << std::endl;
  }
  return true;
}

int main() {
  std::string s1, s2;
  do {
    std::cout << "Enter two strings:" << std::endl;
    std::cin >> s1 >> s2;
  } while (report(std::cin, s1, s2));
  return 0;
}
