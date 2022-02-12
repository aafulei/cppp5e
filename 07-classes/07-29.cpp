// 21/12/17 = Fri
// 18/02/10 = Sat

// Exercise 7.29: Revise your Screen class so that move, set, and display
// functions return Screen and check your prediction from the previous
// exercise.

// Modified from 07-27.cpp

#include <iostream>
#include <string>

class Screen {
public:
  using pos = std::string::size_type;

private:
  pos height = 0, width = 0;
  pos cursor = 0;
  std::string contents;

public:
  Screen();
  Screen(pos h, pos w);
  Screen(pos h, pos w, char x);
  char get() const;
  char get(pos r, pos c) const;
  const Screen display(std::ostream &os) const;
  Screen display(std::ostream &os);
  Screen move(pos r, pos c);
  Screen set(char c);
  Screen set(pos r, pos c, char x);

private:
  void do_display(std::ostream &os) const;
};

Screen::Screen() = default;

Screen::Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {}

Screen::Screen(pos h, pos w, char x)
    : height(h), width(w), contents(h * w, x) {}

char Screen::get() const { return contents[cursor]; }

char Screen::get(pos r, pos c) const { return contents[r * width + c]; }

const Screen Screen::display(std::ostream &os) const {
  do_display(os);
  return *this;
}

Screen Screen::display(std::ostream &os) {
  do_display(os);
  return *this;
}

Screen Screen::move(pos r, pos c) {
  cursor = r * width + c;
  return *this;
}

Screen Screen::set(char x) {
  contents[cursor] = x;
  return *this;
}

Screen Screen::set(pos r, pos c, char x) {
  contents[r * width + c] = x;
  return *this;
}

void Screen::do_display(std::ostream &os) const {
  // os << contents << std::endl;
  for (pos i = 0; i != contents.size(); ++i) {
    if (i && i % width == 0) {
      os << '\n';
    }
    os << contents[i];
  }
}

void test() {
  Screen myScreen(5, 5, 'X');
  myScreen.move(4, 0).set('#').display(std::cout);
  std::cout << "\n";
  myScreen.display(std::cout);
  std::cout << "\n";
}

int main() {
  test();
  return 0;
}
