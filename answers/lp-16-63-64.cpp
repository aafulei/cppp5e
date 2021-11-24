// 18/03/28 = Wed

// Exercise 16.63: Define a function template to count the number of occurrences of a given value in a vector. Test your program by passing it a vector of doubles, a vector of ints, and a vector of strings.

// Exercise 16.64: Write a specialized version of the template from the previous exercise to handle vector<const char*> and a program that uses this specialization.

#include <cstddef>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

using namespace std;

template<typename A, typename B> void print(const map<A, B> &);	// more specialized
template<typename C> void print(const C &);

template<typename T>
void count(const vector<T> & v)
{
	map<T, size_t> m;
	for (const auto & e : v)
		++m[e];
	print(m);
}

// specialization
template<>
void count(const vector<const char *> & v)
{
	map<string, size_t> m;
	for (const auto & e : v)
		++m[string(e)];
	print(m);
}

template<typename A, typename B>
void print(const map<A, B> & m)
{
	for (const auto & e : m)
		cout << e.first << ":\t" << e.second << endl;
}

template<typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << " ";
	cout << endl;
}

template<typename V>
void process(const V & v)
{
	print(v);
	count(v);
}

int main()
{
	vector<int> ivec = {2, 0, 1, 8, 0, 1, 2, 3, 1, 1, 0, 0};
	vector<double> dvec(ivec.cbegin(), ivec.cend());
	vector<string> svec = {"how", "now", "now", "now", "brown", "cow", "cow"};
	vector<const char *> cvec;
	for (const auto & s : svec)
		cvec.push_back(s.c_str());
	process(ivec);
	process(dvec);
	process(svec);
	process(cvec);
	return 0;
}