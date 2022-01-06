// 18/02/05 = Mon

// Exercise 5.23: Write a program that reads two integers from the standard input and prints the result of dividing the first number by the second.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	cout << "Enter two integers: ";
	int a, b;
	cin >> a >> b;
	cout << a << " / " << b << " = " << a / b;
	return 0;
}