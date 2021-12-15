// 21/12/15 = Wed
// 18/02/10 = Sat

// Exercise 7.27: Add the move, set, and display operations to your version of
// Screen. Test your class by executing the following code:

// Screen myScreen(5, 5, 'X');
// myScreen.move(4,0).set('#').display(cout);
// cout << "\n";
// myScreen.display(cout);
// cout << "\n";

#include <string>

class Screen {
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
