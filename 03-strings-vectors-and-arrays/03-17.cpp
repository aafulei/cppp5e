// 21/12/22 = Wed
// 18/01/27 = Sat
// 17/10/22 = Sun

// Exercise 3.17: Read a sequence of words from cin and store the values in a
// vector. After you've read all the words, process the vector and change each
// word to uppercase. Print the transformed elements, eight words to a line.

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> vec;
  for (std::string word; std::cin >> word; /* empty */) {
    vec.push_back(word);
  }
  for (std::string &word : vec) {
    for (char &c : word) {
      c = std::toupper(static_cast<unsigned char>(c));
    }
  }
  for (decltype(vec.size()) i = 0; i != vec.size(); ++i) {
    std::cout << vec[i] << (i % 8 == 7 ? "\n" : " ");
  }
  if (vec.size() % 8 != 0) {
    std::cout << std::endl;
  }
  return 0;
}
