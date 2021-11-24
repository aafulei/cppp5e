// 18/01/16 = Tue

// Exercise 8.11: The program in this section defined its istringstream object inside the outer while loop. What changes would you need to make if record were defined outside that loop? Rewrite the program, moving the definition of record outside the while, and see whether you thought of all the changes that are needed.

// To run, enter "a <data\phones" in command prompt.

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
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
		cout << phone << " ";
	cout << endl;
}

int main()
{
	string line, word;
	vector<PersonInfo> people;
	// modified from textbook: record defined outside the while loop
	istringstream record;
	while (getline(cin, line)) {
		PersonInfo info;
		record.clear();						// **KEY**: clear eof and fail
		record.str(line);					// modified from textbook
		record >> info.name;
		while (record >> word) {
			info.phones.push_back(word);
		}
		people.push_back(info);
	}
	for (auto const& person : people)
		person.print();
	return 0;
}