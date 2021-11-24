 // 18/03/14 = Wed

// Exercise 14.35: Write a class like PrintString that reads a line of input from an istream and returns a string representing what was read. If the read fails, return the empty string.

// Read 10 lines from a file. Print out the lines even if they are empty.

// To run, enter, for example, "a data\spring" or "a data\summer" in command prompt.

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class PrintLine
{
	istream & is = cin;
public:
	PrintLine(istream & is) : is(is) {}
	string operator()() const
	{
		string line;
		getline(is, line);
		return is ? line : string();
	}

};

int main(int argc, char ** argv)
{
	if (argc == 1) {
		cerr << "Error: Format is [command][filename]!" << endl;
		return -1;
	}
	ifstream ifs(argv[1]);
	if (!ifs) {
		cerr << "Error: Cannot open file!" << endl;
		return -1;
	}
	PrintLine printer(ifs);
	for (size_t i = 0; i != 10; ++i)
		cout << "(line " << (i + 1) << ")\t" << printer() << endl;
	ifs.close();
	return 0;
}