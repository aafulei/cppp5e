// 18/03/10 = Sat

// Exercise 13.55: Add an rvalue reference version of push_back to your StrBlob.

#include "include\StrBlob.h"
#include "source\StrBlob.cpp"
#include <string>

using namespace std;

// To turn on debug info on rvalue reference version of push_back()
// g++ lp-13-55.cpp -D DEBUG_PUSH_BACK

int main()
{
	StrBlob sb;
	sb.push_back("a");
	sb.push_back("an");
	string s = "the";
	sb.push_back(std::move(s));
	cout << s << endl;	// empty
	return 0;
}