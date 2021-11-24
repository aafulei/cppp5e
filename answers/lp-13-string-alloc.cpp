// 18/03/06 = Tue

// Demonstrate how a string allocates dynamic memory

#include <iostream>
#include <string>

using namespace std;

void show(const string & s)
{
	auto positive = [](int a){ return a > 0 ? a : 0; };
	string t = "string = " + s + ";";
	cout << t << string(positive(6 - t.size()/8), '\t')
		 << "size = " << s.size() << ";\tcapacity = " << s.capacity() << endl;
}

int main()
{
	string s;
	show(s);
	s += "0";
	show(s);
	s = "012345678912345";
	show(s);
	s += "6";
	show(s);
	s.pop_back();
	show(s);
	s = "ABC";
	show(s);
	s = string(31, '.');
	show(s);
	s.push_back('.');
	show(s);
	s.shrink_to_fit();
	show(s);
	s.clear();
	show(s);
	s.shrink_to_fit();
	show(s);
	return 0;
}