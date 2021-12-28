// 21/12/28 = Tue
// 18/03/03 = Sat

// Exercise 13.8: Write the assignment operator for the HasPtr class from
// exercise 13.5 in § 13.1.1 (p. 499). As with the copy constructor, your
// assignment operator should copy the object to which ps points.

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
