// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.4: Write a class named Person that represents the name and address
// of a person. Use a string to hold each of these elements. Subsequent
// exercises will incrementally add features to this class.

// Exercise 7.5: Provide operations in your Person class to return the name and
// address. Should these functions be const? Explain your choice.

#include <string>

struct Person {
  std::string name;
  std::string addr;

  std::string get_name() const;
  std::string get_addr() const;
};
