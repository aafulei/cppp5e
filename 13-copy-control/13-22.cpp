// 21/12/28 = Tue
// 18/03/04 = Sun

// Exercise 13.22: Assume that we want HasPtr to behave like a value. That is,
// each object should have its own copy of the string to which the objects
// point. We’ll show the definitions of the copy-control members in the next
// section. However, you already know everything you need to know to implement
// these members. Write the HasPtr copy constructor and copy-assignment operator
// before reading on.

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
