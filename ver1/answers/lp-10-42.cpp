// 18/02/23 = Fri

// Exercise 10.42: Reimplement the program that eliminated duplicate words that we wrote in § 10.2.3 (p. 383) to use a list instead of a vector.

// void elimDups(vector<string> & words)
// {
//     sort(words.begin(), words.end());
//     auto end_unique = unique(words.begin(), words.end());
//     words.erase(end_unique, words.end());
// }

// To run, enter, for example, "a <data\how" or "a <data\summer" in command prompt.

#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

template <typename C>
void read(istream & is, C & c)
{
	for (typename C::value_type e; is >> e; c.push_back(e))
		;
}

template <typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << " ";
	cout << endl;
}

void elimDups(list<string> & words)
{
	words.sort();
	words.unique();
}

void process(list<string> & words)
{
	read(cin, words);
	print(words);
	elimDups(words);
	print(words);
}

int main()
{
	list<string> v;
	process(v);
	return 0;
}