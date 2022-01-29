// 22/01/29 = Sat
// 18/02/04 = Sun

// Exercise 5.12: Modify our vowel-counting program so that it counts the number
// of occurrences of the following two-character sequences: ff, fl, and fi.

// Modified from 05-11.cpp

#include <iostream>

int main() {
  char c;
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, blankCnt = 0,
           tabCnt = 0, newlineCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
  std::cin >> std::noskipws;
  // Note: A string like "0xffff" counts for 2 ff occurrences.
  for (bool lastF = false; std::cin >> c; lastF = (c == 'f' && !lastF)) {
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
    if (lastF) {
      if (c == 'f') {
        ++ffCnt;
      } else if (c == 'i') {
        ++fiCnt;
      } else if (c == 'l') {
        ++flCnt;
      }
    }
  }
  std::cout << "Number of vowel a: \t" << aCnt << '\n'
            << "Number of vowel e: \t" << eCnt << '\n'
            << "Number of vowel i: \t" << iCnt << '\n'
            << "Number of vowel o: \t" << oCnt << '\n'
            << "Number of vowel u: \t" << uCnt << '\n'
            << "Number of blanks: \t" << blankCnt << '\n'
            << "Number of tabs: \t" << tabCnt << '\n'
            << "Number of newlines: \t" << newlineCnt << '\n'
            << "Number of ff counts: \t" << ffCnt << '\n'
            << "Number of fl counts: \t" << flCnt << '\n'
            << "Number of fi counts: \t" << fiCnt << std::endl;
  return 0;
}
