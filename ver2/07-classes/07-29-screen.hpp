// 21/12/17 = Fri
// 18/02/10 = Sat

// Exercise 7.29: Revise your Screen class so that move, set, and display
// functions return Screen and check your prediction from the previous
// exercise.

#include <string>

class Screen {
public:
  using pos = std::string::size_type;

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
  pos height = 0, width = 0;
  pos cursor = 0;
  std::string content;

private:
  void do_display(std::ostream &os) const;
};
