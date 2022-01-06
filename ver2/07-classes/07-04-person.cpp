// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.4: Write a class named Person that represents the name and address
// of a person. Use a string to hold each of these elements. Subsequent
// exercises will incrementally add features to this class.

// Exercise 7.5: Provide operations in your Person class to return the name and
// address. Should these functions be const? Explain your choice.

#include "07-04-person.hpp"
#include <string>

std::string Person::get_name() const { return name; }
std::string Person::get_addr() const { return addr; }
