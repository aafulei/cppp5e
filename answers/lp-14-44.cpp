// 18/08/25 = Sat

// Exercise 14.44: Write your own version of a simple desk calculator that can handle binary operations.

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <functional>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

map<string, function<double(double, double)>> binops = {
    {"+", [](double a, double b){ return a + b; }},
    {"-", [](double a, double b){ return a - b; }},
    {"*", [](double a, double b){ return a * b; }},
    {"/", [](double a, double b){ return a / b; }},
    {"^", [](double a, double b){ return pow(a, b); }}
};

vector<set<string>> precedence = {
	{"^"},
	{"*", "/"},
	{"+", "-"}
};

void replace_all(string & s, const string & old, const string & neo)
{
	for (std::size_t pos = 0, len = old.size();
		(pos = s.find(old, pos)) != string::npos;
		pos += (neo.size() - old.size()) + 1)
		s.replace(pos, len, neo);
}

double eval(string);

double evaluate(string s)
{
	replace_all(s, "(", " ( ");
	replace_all(s, ")", " ) ");
	replace_all(s, "+", " + ");
	replace_all(s, "-", " - ");
	replace_all(s, "*", " * ");
	replace_all(s, "/", " / ");


	s = "( " + s + " )";
	deque<string> terms;
	istringstream iss(s);
	string seg;
	while (iss >> seg) {
		if (seg == ")") {
			string to_eval;
			string d;
			while ((d = terms.back()) != "(") {
				to_eval = d + " " + to_eval;
				terms.pop_back();
			}
			terms.pop_back();
			ostringstream oss;
			// cout << "eval: " << to_eval << endl;
			oss << eval(to_eval);
			terms.push_back(oss.str());
		}
		else
			terms.push_back(seg);
	}
	return stod(terms.front());
}

double eval(string s)
{
	deque<double> num;
	deque<string> oper;
	string e;
	bool expect_num = true;
	istringstream iss(s);
	while (iss >> e) {
		if (expect_num) {
			double a = stod(e);
			num.push_back(a);
		}
		else {
			oper.push_back(e);
		}
		expect_num = !expect_num;
	}

	for (auto it = precedence.cbegin(); it != precedence.cend(); ++it) {
		deque<double> rest_num;
		deque<string> rest_oper;
		while (!oper.empty()) {
			string op = oper.front();
			if (it->find(op) == it->end()) {
				rest_num.push_back(num.front());
				num.pop_front();
				rest_oper.push_back(oper.front());
			}
			else {
				double a = num.front();
				num.pop_front();
				double b = num.front();
				num.pop_front();
				num.push_front(binops[op](a, b));
				// cout << endl << "~: " << a << " " << op << " " << b << endl;
			}
			oper.pop_front();
		}
		rest_num.push_back(num.front());
		num = rest_num;
		oper = rest_oper;
	}

	return num.front();
}

int main()
{
	string s;
    while (getline(cin, s)) {
    	cout << s << " = " << evaluate(s) << endl;
    }
}