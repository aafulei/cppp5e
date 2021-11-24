// 18/02/07 = Wed

// Exercise 6.33: Write a recursive function to print the contents of a vector.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// Options for parameters:
// 1.	vector and one iterator;
// 2.	two iterators.
// Option 2 is preferred to follow the convetion of an iterator range.
void recursive_print(vector<int>::iterator b, vector<int>::const_iterator e)
{
	if (b == e)
		cout << endl;
	else {
		cout << *b++ << " ";
		recursive_print(b, e);
	}
}

int main()
{
	vector<int> vec {1, 2, 3, 4, 5};
	recursive_print(vec.begin(), vec.cend());
	return 0;
}