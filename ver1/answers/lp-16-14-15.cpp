// 18/03/24 = Sat

// Exercise 16.14: Write a Screen class template that uses nontype parameters to define the height and width of the Screen.

// Exercise 16.15: Implement input and output operators for your Screen template. Which, if any, friends are necessary in class Screen to make the input and output operators work? Explain why each friend declaration, if any, was needed.

// Modified from lp-07-23-24.cpp, lp-07-27.cpp

#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

template<unsigned W, unsigned H> class Screen;
template<unsigned W, unsigned H>
ostream & operator<<(ostream &, const Screen<W, H> &);

template<unsigned W, unsigned H>
class Screen
{
	using pos = string::size_type;
	string contents;
	pos cursor = 0;
	pos width = 0;
	pos height = 0;
	mutable size_t access_counter = 0;
public:
	// get width and height from non-type template arguments
	Screen() : width(W), height(H), contents(W * H, ' ') {}
	// get width and height from non-type template arguments
	Screen(char c) : width(W), height(H), contents(W * H, c) {}
	bool empty() const
	{
		++access_counter;
		return contents.empty();
	}
	char get() const
	{
		++access_counter;
		return cursor < contents.size() ?			// ensure safety
			  contents[cursor] : '\0';
	}
	char get(pos nr, pos nc) const
	{
		++access_counter;
		return nr * width + nc < contents.size() ?	// ensure safety
			  contents[nr * width + nc] : '\0';
	}
	Screen & move(pos nr, pos nc)
	{
		++access_counter;
		cursor = nr * width + nc;
		return *this;
	}
	size_t count_access() const
	{
		return access_counter;
	}
	Screen & set(char c)
	{
		contents[cursor] = c;
		return *this;
	}
	Screen & set(pos row, pos col, char c)
	{
		contents[row * width + col] = c;
		return *this;
	}
friend ostream & operator<< <W, H>(ostream &, const Screen &);
};

template<unsigned W, unsigned H>
ostream & operator<<(ostream & os, const Screen<W, H> & s)
{
	for (int i = 0; i < s.height; ++i) {
		for (int j = 0; j < s.width; ++j)
			os << s.contents[i * s.width + j];
		os << endl;
	}
	return os;
}

int main()
{
	// lp-07-23-24.cpp
	Screen<0,0> s1;
	Screen<3,4> s2;
	Screen<3,4> s3('*');
	cout << s1.empty() << endl;		// 1
	cout << s2.empty() << endl;		// 0
	cout << s3.empty() << endl;		// 0
	cout << s2.get(1, 1) << endl;	// 
	cout << s3.get() << endl;		// *
	cout << s3.get(2, 2) << endl;	// *
	cout << s1.count_access() << endl;	// 1
	cout << s2.count_access() << endl;	// 2
	cout << s3.count_access() << endl;	// 3

	// lp-07-27.cpp
	Screen<5, 5> myScreen('X');
	cout << endl << myScreen.move(4,0).set('#') << endl;

	return 0;
}