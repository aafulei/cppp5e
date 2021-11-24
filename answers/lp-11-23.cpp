// 18/02/25 = Sun

// Exercise 11.23: Rewrite the map that stored vectors of children’s names with a key that is the family last name for the exercises in § 11.2.1 (p. 424) to use a multimap.

// Exercise 11.7: Define a map for which the key is the family’s last name and the value is a vector of the children’s names. Write code to add new families and to add new children to an existing family.

// Modified from lp-11-07.cpp

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
using family = string;
// change from children(vector<string>) to child(string)
using child = string;
using community = multimap<family, child>;

template<typename A>
void print(const A & a)
{
	for (const auto & p : a)
		cout << p.first << ": " << p.second << endl;
}

int main()
{
	community it;
	// There is no operator[] for a multimap.
	family ms = "microsoft";
	family ap = "apple";
	it.insert({ms, "windows"});
	it.insert({ms, "office"});
	it.insert({ap, "mac"});
	it.insert({ap, "iphone"});
	print(it);
	return 0;
}
