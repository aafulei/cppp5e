// 18/01/15 = Mon

// Exercise 8.5 Rewrite the previous program to store each word in a separate element.

// Exercise 8.4: Write a function to open a file for input and read its contents into a vector of strings, storing each line as a separate element in the vector.

// To run, enter, for example, "a data\spring" in command prompt.

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

bool read(string const& filename, vector<string> & text)
{
	ifstream ifs(filename);
	if (ifs.fail()) {
		cerr << "Error: Cannot open file!" << endl;
		return false;
	}
	// modified from lp-08-04.cpp
	for (string word; ifs >> word; text.push_back(word))
		;
	ifs.close();
	return true;
}

int main(int argc, char ** argv)
{
	if (argc == 1) {
		cerr << "Error: Format is [command][filename]!" << endl;
		return EXIT_FAILURE;
	}
	vector<string> text;
	if (read(argv[1], text)) {
		for (auto const& line : text)
			cout << line << endl;
		return EXIT_SUCCESS;		
	}
	else
		return EXIT_FAILURE;
}