// 22/02/12 = Sat
// 18/02/10 = Sat

// Exercise 7.42: For the class you wrote for exercise 7.40 in Section 7.5.1 (p.
// 291), decide whether any of the constructors might use delegation. If so,
// write the delegating constructor(s) for your class. If not, look at the list
// of abstractions and choose one that you think would use a delegating
// constructor. Write the class definition for that abstraction.

#include <iostream>
#include <sstream>
#include <string>

class Book {
public:
  Book();
  Book(std::string isbn);
  Book(std::string isbn, std::string title);
  Book(std::string isbn, std::string title, std::string author);
  Book(std::istream &is);

  std::string get_isbn() const;
  std::string get_title() const;
  std::string get_author() const;

private:
  std::string isbn;
  std::string title;
  std::string author;
};

Book::Book() : Book("", "", "") { std::clog << "[TRACE] Book()" << std::endl; }

Book::Book(std::string isbn) : Book(isbn, "", "") {
  std::clog << "[TRACE] Book(std::string isbn)" << std::endl;
}

Book::Book(std::string isbn, std::string title) : Book(isbn, title, "") {
  std::clog << "[TRACE] Book(std::string isbn, std::string title)" << std::endl;
}

Book::Book(std::string isbn, std::string title, std::string author)
    : isbn(isbn), title(title), author(author) {
  std::clog
      << "[TRACE] Book(std::string isbn, std::string title, std::string author)"
      << std::endl;
}

Book::Book(std::istream &is) {
  std::clog << "[TRACE] Book(std::istream &is)" << std::endl;
  std::string line;
  std::getline(is, line);
  std::istringstream iss(line);
  std::getline(iss, isbn, '|');
  std::getline(iss, title, '|');
  std::getline(iss, author, '|');
}

std::string Book::get_isbn() const { return isbn; }

std::string Book::get_title() const { return title; }

std::string Book::get_author() const { return author; }

std::ostream &print(std::ostream &os, const Book &book) {
  return os << "ISBN\t" << book.get_isbn() << '\n'
            << "Title\t" << book.get_title() << '\n'
            << "Author\t" << book.get_author() << '\n'
            << std::endl;
}

void test() {
  std::string isbn = "978-7-121-20038-0";
  std::string title = "C++ Primer 5e";
  std::string author = "Stanley B. Lippman; Josee Lajoie; Barbara E. Moo";
  Book b0;
  print(std::cout, b0);
  Book b1(isbn);
  print(std::cout, b1);
  Book b2(isbn, title);
  print(std::cout, b2);
  Book b3(isbn, title, author);
  print(std::cout, b3);
  Book b4(std::cin);
  print(std::cout, b4);
}

int main() {
  test();
  return 0;
}
