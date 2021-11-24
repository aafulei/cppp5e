// 18/03/13 = Tue

// Exercise 14.27: Add increment and decrement operators to your StrBlobPtr class.

// Exercise 14.28: Define addition and subtraction for StrBlobPtr so that these operators implement pointer arithmetic (§ 3.5.3, p. 119).

// Exercise 14.29: We did not define a const version of the increment and decrement operators. Why not?

// Answer: By declaring a member function const, we bind the object to a pointer-to-const, by which we promise not to change the state of the object. However, increment and decrement changes the state of an object.

// Exercise 14.30: Add dereference and arrow operators to your StrBlobPtr class and to the ConstStrBlobPtr class that you defined in exercise 12.22 from § 12.1.6 (p. 476). Note that the operators in constStrBlobPtr must return const references because the data member in constStrBlobPtr points to a const vector.

// Exercise 14.31: Our StrBlobPtr class does not define the copy constructor, assignment operator, or a destructor. Why is that okay?

// Answer: Becasue the synthesized copy-control members do the jobs exactly as we want. Note that StrBlobPtr by definition acts like a pointer, and what we want is just memberwise copy and assignment.

// Exercise 14.32: Define a class that holds a pointer to a StrBlobPtr. Define the overloaded arrow operator for that class.

#include "include\StrBlob.h"
#include "include\StrBlobPtr.h"
#include "source\StrBlob.cpp"
#include "source\StrBlobPtr.cpp"
#include <algorithm>	// for std::transform
#include <cctype>		// for ::toupper
#include <iostream>
#include <string>
#include <utility>		// for std::swap

using namespace std;

class StrBlobPtrPtr
{
	StrBlobPtr * p;
public:
	StrBlobPtrPtr(StrBlobPtr sbp) : p(&sbp) {}
	StrBlobPtr & operator*()  const			{ return *p;}
	StrBlobPtr * operator->() const 		{ return p;	}
};

class NestedPtr
{
	StrBlobPtr * p;
public:
	NestedPtr(StrBlobPtr sbp) : p(&sbp)		{}
	StrBlobPtr operator->() const 			{ return *p;}
	// Alternatively:
	// StrBlobPtr & operator->() const 		{ return *p;}
};

void line()
{
	cout << string(50, '-') << endl;
}

int main()
{
	StrBlob sb = {"a", "an", "the", "that", "these", "theirs"};

	for (auto it = sb.begin(); it != sb.end(); ++it)// it is a StrBlobPtr
		cout << *it << endl;
	line();

	auto it = sb.cend() - 1;						// it is a ConstStrBlobPtr
	do
		cout << *it << endl;
	while (it-- != sb.cbegin());
	line();

	cout << "There are " << sb.cend() - sb.cbegin() << " words in { ";
	for (const auto & s : sb)
		cout << s << " ";
	cout << "}" << endl;
	line();

	for (auto it = sb.cbegin(); it != sb.cend(); ++it)
		cout << it->size() << endl;
	line();

	for (auto it = sb.begin(); it != sb.end(); ++it)
		transform(it->cbegin(), it->cend(), it->begin(), ::toupper);
	for (const auto & s : sb)
		cout << s << endl;
	line();

	for (auto it = sb.begin(), it2 = sb.end() - 1;
		it != sb.begin() + (sb.end() - sb.begin()) / 2; ++it, --it2)
		swap(*it, *it2);
	for (const auto & s : sb)
		cout << s << endl;
	line();

	StrBlobPtrPtr pp(sb.begin());
	cout << pp->derefer() << " has "
		 << (*pp)->size() << " letters." << endl;
	line();
	
	NestedPtr np(sb.end() - 3);
	cout << *(np.operator->()) << " has "
		 << np->size() << " letters." << endl;

	return 0;
}
