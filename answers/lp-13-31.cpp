// 18/03/04 = Sun

// Exercise 13.31: Give your class a < operator and define a vector of HasPtrs. Give that vector some elements and then sort the vector.

// Built incrementally on lp-13-30.cpp

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class HasPtr
{
	string * ps;
	int i;
	static int swap_count;
public:
	HasPtr(const string & s = string()) : ps(new string(s)), i(0) { }
	HasPtr(const HasPtr & hp) : ps(new string(*hp.ps)), i(hp.i) { }
	HasPtr & operator=(HasPtr hp)
	{
		swap(*this, hp);
		return *this;
	}
	~HasPtr()
	{
		delete ps;
	}
	bool operator<(const HasPtr & hp)
	{
		return *ps < *hp.ps;
	}
friend
	void swap(HasPtr & lhs, HasPtr & rhs);
friend
	void print(const HasPtr & hp);
};

int HasPtr::swap_count = 0;

void swap(HasPtr & lhs, HasPtr & rhs)
{
	clog << "swap " << ++HasPtr::swap_count << endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

void print(const HasPtr & hp)
{
	cout << *hp.ps << " ";
}

int main()
{
	HasPtr a("a");
	HasPtr b("b");
	HasPtr c("c");
	HasPtr d("d");
	HasPtr e("e");
	vector<HasPtr> v = { e, c, b, a, d };
	for (const auto & e : v)	// e c b a d
		print(e);
	cout << endl;
	sort(v.begin(), v.end());
	for (const auto & e : v)	// a b c d e
		print(e);
	return 0;
}