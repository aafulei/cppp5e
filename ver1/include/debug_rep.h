// 18/03/28 = Wed: build upon lp-16-48.cpp

// Header for overloaded set of debug_rep

// for lp-16-56-57.cpp, lp-16-65-67.cpp

// To enable specialization and disable non-template versions: define SPEC

#ifndef DEBUG_REP_H
#define DEBUG_REP_H

#include <iostream>
#include <sstream>		// for std::ostringstream
#include <string>

template<typename T> std::string debug_rep(const T &);
template<typename T> std::string debug_rep(T *);
#ifndef SPEC
	std::string debug_rep(const char *);
	std::string debug_rep(char *);
#endif
std::string debug_rep(const std::string &);

template<typename T>
std::string debug_rep(const T & t)
{
	#ifdef DEBUG
		std::clog << "Inst: debug_rep(const T &)" << std::endl;
	#endif
	std::ostringstream oss;
	oss << t;
	return oss.str();
}

template<typename T>
std::string debug_rep(T * p)
{
	#ifdef DEBUG
		std::clog << "Inst: debug_rep(T *)" << std::endl;
	#endif
	std::ostringstream oss;
	oss << "Pointer: ";
	if (p)
		oss << *p;
	else
		oss << "nullptr";
	return oss.str();
}

#ifdef SPEC
// specialization for const char *
template<>
std::string debug_rep(const char * p)
{
	#ifdef DEBUG
		std::clog << "Spec: debug_rep(const char *)" << std::endl;
	#endif
	return debug_rep(std::string(p));
}

// specialization for char *
template<>
std::string debug_rep(char * p)
{
	#ifdef DEBUG
		std::clog << "Spec: debug_rep(char *)" << std::endl;
	#endif
	return debug_rep(std::string(p));
}
#endif	// endif for #ifdef SPEC

#endif