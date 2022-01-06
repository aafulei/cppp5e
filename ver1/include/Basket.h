// 18/03/18 = Sun

// Header for Basket class

#ifndef BASKET_H
#define BASKET_H

#include "Quote.h"
#include <iostream>
#include <memory>
#include <set>

class Basket
{
	using qptr = std::shared_ptr<Quote>;
	using qref = const std::shared_ptr<Quote> &;
	// for in-class initializers, we must use = or {}, cannot use ()
	// in this case, the constructor is explicit, so we must use {}
	std::multiset<qptr, bool(*)(qref, qref)> items{&compare};
public:
	void add_item(qref sale) 			{ items.insert(sale); }
	void add_item(const Quote &);
	void add_item(Quote &&);
	double total_receipt() const;
	void print_total(std::ostream & = std::cout) const;
private:
	static bool compare(qref a, qref b) { return a->isbn() < b->isbn(); }
};

#endif