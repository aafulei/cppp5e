// 18/03/18 = Sun

// Source code for Basket class

#include "..\include\Basket.h"
#include "..\include\Quote.h"
#include <iostream>
#include <set>
#include <memory>

using namespace std;

void Basket::add_item(const Quote & sale)
{
	items.insert(shared_ptr<Quote>(sale.clone()));
}

void Basket::add_item(Quote && sale)
{
	items.insert(shared_ptr<Quote>(std::move(sale).clone()));
}

double Basket::total_receipt() const
{
	double sum {};
	for (auto it = items.cbegin(); it != items.cend(); it = items.upper_bound(*it))
		sum += (*it)->total_price(items.count(*it));
	return sum;
}

void Basket::print_total(ostream & os) const
{
	for (auto it = items.cbegin(); it != items.cend(); it = items.upper_bound(*it)) {
		auto n = items.count(*it);
		(*it)->print_total(n, os);
	}
	os << "Total Receipt\t" << total_receipt() << endl;
}