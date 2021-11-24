// 18/01/17 = Wed

// Exercise 9.18: Write a program to read a sequence of strings from the standard input into a deque. Use iterators to write a loop to print the elements in the deque.

// To run, enter, for example, "a <data\spring" in command prompt.

#include <deque>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::deque;
using std::string;

int main()
{
	deque<string> deq;
	string str;
	while(cin >> str)
		deq.push_back(str);
	// alternatively:
	// for (string str; cin >> str; deq.push_back(str))
	// 	;
	for (auto it = deq.cbegin(); it != deq.cend(); ++it)
		cout << *it << " ";
	return 0;
}