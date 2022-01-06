// 21/12/15 = Wed
// 18/02/10 = Sat

// Exercise 7.24: Give your Screen class three constructors: a default
// constructor; a constructor that takes values for height and width and
// initializes the contents to hold the given number of blanks; and a
// constructor that takes values for height, width, and a character to use as
// the contents of the screen.

#include <cstddef>
#include <string>

// similar to 07-23-screen.hpp but with member functions defined outside class
class Screen {
public:
  using pos = std::string::size_type;

  Screen();
  Screen(pos h, pos w); // ADD
  Screen(pos h, pos w, char x);

  char get() const;
  char get(pos r, pos c) const;
  pos get_size() const;
  pos get_cursor() const;

  Screen &move(pos r, pos c);

  std::size_t access_count() const;

private:
  pos height = 0, width = 0;
  pos cursor = 0;
  std::string content;

  mutable std::size_t access_ctr = 0;
};

// inline functions should be defined in the same translation unit
inline Screen::Screen() = default;

inline Screen::Screen(pos h, pos w)
    : height(h), width(w), content(h * w, ' ') {}

inline Screen::Screen(pos h, pos w, char x)
    : height(h), width(w), content(h * w, x) {}

inline char Screen::get() const {
  ++access_ctr;
  return content[cursor];
}

inline char Screen::get(pos r, pos c) const {
  ++access_ctr;
  return content[r * width + c];
}

inline Screen::pos Screen::get_cursor() const { return cursor; }

inline Screen::pos Screen::get_size() const { return height * width; }

inline Screen &Screen::move(pos r, pos c) {
  cursor = r * width + c;
  return *this;
}

inline std::size_t Screen::access_count() const { return ++access_ctr; }
