// 22/02/24 = Thu
// 18/02/19 = Mon
// 18/01/18 = Thu

// Exercise 9.31: The program on page 354 to remove even-valued elements and
// duplicate odd ones will not work on a list or forward_list. Why? Revise the
// program so that it works on these types as well.

// vector<int> int = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// auto iter = vi.begin();
// while (iter != vi.end()) {
//   if (*iter % 2) {
//     iter = vi.insert(iter, *iter);
//     iter += 2;
//   } else
//     iter = vi.erase(iter);
// }

// Answer: Because operator+= is not defined for list and forward_list. We need
// to use operator++. Besides, for forward_list, we need to use specialized
// operations, i.e. insert_after() and erase_after().

#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

template <typename Seq> void print(const Seq &seq) {
  for (int i = 0; int elem : seq) {
    std::cout << (i++ == 0 ? "" : " ") << elem;
  }
  std::cout << std::endl;
}

int main() {
  // list
  std::list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  print(lst);
  auto iter = lst.begin();
  while (iter != lst.end()) {
    if (*iter % 2) {
      iter = lst.insert(iter, *iter);
      ++iter;
      ++iter;
    } else {
      iter = lst.erase(iter);
    }
  }
  print(lst);
  // forward list
  std::forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  print(flst);
  auto prev = flst.before_begin(), curr = flst.begin();
  while (curr != flst.end()) {
    if (*curr % 2) {
      curr = flst.insert_after(prev, *curr);
      ++curr;
      ++curr;
      ++prev;
      ++prev;
    } else {
      curr = flst.erase_after(prev);
    }
  }
  print(flst);
  return 0;
}
