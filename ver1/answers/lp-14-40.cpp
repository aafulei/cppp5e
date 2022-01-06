// 18/03/14 = Wed

// Exercise 14.40: Rewrite the biggies function from § 10.3.2 (p. 391) to use function-object classes in place of lambdas.

// Read text from cin. Count and print out words longer than or equal to a size, which is 10 by default.

// To run, enter, for example, "a <data\moon" or "a <data\gatsby 15" in command prompt.

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename C>
void read(istream & is, C & c)
{
	for (typename C::value_type e; is >> e; c.push_back(e))
		;
}

template <typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << " ";
	cout << endl;
}

template<typename C>
void elimDups(C & c)
{
	sort(c.begin(), c.end());
	auto unique_end = unique(c.begin(), c.end());
	c.erase(unique_end, c.end());
}

template<typename T>
struct Is_Shorter
{
	bool operator()(const T & a, const T & b)
	{
		return a.size() < b.size();
	}
};

template<typename T>
class Is_Biggie
{
	typename T::size_type sz;
public:
	Is_Biggie(typename T::size_type sz) : sz(sz) {}
	bool operator()(const T & a) const
	{
		return a.size() >= sz;
	}
};

class Print_String
{
	ostream & os;
	string sep;
public:
	Print_String(ostream & os = cout, string sep = " ") : os(os), sep(sep) {}
	void operator()(const string & s) const
	{
		os << s << sep;
	}
};

void biggies(vector<string> & v, string::size_type sz)
{
    elimDups(v);
    stable_sort(v.begin(), v.end(), Is_Shorter<string>());
    auto beg = find_if(v.begin(), v.end(), Is_Biggie<string>(sz));
    auto n = v.end() - beg;
    cout << n << " " << (n > 1 ? "words" : "word") << " of length "
    	 << sz << " or longer." << endl;
    for_each(beg, v.end(), Print_String(cout, "\n"));
    cout << endl;
}

int main(int argc, char ** argv)
{
	auto sz = (argc == 1) ? 10u : atoi(argv[1]);
	vector<string> v;
	read(cin, v);
	biggies(v, sz);
	return 0;
}