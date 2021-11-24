// 18/03/05 = Mon
// 18/03/08 = Thu: move from lp-13-33-38.cpp

#include "..\include\Folder.h"
#include "..\include\Message.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Folder::addMsg(Message * m)
{
	messages.insert(m);
}

void Folder::remMsg(Message * m)
{
	messages.erase(m);
}

void print(const vector<Folder *> & account)
{
	cout << string(50, '-') << endl;
	for (const auto & pf : account)
	{
		cout << pf->name << " has "<< pf->messages.size()
			 << " message(s):" << endl;
		for (const auto & m : pf->messages)
			cout << m->contents << endl;
	}
}