// 17/10/20 = Fri

// Exercise 3.6: Use a range for to change all the characters in a string to X.

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
	string str = "Hello, World!";
	cout << str << endl;
	for (auto &c : str)
		c = 'X';
	cout << str << endl;
	return 0;
}