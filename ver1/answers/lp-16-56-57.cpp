// 18/03/28 = Wed

// Exercise 16.56: Write and test a variadic version of errorMsg.

// Modified from lp-16-48.cpp
 
// Exercise 16.57: Compare your variadic version of errorMsg to the error_msg function in § 6.2.6 (p. 220). What are the advantages and disadvantages of each approach?

// void error_msg(ErrCode e, initializer_list<string> il)
// {
// 	cout << e.msg() << ": ";
// 	for (const auto &elem : il)
// 		cout << elem << " " ;
// 	cout << endl;
// }

// Answer: The variadic template allows the arguments to have different types, but it is harder to write, which usually involves recursion.

// To turn on debug info: g++ lp-16-56-57.cpp -D DEBUG
// To turn it off: compile as usual

#include "include\debug_rep.h"
#include "source\debug_rep.cpp"
#include <iostream>
using namespace std;

template <typename T> ostream & print(ostream &, const T &);

template<typename T, typename ... A>
ostream & print(ostream & os, const T & t, const A & ... a)
{
	os << t << ", ";
	return print(os, a ...);
}

template <typename T>
ostream & print(ostream & os, const T & t)
{
	return os << t << endl;
}

// return type: ostream & (as in textbook) => void
template<typename ... A>
void errorMsg(ostream & os, const A & ... a)
{
	print(os, debug_rep(a) ...);
}

int main()
{
	char a[] = "Hello";
	string s = "World";
	int i = 42;
	double * n = nullptr;
	//"Hello", "World", 42, Pointer: 42, Pointer: nullptr
	errorMsg(cerr, a, s, i, &i, n);
	return 0;
}

