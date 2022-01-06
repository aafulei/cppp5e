// 18/03/25 = Sun
// 18/03/26 = Mon

// Exercise 16.28: Write your own versions of shared_ptr and unique_ptr.

/* ::::Starter::::

Consider the following program, which, when compiled with DEBUG_DELETE defined, will print: Call: DebugDelete() on i

#include "include\DebugDelete.h"
#include <memory>

int main()
{
	unique_ptr<int, DebugDelete> u(new int(42), DebugDelete());
	return 0;
}

*/

// To turn on debug info on deleter:
// g++ lp-16-28.cpp -D DEBUG_DELETE

// To turn it off:
// compile as usual

// To compare the behavior if the standard library version is used:
// g++ lp-16-28.cpp -D DEBUG_COMPARE
// Note: default deleters are different for unique_ptr in the two versions.

#ifndef DEBUG_COMPARE
	#include "include\smart_ptr.h"
#endif
#ifdef DEBUG_COMPARE
	#include <memory>
#endif

#include "include\DebugDelete.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
using svec = vector<string>;
using sptr = shared_ptr<svec>;
using uptr = unique_ptr<svec>;

int main()
{
	sptr p0(nullptr);
	cout << p0.unique() << endl;							// 0
	cout << p0.use_count() << endl;							// 0
	sptr p1(new svec({"a", "an", "the"}));
	cout << p1.use_count() << endl;							// 1
	cout << bool(p1) << endl;								// 1
	sptr p2 = p1;
	cout << p1.use_count() << endl;							// 2
	cout << p2.use_count() << endl;							// 2
	p0 = p0 = p1 = p1 = p2 = p2;
	cout << p0.use_count() << endl;							// 3
	cout << p0->size() << endl;								// 3
	cout << (*p1)[0] << endl;								// a
	cout << *p2->begin() << endl;							// a

	sptr p, q;
	q.reset(new svec({"this", "that"}), DebugDelete());
	p.swap(q);
	q.reset();

	uptr u;
	u.reset(new svec({"i", "it", "you"}));
	uptr v(new svec({"am", "is", "are"}));
	u.swap(v);
	v = nullptr;
	cout << u->operator[](0) << endl;						// am

	sptr x(std::move(u));
	cout << x->operator[](0) << endl;						// am

	/* ---------- postscript ----------
	
	Assume using our own version of smart pointers.

	Q:	How many times that DebugDelete() is called for the above code?

	A:	1. p0, p1, p2 use delete directly.
		2. p originally uses delete, but is swapped with q later, which uses DebugDelete(). So for p DebugDelete() is called.
		3. u and v both use DebugDelete(). However, the resource of u is later stolen by x, which also takes its deleter DebugDelete(). So for u and x DebugDelete() is called.
		4. Thus in total DebugDelete() is called for 3 times.

	----------------------------------- */

	return 0;
}