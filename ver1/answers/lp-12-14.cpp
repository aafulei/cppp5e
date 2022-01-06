// 18/02/14 = Wed

// Exercise 12.14: Write your own version of a function that uses a shared_ptr to manage a connection.

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

void disconnect(connection & c)
{	cout << "disconnecting " << c.get_dest().get_ip() << " ..."<< endl; }

// a deleter must take a single argument of (T *)
void delete_connection(connection * pc)
{	disconnect(*pc); }

void visit(const destination & d)
{
	try {
		connection c = connect(d);
		shared_ptr<connection> p(&c, delete_connection);
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