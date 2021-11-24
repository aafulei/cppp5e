// 18/03/25 = Sun

// Exercise 16.22: Revise your TextQuery programs from § 12.3 (p. 484) so that the shared_ptr members use a DebugDelete as their deleter (§ 12.1.4, p. 468).

// Exercise 16.23: Predict when the call operator will be executed in your main query program. If your expectations and what happens differ, be sure you understand why.

// Answer: When one query completes, the DebugDelete is to be called on the shared pointer that points to the set of the line numbers. When all the queries on the given text completes, the DebugDelete is to be called on the shared pointer that points to the vector of the strings that represent the text.

// To compile: g++ lp-16-22-23.cpp -D DEBUG_DELETE
// To run: a data\gatsby

#include "include\DebugDelete.h"
#include "include\TextQuery.h"
#include "source\TextQuery.cpp"
#include <fstream>

using namespace std;

// a little tweak on the original TextQuery
class my_TextQuery : public TextQuery
{
public:
	my_TextQuery(istream & is)	// default constructor called for TextQuery
	{
		// Unlike the std::shared_ptr constructors, std::make_shared does not allow a custom deleter. 
		txt = shared_ptr<text>(new text(), DebugDelete());	// modified
		lino n = 0;
		for (string line; getline(is, line); txt->push_back(line), ++n) {
			istringstream iss(line);
			for (string word; iss >> word; )
				index[standardize(word)].insert(n);
		}
	}

	// hide TextQuery::query() in TextQuery
	QueryResult query(const string & word) const
	{
		string aim(word);
		standardize(aim);
		auto it = index.find(aim);
		auto sptr = (it == index.end()) ?					// modified
					shared_ptr<lset>(new lset, DebugDelete()) :
					shared_ptr<lset>(new lset(it->second), DebugDelete());
		return QueryResult(aim, txt, sptr);
	}

};

void my_runQueries(ifstream & ifs)
{
	my_TextQuery tq(ifs);									// modified
	const string prompt = "Enter word to search or Q to quit: ";
	cout << prompt;
	for (string word; cin >> word && word != "Q" && word != "q";
		cout << prompt)
		cout << tq.query(word) << endl;
	ifs.close();
}

int main(int argc, char ** argv)
{
	if (argc == 1) {
		cerr << "Error: Format is [command][filename]!" << endl;
		return -1;
	}
	ifstream ifs(argv[1]);
	if (!ifs) {
		cerr << "Error: Cannot open file!" << endl;
		return -1;
	}
	my_runQueries(ifs);
	ifs.close();
	return 0;
}