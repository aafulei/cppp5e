// 17/10/23 = Mon

// Exercise 3.25: Rewrite the grade clustering program from § 3.3.3 (p. 104) using iterators instead of subscripts.

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<unsigned> scores(11);
	unsigned grade;
	while (cin >> grade)
	    if (grade <= 100) {
	    	auto it = scores.begin() + grade / 10;
	        (*it)++;	// don't forget ()
	    }

	for (auto it = scores.cbegin(); it != scores.cend(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}