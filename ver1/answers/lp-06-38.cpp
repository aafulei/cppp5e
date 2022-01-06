// 18/02/07 = Wed

// Exercise 6.38: Revise the arrPtr function on to return a reference to the array.

// int odd[] = {1,3,5,7,9};
// int even[] = {0,2,4,6,8};
// returns a pointer to an array of five int elements
// decltype(odd) *arrPtr(int i)
// {
//     return (i % 2) ? &odd : &even; // returns a pointer to the array
// }

#include <iostream>

using std::cout;
using std::endl;

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

decltype((odd)) arrRef(int i)
{
	return (i % 2) ? odd : even;
}

// access and print out doubled arrays:
// 0 4 8 12 16
// 2 6 10 14 18
int main()
{
	for (auto i : arrRef(0))
		cout << (i *= 2) << " ";
	cout << endl;
	for (auto i : arrRef(1))
		cout << (i *= 2) << " ";
	cout << endl;
}