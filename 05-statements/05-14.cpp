// 22/01/29 = Sat
// 18/02/04 = Sun

// Exercise 5.14: Write a program to read strings from standard input looking
// for duplicated words. The program should find places in the input where one
// word is followed immediately by itself. Keep track of the largest number of
// times a single repetition occurs and which word is repeated. Print the
// maximum number of duplicates, or else print a message saying that no word was
// repeated. For example, if the input is
//
//    how now now now brown cow cow
//
// the output should indicate that the word now occurred three times.

#include <iostream>
#include <string>

int main() {
  int max = 0, num = 0;
  std::string word, lastWord;
  while (std::cin >> word) {
    if (word == lastWord) {
      ++num;
    } else {
      num = 1;
    }
    if (num > max) {
      max = num;
    }
    lastWord = word;
  }
  std::cout << max << std::endl;
  return 0;
}
