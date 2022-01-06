// 18/02/10 = Sat

// Exercise 7.23: Write your own version of the Screen class.
 
// Exercise 7.24: Give your Screen class three constructors: a default constructor; a constructor that takes values for height and width and initializes the contents to hold the given number of blanks; and a constructor that takes values for height, width, and a character to use as the contents of the screen.

// Also add: mutable private data member access_counter

#include <cstddef>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::size_t;
using std::string;

class Screen
{
	using pos = string::size_type;
	string contents;
	pos cursor = 0;
	pos width = 0;
	pos height = 0;
	mutable size_t access_counter = 0;
public:
	Screen() = default;
	Screen(pos w, pos h) : width(w), height(h),
						   contents(w * h, ' ') {}
	Screen(pos w, pos h, char c) : width(w), height(h),
								   contents(w * h, c) {}
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
	Screen & move(pos nr, pos nc);
	size_t count_access() const
	{
		return access_counter;
	}
};

inline Screen & Screen::move(pos nr, pos nc)
{
	++access_counter;
	cursor = nr * width + nc;
	return *this;
}

int main()
{
	Screen s1;
	Screen s2(3, 4);
	Screen s3(3, 4, '*');
	cout << s1.empty() << endl;		// 1
	cout << s2.empty() << endl;		// 0
	cout << s3.empty() << endl;		// 0
	cout << s2.get(1, 1) << endl;	// 
	cout << s3.get() << endl;		// *
	cout << s3.get(2, 2) << endl;	// *
	cout << s1.count_access() << endl;	// 1
	cout << s2.count_access() << endl;	// 2
	cout << s3.count_access() << endl;	// 3
	return 0;
}
