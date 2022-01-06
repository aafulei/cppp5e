// 18/02/05 = Mon

// Question: Are there better ways other than this or using a goto?

// Exercise 5.25: Revise your program from the previous exercise to use a try block to catch the exception. The catch clause should print a message to the user and ask them to supply a new number and repeat the code inside the try.

// Exercise 5.24: Revise your program to throw an exception if the second number is zero. Test your program with a zero input to see what happens on your system if you don’t catch an exception.

// Exercise 5.23: Write a program that reads two integers from the standard input and prints the result of dividing the first number by the second.

#include <cctype>
#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
using std::toupper;

int main()
{
	for (int a, b; cout << "Enter two integers: ", cin >> a >> b; ) {
		try {
			if (b == 0)
				throw runtime_error("Division by 0.");
			cout << a << " / " << b << " = " << a / b << endl;
			break;
		}
		catch (runtime_error err) {
			cout << err.what() << " Try again? Enter (Y)es or (N)o: ";
			char c;
			cin >> c;
			cin.ignore(256, '\n');
			if (!cin || toupper(c) != 'Y')
				break;
		}
	}
	return 0;
}