// 18/02/14 = Wed

// Exercise 12.15: Rewrite the first exercise to use a lambda (§ 10.3.2, p. 388) in place of the end_connection function.

// Exercise 12.14: Write your own version of a function that uses a shared_ptr to manage a connection.

// Modified from lp-12-14.cpp

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

using namespace std;
using address = string;

struct destination
{
	destination(const address & i) : ip(i) {}
	address get_ip() const { return ip; }
private:
	address ip;
};

struct connection
{
	connection(const destination & d) : dest(d) {}
	destination get_dest() const { return dest; }
private:
	destination dest;
};

connection connect(const destination & d)
{
	cout << "connecting " << d.get_ip() << " ..."<< endl;
	return connection(d);
}

void disconnect(const connection & c)
{	cout << "disconnecting " << c.get_dest().get_ip() << " ..."<< endl; }

void visit(const destination & d)
{
	try {
		connection c = connect(d);
		// modified: use a lambda
		// understand what should be in [] and what should be in ()
		shared_ptr<connection> p(&c, [](connection * q){disconnect(*q);});
		throw exception();
	}
	catch(exception) {
		cerr << "Houston, we have a problem. "
		"We're now making a return." << endl;
		return;
	}
}

int main()
{
	visit(destination("192.168.0.1"));
	return 0;
}