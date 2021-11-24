// 18/02/13 = Tue

// Exercise 11.7: Define a map for which the key is the family’s last name and the value is a vector of the children’s names. Write code to add new families and to add new children to an existing family.

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
using family = string;
using children = vector<string>;
using community = map<family, children>;

template<typename A>
void print(const A & a)
{
	for (const auto & p : a) {
		cout << p.first << ": ";
		for (const auto & e : p.second)
			cout << e << " ";
		cout << endl;
	}
}

int main()
{
	community it;
	family ms = "microsoft";
	family ap = "apple";
	it[ms].push_back("windows");
	it[ms].push_back("office");
	it[ap].push_back("mac");
	it[ap].push_back("iphone");
	print(it);
	return 0;
}
