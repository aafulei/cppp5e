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
#include <cctype>

using namespace std;

constexpr double pi() { return std::atan(1)*4; }

map<string, function<double(double, double)>> binops = {
    {"+", [](double a, double b){ return a + b; }},
    {"-", [](double a, double b){ return a - b; }},
    {"*", [](double a, double b){ return a * b; }},
    {"/", [](double a, double b){ return a / b; }},
    {"^", [](double a, double b){ return pow(a, b); }}
};


map<string, string> unary_names = {
	{"-", "unary_minus"},
	{"sin", "unary_sine"}
};

map<string, string> post_unary_names = {
	{"d", "post_unary_degree"}
};

map<string, function<double(double)>> unaops = {
    {"unary_minus", [](double a){ return -a; }},
    {"unary_sine", [](double a){ return sin(a); }},
    {"post_unary_degree", [](double a){ return a * pi() / 180; }}
};

vector<set<string>> precedence = {
	{"^", "post_unary_degree"},
	{"unary_minus", "unary_sine"},
	{"*", "/"},
	{"+", "-"}
};

enum char_type { other, alpha, digit };

char_type char_type_of(char c)
{
    if(isdigit(c))
        return digit;
    if(isalpha(c))
        return alpha;
    return other;
}

string separate_alpha_digit(string s){
  string t = "";
  char_type last = other;
    for(auto c : s) {
        if ((last == alpha && char_type_of(c) == digit) ||
            (last == digit && char_type_of(c) == alpha))
            t.push_back(' ');
        t.push_back(c);
        last = char_type_of(c);
    }
    return t;
}

string separate_symbol(string s){
	string t = "";
    for(auto c : s) {
        if (!isalnum(c) && c != '.') {
            t.push_back(' ');
            t.push_back(c);
            t.push_back(' ');
        }
        else
	        t.push_back(c);
    }
    return t;
}



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
	s = separate_alpha_digit(s);
	s = separate_symbol(s);

	// replace_all(s, "(", " ( ");
	// replace_all(s, ")", " ) ");
	// replace_all(s, "+", " + ");
	// replace_all(s, "-", " - ");
	// replace_all(s, "*", " * ");
	// replace_all(s, "/", " / ");
	// replace_all(s, "^", " ^ ");

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
	string x;
	bool expect_num_or_una = true;
	bool met_una = false;
	istringstream iss(s);
	while (iss >> x) {
		if (expect_num_or_una) {
			if (x.find_first_not_of(".0123456789") == std::string::npos) {
				double a = stod(x);
				num.push_back(a);
				met_una = false;
			}
			else { // x is probably a unary operator
				// cout << "unary spotted" << endl;
				met_una = true;
				oper.push_back(unary_names[x]);
			}
		}
		else { // expecting binary or post_una
			if (post_unary_names.find(x) != post_unary_names.end())
				oper.push_back(post_unary_names[x]);
			else
				oper.push_back(x);
			// cout << "met: " << x << endl;
			// if x is a post_una
				// met_una = true;
			met_una = x.rfind("post", 0) == 0;
		}
		if (!met_una)
			expect_num_or_una = !expect_num_or_una;
	}

	for (auto it = precedence.cbegin(); it != precedence.cend(); ++it) {
		deque<double> rest_num;
		deque<string> rest_oper;
		while (!oper.empty()) {
			string op = oper.front();

			if (it->find(op) == it->end()) {
				if (op.rfind("unary", 0) != 0) {
					rest_num.push_back(num.front());
					num.pop_front();
				}
				rest_oper.push_back(oper.front());
			}
			else if (op.rfind("unary", 0) == 0) {  // if op starts with "unary"
				double a = num.front();
				num.pop_front();
				num.push_front(unaops[op](a));
			}
			else if (op.rfind("post", 0) == 0) {  // if op starts with "post_unary"
				// cout << "spotted " << op << endl;
				double a = num.front();
				num.pop_front();
				num.push_front(unaops[op](a));
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