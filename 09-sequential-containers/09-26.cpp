// 22/02/24 = Thu
// 18/02/19 = Mon
// 18/01/17 = Wed

// Exercise 9.26: Using the following definition of ia, copy ia into a vector
// and into a list. Use the single-iterator form of erase to remove the elements
// with odd values from your list and the even values from your vector.

// int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

#include <iostream>
#include <iterator>
#include <list>
#include <vector>

template <typename Seq> void print(const Seq &seq) {
  for (int i = 0; int elem : seq) { // C++20
    std::cout << (i++ == 0 ? "" : " ") << elem;
  }
  std::cout << std::endl;
}

int main() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  // list
  std::list<int> lst(std::begin(ia), std::end(ia));
  std::cout << "Original list: ";
  print(lst);
  for (std::list<int>::iterator it = lst.begin(); it != lst.end();
       /* empty */) {
    if (*it % 2 == 1) {
      it = lst.erase(it);
    } else {
      ++it;
    }
  }
  std::cout << "Modified list: ";
  print(lst);
  // vector
  std::vector<int> vec(std::begin(ia), std::end(ia));
  std::cout << "Original vector: ";
  print(vec);
  for (std::vector<int>::iterator it = vec.begin(); it != vec.end();
       /* empty */) {
    if (*it % 2 == 0) {
      it = vec.erase(it);
    } else {
      ++it;
    }
  }
  std::cout << "Modified vector: ";
  print(vec);
  return 0;
}
