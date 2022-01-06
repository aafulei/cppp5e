// 18/03/10 = Sat

// Exercise 13.58:  Write versions of class Foo with print statements in their sorted functions to test your answers to the previous two exercises.

// Exercise 13.56: What would happen if we defined sorted as:
// Foo Foo::sorted() const &
// {
//     Foo ret(*this);
//     return ret.sorted();
// }

// Exercise 13.57: What if we defined sorted as:
// Foo Foo::sorted() const &
// {
//     return Foo(*this).sorted();
// }

// To complie as usual:
// g++ lp-13-58.cpp

// To complie with definition in Exercise 13.56: (will lead to stack overflow)
// g++ lp-13-58.cpp -D EXERCISE_13_56

// To complie with definition in Exercise 13.57:
// g++ lp-13-58.cpp -D EXERCISE_13_57

// To run, enter, for example, "a <data\digits" in command prompt.

#include <algorithm>
#include <iostream>
#include <vector>

#ifdef EXERCISE_13_56
#define UNUSUAL
#endif

#ifdef EXERCISE_13_57
#define UNUSUAL
#endif

using namespace std;

class Foo
{
	vector<int> data;
public:
	Foo(vector<int> data) : data(data) {}
	Foo sorted() &&;
	Foo sorted() const &;
friend
	ostream & operator<<(ostream & os, const Foo & foo)
	{
		for (auto i : foo.data)
			os << i << " ";
		return os;
	}
};

Foo Foo::sorted() &&
{
	clog << "Call: Foo Foo::sorted() &&" << endl;
	sort(data.begin(), data.end());
	return *this;
}

Foo Foo::sorted() const &
{
	clog << "Call: Foo Foo::sorted() const &" << endl;
#ifndef UNUSUAL
	Foo result(*this);
	sort(result.data.begin(), result.data.end());
	return result;
#endif
#ifdef EXERCISE_13_56
	Foo ret(*this);
    return ret.sorted();
#endif
#ifdef EXERCISE_13_57
	return Foo(*this).sorted();
#endif
}

ostream & operator<<(ostream & os, const Foo & foo);

int main()
{
	vector<int> v;
	for (int i; cin >> i; v.push_back(i))
		;
	Foo a(v);
	cout << a << endl;
	auto b = a.sorted();
	cout << b << endl;
	cout << Foo(v).sorted() << endl;
}