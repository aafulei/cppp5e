// 17/10/25 = Wed
// 18/01/16 = Tue: redo
// 18/02/18 = Sun: a concise *b++

// Exercise 9.4: Write a function that takes a pair of iterators to a vector<int> and an int value. Look for that value in the range and return a bool indicating whether it was found.

#include <iostream>
#include <vector>

using std::boolalpha;
using std::cout;
using std::endl;
using std::vector;

bool find(vector<int>::const_iterator b, vector<int>::const_iterator e, int val)
{
	while (b != e)
		if (*b++ == val)
			return true;
	return false;
}

int main()
{
	vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int>::const_iterator b = vec.cbegin();
	vector<int>::const_iterator e = vec.cend();
	cout << boolalpha;
	cout << find(b, e, 0) << endl;	// true
	cout << find(b, e, 9) << endl;	// true
	cout << find(b, e, 10) << endl;	// false
	cout << find(b, e, 42) << endl;	// false
	return 0;
}