// 21/12/26 = Sun
// 18/02/06 = Tue

// Exercise 6.11: Write and test your own version of reset that takes a reference.

#include <iostream>

using std::cout;
using std::endl;

void reset(int &i)
{
	i = 0;
}

int main()
{
	int i = 42;
	cout << i << endl;
	reset(i);
	cout << i << endl;
	return 0;
}
