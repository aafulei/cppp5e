// 21/12/28 = Tue
// 18/03/04 = Sun

// Exercise 13.27: Define your own reference-counted version of HasPtr.

/*

=== Output ===
Hello, World!
2
How are you?
1
Hello, World!
1
How are you?
2

3
~HasPtr() deleting How do you do?
~HasPtr() deleting How do you do?
~HasPtr() deleting How do you do?
~HasPtr() deleting Happy New Year!
*/
#include <cstddef>
#include <iostream>
#include <string>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}

  HasPtr(const HasPtr &hp) : ps(hp.ps), i(hp.i), use(hp.use) { ++*hp.use; }

  HasPtr &operator=(const HasPtr &hp) {
    if (&hp != this) {
      --*use;
      if (*use == 0) {
        delete ps;
        delete use;
      }
      ps = hp.ps;
      i = hp.i;
      use = hp.use;
      ++*use;
    }
    return *this;
  }

  ~HasPtr() {
    --*use;
    if (*use == 0) {
      std::clog << "~HasPtr() deleting " << *ps << std::endl;
      delete ps;
      delete use;
    }
  }

  std::string get_string() const { return *ps; }

  std::size_t use_count() const { return *use; }

private:
  std::string *ps;
  int i;
  std::size_t *use;
};

int main() {
  HasPtr hp0;
  HasPtr hp1("Hello, World!");
  HasPtr hp2(hp1);
  std::cout << hp2.get_string() << std::endl; // Hello, World!
  std::cout << hp2.use_count() << std::endl;  // 2
  hp1 = HasPtr("How are you?");
  std::cout << hp1.get_string() << std::endl; // How are you?
  std::cout << hp1.use_count() << std::endl;  // 1
  std::cout << hp2.get_string() << std::endl; // Hello, World!
  std::cout << hp2.use_count() << std::endl;  // 1
  hp2 = hp1;
  std::cout << hp2.get_string() << std::endl; // How are you?
  std::cout << hp2.use_count() << std::endl;  // 2
  hp1 = hp2 = hp0;
  std::cout << hp2.get_string() << std::endl; //
  std::cout << hp2.use_count() << std::endl;  // 3
  hp0 = hp1 = hp2 = HasPtr("Happy New Year!");
  int n = 3;
  while (n-- > 0) {
    HasPtr *php = new HasPtr("How do you do?");
    delete php;
  }
  return 0;
}
