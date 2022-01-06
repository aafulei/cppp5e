// 21/12/29 = Wed
// 18/03/13 = Tue

// a ../data/summer

// 39 : Shall I compare thee to a summer's day?
// 40 : Thou art more lovely and more temperate.
// 45 : Rough winds do shake the darling buds of May,
// 45 : And summer's lease hath all too short a date.
// 42 : Sometime too hot the eye of heaven shines,
// 40 : And often is his gold complexion dimmed;
// 43 : And every fair from fair sometime declines,
// 50 : By chance, or nature's changing course, untrimmed
// 38 : But thy eternal summer shall not fade,
// 44 : Nor lose possession of that fair thou ow'st,
// 49 : Nor shall death brag thou wand'rest in his shade,
// 43 : When in eternal lines to Time thou grow'st.
// 44 : So long as men can breathe, or eyes can see,
// 48 : So long lives this, and this gives life to thee.

#include <cstddef>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlobPtr;

class StrBlob {
  friend StrBlobPtr;

public:
  using size_type = std::vector<std::string>::size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  void push_back(const std::string &t) { data->push_back(t); }
  void pop_back();
  std::string &front();
  std::string &back();
  StrBlobPtr begin();
  StrBlobPtr end();

private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()){};

StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const {
  if (i >= size()) {
    throw std::out_of_range(msg);
  }
}

void StrBlob::pop_back() {
  check(0, "pop_back() on empty StrBlob!");
  data->pop_back();
}

std::string &StrBlob::front() {
  check(0, "front() on empty StrBlob!");
  return data->front();
}

std::string &StrBlob::back() {
  check(0, "back() on empty StrBlob!");
  return data->back();
}



class StrBlobPtr {
public:
  StrBlobPtr() : curr(0) {}
  StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
  std::string &operator*() const;

  std::string *operator->() const;

  StrBlobPtr &incr();



  bool operator==(const StrBlobPtr &);  // for sb.begin() != sb.end()
  bool operator!=(const StrBlobPtr &);

private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
  std::shared_ptr<std::vector<std::string>> sptr = wptr.lock();
  if (!sptr) {
    throw std::runtime_error("Unbound StrBlobPtr!");
  }
  if (i >= sptr->size()) {
    throw std::out_of_range(msg);
  }
  return sptr;
}

std::string &StrBlobPtr::operator*() const {
  std::shared_ptr<std::vector<std::string>> sptr =
      check(curr, "deref past the end");
  return (*sptr)[curr];
}

std::string *StrBlobPtr::operator->() const {
  return &**this;
}

StrBlobPtr &StrBlobPtr::incr() {
  check(curr, "increment past the end");
  ++curr;
  return *this;
}

bool StrBlobPtr::operator==(const StrBlobPtr & sb)
{
  return curr == sb.curr && wptr.lock() == sb.wptr.lock();
}

bool StrBlobPtr::operator!=(const StrBlobPtr & sb)
{
  return !(*this == sb);
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, size()); }

StrBlob read(const std::string & filename)
{
  StrBlob sb;
  std::ifstream ifs(filename);
  if (!ifs)
    throw std::runtime_error("Cannot open " + filename + "!");
  for (std::string line; std::getline(ifs, line); sb.push_back(line))
    ;
  ifs.close();
  return sb;
}

// StrBlob & cannot be const, because StrBlobPtr is not pointer-to-const
void print(StrBlob & sb)
{
  for (auto sbp = sb.begin(); sbp != sb.end(); sbp.incr())
    // std::cout << sbp.deref() << std::endl;
    std::cout << sbp->size() << " : " << *sbp << std::endl;
}

int main(int argc, char ** argv)
{
  if (argc == 1) {
    std::cerr << "Error: Format is [command][filename]!" << std::endl;
    return -1;
  }
  auto sb = read(argv[1]);
  print(sb);
  return 0;
}
