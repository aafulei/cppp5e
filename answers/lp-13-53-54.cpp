// 18/03/10 = Sat

// Exercise 13.53: As a matter of low-level efficiency, the HasPtr assignment operator is not ideal. Explain why. Implement a copy-assignment and move- assignment operator for HasPtr and compare the operations executed in your new move-assignment operator versus the copy-and-swap version.

// Copy-and-swap version:
// class HasPtr {
// public:
// 	HasPtr(HasPtr && hp) noexcept : ps(hp.ps), i(hp.i)
// 	{
// 		hp.ps = 0;
// 	}
// 	HasPtr& operator=(HasPtr rhs)
// 	{
// 		swap(*this, rhs);
// 		return *this;
// 	}
// 	// ......
// };

// Answer: Consider hp = std::move(hp2);. In the copy-and-swap version, the pointer ps and the int i are copied twice: once from std::move(hp2) to rhs, and once from rhs to hp, as a result of calling swap(). If we implement a move-assignment for HasPtr, the time of copy can be brought down to 1.

// Exercise 13.54: What would happen if we defined a HasPtr move-assignment operator but did not change the copy-and-swap operator? Write code to test your answer.

// Answer: Ambiguity overload.

// Built incrementally on lp-13-30.cpp

// To turn on copy-and-swap assignment and show debug info:
// g++ lp-13-53-54.cpp -D DEBUG_COPY_AND_SWAP

// To turn on move-assignment operator and show debug info:
// g++ lp-13-53-54.cpp -D DEBUG_MOVE_ASSIGN

// To turn on move-assignment without showing debug info:
// g++ lp-13-53-54.cpp

#include <iostream>
#include <string>
#include <utility>			// for std::swap() and std::move()

#ifdef DEBUG_COPY_AND_SWAP
#define DEBUG
#endif

#ifdef DEBUG_MOVE_ASSIGN
#define DEBUG
#endif

using namespace std;

class HasPtr
{
	string * ps;
	int i;
public:
	HasPtr(const string & s = string()) : ps(new string(s)), i(0) { }
	HasPtr(const HasPtr & hp) : ps(new string(*hp.ps)), i(hp.i)
	{
#ifdef DEBUG
		clog << "Call: copy constructor" << endl;
#endif
	}
	HasPtr(HasPtr && hp) noexcept : ps(hp.ps), i(hp.i)
	{
#ifdef DEBUG
		clog << "Call: move constructor" << endl;
#endif
		hp.ps = 0;
	}
#ifdef DEBUG_COPY_AND_SWAP
	HasPtr & operator=(HasPtr rhs)
	{
		clog << "Call: copy-and-swap assignment" << endl;
		swap(*this, rhs);
		return *this;
	}
#endif
#ifndef DEBUG_COPY_AND_SWAP
	HasPtr & operator=(const HasPtr & hp)
	{
#ifdef DEBUG_MOVE_ASSIGN
		clog << "Call: copy-assignment operator" << endl;
#endif
		auto pt = new string(*hp.ps);
		delete ps;
		ps = pt;
		i = hp.i;
		return *this;
	}
	HasPtr & operator=(HasPtr && hp) noexcept
	{
#ifdef DEBUG_MOVE_ASSIGN
		clog << "Call: move-assignment operator" << endl;
#endif
		if (this != &hp) {
			ps = hp.ps;
			i = hp.i;
			hp.ps = nullptr;
		}
		return *this;
	}
#endif
	~HasPtr()
	{
		delete ps;
	}
friend
	void swap(HasPtr & lhs, HasPtr & rhs);
friend
	void print(const HasPtr & hp);
};

void swap(HasPtr & lhs, HasPtr & rhs)
{
#ifdef DEBUG
	clog << "Call: swap(HasPtr &, HasPtr &)" << endl;
#endif
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

void print(const HasPtr & hp)
{
	cout << *hp.ps << endl;
}

int main()
{
	HasPtr a("Hello");
	HasPtr b("World");
	HasPtr c;
	c = std::move(b);
	b = std::move(a);
	print(b);			// Hello
	print(c);			// World
	return 0;
}

/* ---------- postscript ----------

Result ifdef DEBUG_COPY_AND_SWAP

Call: move constructor
Call: copy-and-swap assignment
Call: swap(HasPtr &, HasPtr &)
Call: move constructor
Call: copy-and-swap assignment
Call: swap(HasPtr &, HasPtr &)
Hello
World

Result ifdef DEBUG_MOVE_ASSIGN

Call: move-assignment operator
Call: move-assignment operator
Hello
World

*/