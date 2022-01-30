// 22/01/30 = Sun
// 18/01/30 = Tue
// 18/01/16 = Tue

// Exercise 8.9: Use the function you wrote for the first exercise in § 8.1.2
// (p. 314) to print the contents of an istringstream object.

// Exercise 8.1: Write a function that takes and returns an istream&. The
// function should read the stream until it hits end-of-file. The function
// should print what it reads to the standard output. Reset the stream so that
// it is valid before returning the stream.

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

std::istream &read(std::istream &is) {
  std::string line;
  while (std::getline(is, line)) {
    std::cout << line << std::endl;
  }
  is.clear();
  return is;
}

int main() {
  std::istringstream iss("Hello, World!");
  read(iss);
  assert(iss.good());
  return 0;
}
