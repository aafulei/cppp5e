// 22/02/12 = Sat
// 18/02/10 = Sat

// Exercise 7.22: Update your Person class to hide its implementation.

// Modified from 07-15.cpp

#include <iostream>
#include <string>

class Person {
  friend std::istream &read(std::istream &is, Person &p);
  friend std::ostream &print(std::ostream &os, const Person &p);

public:
  Person();
  Person(const std::string &name);
  Person(const std::string &name, const std::string &addr);

  std::string get_name() const;
  std::string get_addr() const;

private:
  std::string name;
  std::string addr;
};

// --- impl --------------------------------------------------------------------

Person::Person() = default;
Person::Person(const std::string &name) : name(name) {}
Person::Person(const std::string &name, const std::string &addr)
    : name(name), addr(addr) {}

std::string Person::get_name() const { return name; }
std::string Person::get_addr() const { return addr; }

std::istream &read(std::istream &is, Person &p) {
  return is >> p.name >> p.addr;
}

std::ostream &print(std::ostream &os, const Person &p) {
  if (p.name.empty()) {
    return os << "(empty)" << std::endl;
  }
  if (p.addr.empty()) {
    return os << p.name << std::endl;
  }
  return os << p.name << " @ " << p.addr << std::endl;
}

void test() {
  Person p0;
  Person p1("Name");
  Person p2("Name", "Address");
  print(std::cout, p0);
  print(std::cout, p1);
  print(std::cout, p2);
}

int main() {
  test();
  return 0;
}
