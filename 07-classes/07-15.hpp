// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.15: Add appropriate constructors to your Person class.

// Modified based on 07-04.hpp

#include <string>

struct Person {
  std::string name;
  std::string addr;

  Person();
  Person(const std::string &);
  Person(const std::string &, const std::string &);

  std::string get_name() const;
  std::string get_addr() const;
};
