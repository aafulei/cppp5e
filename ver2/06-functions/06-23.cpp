// 21/12/26 = Sun
// 18/02/06 = Tue

// Exercise 6.23: Write your own versions of each of the print functions presented in this section. Call each of these functions to print i and j defined as follows:

// int i = 0, j[2] = {0, 1};

#include <cstddef>
#include <iostream>
#include <iterator>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::size_t;

void print(const int *);
void print(const int * b, const int * e);
void print(const int * a, size_t n);
void print(int (&a)[2]);

void print(const int * p)
{
	cout << *p << endl;
}

void print(const int * b, const int * e)
{
	for (const int * p = b; p != e; ++p)
		cout << *p << " ";
	cout << endl;
}

void print(const int * a, size_t n)
{
	for (size_t i = 0; i != n; ++i)
		cout << a[i] << " ";
	cout << endl;
}

void print(int (&a)[2])
{
	for (int i = 0; i < 2; ++i)
		cout << a[i] << " ";
	cout << endl;
}

template<size_t N>
void print(int (&a)[N])
{
	for (auto i : a)
		cout << i << " ";
	cout << endl;
}

int main()
{
	int i = 0, j[2] = {0, 1};
	print(&i);
	print(begin(j), end(j));
	print(j);
	print<>(j);	// call template function
	return 0;
}
