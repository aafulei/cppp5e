// 18/02/13 = Tue

// Exercise 11.12: Write a program to read a sequence of strings and ints, storing each into a pair. Store the pairs in a vector.

// Exercise 11.13: There are at least three ways to create the pairs in the program for the previous exercise. Write three versions of that program, creating the pairs in each way. Explain which form you think is easiest to write and understand, and why.

// Answer: List initialize with two parameters is the easiest to write and understand, because by a pair we mean two elements.

// The sequence of strings and ints can be something like:
// Hello 1 World 2 Let's 3 Make 4 You 5 a 6 Better 7 Place 8

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void print(vector<pair<string, int>> & v)
{
	for (const auto & e : v)
		cout << e.first << " " << e.second << endl;
}

void clear(vector<pair<string, int>> & v)
{
	v.clear();
	cin.ignore(256, '\n');
	cin.clear();
}

int main()
{
	vector<pair<string, int>> v;
	string s;
	int i;

	// value initialize a pair
	cout << "Enter a sequence of strings and ints: ";
	for (pair<string, int> p; cin >> p.first >> p.second; v.push_back(p))
		;
	print(v);
	clear(v);

	// list initialize a pair
	cout << "Enter a sequence of strings and ints: ";
	while (cin >> s >> i)
		v.push_back(pair<string, int>(s, i));
	print(v);
	clear(v);

	// initialize a pair using make_pair
	cout << "Enter a sequence of strings and ints: ";
	while (cin >> s >> i)
		v.push_back(make_pair(s, i));
	print(v);
	clear(v);

	return 0;
}