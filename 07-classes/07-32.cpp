// 21/17/17 = Fri
// 18/02/10 = Sat

// Exericse 7.32: Define your own versions of Screen and Window_mgr in which
// clear is a member of Window_mgr and a friend of Screen.

// Modified from 07-24.cpp

#include <iostream>
#include <string>
#include <vector>

class Screen;

class Window_mgr {
public:
  using ScreenIndex = std::vector<Screen>::size_type;

private:
  std::vector<Screen> screens;

public:
  Window_mgr();
  Screen &get(ScreenIndex);
  const Screen &get(ScreenIndex) const;
  void clear(ScreenIndex);
};

class Screen {
  friend void Window_mgr::clear(ScreenIndex);

public:
  using pos = std::string::size_type;

private:
  pos height = 0;
  pos width = 0;
  pos cursor = 0;
  std::string contents;

public:
  Screen();
  Screen(pos h, pos w);
  Screen(pos h, pos w, char x);
  char get() const;
  char get(pos r, pos c) const;
  const Screen &display(std::ostream &os) const;
  Screen &display(std::ostream &os);
  Screen &move(pos r, pos c);
  Screen &set(char c);
  Screen &set(pos r, pos c, char x);

private:
  void do_display(std::ostream &os) const;
};

Window_mgr::Window_mgr() { screens = std::vector<Screen>{Screen{5, 5, '.'}}; }

Screen &Window_mgr::get(ScreenIndex i) { return screens[i]; }

const Screen &Window_mgr::get(ScreenIndex i) const { return screens[i]; }

Screen::Screen() = default;

Screen::Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {}

Screen::Screen(pos h, pos w, char x)
    : height(h), width(w), contents(h * w, x) {}

char Screen::get() const { return contents[cursor]; }

char Screen::get(pos r, pos c) const { return contents[r * width + c]; }

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
  contents[cursor] = x;
  return *this;
}

Screen &Screen::set(pos r, pos c, char x) {
  contents[r * width + c] = x;
  return *this;
}

void Screen::do_display(std::ostream &os) const {
  // os << contents << std::endl;
  for (pos i = 0; i != height; ++i) {
    for (pos j = 0; j != width; ++j) {
      os << contents[i * width + j];
    }
    os << "\n";
  }
}

void Window_mgr::clear(ScreenIndex i) {
  Screen &s = screens[i];
  s.contents = std::string(s.height * s.width, '.');
}

int main() {
  Window_mgr myWinMgr;
  Screen &myScreen = myWinMgr.get(0);
  std::cout << "\n";
  myScreen.move(4, 0).set('#').display(std::cout);
  std::cout << "\n";
  myWinMgr.clear(0);
  myScreen.display(std::cout);
  std::cout << "\n";
  return 0;
}
