// 18/02/11 = Sun

// Exercise 7.57: Write your own version of the Account class.

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Bank;

class Account
{
	friend Bank;
	const string owner;
	double amount;
	static double rate;
public:
	Account(string o, double a = 0.0) : owner(o), amount(a) {}
	Account & accrue()
	{
		amount *= (1 + rate);
		return *this;
	}
	double get_amount() const		{	return amount;	}
	static double get_rate()		{	return rate;	}
};

class Bank
{
public:
	static void set_rate(double r)	{	Account::rate = r;	}
};

double Account::rate = 0.05;

int main()
{
	Account kaka("Kaka", 3000);
	cout << kaka.get_rate() << endl;
	cout << Account::get_rate() << endl;
	cout << kaka.get_amount() << endl;
	cout << kaka.accrue().get_amount() << endl;
	Bank::set_rate(0.025);
	cout << kaka.accrue().get_amount() << endl;
	return 0;
}