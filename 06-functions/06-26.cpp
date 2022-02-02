// 22/02/02 = Wed
// 18/02/07 = Wed

// Exercise 6.26: Write a program that accepts the options presented in this section. Print the values of the arguments passed to main.

#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char ** argv)
{
	for (int i = 1; i < argc; ++i)
		// convert argv[i] to string so that concatenation is easy
		cout << string(argv[i]) + " ";
	cout << endl;
	return 0;
}
