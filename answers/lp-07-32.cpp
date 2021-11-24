// 18/02/10 = Sat

// Exercise 7.32: Define your own versions of Screen and Window_mgr in which clear is a member of Window_mgr and a friend of Screen.

// Modified from lp-07-27.cpp

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ostream;
using std::invalid_argument;
using std::string;
using std::vector;

// Order that must be followed:
// 0.	Must forward declare Screen first, because Window_mgr manages Screen objects;
// 1.	Must define class Window_mgr before class Screen, otherwise Screen cannot befriend Window_mgr::clear();
// 1.5	Must declare but not define Window_mgr::clear();
// 2.	Must define Screen before Window_mgr::clear(), otherwise clear() cannot use incomplete type Screen;
// 3.	Must define Window_mgr::clear() in the end.
class Screen;
class Window_mgr
{
	using ScreenIndex = vector<Screen>::size_type;
	// Cannot use in-class initializer such as {Screen(24, 80, ' ')}; Why?
	vector<Screen> screens;
public:
	// Important: the & is sine qua non (absolutely necessary)! Why?
	void add(Screen const & s)
	{	screens.push_back(s); }
	Screen & get(ScreenIndex i)
	{	return screens[i]; }
	void clear(ScreenIndex i, char c = ' ');
};

class Screen
{
	using pos = string::size_type;
	string contents;
	pos cursor = 0;
	pos width = 0;
	pos height = 0;
public:
	Screen() = default;
	Screen(pos w, pos h) : width(w), height(h),
						   contents(w * h, ' ') {}
	Screen(pos w, pos h, char c) : width(w), height(h),
								   contents(w * h, c) {}
	bool empty() const
	{ 	return contents.empty(); }
	char get() const
	{ 	return cursor < contents.size() ? contents[cursor] : '\0'; }
	char get(pos row, pos col) const
	{	return row * width + col < contents.size() ?
			   contents[row * width + col] : '\0'; }
	Screen & move(pos row, pos col);
	Screen & set(char c);
	Screen & set(pos row, pos col, char c);
	Screen & display(ostream & os);
	const Screen & display(ostream & os) const;
private:
	void do_display(ostream & os) const;
	friend void Window_mgr::clear(ScreenIndex i, char c);
};

void Window_mgr::clear(ScreenIndex i, char c)
{
	if (i >= screens.size())
		throw invalid_argument("Invalid subscripting!");
	screens[i].contents.assign(screens[i].contents.size(), c);
	// alternatively:
	// for (auto & e : screens[i].contents)
	// 	e = c;
}

inline Screen & Screen::move(pos row, pos col)
{
	cursor = row * width + col;
	return *this;
}

inline Screen & Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen & Screen::set(pos row, pos col, char c)
{
	contents[row * width + col] = c;
	return *this;
}

inline Screen & Screen::display(ostream & os)
{
	do_display(os);
	return *this;
}

inline const Screen & Screen::display(ostream & os) const
{
	do_display(os);
	return *this;
}

// Important: The const cannot be omitted!
// When one member calls another, the this pointer is passed implicitly.
void Screen::do_display(ostream & os) const
{
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j)
			os << contents[i * width + j];
		os << endl;
	}
}

int main()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4,0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";
	Window_mgr myManager;
	myManager.add(myScreen);
	myManager.clear(0, 'O');
	myManager.get(0).display(cout);
	return 0;
}