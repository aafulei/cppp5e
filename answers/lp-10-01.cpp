// 18/01/23 = Mon
// 18/02/21 = Wed: a templatized read()

// Exercise 10.1: The algorithm header defines a function named count that, like find, takes a pair of iterators and a value. count returns a count of how often that value appears. Read a sequence of ints into a vector and print the count of how many elements have a given value.

// To run, enter, for example, "a <data\digits" in command prompt.

#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::count;
using std::cout;
using std::endl;
using std::istream;
using std::vector;

template <typename C>
void read(istream & is, C & c)
{
	// need 'typename' before 'C:: value_type' because 'C' is a dependent scope
	for (typename C::value_type e; is >> e; c.push_back(e))
		;
}

template <typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << " ";
	cout << endl;
}

int main()
{
	vector<int> v;
	read(cin, v);
	print(v);
	for (int i = 0; i != 10; ++i)
		cout << i << ": " << count(v.cbegin(), v.cend(), i) << endl;
	return 0;
}

/* ---------- postscript ----------

> Explanation: Why do we need a typename in the for header?

Consider

template<typename T>
void foo()
{
	typename T::S * p;
}

With typename T::S, we confirm to the compiler that S is a type defined in the T scope. In this way, p is defined to be a pointer to the type T::S. Without typename, there would be ambiguity. It could also be that S is a static member in class T, and it multiplies with p. 

----------------------------------- */