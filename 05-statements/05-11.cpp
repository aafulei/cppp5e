// 22/01/29 = Sat
// 18/02/04 = Sun

// Exercise 5.11: Modify our vowel-counting program so that it also counts the
// number of blank spaces, tabs, and newlines read.

// Modified from 05-10.cpp

#include <iostream>

int main() {
  char c;
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, blankCnt = 0,
           tabCnt = 0, newlineCnt = 0;
  // Add - do not skip white spaces
  std::cin >> std::noskipws;
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
    // Add
    case ' ':
      ++blankCnt;
      break;
    case '\t':
      ++tabCnt;
      break;
    case '\n':
      ++newlineCnt;
      break;
    }
  }
  std::cout << "Number of vowel a: \t" << aCnt << '\n'
            << "Number of vowel e: \t" << eCnt << '\n'
            << "Number of vowel i: \t" << iCnt << '\n'
            << "Number of vowel o: \t" << oCnt << '\n'
            << "Number of vowel u: \t" << uCnt << '\n'
            << "Number of blanks: \t" << blankCnt << '\n'
            << "Number of tabs: \t" << tabCnt << '\n'
            << "Number of newlines: \t" << newlineCnt << std::endl;
  return 0;
}
