// 21/12/28 = Tue
// 18/03/03 = Sat

// Exercise 13.5: Given the following sketch of a class, write a copy
// constructor that copies all the members. Your constructor should dynamically
// allocate a new string (§ 12.1.2, p. 458) and copy the object to which ps
// points, rather than copying ps itself.

// class HasPtr {
// public:
//  HasPtr(const std::string &s = std::string()):
//      ps(new std::string(s)), i(0) { }
// private:
//  std::string *ps;
//  int i;
// };

// Note: These answers are the same: 13-05, 13-08, 13-11, 13-22

#include <iostream>
#include <string>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}

  HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}

  HasPtr &operator=(const HasPtr &hp) {
    if (&hp != this) {
      std::string *temp = new std::string(*hp.ps);
      delete ps;
      ps = temp;
      i = hp.i;
    }
    return *this;
  }

  ~HasPtr() { delete ps; }

  std::string get_string() const { return *ps; }

private:
  std::string *ps;
  int i;
};

int main() {
  HasPtr hp0;
  HasPtr hp1("Hello, World!");
  std::cout << hp1.get_string() << std::endl;
  HasPtr hp2 = hp1;
  hp1 = hp0;
  std::cout << hp2.get_string() << std::endl;
  hp0 = HasPtr("How are you?");
  hp2 = hp1 = hp0 = hp0;
  std::cout << hp1.get_string() << std::endl;
  std::cout << hp2.get_string() << std::endl;
  return 0;
}
