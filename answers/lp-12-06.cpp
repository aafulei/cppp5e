// 18/02/14 = Wed

// Exercise 12.6: Write a function that returns a dynamically allocated vector of ints. Pass that vector to another function that reads the standard input to give values to the elements. Pass the vector to another function to print the values that were read. Remember to delete the vector at the appropriate time.

// To run, enter, for example, "a <data\digits" in command prompt.

#include <iostream>
#include <new>		// to use nothrow
#include <vector>

using namespace std;

vector<int> * allocate();
void write(vector<int> &);
void print(const vector<int> &);

// Must return vector<int> * rather than vector<int> &. Why?
vector<int> * allocate()
{
	return new(nothrow) vector<int>;
}

void write(vector<int> & v)
{
	for (int i; cin >> i; v.push_back(i))
		;
}

void print(const vector<int> & v)
{
	for (auto i : v)
		cout << i << " ";
	cout << endl;
}

int main()
{
	vector<int> * p = allocate();
	if (!p) {
		cerr << "Error: Bad allocate!" << endl;
		return -1;
	}
	write(*p);
	print(*p);
	delete p;
	return 0;
}
