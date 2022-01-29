// 22/01/29 = Sat
// 18/02/04 = Sun

// Exercise 5.9: Write a program using a series of if statements to count the
// number of vowels in text read from cin.

#include <iostream>

int main() {
  char c;
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
  while (std::cin >> c) {
    if (c == 'a') {
      ++aCnt;
    } else if (c == 'e') {
      ++eCnt;
    } else if (c == 'i') {
      ++iCnt;
    } else if (c == 'o') {
      ++oCnt;
    } else if (c == 'u') {
      ++uCnt;
    }
  }
  std::cout << "Number of vowel a: \t" << aCnt << '\n'
            << "Number of vowel e: \t" << eCnt << '\n'
            << "Number of vowel i: \t" << iCnt << '\n'
            << "Number of vowel o: \t" << oCnt << '\n'
            << "Number of vowel u: \t" << uCnt << std::endl;
  return 0;
}
