// 18/02/20 = Tue

// Exercise 9.50:  Write a program to process a vector<string>s whose elements represent integral values. Produce the sum of all the elements in that vector. Change the program so that it sums of strings that represent floating-point values.

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int sum_int(const vector<string> & v)
{
	int sum = 0;
	for (const auto & e : v)
		sum += stoi(e);
	return sum;
}

double sum_double(const vector<string> & v)
{
	double sum = 0.0;
	for (const auto & e : v)
		sum += stod(e);
	return sum;
}

template<typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << " ";
	cout << endl;
}

int main()
{
	// sum all the integers
	vector<string> v = {"-1", "+2", "34"};
	print(v);
	cout << sum_int(v) << endl;
	
	// sum all the floating numbers
	v = {"-0.1", "+.2", "3e4"};
	print(v);
	cout << sum_double(v) << endl;

	return 0;
}