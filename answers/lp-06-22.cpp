// 18/02/06 = Tue

// Exercise 6.22: Write a function to swap two int pointers.

#include <iostream>

using std::cout;
using std::endl;

void swap_by_ref(int *& r, int *& s)
{
	int * t = r;
	r = s;
	s = t;
}

void swap_by_ptr(int ** r, int ** s)
{
	int * t = *r;
	*r = *s;
	*s = t;
}

int main()
{
	int a[] = {42, 24};
	int * p = a, * q = a + 1;
	cout << "p points to " << *p << endl;
	cout << "q points to " << *q << endl;

	cout << "swapping ..." << endl;
	swap_by_ref(p, q);
	cout << "p points to " << *p << endl;
	cout << "q points to " << *q << endl;

	cout << "swapping ..." << endl;
	swap_by_ptr(&p, &q);
	cout << "p points to " << *p << endl;
	cout << "q points to " << *q << endl;

	return 0;
}