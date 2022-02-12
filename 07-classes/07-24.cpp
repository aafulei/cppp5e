// 21/12/15 = Wed
// 18/02/10 = Sat

// Exercise 7.24: Give your Screen class three constructors: a default
// constructor; a constructor that takes values for height and width and
// initializes the contents to hold the given number of blanks; and a
// constructor that takes values for height, width, and a character to use as
// the contents of the screen.

// Modified from 07-23.cpp

#include <cstddef>
#include <iostream>
#include <string>

class Screen {
public:
  using pos = std::string::size_type;

public:
  Screen() = default;
  Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {} // Add
  Screen(pos h, pos w, char x) : height(h), width(w), contents(h * w, x) {}

  char get() const { return contents[cursor]; }
  char get(pos r, pos c) const { return contents[r * width + c]; }
  pos get_size() const { return height * width; }
  pos get_cursor() const { return cursor; }

  Screen &move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
  }
  std::size_t get_access_count() const { return ++access_ctr; }

private:
  pos height = 0;
  pos width = 0;
  pos cursor = 0;
  std::string contents;
  mutable std::size_t access_ctr = 0;
};

void test() {
  Screen scr1;
  std::cout << "scr1 size = " << scr1.get_size() << std::endl; // 0
  // note that can't call scr1.get() as it is an empty screen
  Screen scr2(24, 80);
  std::cout << "scr2 size = " << scr2.get_size() << std::endl;        // 1920
  std::cout << "scr2 cursor at '" << scr2.get() << '\'' << std::endl; // ' '
  Screen scr3(3840, 2160, '*');
  std::cout << "scr2 size = " << scr3.get_size() << std::endl;        // 8294400
  std::cout << "scr3 cursor at '" << scr3.get() << '\'' << std::endl; // '*'
}

int main() {
  test();
  return 0;
}
