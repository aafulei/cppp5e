// 18/02/25 = Sun

// Exercise 11.31: Write a program that defines a multimap of authors and their works. Use find to find an element in the multimap and erase that element. Be sure your program works correctly if the element you look for is not in the map.

// Exercise 11.32: Using the multimap from the previous exercise, write a program to print the list of authors and their works alphabetically.

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

using namespace std;
using author = string;
using work = string;

unsigned find_and_earse
(multimap<author, work> & mm, const pair<author, work> p)
{
	unsigned count = 0;
	// it would be an error to dereference off-the-end iterator
	for (auto it = mm.find(p.first); it != mm.end() && it->first == p.first; )
		if (it->second == p.second) {
			it = mm.erase(it);
			++count;
		}
		else
			++it;
	return count;
}

void process(multimap<author, work> & mm, const pair<author, work> p)
{
	cout << "Finding and erasing {" + p.first + ", " + p.second + "}: "
		<< find_and_earse(mm, p) << endl;
}

template<typename S>
void print(const set<S> & s)
{
	for (const auto & e : s)
		cout << "\"" << e << "\"" << " ";
	cout << endl;
}

template<typename S, typename T>
void print(const map<S, T> & m)
{
	for (const auto & e : m) {
		cout << "[" << e.first << "] ";
		print(e.second);
	}
	cout << endl;
}

template<typename S, typename T>
map<S, set<T>> convert(const multimap<S, T> & mm)
{
	map<S, set<T>> ms;
	for (const auto & kv : mm) {
		ms[kv.first].insert(kv.second);
	}
	return ms;
}

// Essentially, it is to convert a multimap<S, T> to a map<S, set<T>>.
void print(const multimap<author, work> & mm)
{
	auto ms = convert(mm);
	print(ms);
}

int main()
{
	multimap<author, work> mm = {{"Lippman", "C++ Primer"},
		{"Stroustrup", "C++"}, {"Stroustrup", "C++"},
		{"Stroustrup", "The C++ Programming Language"},
		{"Stroustrup", "A Tour of C++"},
		{"Meyers", "Effective C++"},
		{"Meyers", "Effective Modern C++"}};
	
	// Excercise 11.31: find and erase a particular work of an author
	const author kr = "Kernighan & Ritchie";
	const author s = "Stroustrup";
	const work c = "C";
	const work cpp = "C++";
	process(mm, {"", ""});				// should work on an empty pair
	process(mm, {kr, c});
	process(mm, {s, c});
	process(mm, {s, cpp});

	// Exercise 11.32: print authors and works alphabetically
	print(multimap<author, work>());	// should work on an empty multimap
	print(mm);

	return 0;
}