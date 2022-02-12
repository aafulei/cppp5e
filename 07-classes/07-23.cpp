// 21/12/15 = Wed
// 18/02/10 = Sat

// Exercise 7.23: Write your own version of the Screen class.

#include <cstddef>
#include <iostream>
#include <string>

class Screen {
public:
  using pos = std::string::size_type;

private:
  pos height = 0;
  pos width = 0;
  pos cursor = 0;
  std::string contents;
  mutable std::size_t access_ctr = 0;

public:
  Screen() = default;
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
};

void test() {
  Screen scr(24, 80, '*');
  std::cout << scr.get() << std::endl;               // *
  std::cout << scr.get_size() << std::endl;          // 1920 (= 24 * 80)
  std::cout << scr.move(10, 10).get() << std::endl;  // *
  std::cout << scr.get_cursor() << std::endl;        // 810 (= 10 * 80 + 10)
  const Screen scr2(100, 100, '.');                  // note that scr2 is const
  std::cout << scr2.get_access_count() << std::endl; // 1 (called once)
  std::cout << scr2.get_access_count() << std::endl; // 2 (called twice)
}

int main() {
  test();
  return 0;
}
