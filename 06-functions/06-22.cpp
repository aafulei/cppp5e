// 22/02/02 = Wed
// 18/02/06 = Tue

// Exercise 6.22: Write a function to swap two int pointers.

#include <iostream>

void swap_by_ptr(int **ppa, int **ppb) {
  int *ppt = *ppa;
  *ppa = *ppb;
  *ppb = ppt;
}

void swap_by_ref(int *&pa, int *&pb) {
  int *pt = pa;
  pa = pb;
  pb = pt;
}

void test() {
  int a = 3, b = 4, *pa = &a, *pb = &b;
  std::cout << "*pa = " << *pa << ", *pb = " << *pb << std::endl;
  swap_by_ptr(&pa, &pb);
  std::cout << "*pa = " << *pa << ", *pb = " << *pb << std::endl;
  swap_by_ref(pa, pb);
  std::cout << "*pa = " << *pa << ", *pb = " << *pb << std::endl;
}

int main() {
  test();
  return 0;
}
