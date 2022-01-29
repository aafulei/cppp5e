// 22/01/29 = Sat
// 18/02/04 = Sun

// Exercise 5.10: There is one problem with our vowel-counting program as we've
// implemented it: It doesn’t count capital letters as vowels. Write a program
// that counts both lower- and uppercase letters as the appropriate vowel --
// that is, your program should count both 'a' and 'A' as part of aCnt, and so
// forth.

#include <iostream>

int main() {
  char c;
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
  while (std::cin >> c) {
    switch (c) {
    case 'a':
    case 'A':
      ++aCnt;
      break;
    case 'e':
    case 'E':
      ++eCnt;
      break;
    case 'i':
    case 'I':
      ++iCnt;
      break;
    case 'o':
    case 'O':
      ++oCnt;
      break;
    case 'u':
    case 'U':
      ++uCnt;
      break;
    }
  }
  std::cout << "Number of vowel a: " << aCnt << '\n'
            << "Number of vowel e: " << eCnt << '\n'
            << "Number of vowel i: " << iCnt << '\n'
            << "Number of vowel o: " << oCnt << '\n'
            << "Number of vowel u: " << uCnt << std::endl;
  return 0;
}
