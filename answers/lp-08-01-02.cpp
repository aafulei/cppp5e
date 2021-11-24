// 17/10/20 = Fri
// 18/01/30 = Tue: print (read(cin)).rdstate(), an iostate object, to clog

// Exercise 8.1: Write a function that takes and returns an istream&. The function should read the stream until it hits end-of-file. The function should print what it reads to the standard output. Reset the stream so that it is valid before returning the stream.

// Exercise 8.2: Test your function by calling it, passing cin as an argument.

// To run, enter, for example, "a <data\spring" or "a <data\summer" in command prompt.

#include <iostream>
#include <string>

using std::cin;
using std::clog;
using std::cout;
using std::endl;
using std::istream;
using std::string;

// remember to pass and return by reference
istream & read(istream & is)
{
	istream::iostate old_state = is.rdstate();	// alternatively: auto
	is.clear();
	for (string s; is >> s; cout << s << " ")
		;
	cout << endl;
	// Question: Can we omit is.clear() and do is.setstate(old_state) directly ?
	// Answer: No. Because setstate() only ADDS to the current state.
	is.clear();
	is.setstate(old_state);
	return is;
}

int main()
{
	// read(cin) returns a reference to cin;
	// cin.rdstate() returns an object of type istream::iostate
	// iostate is a machine-dependent integral type that represents condition states
	// istream::goodbit is an iostate, whose value is guaranteed to have value 0
	clog << (read(cin)).rdstate() << endl;
	return 0;
}