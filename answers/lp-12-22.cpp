// 18/02/28 = Wed
// 18/03/12 = Mon: redo, with header and source code separated

// Exercise 12.22: What changes would need to be made to StrBlobPtr to create a class that can be used with a const StrBlob? Define a class named ConstStrBlobPtr that can point to a const StrBlob.

// Exercise 12.19: Define your own version of StrBlobPtr and update your StrBlob class with the appropriate friend declaration and begin and end members.

// Exercise 12.20: Write a program that reads an input file a line at a time into a StrBlob and uses a StrBlobPtr to print each element in that StrBlob.

// Built incrementally on lp-12-19-20.cpp

// Question: Much duplication in writing ConstStrBlobPtr. How can we make it easier?

// To run, enter, for example, "a data\spring" or "a data\summer" in command prompt.

#include "include\StrBlob.h"
#include "source\StrBlob.cpp"

#include "include\StrBlobPtr.h"
#include "source\StrBlobPtr.cpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

StrBlob read(const string & filename)
{
	StrBlob sb;
	ifstream ifs(filename);
	if (!ifs)
		throw runtime_error("Cannot open " + filename + "!");
	for (string line; getline(ifs, line); sb.push_back(line))
		;
	ifs.close();
	return sb;
}

// Now that we have the ConstStrBlob class, we may pass a const StrBlob &.
void print(const StrBlob & sb)
{
	for (auto csbp = sb.cbegin(); csbp != sb.cend(); csbp.increment())
		cout << csbp.derefer() << endl;
}

int main(int argc, char ** argv)
{
	if (argc == 1) {
		cerr << "Error: Format is [command][filename]!" << endl;
		return -1;
	}
	// Now that print() takes a const StrBlob &, we may pass a temporary StrBlob.
	print(read(argv[1]));
	return 0;
}