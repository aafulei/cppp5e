// 18/01/16 = Tue
// 18/01/30 = Tue: print read(iss).rdstate() to clog

// Exercise 8.9: Use the function you wrote for the first exercise in § 8.1.2
// (p. 314) to print the contents of an istringstream object.

// Exercise 8.1: Write a function that takes and returns an istream&. The
// function should read the stream until it hits end-of-file. The function
// should print what it reads to the standard output. Reset the stream so that
// it is valid before returning the stream.

// To run, just enter "a" in command prompt.

#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::clog;
using std::cout;
using std::endl;
using std::istream;
using std::istringstream;
using std::string;

istream &read(istream &is) {
  istream::iostate old_state = is.rdstate();
  is.clear();
  for (string s; is >> s; cout << s << " ")
    ;
  cout << endl;
  is.clear();
  is.setstate(old_state);
  return is;
}

int main() {
  // modified from lp-08-01.cpp
  istringstream iss("In pursuit of wisdom, every day something is dropped.");
  // dynamic binding: read(), which accepts an &istream, now takes in an
  // &istringstream read(iss) returns a reference to iss; iss.rdstate() returns
  // an object of type istringstream::iostate istringstream::goodbit is an
  // iostate, whose value is guaranteed to have value 0 call operator () and dot
  // operator (.) are in the same level of precedence
  clog << read(iss).rdstate() << endl;
  return 0;
}
