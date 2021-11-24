// 18/02/07 = Wed

// Exercise 6.25: Write a main function that takes two arguments. Concatenate the supplied arguments and print the resulting string.

#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char ** argv)
{
	if (argc != 3) {
		cerr << "Error: Require two arguments!" << endl;
		return -1;
	}
	// convert argv[] to string so that concatenation is easy
	cout << string(argv[1]) + " " + string(argv[2]) << endl;
	return 0;
}