// 18/01/17 = Wed

// Exercise 9.19: Rewrite the program from the previous exercise to use a list. List the changes you needed to make.

// Exercise 9.18: Write a program to read a sequence of strings from the standard input into a deque. Use iterators to write a loop to print the elements in the deque.

// Answer: Almost nothing to change except for the name of the container.

// Here we intentionally try a different way.

// To run, enter, for example, "a <data\spring" in command prompt.

#include <iostream>
#include <list>
#include <string>

using std::cin;
using std::cout;
using std::list;
using std::string;

int main()
{
	list<string> lst;
	string str;
	// use push_front and const_reverse_iterator instead
	while (cin >> str)
		lst.push_front(str); 
	for (auto it = lst.crbegin(); it != lst.crend(); ++it)
		cout << *it << " ";
	return 0;
}