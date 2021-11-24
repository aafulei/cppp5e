// 18/03/25 = Sun

// Header for DebugDelete class

// A function object class that calls delete on a given pointer. Given a pointer p, DebugDelete(p) is equivalent to delete p.

// To turn on debug info: g++ -D DEBUG_DELETE
// To turn it off: compile as usual

// for lp-16-21.cpp, lp-16-22.cpp

#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

#include <iostream>
#include <typeinfo>
#include <string>

// Because we have a reference-type data member (os) in DebugDelete, the copy-assignment operator is synthesized to be deleted.
class DebugDelete
{
	std::ostream & os = std::clog;
public:
	DebugDelete() = default;
	DebugDelete(std::ostream & os) : os(os) {}
	template<typename T>
	void operator()(T * p) const
	{
		#ifdef DEBUG_DELETE
			std::clog << std::string(100, '-') << std::endl;
			std::clog << "Call: DebugDelete() on " << typeid(T).name() << std::endl;
			std::clog << std::string(100, '-') << std::endl;
		#endif
		delete p;
	}
};

#endif