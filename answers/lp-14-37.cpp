 // 18/03/14 = Wed

// Exercise 14.37: Write a class that tests whether two values are equal. Use that object and the library algorithms to write a program to replace all instances of a given value in a sequence.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
class Equal
{
	T v;
public:
	Equal(const T & v) : v(v) {}
	bool operator()(T u) const
	{
		return u == v;
	}
};

template<typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << endl;
}

string process(const string & line)
{
	istringstream iss(line);
	ostringstream oss;
	istream_iterator<string> isit(iss), isend;
	ostream_iterator<string> osit(oss, " ");
	string word, with;
	cout << "Enter the word you want to replace: ";
	cin >> word;
	cout << "with what? ";
	cin >> with;
	Equal<string> eq(word);
	replace_copy_if(isit, isend, osit, eq, with);
	return oss.str();
}

int main()
{
	const string line = "how now now now brown cow cow";
	cout << line << endl;
	cout << process(line) << endl;
	return 0;
}