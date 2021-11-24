// 18/02/22 = Thu

// Exercise 10.21: Write a lambda that captures a local int variable and decrements that variable until it reaches 0. Once the variable is 0 additional calls should no longer decrement the variable. The lambda should return a bool that indicates whether the captured variable is 0.

// Since the local variable is a (signed) int, should say "Once the variable is <= 0 ...", in order to avoid endless loop.

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int i = 10;
	auto f = [&i]() -> bool			// -> bool can be omitted
			 {
			 	if (i > 0) {
			 		--i;
			 		return false;
			 	}
			 	else
			 		return true;
			 };
	do
		cout << i << endl;			// count down from 10 to 0
	while (!f());
	return 0;
}