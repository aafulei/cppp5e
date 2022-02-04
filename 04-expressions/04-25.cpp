// 22/02/04 = Fri
// 18/02/03 = Sat

// Exercise 4.25: What is the value of ~'q' << 6 on a machine with 32-bit ints
// and 8 bit chars, that uses Latin-1 character set in which 'q' has the bit
// pattern 01110001?

#include <iostream>

int main() {
  std::cout << (~'q' << 6) << std::endl; // -7296
  return 0;
}
