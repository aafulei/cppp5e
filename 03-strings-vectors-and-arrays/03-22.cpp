// 21/12/22 = Wed
// 18/01/27 = Sat
// 17/10/23 = Mon

// Exercise 3.22: Revise the loop that printed the first paragraph in text to
// instead change the elements in text that correspond to the first paragraph to
// all uppercase. After you've updated text, print its contents.

// for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
//   cout << *it << endl;
// }

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
  for (const std::string &line : text) {
    std::cout << line << std::endl;
  }
  return 0;
}
