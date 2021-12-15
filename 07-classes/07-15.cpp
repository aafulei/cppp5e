// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.15: Add appropriate constructors to your Person class.

// (Linux/macOS) clang++ -std=c++11 07-15.cpp && ./a.out
// (Windows) clang++ -std=c++11 07-15.cpp && a

// Modified based on 07-04.cpp

#include "07-15.hpp"
#include <iostream>
#include <string>

// --- impl --------------------------------------------------------------------

Person::Person() = default;
Person::Person(const std::string &n) : name(n) {}
Person::Person(const std::string &n, const std::string &a) : name(n), addr(a) {}

std::string Person::get_name() const { return name; }
std::string Person::get_addr() const { return addr; }

// --- test --------------------------------------------------------------------

void print(const Person &p) {
  if (p.name.empty()) {
    std::cout << "(empty)" << std::endl;
  } else if (p.addr.empty()) {
    std::cout << p.name << std::endl;
  } else {
    std::cout << p.name << " @ " << p.addr << std::endl;
  }
}

int main() {
  Person p0;
  Person p1("Joe");
  Person p2("Peter", "England");
  print(p0); // (empty)
  print(p1); // Joe
  print(p2); // Peter @ England
  return 0;
}
