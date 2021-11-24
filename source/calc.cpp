// 18/08/29 = Wed
// 18/09/04 = Tue

// TODO: is_legal
// TODO: color parentheses
// TODO: remove duplicated parentheses

#include <algorithm>
#include <cctype>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int PRECISION = 10;

constexpr double pi() { return std::atan(1) * 4; }

map<string, function<double(double, double)>> binops = {
	{"+", [](double a, double b){ return a + b; }},
	{"-", [](double a, double b){ return a - b; }},
	{"*", [](double a, double b){ return a * b; }},
	{"/", [](double a, double b){ return a / b; }},
	{"^", [](double a, double b){ return pow(a, b); }}
};

// later to divide into pre and post unaops
map<string, function<double(double)>> unaops = {
	{"pre_unary_minus",		[](double a){ return -a; }},
	{"-",		[](double a){ return -a; }},
	{"pre_unary_sine",		[](double a){ return sin(a); }},
	{"sin",		[](double a){ return sin(a); }},
	{"pre_unary_cosine",	[](double a){ return cos(a); }},
	{"cos",	[](double a){ return cos(a); }},
	{"post_unary_degree",	[](double a){ return a * pi() / 180; }}
	{"d",	[](double a){ return a * pi() / 180; }},
	{"squared",	[](double a){ return a * a; }}
};

map<string, string> pre_unary_names = {
	{"-",	"pre_unary_minus"},
	{"sin", "pre_unary_sine"},
	{"cos", "pre_unary_cosine"}
};

map<string, string> post_unary_names = {
	{"d",	"post_unary_degree"}
};

vector<set<string>> precedence = {
	{"^", "post_unary_degree"},
	{"pre_unary_minus",
	 "pre_unary_sine",
	 "pre_unary_cosine"},
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
  string t;
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

string separate_symbol(string s) {
	string t;
	for(auto c : s) {
		if (isalnum(c) || c == '.' || isspace(c))
			t.push_back(c);
		else {
			t.push_back(' ');
			t.push_back(c);
			t.push_back(' ');
		}
	}
	return t;
}

string trim_duplicated_spaces(string s)
{
	auto new_end = unique(s.begin(), s.end(),
						  [](char lhs, char rhs)
						  { return isspace(lhs) && isspace(rhs); });
	s.erase(new_end, s.end());
	return s;
}

bool isnum(const string & s)
{
	return !s.empty() & s.find_first_not_of(".0123456789") == string::npos &
		   (s.find('.') == string::npos ||
			s.find('.', s.find('.') + 1) == string::npos);
}

template<typename S, typename T, typename V>
bool isin(const T & t, const map<S, V> & m)
{
	return m.find(S(t)) != m.end();
}

string dtos(double a, int n=10)
{
	stringstream ss;
	ss << setprecision(n) << a;
	return ss.str();
}

string format(const list<string> & expr)
{
	string t;
	auto b = expr.cbegin();
	auto e = expr.crbegin();
	while (*b == "(" && *e == ")") {
		++b;
		++e;
	}
	string last, before_last;
	while (b != e.base()) {
		if (last == "(" || *b == ")" ||
		   (last == "-" && isnum(*b) && !isnum(before_last)))  // negative sign
			t += *b;
		else
			t += " " + *b;
		before_last = last;
		last = *b;
		++b;
	}
	return t;
}

double eval(list<string> && expr);

double evaluate(string str)
{
	str = separate_alpha_digit(str);
	str = separate_symbol(str);
	str = trim_duplicated_spaces(str);
	str = "( " + str + " )";

	list<string> expr;
	istringstream iss(str);

	for (string s; iss >> s; expr.push_back(s))
		;

	cout << "= " << format(expr) << endl;
	while (expr.size() > 2) {
		for (auto it = expr.begin(); it != expr.end(); ) {
			if (*it == ")") {
				list<string> rest_expr(next(it), expr.end());
				list<string> to_eval;
				--it;  // dismiss ")"
				while (*it != "(") {
					to_eval.push_front(std::move(*it));
					--it;
				}
				it = expr.erase(it, expr.end());

				double res = eval(std::move(to_eval));
				if (res >= 0)
					expr.push_back(dtos(res));
				else {
					expr.push_back("-");
					expr.push_back(dtos(-res));
				}

				expr.insert(expr.end(), rest_expr.begin(), rest_expr.end());

				cout << "= " << format(expr) << endl;
			}
			else
				++it;
		}
	}

	return expr.size() == 1 ? stod(expr.back()) : -stod(expr.back());
}


enum token_type { unknown = -1, number, binary, pre_unary, post_unary };

// later to put in class
string token_type_of(token_type tt)
{
	switch(tt) {
		case unknown: return "unknown";
		case number: return "number";
		case binary: return "binary";
		case pre_unary: return "pre_unary";
		case post_unary: return "post_unary";
	}
}

struct token
{
	string v;
	token_type t;
	int p;

	token(string v): v(v), t(token_type::unknown), p(-1) {}
	token(string v, token_type t): v(v), t(t) {
		// look up precedence level table
	}

	token & operator=(const string & s)
	{
		v = s;
		t = token_type::unknown;
		return *this;
	}

	token & operator=(string && s) noexcept
	{
		v = std::move(s);
		t = token_type::unknown;
		return *this;
	}

	string value() const		{ return v; }
	token_type type() const 	{ return t; }
	string repr() const 		{ return token_type_of(t); }
};


double reduce(list<token> && chain)
{
	for (auto is = chain.begin(); is != chain.end(); ) {
		if (is->is_num() ||
			is->is_oper() && is->precedence() != level)
			++is;
		else {
			if (is->is_pre_unary()) {
				// do something
			}
			else if (is->is_post_unary()) {

			}
			else { // binary {}

			}
		}
	}
}


double eval(list<string> && expr)
{
	list<token> chain;

	deque<double> num;
	deque<string> oper;
	string s;
	bool expect_number_or_pre_unary = true;
	bool met_unary = false;

	while (!expr.empty()) {
		s = expr.front();
		if (expect_number_or_pre_unary) {
			// met a number
			if (isnum(s)) {
				num.push_back(stod(s));
				met_unary = false;
				chain.emplace_back(s, token_type::number);
			}
			// met a prefix unary
			else {
				oper.push_back(pre_unary_names[s]);
				met_unary = true;
				chain.emplace_back(s, token_type::pre_unary);
			}
		}
		else {
			// met a postfix unary
			if (isin(s, post_unary_names)) {
				oper.push_back(post_unary_names[s]);
				met_unary = true;
				chain.emplace_back(s, token_type::post_unary);
			}
			// met a binary
			else {
				oper.push_back(s);
				met_unary = false;
				chain.emplace_back(s, token_type::binary);
			}
		}
		if (!met_unary)
			expect_number_or_pre_unary = !expect_number_or_pre_unary;
		expr.pop_front();
	}

	// GOOD:
	// cout << endl;
	// cout << "[chain] ";
	// for (auto c : chain)
	// 	cout << '[' << c.repr() << ']' << " ";
	// cout << "[end of chain]";
	// cout << endl;

	for (auto it = precedence.cbegin(); it != precedence.cend(); ++it) {
		deque<double> rest_num;
		deque<string> rest_oper;
		int i = 0;
		for (auto is = chain.begin(); is != chain.end(); ) {
			if (is.type() == token_type::number)
				++is;
			else {
				token tk = *is;
				string op = tk.value();
				if (it->find(op) != it->end()) {
					if (tk.type() == token::pre_unary) {
						auto ir = is;
						list<token> pre_unary_stack;
						while (is->type == token_type::pre_unary)
							pre_unary_stack.push_back(*is++);
						// assert now iterator is points to a number
						double intermediate = stod(is->value());
						while (!pre_unary_stack.empty()) {
							op = pre_unary_stack.back().value();
							intermediate = unaops[op](intermediate);
							pre_unary_stack.pop_back();
						}
						*ir = intermediate;
						// iterator points to the elem following erase
						is = chain.erase(std::next(ir), std::next(is));
					}
					else if (tk.type() == token_type::post_unary) {
						double intermediate = stod((std::prev(is))->value());
						auto ir = std::prev(is);
						list<token> post_unary_queue;
						while (is->type == token_type::post_unary)
							post_unary_queue.push_back(*is++);
						// assert now iterator is points to a binary
						while (!post_unary_queue.empty()) {
							op = post_unary_queue.front();
							intermediate = unaops[op](intermediate);
							post_unary_queue.pop_front();
						}
						*ir = intermediate;
						is = chain.erase(std::next(ir), is);
					}
					else if (tk.type() == token_type::binary) {
						//HARD: if binary not see numbers around it
						// then require clearing of lower precedence first
					}

				}
			}
		}

		for (; !oper.empty(); oper.pop_front()) {
			string op = oper.front();
			// op is in current precedence level
			if (it->find(op) != it->end()) {
				// op is unary
				// !!!!!!!!!!!!!!!!!!! WRONG WITH sin(cos(0)) !!!!!!!!!!!!!!
				if (op.find("unary") != string::npos) {
					double a = num.front();
					num.pop_front();
					num.push_front(unaops[op](a));
				}
				// op is binary
				else {
					double a = num.front();
					num.pop_front();
					double b = num.front();
					num.pop_front();
					num.push_front(binops[op](a, b));
				}
			}
			// op not in current precedence level
			else {
				// save op to deal with it later
				rest_oper.push_back(op);
				// if op is not prefix unary:
				//		save number to deal with it later
				if (op.find("pre_unary") == string::npos) {
					rest_num.push_back(num.front());
					num.pop_front();
				}
			}
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
	cout << ">  ";
	while (getline(cin, s)) {
		double res = evaluate(s);
		cout << ">  ";
	}
}