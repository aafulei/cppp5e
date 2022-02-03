// 22/02/03 = Thu
// 18/02/08 = Thu

// Exercise 6.47: Revise the program you wrote in the exercises in § 6.3.2 (p. 228) that used recursion to print the contents of a vector to conditionally print information about its execution. For example, you might print the size of the vector on each call. Compile and run the program with debugging turned on and again with it turned off.

// Exercise 6.33: Write a recursive function to print the contents of a vector.

// To turn on debug information, compile as usual.
// To turn it off: g++ lp-06-47.cpp -D NDEBUG

#include <iostream>
#include <vector>

using std::clog;
using std::cout;
using std::endl;
using std::vector;

void recursive_print(vector<int>::iterator b, vector<int>::const_iterator e)
{
#ifndef NDEBUG
	clog << endl << "DEBUG: size of vector = " << (e - b) << endl;
#endif
	if (b == e)
		cout << endl;
	else {
		cout << *b++ << " ";
		recursive_print(b, e);
	}
}

int main()
{
	vector<int> vec {1, 2, 3, 4, 5};
	recursive_print(vec.begin(), vec.cend());
	return 0;
}

