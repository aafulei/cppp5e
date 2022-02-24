// 22/02/24 = Thu
// 18/01/17 = Wed

// Exercise 9.27: Write a program to find and remove the odd-valued elements in
// a forward_list<int>.

#include <forward_list>
#include <iostream>

void print(const std::forward_list<int> &flst) {
  for (int i = 0; int elem : flst) { // C++20
    std::cout << (i++ == 0 ? "" : " ") << elem;
  }
  std::cout << std::endl;
}

void remove_odd_values(std::forward_list<int> &flst) {
  for (std::forward_list<int>::iterator curr = flst.begin(),
                                        prev = flst.before_begin();
       curr != flst.end();
       /* empty */) {
    if (*curr % 2 == 1) {
      curr = flst.erase_after(prev);
    } else {
      prev = curr;
      ++curr;
    }
  }
}

int main() {
  std::forward_list<int> flst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  print(flst);
  remove_odd_values(flst);
  print(flst);
  return 0;
}
