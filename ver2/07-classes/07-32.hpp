#include <string>
#include <vector>
#include <iostream>

class Screen;

class Window_mgr {
public:
  using ScreenIndex = std::vector<Screen>::size_type;

  Window_mgr();
  Screen &get(ScreenIndex);
  const Screen &get(ScreenIndex) const;
  void clear(ScreenIndex);

private:
  std::vector<Screen> screens;
};

class Screen {
  friend void Window_mgr::clear(ScreenIndex);

public:
  using pos = std::string::size_type;

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
  pos height = 0, width = 0;
  pos cursor = 0;
  std::string content;

private:
  void do_display(std::ostream &os) const;
};

Window_mgr::Window_mgr()
{
  screens = std::vector<Screen> {Screen{5, 5, '.'}};
}

Screen &Window_mgr::get(ScreenIndex i)
{
  return screens[i];
}

const Screen &Window_mgr::get(ScreenIndex i) const
{
  return screens[i];
}

inline Screen::Screen() = default;

inline Screen::Screen(pos h, pos w) : height(h), width(w), content(h * w, ' ') {}

inline Screen::Screen(pos h, pos w, char x) : height(h), width(w), content(h * w, x) {}

inline char Screen::get() const { return content[cursor]; }

inline char Screen::get(pos r, pos c) const { return content[r * width + c]; }

inline const Screen &Screen::display(std::ostream &os) const {
  do_display(os);
  return *this;
}

inline Screen &Screen::display(std::ostream &os) {
  do_display(os);
  return *this;
}

inline Screen &Screen::move(pos r, pos c) {
  cursor = r * width + c;
  return *this;
}

inline Screen &Screen::set(char x) {
  content[cursor] = x;
  return *this;
}

inline Screen &Screen::set(pos r, pos c, char x) {
  content[r * width + c] = x;
  return *this;
}

inline void Screen::do_display(std::ostream &os) const {
  // os << content << std::endl;
  for (pos i = 0; i != height; ++i) {
    for (pos j = 0; j != width; ++j) {
      os << content[i * width + j];
    }
    os << "\n";
  }
}




inline void Window_mgr::clear(ScreenIndex i) {
  Screen &s = screens[i];
  s.content = std::string(s.height * s.width, '.');
}
