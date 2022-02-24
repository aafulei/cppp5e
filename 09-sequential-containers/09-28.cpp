// 22/02/24 = Thu
// 18/01/17 = Wed

// Exercise 9.28: Write a function that takes a forward_list<string> and two
// additional string arguments. The function should find the first string and
// insert the second immediately following the first. If the first string is not
// found, then insert the second string at the end of the list.

#include <forward_list>
#include <iostream>
#include <iterator>
#include <string>

void print(const std::forward_list<std::string> &flst) {
  for (const std::string &elem : flst) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}

void insert(std::forward_list<std::string> &flst, const std::string &s1,
            const std::string &s2) {
  std::forward_list<std::string>::iterator prev = flst.before_begin(),
                                           curr = flst.begin();
  bool found = false;
  for (/* empty */; curr != flst.end(); prev = curr++) {
    if (*curr == s1) {
      curr = flst.insert_after(curr, s2);
      found = true;
    }
  }
  if (!found) {
    flst.insert_after(prev, s2);
  }
}

void test(std::forward_list<std::string> flst, const std::string &s1,
          const std::string &s2) {
  std::cout << "Original Forward List: ";
  print(flst);
  insert(flst, s1, s2);
  std::cout << "Modified Forward List: ";
  print(flst);
  std::cout << std::endl;
}

int main() {
  test({"Hello", "World"}, "World", "!");
  test({"Hello", "World"}, "World", "World");
  test({"Hey"}, "World", "!");
  test({"Hey"}, "World", "World");
  test({}, "World", "!");
  test({}, "World", "World");
  return 0;
}
