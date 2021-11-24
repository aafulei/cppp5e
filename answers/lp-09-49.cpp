// 18/01/19 = Fri: try
// 18/02/20 = Tue

// Exercise 9.49: A letter has an ascender if, as with d or f, part of the letter extends above the middle of the line. A letter has a descender if, as with p or g, part of the letter extends below the line. Write a program that reads a file containing words and reports the longest word that contains neither ascenders nor descenders.

// Assume ascenders and descenders only refer to lowercase letters.

// Ascenders:
// abcdefghijklmnopqrstuvwxyz
//  ^ ^ ^ ^^^^^       ^      

// Descenders:
// abcdefghijklmnopqrstuvwxyz
//       ^  ^     ^^       ^

// To run, enter, for example, "a data\summer" or "a data\gettysburg" in command prompt.

#include <fstream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;

const string ascenders = "bdfhijklt";
const string descenders = "gjpqy";
const string adescenders = ascenders + descenders;

int getlen(const string & s)
{
	if (s.find_first_of(adescenders) == string::npos)
		return s.size();
	else
		return -1;
}

bool process(const string & filename)
{
	ifstream ifs(filename);
	if (!ifs) {
		cerr << "Error: Cannot open file!" << endl;
		return false;
	}
	string maxword;
	int len, maxlen = 0;
	for (string word; ifs >> word; )
		if ((len = getlen(word)) > maxlen) {
			maxlen = len;
			maxword = word;
		}
	ifs.close();
	ifs.open(filename);
	for (string line; getline(ifs, line); cout << line << endl)
		;
	ifs.close();
	cout << string(75, '-') << endl;
	cout << "The longest word without an ascender or a descender is \"" << maxword << "\"." << endl;
	return true;
}

int main(int argc, char ** argv)
{
	if (argc == 1) {
		cerr << "Error: Format is [command][filename]!" << endl;
		return -1;
	}
	return process(argv[1]) ? 0 : -1;
}

