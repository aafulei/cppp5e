// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.9: Add operations to read and print Person objects to the code you
// wrote for the exercises in § 7.1.2 (p. 260).

// (Linux/macOS) clang++ -std=c++11 07-09.cpp && ./a.out <../data/person
// (Windows) clang++ -std=c++11 07-09.cpp && a <../data/person

#include "07-09.hpp"
#include <iostream>
#include <string>

// --- impl --------------------------------------------------------------------

std::istream &read(std::istream &is, Person &p) {
  return is >> p.name >> p.addr;
}

std::ostream &print(std::ostream &os, const Person &p) {
  return os << p.get_name() << " @ " << p.get_addr();
}

// --- test --------------------------------------------------------------------

int main() {
  Person p;
  read(std::cin, p);
  print(std::cout, p);
  return 0;
}
