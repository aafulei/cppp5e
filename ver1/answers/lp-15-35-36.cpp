// 18/03/19 = Mon

// Exercise 15.35: Implement the Query and Query_base classes, including a definition of rep but omitting the definition of eval.

// Exercise 15.36: Put print statements in the constructors and rep members and run your code to check your answers to (a) and (b) from the first exercise.

// Exercise 15.34: For the expression built in Figure 15.3 (p. 638):
// (a) List the constructors executed in processing that expression.
// (b) List the calls to rep that are made from cout << q.
// (c) List the calls to eval made from q.eval().

// To turn on debug info on constructors:
// g++ lp-15-35-36.cpp -D DEBUG_CTOR

// To turn on debug info on rep():
// g++ lp-15-35-36.cpp -D DEBUG_REP

// To turn on debug info on eval():
// g++ lp-15-35-36.cpp -D DEBUG_EVAL

// To turn it off:
// compile as usual

// To run, enter, for example, "a <data\story" in command prompt.

#include "include\Query.h"
#include "include\TextQuery.h"
#include "source\Query.cpp"
#include "source\TextQuery.cpp"
#include <string>

using namespace std;

void line()
{
	cout << string(50, '-') << endl;
}

int main()
{
	Query q = Query("fiery") & Query("bird") | Query("wind");	line();
	cout << q << endl;											line();
	q.eval(TextQuery(cin));
	return 0;
}