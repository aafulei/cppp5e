// 18/03/12 = Mon: overloaded operators
// 18/03/13 = Tue: additional assignment operator
// 18/03/14 = Wed: conversion operators
// 18/03/28 = Wed: operator==, operator!=, hash<Sales_data> specialization

// Header for Sales_data class

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <cstddef>				// for std::size_t
#include <functional>			// for std::hash
#include <iostream>
#include <string>

// Ex 15.3
class Sales_data
{
	std::string book_number;
	unsigned quantity = 0u;
	double revenue = 0.0;
public:
	Sales_data() = default;
	Sales_data(const std::string & b) : book_number(b) {}
	Sales_data(const std::string & b, unsigned q, double p)
		: book_number(b), quantity(q), revenue(q * p) {}
	std::string isbn() const 				{ return book_number; }
	Sales_data & operator+=(const Sales_data &);
	Sales_data & operator-=(const Sales_data &);					// Ex 14.13
	Sales_data & operator=(const std::string &);					// Ex 14.22
	explicit operator std::string() const 	{ return book_number; }	// Ex 14.45
	explicit operator double() const		{ return revenue; }		// Ex 14.45
private:
	double avg_price() const				{ return revenue / quantity; }
friend bool operator==(const Sales_data &, const Sales_data &);
friend bool operator!=(const Sales_data &, const Sales_data &);
friend Sales_data operator+(const Sales_data &, const Sales_data &);
friend Sales_data operator-(const Sales_data &, const Sales_data &);
friend std::istream & operator>>(std::istream &, Sales_data &);
friend std::ostream & operator<<(std::ostream &, const Sales_data &);
friend struct std::hash<Sales_data>;								// Ex 16.62
};

namespace std
{
	template<>
	struct hash<Sales_data>
	{
		using result_type = size_t;
		using argument_type = Sales_data;
		result_type operator()(const Sales_data & sd) const
		{
			#ifdef DEBUG_HASH
				clog << "Call: operator()(const Sales_data &)" << endl;
			#endif
			return hash<string>()(sd.book_number) ^
				   hash<unsigned>()(sd.quantity) ^
				   hash<double>()(sd.revenue);
		}
	};
}

#endif
