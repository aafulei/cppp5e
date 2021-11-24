// 18/02/05 = Mon

// Exercise 5.24: Revise your program to throw an exception if the second number is zero. Test your program with a zero input to see what happens on your system if you don’t catch an exception.

// Exercise 5.23: Write a program that reads two integers from the standard input and prints the result of dividing the first number by the second.

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
	cout << "Enter two integers: ";
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw runtime_error("Division by 0.");
	cout << a << " / " << b << " = " << a / b << endl;
	return 0;
}