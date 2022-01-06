// 21/12/15 = Wed
// 18/02/10 = Sat

// Exercise 7.27: Add the move, set, and display operations to your version of
// Screen. Test your class by executing the following code:

// Screen myScreen(5, 5, 'X');
// myScreen.move(4,0).set('#').display(cout);
// cout << "\n";
// myScreen.display(cout);
// cout << "\n";

#include "07-27-screen.hpp"
#include <iostream>

Screen::Screen() = default;

Screen::Screen(pos h, pos w) : height(h), width(w), content(h * w, ' ') {}

Screen::Screen(pos h, pos w, char x) : height(h), width(w), content(h * w, x) {}

char Screen::get() const { return content[cursor]; }

char Screen::get(pos r, pos c) const { return content[r * width + c]; }

const Screen &Screen::display(std::ostream &os) const {
  do_display(os);
  return *this;
}

Screen &Screen::display(std::ostream &os) {
  do_display(os);
  return *this;
}

Screen &Screen::move(pos r, pos c) {
  cursor = r * width + c;
  return *this;
}

Screen &Screen::set(char x) {
  content[cursor] = x;
  return *this;
}

Screen &Screen::set(pos r, pos c, char x) {
  content[r * width + c] = x;
  return *this;
}

void Screen::do_display(std::ostream &os) const {
  // os << content << std::endl;
  for (pos i = 0; i != content.size(); ++i) {
    if (i && i % width == 0) {
      os << '\n';
    }
    os << content[i];
  }
}
