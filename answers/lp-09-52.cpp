// 18/08/25 = Sat

// Exercise 9.52: Use a stack to process parenthesized expressions. When you see an open parenthesis, note that it was seen. When you see a close parenthesis after an open parenthesis, pop elements down to and including the open parenthesis off the stack. push a value onto the stack to indicate that a parenthesized expression was replaced.

// To run, enter, for example, "a <data\expr" in command prompt.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// assume that expression s is legal
void parse(string s)
{
    s = '(' + s + ')';
    stack<char> ex;
    stack<char> op;
    for (char c : s) {
        if (c == ')') {
            char d;
            while ((d = ex.top()) != '(') {
                op.push(d);
                ex.pop();
            }
            ex.pop();
            while (!op.empty()) {
                cout << op.top();
                op.pop();
            }
            cout << endl;
        }
        else
            ex.push(c);
    }
}

int main()
{
    string s;
    while (getline(cin, s)) {
        cout << "parsing " << s << ":" << endl;
        parse(s);
        cout << endl;
    }
}