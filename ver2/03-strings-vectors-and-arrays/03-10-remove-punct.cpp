// 21/12/22 = Wed
// 18/01/26 = Fri
// 17/10/20 = Fri

// Exercise 3.10: Write a program that reads a string of characters including
// punctuation and writes what was read but with the punctuation removed.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-10-remove-punct.cpp && \
./a.out <../data/summer.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-10-remove-punct.cpp && ^
a <..\data\summer.txt

=== Input ===
(summer.txt)
Shall I compare thee to a summer's day?
Thou art more lovely and more temperate.
Rough winds do shake the darling buds of May,
And summer's lease hath all too short a date.
Sometime too hot the eye of heaven shines,
And often is his gold complexion dimmed;
And every fair from fair sometime declines,
By chance, or nature's changing course, untrimmed;
But thy eternal summer shall not fade,
Nor lose possession of that fair thou ow'st,
Nor shall death brag thou wand'rest in his shade,
When in eternal lines to Time thou grow'st.
So long as men can breathe, or eyes can see,
So long lives this, and this gives life to thee.

=== Output ===
Shall I compare thee to a summers day
Thou art more lovely and more temperate
Rough winds do shake the darling buds of May
And summers lease hath all too short a date
Sometime too hot the eye of heaven shines
And often is his gold complexion dimmed
And every fair from fair sometime declines
By chance or natures changing course untrimmed
But thy eternal summer shall not fade
Nor lose possession of that fair thou owst
Nor shall death brag thou wandrest in his shade
When in eternal lines to Time thou growst
So long as men can breathe or eyes can see
So long lives this and this gives life to thee
*/

#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string line;
  while (std::getline(std::cin, line)) {
    for (unsigned char c : line) {
      if (!std::ispunct(c)) {
        std::cout << c;
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
