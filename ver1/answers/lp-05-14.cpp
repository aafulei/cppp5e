// 18/02/04 = Sun

// Exercise 5.14: Write a program to read strings from standard input looking for duplicated words. The program should find places in the input where one word is followed immediately by itself. Keep track of the largest number of times a single repetition occurs and which word is repeated. Print the maximum number of duplicates, or else print a message saying that no word was repeated. For example, if the input is "how now now now brown cow cow" the output should indicate that the word "now" occurred three times.

// To run, enter, for example, "a <data\how" in command prompt.

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string word, last_word, max_word;
	int count, max_count = 0;
	while (cin >> word) {
		if (word == last_word)
			++count;
		else {
			if (count > max_count) {
				max_count = count;
				max_word = last_word;
			}
			count = 1;
		}
		last_word = word;
	}
	if (max_count <= 1)
		cout << "No word was repeated." << endl;
	else
		cout << "The word \"" << max_word << "\" occurred " << max_count << " times." << endl;
	return 0;
}