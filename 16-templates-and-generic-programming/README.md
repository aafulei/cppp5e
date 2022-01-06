# Chapter 16 Templates and Generic Programming

- [Section 16.1 Defining a Template](#section-161-defining-a-template)
  - *Exercises* [`16.1`](#exercise-161) [`16.2`](#exercise-162) [`16.3`](#exercise-163) [`16.4`](#exercise-164) [`16.5`](#exercise-165) [`16.6`](#exercise-166) [`16.7`](#exercise-167) [`16.8`](#exercise-168)
  - *Exercises* [`16.9`](#exercise-169) [`16.10`](#exercise-1610) [`16.11`](#exercise-1611) [`16.12`](#exercise-1612) [`16.13`](#exercise-1613) [`16.14`](#exercise-1614) [`16.15`](#exercise-1615) [`16.16`](#exercise-1616)
  - *Exercises* [`16.17`](#exercise-1617) [`16.18`](#exercise-1618) [`16.19`](#exercise-1619) [`16.20`](#exercise-1620)
  - *Exercises* [`16.21`](#exercise-1621) [`16.22`](#exercise-1622) [`16.23`](#exercise-1623) [`16.24`](#exercise-1624)
  - *Exercises* [`16.25`](#exercise-1625) [`16.26`](#exercise-1626) [`16.27`](#exercise-1627)
  - *Exercises* [`16.28`](#exercise-1628) [`16.29`](#exercise-1629) [`16.30`](#exercise-1630) [`16.31`](#exercise-1631)

- [Section 16.2 Template Argument Deduction](#section-162-template-argument-deduction)
  - *Exercises* [`16.32`](#exercise-1632) [`16.33`](#exercise-1633) [`16.34`](#exercise-1634) [`16.35`](#exercise-1635) [`16.36`](#exercise-1636)
  - *Exercises* [`16.37`](#exercise-1637) [`16.38`](#exercise-1638) [`16.39`](#exercise-1639)
  - *Exercises* [`16.40`](#exercise-1640) [`16.41`](#exercise-1641)
  - *Exercises* [`16.42`](#exercise-1642) [`16.43`](#exercise-1643) [`16.44`](#exercise-1644) [`16.45`](#exercise-1645)
  - *Exercises* [`16.46`](#exercise-1646)
  - *Exercises* [`16.47`](#exercise-1647)

- [Section 16.3 Overloading and Templates](#section-163-overloading-and-templates)
  - *Exercises* [`16.48`](#exercise-1648) [`16.49`](#exercise-1649) [`16.50`](#exercise-1650)

- [Section 16.4 Variadic Templates](#section-164-variadic-templates)
  - *Exercises* [`16.51`](#exercise-1651) [`16.52`](#exercise-1652)
  - *Exercises* [`16.53`](#exercise-1653) [`16.54`](#exercise-1654) [`16.55`](#exercise-1655)
  - *Exercises* [`16.56`](#exercise-1656) [`16.57`](#exercise-1657)
  - *Exercises* [`16.58`](#exercise-1658) [`16.59`](#exercise-1659) [`16.60`](#exercise-1660) [`16.61`](#exercise-1661)

- [Section 16.5 Template Specializations](#section-165-template-specializations)
  - *Exercises* [`16.62`](#exercise-1662) [`16.63`](#exercise-1663) [`16.64`](#exercise-1664) [`16.65`](#exercise-1665) [`16.66`](#exercise-1666) [`16.67`](#exercise-1667)

## Section 16.1 Defining a Template

### Exercise 16.1

> Define instantiation.

**Answer:**

- [`16-01.cpp`](16-01.cpp)

### Exercise 16.2

> Write and test your own versions of the compare functions.

**Answer:**

- [`16-02.cpp`](16-02.cpp)

### Exercise 16.3

> Call your compare function on two `Sales_data` objects to see how your compiler handles errors during instantiation.

**Answer:**

### Exercise 16.4

> Write a template that acts like the library find algorithm. The function will need two template type parameters, one to represent the function's iterator parameters and the other for the type of the value. Use your function to find a given value in a vector<int> and in a list<string>.

**Answer:**

- [`16-04.cpp`](16-04.cpp)

### Exercise 16.5

> Write a template version of the print function from Section 6.2.4 (p. 217) that takes a reference to an array and can handle arrays of any size and any element type.

**Answer:**

- [`16-05.cpp`](16-05.cpp)

### Exercise 16.6

> How do you think the library begin and end functions that take an array argument work? Define your own versions of these functions.

**Answer:**

- [`16-06.cpp`](16-06.cpp)

### Exercise 16.7

> Write a constexpr template that returns the size of a given array.

**Answer:**

- [`16-07.cpp`](16-07.cpp)

### Exercise 16.8

> In the "Key Concept" box on *page 108*, we noted that as a matter of habit C++ programmers prefer using != to using <. Explain the rationale for this habit.

**Answer:**

### Exercise 16.9

> What is a function template? What is a class template?

**Answer:**

### Exercise 16.10

> What happens when a class template is instantiated?

**Answer:**

### Exercise 16.11

> The following definition of List is incorrect. How would you fix it?
>
> ```c++
> template <typename elemType> class ListItem;
> template <typename elemType> class List {
> public:
>   List<elemType>();
>   List<elemType>(const List<elemType> &);
>   List<elemType> &operator=(const List<elemType> &);
>   ~List();
>   void insert(ListItem *ptr, elemType value);
>
> private:
>   ListItem *front, *end;
> };
> ```

**Answer:**

### Exercise 16.12

> Write your own version of the Blob and BlobPtr templates. including the various `const` members that were not shown in the text.

**Answer:**

- [`16-12.cpp`](16-12.cpp)

### Exercise 16.13

> Explain which kind of friendship you chose for the equality and relational operators for BlobPtr.

**Answer:**

### Exercise 16.14

> Write a Screen class template that uses nontype parameters to define the height and width of the Screen.

**Answer:**

- [`16-14.cpp`](16-14.cpp)

### Exercise 16.15

> Implement input and output operators for your Screen template. Which, if any, friends are necessary in class Screen to make the input and output operators work? Explain why each friend declaration, if any, was needed.

**Answer:**

- [`16-15.cpp`](16-15.cpp)

### Exercise 16.16

> Rewrite the StrVec class (Section 13.5, p. 526) as a template named Vec.

**Answer:**

- [`16-16.cpp`](16-16.cpp)

### Exercise 16.17

> What, if any, are the differences between a type parameter that is declared as a typename and one that is declared as a class? When must typename be used?

**Answer:**

### Exercise 16.18

> Explain each of the following function template declarations and identify whether any are illegal. Correct each error that you find.
>
> (a) `template <typename T, U, typename V> void f1(T, U, V);`
>
> (b) `template <typename T> T f2(int &T);`
>
> (c) `inline template <typename T> T foo(T, unsigned int*);`
>
> (d) `template <typename T> f4(T, T);`
>
> (e) `typedef char Ctype; template <typename Ctype> Ctype f5(Ctype a);`

**Answer:**

### Exercise 16.19

> Write a function that takes a reference to a container and prints the elements in that container. Use the container's size_type and size members to control the loop that prints the elements.

**Answer:**

- [`16-19.cpp`](16-19.cpp)

### Exercise 16.20

> Rewrite the function from the previous exercise to use iterators returned from begin and end to control the loop.

**Answer:**

- [`16-20.cpp`](16-20.cpp)

### Exercise 16.21

> Write your own version of DebugDelete.

**Answer:**

- [`16-21.cpp`](16-21.cpp)

### Exercise 16.22

> Revise your TextQuery programs from Section 12.3 (p. 484) so that the shared_ptr members use a DebugDelete as their deleter (Section 12.1.4, p. 468).

**Answer:**

- [`16-22.cpp`](16-22.cpp)

### Exercise 16.23

> Predict when the call operator will be executed in your main query program. If your expectations and what happens differ, be sure you understand why.

**Answer:**

### Exercise 16.24

> Add a constructor that takes two iterators to your Blob template.

**Answer:**

### Exercise 16.25

> Explain the meaning of these declarations:
>
> ```c++
> extern template class vector<string>;
> template class vector<Sales_data>;
> ```

**Answer:**

### Exercise 16.26

> Assuming NoDefault is a class that does not have a default constructor, can we explicitly instantiate vector<NoDefault>? If not, why not?

**Answer:**

### Exercise 16.27

> For each labeled statement explain what, if any, instantiations happen. If a template is instantiated, explain why; if not, explain why not.
>
> ```c++
> template <typename T> class Stack {};
> void f1(Stack<char>);
> class Exercise {
>   Stack<double> &rsd;
>   Stack<int> si;
> };
> int main() {
>   Stack<char> *sc;
>   f1(*sc);
>   int iObj = sizeof(Stack<string>);
> }
> ```

**Answer:**

### Exercise 16.28

> Write your own versions of shared_ptr and unique_ptr.

**Answer:**

- [`16-28.cpp`](16-28.cpp)

### Exercise 16.29

> Revise your Blob class to use your version of shared_ptr rather than the library version.

**Answer:**

- [`16-29.cpp`](16-29.cpp)

### Exercise 16.30

> Rerun some of your programs to verify your shared_ptr and revised Blob classes. (Note: Implementing the weak_ptr type is beyond the scope of this Primer, so you will not be able to use the BlobPtr class with your revised Blob.)

**Answer:**

- [`16-30.cpp`](16-30.cpp)

### Exercise 16.31

> Explain how the compiler might inline the call to the deleter if we used DebugDelete with unique_ptr.

**Answer:**

## Section 16.2 Template Argument Deduction

### Exercise 16.32

> What happens during template argument deduction?

**Answer:**

### Exercise 16.33

> Name two type conversions allowed on function arguments involved in template argument deduction.

**Answer:**

### Exercise 16.34

> Given only the following code, explain whether each of these calls is legal. If so, what is the type of T? If not, why not?
>
> ```c++
> template <class T> int compare(const T &, const T &);
> ```
>
> (a) `compare("hi", "world"); (b) compare("bye", "dad");`

**Answer:**

### Exercise 16.35

> Which, if any, of the following calls are errors? If the call is legal, what is the type of T? If the call is not legal, what is the problem?
>
> ```c++
> template <typename T> T calc(T, int);
> template <typename T> T fcn(T, T);
> double d;
> float f;
> char c;
> ```
>
> (a) `calc(c, 'c');`
>
> (b) `calc(d, f);`
>
> (c) `fcn(c, 'c');`
>
> (d) `fcn(d, f);`

**Answer:**

### Exercise 16.36

> What happens in the following calls:
>
> ```c++
> template <typename T> f1(T, T);
> template <typename T1, typename T2) f2(T1, T2);
> int i = 0, j = 42, *p1 = &i, *p2 = &j;
> const int *cp1 = &i, *cp2 = &j;
> ```
>
> (a) `f1(p1, p2);`
>
> (b) `f2(p1, p2);`
>
> (c) `f1(cp1, cp2);`
>
> (d) `f2(cp1, cp2); (e) f1(p1, cp1); (e) f2(p1, cp1);`

**Answer:**

### Exercise 16.37

> The library max function has two function parameters and returns the larger of its arguments. This function has one template type parameter. Could you call max passing it an `int` and a `double`? If so, how? If not, why not?

**Answer:**

### Exercise 16.38

> When we call make_shared (Section 12.1.1, p. 451), we have to provide an explicit template argument. Explain why that argument is needed and how it is used.

**Answer:**

### Exercise 16.39

> Use an explicit template argument to make it sensible to pass two string literals to the original version of compare from Section 16.1.1 (p. 652).

**Answer:**

### Exercise 16.40

> Is the following function legal? If not, why not? If it is legal, what, if any, are the restrictions on the argument type(s) that can be passed, and what is the return type?
>
> ```c++
> template <typename It> auto fcn3(It beg, It end) -> decltype(*beg + 0) {
>   // process the range
>   return *beg; // return a copy of an element from the range
> }
> ```

**Answer:**

### Exercise 16.41

> Write a version of sum with a return type that is guaranteed to be large enough to hold the result of the addition.

**Answer:**

- [`16-41.cpp`](16-41.cpp)

### Exercise 16.42

> Determine the type of T and of val in each of the following calls:
>
> ```c++
> template <typename T> void g(T &&val);
> int i = 0;
> const int ci = i;
> ```
>
> (a) `g(i);`
>
> (b) `g(ci);`
>
> (c) `g(i * ci);`

**Answer:**

### Exercise 16.43

> Using the function defined in the previous exercise, what would the template parameter of g be if we called g(i = ci)?

**Answer:**

### Exercise 16.44

> Using the same three calls as in the first exercise, determine the types for T if g's function parameter is declared as T (not T&&). What if g's function parameter is const T&?

**Answer:**

### Exercise 16.45

> Given the following template, explain what happens if we call g on a literal value such as 42. What if we call g on a variable of type `int`?
>
> ```c++
> template <typename T> void g(T &&val) { vector<T> v; }
> ```

**Answer:**

### Exercise 16.46

> Explain this loop from StrVec::reallocate in Section 13.5 (p. 530):
>
> ```c++
> for (size_t i = 0; i != size(); ++i)
>   alloc.construct(dest++, std::move(*elem++));
> ```

**Answer:**

### Exercise 16.47

> Write your own version of the flip function and test it by calling functions that have lvalue and rvalue reference parameters.

**Answer:**

- [`16-47.cpp`](16-47.cpp)

## Section 16.3 Overloading and Templates

### Exercise 16.48

> Write your own versions of the debug_rep functions.

**Answer:**

- [`16-48.cpp`](16-48.cpp)

### Exercise 16.49

> Explain what happens in each of the following calls:
>
> ```c++
> template <typename T> void f(T);
> template <typename T> void f(const T *);
> template <typename T> void g(T);
> template <typename T> void g(T *);
> int i = 42, *p = &i;
> const int ci = 0, *p2 = &ci;
> g(42);
> g(p);
> g(ci);
> g(p2);
> f(42);
> f(p);
> f(ci);
> f(p2);
> ```

**Answer:**

### Exercise 16.50

> Define the functions from the previous exercise so that they print an identifying message. Run the code from that exercise. If the calls behave differently from what you expected, make sure you understand why.

**Answer:**

- [`16-50.cpp`](16-50.cpp)

## Section 16.4 Variadic Templates

### Exercise 16.51

> Determine what sizeof...(Args) and sizeof...(rest) return for each call to foo in this section.

**Answer:**

### Exercise 16.52

> Write a program to check your answer to the previous question.

**Answer:**

- [`16-52.cpp`](16-52.cpp)

### Exercise 16.53

> Write your own version of the print functions and test them by printing one, two, and five arguments, each of which should have different types.

**Answer:**

- [`16-53.cpp`](16-53.cpp)

### Exercise 16.54

> What happens if we call print on a type that doesn't have an << operator?

**Answer:**

### Exercise 16.55

> Explain how the variadic version of print would execute if we declared the nonvariadic version of print after the definition of the variadic version.

**Answer:**

### Exercise 16.56

> Write and test a variadic version of errorMsg.

**Answer:**

- [`16-56.cpp`](16-56.cpp)

### Exercise 16.57

> Compare your variadic version of errorMsg to the error_msg function in Section 6.2.6 (p. 220). What are the advantages and disadvantages of each approach?

**Answer:**

### Exercise 16.58

> Write the emplace_back function for your StrVec class and for the Vec class that you wrote for the exercises in Section 16.1.2 (p. 668).

**Answer:**

- [`16-58.cpp`](16-58.cpp)

### Exercise 16.59

> Assuming s is a string, explain svec.emplace_back(s).

**Answer:**

### Exercise 16.60

> Explain how make_shared (Section 12.1.1, p. 451) works.

**Answer:**

### Exercise 16.61

> Define your own version of make_shared.

**Answer:**

- [`16-61.cpp`](16-61.cpp)

## Section 16.5 Template Specializations

### Exercise 16.62

> Define your own version of hash<Sales_data> and define an unordered_multiset of `Sales_data` objects. Put several transactions into the container and print its contents.

**Answer:**

- [`16-62.cpp`](16-62.cpp)

### Exercise 16.63

> Define a function template to count the number of occurrences of a given value in a vector. Test your program by passing it a vector of doubles, a vector of ints, and a vector of strings.

**Answer:**

- [`16-63.cpp`](16-63.cpp)

### Exercise 16.64

> Write a specialized version of the template from the previous exercise to handle `vector<const char *>` and a program that uses this specialization.

**Answer:**

- [`16-64.cpp`](16-64.cpp)

### Exercise 16.65

> In Section 16.3 (p. 698) we defined overloaded two versions of debug_rep one had a const char* and the other a char* parameter. Rewrite these functions as specializations.

**Answer:**

- [`16-65.cpp`](16-65.cpp)

### Exercise 16.66

> What are the advantages and disadvantages of overloading these debug_rep functions as compared to defining specializations?

**Answer:**

### Exercise 16.67

> Would defining these specializations affect function matching for debug_rep? If so, how? If not, why not?

**Answer:**

