// 18/02/24 = Sat

// Exercise 11.20: Rewrite the word-counting program from § 11.1 (p. 421) to use insert instead of subscripting. Which program do you think is easier to write and read? Explain your reasoning.

// map<string, size_t> word_count;
// string word;
// while (cin >> word)
// 		++word_count[word];
// for (const auto &w : word_count)
// 	cout <<  w.first << " occurs " << w.second
// 		<< ((w.second > 1) ? " times" : " time") << endl;

// Answer: The program using subscripting is easier to write and read, because it is intuitive to read, and concise to write, if we view a map as an associative array. Moreover, to use insert you have to remember the structure of its returned value (a pair of an iterator and a bool).

// To run, enter, for example, "a <data\how" in command prompt.

#include <cstddef>
#include <iostream>
#include <map>

using namespace std;

int main()
{
	// count
	map<string, size_t> count;
	for (string word; cin >> word; ) {
		auto result = count.insert({word, 1});
		if (!result.second)
			++result.first->second;
	}
	// print
	for (const auto & word : count)
		cout << word.first << " occurs " << word.second
			 << ((word.second > 1) ? " times" : " time") << endl;
	return 0;
}