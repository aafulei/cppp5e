// 17/10/20 = Fri

// Exercise 3.7: What would happen if you define the loop control variable in the previous exercise as type char? Predict the results and then change your program to use a char to see if you were right.

// Answer: The string will not be changed.

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
	string str = "Hello, World!";
	cout << str << endl;
	for (char c : str)
		c = 'X';
	cout << str << endl;
	return 0;
}