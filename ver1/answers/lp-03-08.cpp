// 17/10/20 = Fri

// Exercise 3.8: Rewrite the program in the first exercise, first using a while and again using a traditional for loop. Which of the three approaches do you prefer and why?

// Answer: I prefer the range-for approach because it avoids out-of-range subscripting.

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
	// using a while
	string str = "Hello, World!";
	cout << str << endl;
	decltype (str.size()) index = 0;	// index is a string::size_type
	while (index < str.size()) {
		str[index] = 'X';
		index += 1;
	}
	cout << str << endl;

	// using a traditional for loop
	str = "Hello, World!";
	cout << str << endl;
	for (string::size_type i = 0; i < str.size(); ++i)
		str[i] = 'X';
	cout << str << endl;

	return 0;
}