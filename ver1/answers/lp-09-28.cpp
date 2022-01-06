// 18/01/17 = Wed
// 18/02/19 = Mon: add const to parameters

// Exercise 9.28: Write a function that takes a forward_list<string> and two additional string arguments. The function should find the first string and insert the second immediately following the first. If the first string is not found, then insert the second string at the end of the list.

#include <forward_list>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::forward_list;
using std::string;
using std::vector;

void insert(forward_list<string> & fl, const string & s1, const string & s2)
{
	decltype(fl.begin()) p, q;
	bool found = false;
	for (p = fl.before_begin(), q = fl.begin(); q != fl.end(); ++p, ++q) {
		if (*q == s1) {
			p = fl.insert_after(p, s2);
			found = true;
		}
	}
	if (!found)
		fl.insert_after(p, s2);
}

template<typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << " ";
	cout << endl;
}

void process(forward_list<string> & fl, const string & s1, const string & s2)
{
	cout << string(25, '-') << endl;
	print(fl);
	insert(fl, s1, s2);
	print(fl);
}

int main()
{
	const string s1 = "Harden";
	const string s2 = "James";
	vector<forward_list<string>> v = {{"Harden", "Harden"}, {}, {"Lebron"}};
	for (auto & fl : v)
		process(fl, s1, s2);
	return 0;
}