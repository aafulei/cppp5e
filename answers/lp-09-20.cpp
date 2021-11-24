// 18/01/17 = Wed

// Exercise 9.20: Write a program to copy elements from a list<int> into two deques. The even-valued elements should go into one deque and the odd ones into the other.

// To run, enter, for example, "a <data\digits" in command prompt.

#include <deque>
#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::list;

template<typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << " ";
	cout << endl;
}

int main()
{
	list<int> lst;
	for (int i; cin >> i; lst.push_back(i))
		;
	print(lst);
	deque<int> even, odd;
	for (auto it = lst.cbegin(); it != lst.cend(); ++it) {
		if (*it % 2 == 0)
			even.push_back(*it);
		else
			odd.push_back(*it);
		// alternatively:
		// (*it % 2 == 0 ? even : odd).push_back(*it);
	}
	cout << "Even:\t";
	print(even);
	cout << "Odd:\t";
	print(odd);
	return 0;
}