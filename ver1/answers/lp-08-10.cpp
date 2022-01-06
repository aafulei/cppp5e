// 18/01/16 = Tue
// 18/01/30 = Tue: concise for loops

// Exercise 8.10: Write a program to store each line from a file in a vector<string>. Now use an istringstream to read each element from the vector a word at a time.

// To run, enter, for example, "a data\spring" in command prompt.

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

bool store(string filename, vector<string> & text)
{
	ifstream ifs(filename);
	if (ifs.fail()) {
		cerr << "Error: Cannot open file!" << endl;
		return false;
	}
	for (string line; getline(ifs, line); text.push_back(line))
		;
	ifs.close();
	return true;
}

void read(vector<string> text)
{
	for (auto const& line : text) {
		istringstream iss(line);
		for (string word; iss >> word; cout << word << endl)
			;
	}
}

int main(int argc, char ** argv)
{
	bool state;
	if (argc == 1) {
		cerr << "Error. Format is [command][filename]!" << endl;
		return EXIT_FAILURE;
	}
	vector<string> text;
	if (store(argv[1], text)) {
		read(text);
		return EXIT_SUCCESS;
	}
	else
		return EXIT_FAILURE;
}
