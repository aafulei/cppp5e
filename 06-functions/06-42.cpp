// 22/02/03 = Thu
// 18/02/08 = Thu

// Exercise 6.42: Give the second parameter of make_plural (§ 6.3.2, p. 224) a
// default argument of 's'. Test your program by printing singular and plural
// versions of the words success and failure.

#include <cstddef>
#include <iostream>
#include <string>

std::string make_plural(std::size_t ctr, const std::string &word,
                        const std::string &ending = "s") {
  return (ctr > 1) ? word + ending : word;
}

void test() {
  std::cout << make_plural(1, "success", "es") << std::endl; // success
  std::cout << make_plural(2, "success", "es") << std::endl; // successes
  std::cout << make_plural(1, "failure") << std::endl;       // failure
  std::cout << make_plural(2, "failure") << std::endl;       // failures
}

int main() {
  test();
  return 0;
}
