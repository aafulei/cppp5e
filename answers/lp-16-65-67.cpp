// 18/03/28 = Wed

// Exercise 16.65: In § 16.3 (p. 698) we defined overloaded two versions of debug_rep one had a const char* and the other a char* parameter. Rewrite these functions as specializations.

// Exercise 16.66: What are the advantages and disadvantages of overloading these debug_rep functions as compared to defining specializations?

// Answer:
// Pros: Do not affect function matching. Consistency in using one template.
// Cons: Error-prone as we have to take care of order of declarations.

// Exercise 16.67: Would defining these specializations affect function matching for debug_rep? If so, how? If not, why not?

// Answer: No. "When we define a function template specialization, we are essentially taking over the job of the compiler. That is, we are supplying the definition to use for a specific instantiation of the original template. It is important to realize that a specialization is an instantiation; it is not an overloaded instance of the function name. Specializations instantiate a template; they do not overload it. As a result, specializations do not affect function matching."

// To enable speicalization and disable non-template versions:
// g++ lp-16-65-67.cpp -D SPEC

// To turn on debug info:
// g++ lp-16-65-67.cpp -D SPEC -D DEBUG

#include "include\debug_rep.h"
#include "source\debug_rep.cpp"
#include <iostream>

using namespace std;

int main()
{
	char a[] = "Hello";
	cout << debug_rep(a) << endl;		// debug_rep(char *)
	cout << debug_rep("Hi") << endl;	// debug_rep(const char *)
	return 0;
}