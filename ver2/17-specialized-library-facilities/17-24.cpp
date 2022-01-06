#include <iostream>
#include <regex>
#include <string>

// morgan (201) 555-0168 862-555-0123
// drew (973)555.0130
// lee (609) 555-0132 2015550175 800.555-0110

// clang++ 17-24.cpp && a <../data/phone-numbers.txt

int main() {
  std::regex r("(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})");
  for (std::string line; std::getline(std::cin, line); /* empty */) {
    std::cout << std::regex_replace(line, r, "$2.$5.$7") << std::endl;
  }
  return 0;
}
