// 21/12/22 = Wed
// 18/01/27 = Sat
// 17/10/23 = Mon

// Exercise 3.22: Revise the loop that printed the first paragraph in text to
// instead change the elements in text that correspond to the first paragraph to
// all uppercase. After you’ve updated text, print its contents.

// for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
//   cout << *it << endl;
// }

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-22-uppercase.cpp && \
./a.out <../data/summer-paragraphs.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-22-uppercase.cpp && ^
a <..\data\summer-paragraphs.txt

=== Input ===
(summer-paragraphs.txt)
Shall I compare thee to a summer's day?
Thou art more lovely and more temperate.

Rough winds do shake the darling buds of May,
And summer's lease hath all too short a date.

=== Output ===
(summer-paragraphs.txt)
SHALL I COMPARE THEE TO A SUMMER'S DAY?
THOU ART MORE LOVELY AND MORE TEMPERATE.

Rough winds do shake the darling buds of May,
And summer's lease hath all too short a date.
*/

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> text;
  for (std::string line; std::getline(std::cin, line); /* empty */) {
    text.push_back(line);
  }
  for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
    for (char &c : *it) {
      c = std::toupper(static_cast<unsigned char>(c));
    }
  }
  for (const auto &para : text) {
    std::cout << para << std::endl;
  }
  return 0;
}
