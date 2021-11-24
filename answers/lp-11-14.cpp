// 18/02/24 = Sat

// Exercise 11.14: Extend the map of children to their family name that you wrote for the exercises in § 11.2.1 (p. 424) by having the vector store a pair that holds a child’s name and birthday.

// Exercise 11.7: Define a map for which the key is the family’s last name and the value is a vector of the children’s names. Write code to add new families and to add new children to an existing family.

// Modified from lp-11-07.cpp

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using family = string;
using children = vector<pair<string, string>>;
using community = map<family, children>;

void print(const community & c)
{
	for (const auto & f : c) {
		cout << f.first << ": ";
		for (const auto & child : f.second)
			cout << child.first << "(" << child.second << ")" << " ";
		cout << endl;
	}
}

int main()
{
	community it;
	family ms = "microsoft";
	family ap = "apple";
	// Question: Cannot write it[ms].push_back("windows", "1985/11/20"); Why?
	// Answer: This has nothing to with explicit/implicit conversion. Just that how can you supply two arguments in a pair of parenthese when it only asks one.
	// For example, consider void foo(string);
	// A string can be constructed like string(10, 'c').
	// But can you call foo(10, 'c')? Of course not.
	it[ms].push_back(pair<string, string>("windows", "1985/11/20"));
	it[ms].push_back(make_pair("office", "1990/11/19"));
	it[ap].push_back({"mac", "1984/01/24"});
	it[ap].emplace_back("iphone", "2007/01/09");
	print(it);
	return 0;
}