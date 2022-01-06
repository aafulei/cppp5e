// 18/02/14 = Wed
// 18/02/27 = Tue: pass vector, not smart pointer, as argument

// Exercise 12.7: Redo the previous exercise, this time using shared_ptr.

// Exercise 12.6: Write a function that returns a dynamically allocated vector of ints. Pass that vector to another function that reads the standard input to give values to the elements. Pass the vector to another function to print the values that were read. Remember to delete the vector at the appropriate time.

// Modified from lp-12-06.cpp
// Merely:
// smart_ptr allocate() { return make_shared<vector<int>>(); }
// no need to delete

// To run, enter, for example, "a <data\digits" in command prompt.

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

using smart_ptr = shared_ptr<vector<int>>;

smart_ptr allocate()
{
	return make_shared<vector<int>>();
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
	smart_ptr p = allocate();
	write(*p);
	print(*p);
	return 0;
}