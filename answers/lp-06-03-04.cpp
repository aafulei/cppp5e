// 18/02/06 = Tue

// Exercise 6.3: Write and test your own version of fact.

// Exercise 6.4: Write a function that interacts with the user, asking for a number and generating the factorial of that number. Call this function from main.

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::invalid_argument;

// Question: Can we define n as an unsigned short?
// Answer: Yes, because (n * fact(n-1)) converts n into unsigned long long.
unsigned long long fact(unsigned short n)
{
	return n == 0 ? 1ULL : n * fact(n-1);
}

void generate()
{
	for (unsigned short n; cout << "Enter an integer n: ", cin >> n; ) {
		// Note: Curly braces cannot be omitted following try and catch.
		try {
			if (n > 20)
				throw invalid_argument("Invalid argument: n must be in [0, 20].");
			else
				cout << n << "! = " << fact(n) << endl;
		}
		catch (invalid_argument err) {
			cout << err.what() << endl;
		}
	}
}

int main()
{
	generate();
	return 0;
}