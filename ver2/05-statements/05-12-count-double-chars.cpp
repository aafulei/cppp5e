// 18/02/04 = Sun

// Exercise 5.9: Write a program using a series of if statements to count the
// number of vowels in text read from cin.

#include <cstring>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::getline;
using std::string;
using std::tolower;
using std::std::endl;

int main() {
  unsigned a, e, i, o, u, blank, tab, newline, ff, fl, fi;
  a = e = i = o = u = blank = tab = newline = ff = fl = fi = 0;
  for (string line; getline(cin, line); ++newline) {
    bool prev = false;
    for (auto c : line) {
      if (prev) {
        if (c == 'f')
          ++ff;
        else if (c == 'l')
          ++fl;
        else if (c == 'i')
          ++fi;
        prev = false;
      } else if (c == 'f')
        prev = true;
      c = tolower(c);
      if (c == 'a')
        ++a;
      else if (c == 'e')
        ++e;
      else if (c == 'i')
        ++i;
      else if (c == 'o')
        ++o;
      else if (c == 'u')
        ++u;
      else if (c == ' ')
        ++blank;
      else if (c == '\t')
        ++tab;
    }
  }
  std::cout << "a\t" << a << std::endl;
  std::cout << "e\t" << e << std::endl;
  std::cout << "i\t" << i << std::endl;
  std::cout << "o\t" << o << std::endl;
  std::cout << "u\t" << u << std::endl;
  std::cout << "blank\t" << blank << std::endl;
  std::cout << "tab\t" << tab << std::endl;
  std::cout << "newline\t" << newline << std::endl;
  std::cout << "ff\t" << ff << std::endl;
  std::cout << "fi\t" << fi << std::endl;
  std::cout << "fl\t" << fl << std::endl;
  return 0;
}
