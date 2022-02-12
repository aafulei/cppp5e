// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.15: Add appropriate constructors to your Person class.

// Modified from 07-04.cpp

#include <iostream>
#include <string>

struct Person {
  std::string name;
  std::string addr;

  Person();
  Person(const std::string &name);
  Person(const std::string &name, const std::string &addr);

  std::string get_name() const;
  std::string get_addr() const;
};

// --- impl --------------------------------------------------------------------

Person::Person() = default;
Person::Person(const std::string &name) : name(name) {}
Person::Person(const std::string &name, const std::string &addr)
    : name(name), addr(addr) {}

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

void test() {
  Person p0;
  Person p1("Name");
  Person p2("Name", "Address");
  print(p0);
  print(p1);
  print(p2);
}

int main() {
  test();
  return 0;
}
