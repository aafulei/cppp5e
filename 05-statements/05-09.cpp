// 22/01/29 = Sat
// 18/02/04 = Sun

// Exercise 5.9: Write a program using a series of if statements to count the
// number of vowels in text read from cin.

#include <iostream>
#include <string>

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
  std::cout << "Number of vowel a: " << aCnt << '\n'
            << "Number of vowel e: " << eCnt << '\n'
            << "Number of vowel i: " << iCnt << '\n'
            << "Number of vowel o: " << oCnt << '\n'
            << "Number of vowel u: " << uCnt << std::endl;
  return 0;
}
