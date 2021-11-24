// 18/02/23 = Fri

// Exercise 10.33: Write a program that takes the names of an input file and two output files. The input file should hold integers. Using an istream_iterator read the input file. Using ostream_iterators, write the odd numbers into the first output file. Each value should be followed by a space. Write the even numbers into the second file. Each of these values should be placed on a separate line.

// To run, enter, for example, "a data\digits output\odd output\even" in command prompt.

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

bool separate(string ifname, string ofname1, string ofname2)
{
	ifstream ifs(ifname);
	ofstream ofs_odd(ofname1);
	ofstream ofs_even(ofname2);
	if (!(ifs && ofs_odd && ofs_even)) {
		cerr << "Error: Cannot open file(s)!" << endl;
		return false;
	}
	istream_iterator<int> isit(ifs), isend;
	ostream_iterator<int> osit_odd(ofs_odd, " "), osit_even(ofs_even, "\n");
	while (isit != isend) {
		if (*isit % 2 == 1)
			osit_odd = *isit;
			// equivalent to:
			// *osit_odd++ = *isit;
		else
			osit_even = *isit;
			// equivalent to:
			// *osit_even++ = *isit;
		++isit;
	}
	return true;
}

int main(int argc, char ** argv)
{
	if (argc < 4) {
		cerr << "Error: Format is [command][input][output1][output2]!"
			 << endl;
		return -1;
	}
	return separate(argv[1], argv[2], argv[3]) ? 0 : -1;
}
