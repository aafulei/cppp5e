// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.9: Add operations to read and print Person objects to the code you
// wrote for the exercises in § 7.1.2 (p. 260).

#include <iostream>
#include <string>

struct Person {
  std::string name;
  std::string addr;

  std::string get_name() const { return name; }
  std::string get_addr() const { return addr; }
};
