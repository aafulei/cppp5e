// 18/02/08 = Thu

// Exercise 6.51: Write all four versions of f. Each function should print a distinguishing message. Check your answers for the previous exercise. If your answers were incorrect, study this section until you understand why your answers were wrong.

#include <iostream>

using std::clog;
using std::endl;

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

void f()
{
	#ifndef NDEBUG
	clog << __func__ << " @ Line " << __LINE__ << endl;
	#endif
}

void f(int)
{
	#ifndef NDEBUG
	clog << __func__ << " @ Line " << __LINE__ << endl;
	#endif
}

void f(int, int)
{
	#ifndef NDEBUG
	clog << __func__ << " @ Line " << __LINE__ << endl;
	#endif
}

void f(double, double)
{
	#ifndef NDEBUG
	clog << __func__ << " @ Line " << __LINE__ << endl;
	#endif
}

int main()
{
	f(42);
	f(42, 0);
	f(2.56, 3.14);
	return 0;
}
