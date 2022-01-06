// 21/12/25 = Sat
// 18/02/04 = Sun

// Exercise 5.21: Revise the program from the exercise in § 5.5.1 (p. 191) so
// that it looks only for duplicated words that start with an uppercase letter.

// Exercise 5.20: Write a program to read a sequence of strings from the
// standard input until either the same word occurs twice in succession or all
// the words have been read. Use a while loop to read the text one word at a
// time. Use the break statement to terminate the loop if a word occurs twice in
// succession. Print the word if it occurs twice in succession, or else print a
// message saying that no word was repeated.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 05-21-dedup-uppercase.cpp && \
./a.out <../data/words-ending-with-ow.txt && \
a <..\data\gettysburg.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 05-21-dedup-uppercase.cpp && ^
a <..\data\words-ending-with-ow.txt && ^
a <..\data\gettysburg.txt

=== Input ===
(words-ending-with-ow.txt)
how now now now brown Cow Cow

(gettysburg.txt)
... We have come to dedicate a portion of that field, as a final resting place
for those who here gave their lives that that nation might live...

=== Output ===
(words-ending-with-ow.txt)
Cow

(gettysburg.txt)
No repeated words found
*/

#include <cctype>
#include <iostream>
#include <string>

int main() {
  bool repeated = false;
  for (std::string prev, curr; std::cin >> curr; prev = curr) {
    if (!curr.empty() && std::isupper(static_cast<unsigned char>(curr[0])) &&
        curr == prev) {
      std::cout << curr << std::endl;
      repeated = true;
      break;
    }
  }
  if (!repeated) {
    std::cout << "No repeated words found" << std::endl;
  }
  return 0;
}
