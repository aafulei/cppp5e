// 18/03/27 = Tue

// Exercise 16.49: Explain what happens in each of the following calls:

// template <typename T> void f(T);
// template <typename T> void f(const T *);
// template <typename T> void g(T);
// template <typename T> void g(T *);
// int i = 42, * p = &i;
// const int ci = 0, * p2 = &ci;
// g(42);  g(p);  g(ci);  g(p2);
// f(42);  f(p);  f(ci);  f(p2);

// Answer: See comment in the following program.

// Exercise 16.50: Define the functions from the previous exercise so that they print an identifying message. Run the code from that exercise. If the calls behave differently from what you expected, make sure you understand why.

#include<iostream>

using namespace std;

template <typename T> void f(T)
{
	clog << "Instantiate: f(T)" << endl;
}
template <typename T> void f(const T *)
{
	clog << "Instantiate: f(const T *)" << endl;
}
template <typename T> void g(T)
{
	clog << "Instantiate: g(T)" << endl;
}
template <typename T> void g(T *)
{
	clog << "Instantiate: g(T *)" << endl;
}

int i = 42, * p = &i;
const int ci = 0, * p2 = &ci;

int main()
{
	g(42);		// g(T)				T is int
	g(p);		// g(T *)			T is int
	g(ci);		// g(T)				T is const int
	g(p2);		// g(T *)			T is const int
	f(42);		// f(T)				T is int
	f(p);		// f(T)				T is const int *
	f(ci);		// f(T)				T is const int
	f(p2);		// f(const T *)		T is int
	return 0;
}

/* ---------- postscript ----------

	Q: Consider f(p). It is f(T) rather than f(const T *) that is instantiated. Why?

	A: Because f(const T *) would require binding a non-const int to a reference to const. Though the conversion is allowed, it is less good. Now f(T) is an exact match, though it is less specified than f(T *), if there is one.

----------------------------------- */
