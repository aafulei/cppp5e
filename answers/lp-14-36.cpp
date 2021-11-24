 // 18/03/14 = Wed

// Exercise 14.36: Use the class from the previous exercise to read the standard input, storing each line as an element in a vector.

// Exercise 14.35: Write a class like PrintString that reads a line of input from an istream and returns a string representing what was read. If the read fails, return the empty string.

// Modified from lp-14-35.cpp

// To run, enter, for example, "a <data\spring" or "a <data\summer" in command prompt.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PrintLine
{
	istream & is;
public:
	// We move cin from the in-class initializer to the default argument of the constructor so that the constructor now plays the role of default constructor
	PrintLine(istream & is = cin) : is(is) {}
	string operator()() const
	{
		string line;
		getline(is, line);
		return is ? line : string();
	}

};

template<typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << endl;
}

int main(int argc, char ** argv)
{
	vector<string> v;
	PrintLine printer;	// call default constructor, which binds is to cin
	// Question: For the condition, we cannot replace cin with !line.empty(). Why?
	// Answer: Consider reading an input which has empty lines in the middle.
	for (string line = printer(); cin; line = printer())
		v.push_back(line);
	print(v);
	return 0;
}