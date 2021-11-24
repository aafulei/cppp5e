// 18/03/27 = Tue

// Exercise 16.45: Given the following template, explain what happens if we call g on a literal value such as 42. What if we call g on a variable of type int?

// template <typename T> void g(T&& val) { vector<T> v; }

// Answer: 
// 1. 	If we call on 42, then T is int and val is an rvalue reference.
// 		An empty vector<int> will be default constructed.
// 2. 	If we call on an int, then T is int & and val is an int &, too.
// 		The instantiation will fail because a reference is not an object, and we cannot have a vector of references.

#include <vector>

using namespace std;

int i = 42;

template <typename T> void g(T&& val) { vector<T> v; }

int main()
{
	g(42);
	// g(i);	// instantiation would fail if we called
	return 0;
}