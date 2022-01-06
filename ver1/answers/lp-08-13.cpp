// 18/1/16 = Tue

// Exercise 8.13: Rewrite the phone number program from this section to read from a named file rather than from cin.

// To run, enter "a data\phones" in command prompt.

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

struct PersonInfo
{
	string name;
	vector<string> phones;
	void print() const;
};

void PersonInfo::print() const
{
	cout << name << " # ";
	for (auto const& phone : phones)
		cout << phone << ' ';
	cout << endl;
}

int main(int argc, char ** argv)
{
	string line, word;
	vector<PersonInfo> people;
	istringstream record;					// modified from textbook
	if (argc == 1) {
		cerr << "Error: Format is [command][filename]!" << endl;
		return EXIT_FAILURE;
	}
	ifstream ifs(argv[1]);
	if (ifs.fail()) {
		cerr << "Error: Cannot open file!" << endl;
		return EXIT_FAILURE;
	}
	while (getline(ifs, line)) {			// modified from lp-08-11.cpp
		PersonInfo info;
		record.clear();						// **KEY**: clear eof and fail
		record.str(line);					// modified from textbook
		record >> info.name;
		while (record >> word) {
			info.phones.push_back(word);
		}
		people.push_back(info);
	}
	ifs.close();
	for (auto const& person : people)
		person.print();
	return EXIT_SUCCESS;
}