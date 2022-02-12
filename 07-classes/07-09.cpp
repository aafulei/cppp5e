// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.9: Add operations to read and print Person objects to the code you
// wrote for the exercises in § 7.1.2 (p. 260).

// Exercise 7.4: Write a class named Person that represents the name and address
// of a person. Use a string to hold each of these elements. Subsequent
// exercises will incrementally add features to this class.

#include <iostream>
#include <string>

struct Person {
  std::string name;
  std::string addr;

  std::string get_name() const;
  std::string get_addr() const;
};

// --- impl --------------------------------------------------------------------

std::string Person::get_name() const { return name; }
std::string Person::get_addr() const { return addr; }

// -----------------------------------------------------------------------------

std::istream &read(std::istream &is, Person &p) {
  return is >> p.name >> p.addr;
}

std::ostream &print(std::ostream &os, const Person &p) {
  return os << p.get_name() << " @ " << p.get_addr();
}

void test() {
  Person p;
  read(std::cin, p);
  print(std::cout, p);
}

int main() {
  test();
  return 0;
}
