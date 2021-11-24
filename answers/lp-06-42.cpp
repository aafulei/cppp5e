// 18/02/08 = Thu

// Exercise 6.42: Give the second parameter of make_plural (§ 6.3.2, p. 224) a default argument of 's'. Test your program by printing singular and plural versions of the words success and failure.

#include <cstddef>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::size_t;
using std::string;

string make_plural(size_t ctr, const string & word, const string & ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
	cout << make_plural(1, "success", "es") << endl;
	cout << make_plural(2, "success", "es") << endl;
	cout << make_plural(1, "failure") << endl;
	cout << make_plural(2, "failure") << endl;
	return 0;
}