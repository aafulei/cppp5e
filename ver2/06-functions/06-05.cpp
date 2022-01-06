// 21/12/26 = Sun
// 18/02/06 = Tue

// Exercise 6.5: Write a function to return the absolute value of its argument.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

double abs(double x)
{
	return x >= 0 ? x : -x;
}

int main()
{
	for (double x;
		cout << "Enter a number: ", cin >> x, cin.ignore(256, '\n');
		cout << "|" << x << "| = " << abs(x) << endl)
			;
	return 0;
}
