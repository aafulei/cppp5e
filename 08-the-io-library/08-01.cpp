// 22/01/20 = Thu
// 18/01/30 = Tue
// 17/10/20 = Fri

// Exercise 8.1: Write a function that takes and returns an istream&. The
// function should read the stream until it hits end-of-file. The function
// should print what it reads to the standard output. Reset the stream so that
// it is valid before returning the stream.

// Exercise 8.2: Test your function by calling it, passing cin as an argument.

#include <iostream>

std::istream &read(std::istream &is) {
  std::string line;
  while (std::getline(is, line)) {
    std::cout << line << std::endl;
  }
  is.clear();
  return is;
}

int main() {
  std::cout << read(std::cin).good() << std::endl;
  return 0;
}
