// 18/02/06 = Tue

// Exercise 6.7: Write a function that returns 0 when it is first called and then generates numbers in sequence each time it is called again.

#include <iostream>

using std::cout;
using std::endl;

unsigned call()
{
	static int c;
	return c++;
}

int main()
{
	for (int i = 0; i < 10; ++i)
		cout << call() << endl;
	return 0;
}