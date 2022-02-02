// 22/02/02 = Wed
// 18/02/07 = Wed

// Exercise 6.25: Write a main function that takes two arguments. Concatenate
// the supplied arguments and print the resulting string.

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " str1 str2" << std::endl;
    return 1;
  }
  std::cout << std::string(argv[1]) + std::string(argv[2]) << std::endl;
  return 0;
}
