// 18/03/07 = Wed: StrVec
// 18/03/08 = Thu: String and Message

// Exercise 13.49: Add a move constructor and move-assignment operator to your StrVec, String, and Message classes.

// To turn on debug information against self-assignment:
// g++ lp-13-49.cpp -D DEBUG_SELF_ASSIGN

// To turn on debug information on move:
// g++ lp-13-49.cpp -D DEBUG_MOVE

// To turn it off:
// compile as usual

#include "include\Folder.h"
#include "include\Message.h"
#include "include\String.h"
#include "include\StrVec.h"
#include "source\Folder.cpp"
#include "source\Message.cpp"
#include "source\String.cpp"
#include "source\StrVec.cpp"
#include <iostream>
#include <string>				// for std::string
#include <utility>				// for std::move
#include <vector>

using namespace std;

void notify(const string & s)
{
	cout << string(50, '-') << endl;
	cout << s << endl;
}

int main()
{
	StrVec sv1;
	sv1.push_back("Hello");
	sv1.push_back("World");
	StrVec sv2 = std::move(sv1 = sv1);
	cout << "sv1 : " << sv1 << endl;
	cout << "sv2 : " << sv2 << endl;
	sv1 = std::move(sv2 = std::move(sv2));
	cout << "sv1 : " << sv1 << endl;
	cout << "sv2 : " << sv2 << endl;

	cout << string(50, '-') << endl;
	
	String s = "How do you do?";
	String t = std::move(s = s);
	cout << "s   : " << s << endl;
	cout << "t   : " << t << endl;
	s = std::move(t = std::move(t));
	cout << "s   : " << s << endl;
	cout << "t   : " << t << endl;

	cout << string(50, '-') << endl;

	Folder inbox("[Inbox]");
	Folder unread("[Unread]");
	Folder spam("[Spam]");
	vector<Folder *> account = { &inbox, &unread, &spam };

	Message a("Season's Greetings!");
	a.save(inbox);
	a.save(unread);
	Message b = std::move(a = a);
	cout << "a   : " << a.read() << endl;
	cout << "b   : " << b.read() << endl;
	print(account);
	cout << string(50, '-') << endl;
	a = std::move(b = std::move(b));
	cout << "a   : " << a.read() << endl;
	cout << "b   : " << b.read() << endl;
	print(account);

	return 0;
}