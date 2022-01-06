// 18/02/10 = Sat

// Exercise 7.28: What would happen in the previous exercise if the return type of move, set, and display was Screen rather than Screen&?

// Answer: A copy of the screen is returned. As a result, the move and set operation will not affect the myScreen, though the program still compiles.

// Exercise 7.29: Revise your Screen class so that move, set, and display functions return Screen and check your prediction from the previous exercise.

// Exercise 7.27: Add the move, set, and display operations to your version of Screen. Test your class by executing the following code:

// Screen myScreen(5, 5, 'X');
// myScreen.move(4,0).set('#').display(cout);
// cout << "\n";
// myScreen.display(cout);
// cout << "\n";

// Modified from lp-07-27.cpp

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

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
	Screen move(pos row, pos col);
	Screen set(char c);
	Screen set(pos row, pos col, char c);
	Screen display(ostream & os);
	const Screen display(ostream & os) const;
private:
	void do_display(ostream & os) const;
};

inline Screen Screen::move(pos row, pos col)
{
	cursor = row * width + col;
	return *this;
}

inline Screen Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen Screen::set(pos row, pos col, char c)
{
	contents[row * width + col] = c;
	return *this;
}

inline Screen Screen::display(ostream & os)
{
	do_display(os);
	return *this;
}

inline const Screen Screen::display(ostream & os) const
{
	do_display(os);
	return *this;
}

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
	return 0;
}