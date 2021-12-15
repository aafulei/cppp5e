// 21/12/15 = Wed
// 18/02/10 = Sat

// Exercise 7.23: Write your own version of the Screen class.

#include <cstddef>
#include <string>

class Screen {
public:
  using pos = std::string::size_type;

  Screen() = default;
  Screen(pos h, pos w, char x) : height(h), width(w), content(h * w, x) {}

  char get() const { return content[cursor]; }
  char get(pos r, pos c) const { return content[r * width + c]; }
  pos get_size() const { return height * width; }
  pos get_cursor() const { return cursor; }

  Screen &move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
  }

  std::size_t access_count() const { return ++access_ctr; }

private:
  pos height = 0, width = 0;
  pos cursor = 0;
  std::string content;

  mutable std::size_t access_ctr = 0;
};
