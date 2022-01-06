// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.4: Write a class named Person that represents the name and address
// of a person. Use a string to hold each of these elements. Subsequent
// exercises will incrementally add features to this class.

// Exercise 7.5: Provide operations in your Person class to return the name and
// address. Should these functions be const? Explain your choice.

/* (Linux/macOS) clang++ -std=c++11 -pedantic -Wall -Wextra \
 07-04-person.cpp 07-04-test.cpp && ./a.out

 (Windows) clang++ -std=c++11 -pedantic -Wall -Wextra ^
 07-04-person.cpp 07-04-test.cpp && a */

#include "07-04-person.hpp"
#include <iostream>

int main() {
  Person p;
  p.name = "Peter";
  p.addr = "England";
  std::cout << p.name << " @ " << p.addr << std::endl; // Peter @ England
  return 0;
}
