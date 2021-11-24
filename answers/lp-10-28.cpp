// 18/02/22 = Thu

// Exercise 10.28: Copy a vector that holds the values from 1 to 9 inclusive, into three other containers. Use an inserter, a back_inserter, and a front_inserter, respectivly to add elements to these containers. Predict how the output sequence varies by the kind of inserter and verify your predictions by running your programs.

// To run, enter, for example, "a <data\digits" in command prompt.

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std;

template<typename C>
void read(istream & is, C & c)
{
	for (typename C::value_type e; is >> e; c.push_back(e))
		;
}

template<typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << " ";
	cout << endl;
}

int main()
{
	vector<int> u, v;
	deque<int> d;
	list<int> l;

	read(cin, u);
	print(u);	
	auto b = u.cbegin(), e = u.cend();

	// inserter
	copy(b, e, inserter(d, d.begin()));
	print(d);

	// back_inserter
	copy(b, e, back_inserter(v));
	print(v);
	
	// front_inserter
	copy(b, e, front_inserter(l));
	print(l);
	
	return 0;
}