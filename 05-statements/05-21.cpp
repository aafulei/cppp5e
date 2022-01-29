// 22/01/29 = Sat
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

// Modified from 05-20.cpp

#include <iostream>
#include <string>

int main() {
  bool has_repeat = false;
  for (std::string word, last; std::cin >> word; last = word) {
    // skip words that do not start with an uppercase letter
    if (!(word.size() && 'A' <= word[0] && word[0] <= 'Z')) {
      continue;
    }
    if (word == last) {
      std::cout << word << std::endl;
      has_repeat = true;
      break;
    }
  }
  if (!has_repeat) {
    std::cout << "No word that starts with an uppercase letter was repeated."
              << std::endl;
  }
  return 0;
}
