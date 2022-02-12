// 22/02/12 = Sat
// 18/02/11 = Sun

// Exercise 7.53: Define your own version of Debug.

#include <iostream>

class Debug {
public:
  constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
  constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}

  constexpr bool any() const { return hw || io || other; }

  void set_hw(bool b) { hw = b; }
  void set_io(bool b) { io = b; }
  void set_other(bool b) { other = b; }

private:
  bool hw;    // hardware errors other than IO errors
  bool io;    // IO errors
  bool other; // other errors
};

int main() {
  constexpr Debug io_sub(false, true, false);
  // C++17
  if constexpr (io_sub.any()) {
    std::cerr << "Print IO error messages." << std::endl;
  }
  constexpr Debug prod(false);
  // C++17
  if constexpr (prod.any()) {
    std::cerr << "Shouldn't be printed." << std::endl;
  }
  return 0;
}
