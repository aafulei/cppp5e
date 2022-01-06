// 18/03/16 = Fri
// 18/03/18 = Sun: copy-control members; clone()

// Header for Quote class hierarchy

#ifndef QUOTE_H
#define QUOTE_H

#include <cstddef>
#include <iostream>
#include <string>

// Ex 15.3
class Quote
{
	std::string book_number;
protected:
	double price = 0.0;
public:
	// Ex 15.26 requires a print for constructors, otherwise we simply have
	// Quote()	= default;
	// virtual ~Quote() = default;
	Quote();
	Quote(const std::string &, double);
	Quote(const Quote &);					// Ex 15.26
	Quote(Quote &&) noexcept;				// Ex 15.26
	Quote & operator=(const Quote &);		// Ex 15.26
	Quote & operator=(Quote &&) noexcept;	// Ex 15.26
	virtual ~Quote();
	virtual Quote * clone() const &			// Ex 15.30
	{
		return new Quote(*this);
	}
	virtual Quote * clone() &&				// Ex 15.30
	{
		return new Quote(std::move(*this));
	}
	std::string isbn() const 						{ return book_number; }
	virtual double total_price(std::size_t n) const	{ return price * n;   }
	virtual void print_total(std::size_t, std::ostream & os = std::cout) const;
	virtual void debug() const;
};

// Ex 15.15
class Disc_quote : public Quote
{
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
public:
	Disc_quote() = default;
	Disc_quote(const std::string &, double, std::size_t, double); // Ex 15.27
	virtual double total_price(std::size_t n) const = 0;
	virtual void debug() const;
};


// Ex 15.5
// refactored in Ex 15.15
class Bulk_quote : public Disc_quote
{
	// std::size_t min_quantity = 0;// refactored in Ex 15.15: => Disc_quote
	// double discount = 0.0;		// refactored in Ex 15.15: => Disc_quote
public:
	// Ex 15.26 requires a print for constructors, otherwise we simply have
	// Bulk_quote()	= default;
	Bulk_quote();
	Bulk_quote(const std::string &, double, std::size_t, double); // refactored in Ex 15.15
	Bulk_quote(const Bulk_quote &);					// Ex 15.26
	Bulk_quote(Bulk_quote &&) noexcept;				// Ex 15.26
	Bulk_quote & operator=(const Bulk_quote &);		// Ex 15.26
	Bulk_quote & operator=(Bulk_quote &&) noexcept;	// Ex 15.26
	virtual ~Bulk_quote() override;					// Ex 15.26
	virtual Bulk_quote * clone() const &			// Ex 15.30
	{
		return new Bulk_quote(*this);
	}
	virtual Bulk_quote * clone() &&					// Ex 15.30
	{
		return new Bulk_quote(std::move(*this));
	}
	virtual double total_price(std::size_t n) const override;
	// virtual void debug() const;	// refactored in Ex 15.15: => Disc_quote
};

// Ex 15.7
// refactored in Ex 15.16
class Limited_quote : public Disc_quote
{
	// std::size_t lim_quantity = 0;// refactored in Ex 15.16: => Disc_quote
	// double discount = 0.0;		// refactored in Ex 15.16: => Disc_quote
public:
	Limited_quote() = default;
	Limited_quote(const std::string & b, double p, std::size_t q, double d)
		: Disc_quote(b, p, q, d) {}	// refactored in Ex 15.16
	virtual double total_price(std::size_t n) const override;
	// virtual void debug() const;	// refactored in Ex 15.15: => Disc_quote
};

#endif