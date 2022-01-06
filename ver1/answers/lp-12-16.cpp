// 18/02/28 = Wed

// Exercise 12.16: Compilers don’t always give easy-to-understand error messages if we attempt to copy or assign a unique_ptr. Write a program that contains these errors to see how your compiler diagnoses them.

// Answer: Compilation error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]'.

#include <memory>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	unique_ptr<int> p(new int(42));
	// unique_ptr<int> q(p);			// no copy
	// unique_ptr<int> r; r = p;		// no assignment
	return 0;
}