# Chapter 6 Functions

- [Section 6.1 Function Basics](#section-61-function-basics)
  - Exercises [`6.1`](#exercise-61) [`6.2`](#exercise-62) [`6.3`](#exercise-63) [`6.4`](#exercise-64) [`6.5`](#exercise-65)
  - Exercises [`6.6`](#exercise-66) [`6.7`](#exercise-67)
  - Exercises [`6.8`](#exercise-68)
  - Exercises [`6.9`](#exercise-69)

- [Section 6.2 Argument Passing](#section-62-argument-passing)
  - Exercises [`6.10`](#exercise-610)
  - Exercises [`6.11`](#exercise-611) [`6.12`](#exercise-612) [`6.13`](#exercise-613) [`6.14`](#exercise-614) [`6.15`](#exercise-615)
  - Exercises [`6.16`](#exercise-616) [`6.17`](#exercise-617) [`6.18`](#exercise-618) [`6.19`](#exercise-619) [`6.20`](#exercise-620)
  - Exercises [`6.21`](#exercise-621) [`6.22`](#exercise-622) [`6.23`](#exercise-623) [`6.24`](#exercise-624)
  - Exercises [`6.25`](#exercise-625) [`6.26`](#exercise-626)
  - Exercises [`6.27`](#exercise-627) [`6.28`](#exercise-628) [`6.29`](#exercise-629)

- [Section 6.3 Return Types and the `return` Statement](#section-63-return-types-and-the-return-statement)
  - Exercises [`6.30`](#exercise-630) [`6.31`](#exercise-631) [`6.32`](#exercise-632) [`6.33`](#exercise-633) [`6.34`](#exercise-634) [`6.35`](#exercise-635)
  - Exercises [`6.36`](#exercise-636) [`6.37`](#exercise-637) [`6.38`](#exercise-638)

- [Section 6.4 Overloaded Functions](#section-64-overloaded-functions)
  - Exercises [`6.39`](#exercise-639)

- [Section 6.5 Features for Specialized Uses](#section-65-features-for-specialized-uses)
  - Exercises [`6.40`](#exercise-640) [`6.41`](#exercise-641) [`6.42`](#exercise-642)
  - Exercises [`6.43`](#exercise-643) [`6.44`](#exercise-644) [`6.45`](#exercise-645) [`6.46`](#exercise-646)
  - Exercises [`6.47`](#exercise-647) [`6.48`](#exercise-648)

- [Section 6.6 Function Matching](#section-66-function-matching)
  - Exercises [`6.49`](#exercise-649) [`6.50`](#exercise-650) [`6.51`](#exercise-651)
  - Exercises [`6.52`](#exercise-652) [`6.53`](#exercise-653)

- [Section 6.7 Pointers to Functions](#section-67-pointers-to-functions)
  - Exercises [`6.54`](#exercise-654) [`6.55`](#exercise-655) [`6.56`](#exercise-656)

### Exercise 6.1

> What is the difference between a parameter and an argument?

**Answer:**

- Parameter: also called *"formal argument"*. Local variables defined in the function's parameter list, which are initialized from the arguments provided in the function call.

- Argument: also called *"actual argument".* Values supplied in the function call, which are used to initialize the function's parameters.

### Exercise 6.2

> Indicate which of the following functions are in error and why.
Suggest how you might correct the problems.

(a)

```c++
int f() {
     string s;
     // ...
     return s;
 }
```

**Answer:** Return type is `int`, but returns a `string`. May change return type from `int` to `string`.

(b)

```c++
f2(int i) { /* ... */ }
```

**Answer:** Missing return type in the definition. May specify return type as `void` if nothing to return.

(c)

```c++
int calc(int v1, int v1) /* ... */ }
```

**Answer:** Duplicated names in parameter list. May change `v1` to `v2`.

(d)

```c++
double square(double x) return x * x;
```

**Answer:** Missing curly braces for the function body. May add a pair of curly braces around the body.//

### Exercise 6.3

> Write and test your own version of `fact`.

**Answer:**

### Exercise 6.4

> Write a function that interacts with the user, asking for a number and generating the factorial of that number. Call this function from main.

**Answer:**

### Exercise 6.5

> Write a function to return the absolute value of its argument.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

double abs(double x)
{
  return x >= 0 ? x : -x;
}

int main()
{
  for (double x;
    cout << "Enter a number: ", cin >> x, cin.ignore(256, '\n');
    cout << "|" << x << "| = " << abs(x) << endl)
      ;
  return 0;
}

### Exercise 6.6

> Explain the differences between a parameter, a local variable, and a local static variable. Give an example of a function in which each might be useful.

**Answer:** Consider

```c++
void foo(int a)
{
  int b = a * a;
  static int c; // value initialized
  cout << "# call = " << ++c;
  return b;
}
```

`a` is a parameter, `b` is a local variable, and `c` is a local static variable.

|                | parameter                                | local variable                           | local static variable                    |
| -------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
| definition     | in the parameter list                    | in the function body                     | in the function body                     |
| initialization | initialized from the corresponding argument | default initialized if without an explicit initializer | value initialized if without an explicit initializer |
| destruction    | when function ends                       | when function ends                       | when program terminates                  |
| lifetime       | within one call                          | within one call                          | across calls                             |

//

### Exercise 6.7

> Write a function that returns 0 when it is first called and then generates numbers in sequence each time it is called again.

#include <iostream>

using std::cout;
using std::endl;

unsigned call()
{
  static int c;
  return c++;
}

int main()
{
  for (int i = 0; i < 10; ++i)
    cout << call() << endl;
  return 0;
}

### Exercise 6.8

> Write a header file named Chapter6.h that contains declarations for the functions you wrote for the exercises in § 6.1 (p. 205).

**Answer:**

### Exercise 6.3

> Write and test your own version of fact.

**Answer:**

### Exercise 6.4

> Write a function that interacts with the user, asking for a number and generating the factorial of that number. Call this function from main.

**Answer:**

### Exercise 6.7

> Write a function that returns 0 when it is first called and then generates numbers in sequence each time it is called again.

#ifndef CHAPTER6_H
#define CHAPTER6_H

unsigned long long fact(unsigned short);
void generate();
unsigned call();

#endif//

**Answer:**

### Exercise 6.9

> Write your own versions of the fact.cc and factMain.cc files. These files should include your Chapter6.h from the exercises in the previous section. Use these files to understand how your compiler supports separate compilation.

// This correspond to fact.cc

// To compile, use either one of the two ways:
// 1.   g++ lp-06-09-fact.cpp lp-06-09-generate.cpp
// 2.   g++ lp-06-09-fact.cpp -c
//    g++ lp-06-09-generate.cpp -c
//    g++ lp-06-09-generate.o lp-06-09-fact.o

#include "include\Chapter6.h"

unsigned long long fact(unsigned short n)
{
  return n == 0 ? 1ULL : n * fact(n-1);
}
//

### Exercise 6.9

> Write your own versions of the fact.cc and factMain.cc files. These files should include your Chapter6.h from the exercises in the previous section. Use these files to understand how your compiler supports separate compilation.

**Answer:**

### Exercise 6.10

> Using pointers, write a function to swap the values of two ints. Test the function by calling it and printing the swapped values.

**Answer:**

### Exercise 6.11

> Write and test your own version of reset that takes a reference.

**Answer:**

### Exercise 6.12

> Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use references instead of pointers to swap the value of two ints. Which version do you think would be easier to use and why?

**Answer:**

### Exercise 6.13

> Assuming `T` is the name of a type, explain the difference between a function declared as `void f(T)` and `void f(T&)`.

**Answer:**

Pass by value versus pass by reference.

### Exercise 6.14

> Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.

**Answer:** To use a reference type: change all the letters in a string to uppercase. For example,

```c++
void uppper(string &s)
{
  for (auto & c : s)
    c = toupper(c);
}
```

Not to use a reference type: when passing a pointer, we may take the address directly, and there is no need to use a reference. For example,

```c++
void print(int * p, int n)
{
  while (n-- > 0)
    cout << *p++ << " ";
}

int main()
{
    int a[] = {1, 2, 3};
  print(a, sizeof a / sizeof a[0]);
  return 0;
}
```

### Exercise 6.15

> Explain the rationale for the type of each of `find_char`’s parameters In particular, why is `s` a reference to const but `occurs` is a plain reference? Why are these parameters references, but the char parameter `c` is not? What would happen if we made `s` a plain reference? What if we made `occurs` a reference to const?

```c++
string::size_type find_char(const string &s, char c,
                           string::size_type &occurs)
{
    auto ret = s.size();   // position of the first occurrence, if any
    occurs = 0;            // set the occurrence count parameter
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;   // remember the first occurrence of c
            ++occurs;      // increment the occurrence count
         }
    }
    return ret;            // count is returned implicitly in occurs
}
```

**Answer:** `const` for `s` because we do not plan to change it. However, we are to make change to `occurs` which is used as a counter. `c` is temporary and is a `char`, which is easy to pass by value. If we made `s` a plain reference, we may make changes to it. If we made `occurs` a reference-to-const, then there would be a compilation error since we are not allowed to change it.

### Exercise 6.16

> The following function, although legal, is less useful than it might be. Identify and correct the limitation on this function:

```c++
bool is_empty(string& s) { return s.empty(); }
```

**Answer:** Since the function does not change `s`, the reference should be declared as a reference-to-const.

```c++
bool is_empty(const string & s)
{
  return s.empty();
}
```

### Exercise 6.17

> Write a function to determine whether a string contains any capital letters. Write a function to change a string to all lowercase. Do the parameters you used in these functions have the same type? If so, why? If not, why not?


**Answer:**

No. The first functions does not change the string while the second does.

### Exercise 6.18

> Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does.

(a) A function named `compare` that returns a `bool` and has two parameters that are references to a class named `matrix`.

(b) A function named `change_val` that returns a `vector<int>` iterator and takes two parameters: One is an `int` and the other is an iterator for a `vector<int>`.

**Answer:**

(a)

```c++
bool compare(const matrix &, const matrix &);
```

(b)

```c++
vector<int>::iterator change_val(int, vector<int>::iterator);
```

### Exercise 6.19

> Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why.

```c++
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
```

(a) `calc(23.4, 55.1);`

(b) `count("abcda", 'a');`

(c) `calc(66);`

(d) `sum(vec.begin(), vec.end(), 3.8);`

**Answer:**

(a) illegal, because the number of arguments mismatch with that of parameters.

(b) legal.

(c) legal  (conversion from `int` to `double` is possible).

(d) legal (conversion from `double` to `int` is possible).

### Exercise 6.20

> When should reference parameters be references to const? What happens if we make a parameter a plain reference when it could be a reference to const?

**Answer:**

Whenever the function does not change the value of the parameters. Then we would fail in passing const objects and literals that are possible to bind to references to const.//

### Exercise 6.21

> Write a function that takes an int and a pointer to an int and returns the larger of the int value or the value to which the pointer points. What type should you use for the pointer?

**Answer:**


### Exercise 6.22

> Write a function to swap two int pointers.

**Answer:**

### Exercise 6.23

> Write your own versions of each of the print functions presented in this section. Call each of these functions to print i and j defined as follows:

**Answer:**

### Exercise 6.24

> Explain the behavior of the following function. If there are problems in the code, explain what they are and how you might fix them.

```c++
void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
```

**Answer:** Compiler will not verify the size of `ia`. What is really passed is a `const int *`.

```c++
template<size_t N>
void print(int (&a)[N])
{
  for (auto i : a)
    cout << i << endl;
}
```

### Exercise 6.25

> Write a main function that takes two arguments. Concatenate the supplied arguments and print the resulting string.

**Answer:**

### Exercise 6.26

> Write a program that accepts the options presented in this section. Print the values of the arguments passed to main.

**Answer:**

### Exercise 6.27

> Write a function that takes an initializer_list<int> and produces the sum of the elements in the list.

**Answer:**

### Exercise 6.28

> In the second version of error_msg that has an `ErrCode` parameter, what is the type of `elem` in the for loop?

```c++
void error_msg(ErrCode e, initializer_list<string> il)
{
    cout << e.msg() << ": ";
    for (const auto &elem : il)
        cout << elem << " " ;
    cout << endl;
}
```

**Answer:**

`const string &`

### Exercise 6.29

> When you use an `initializer_list` in a range for would you ever use a reference as the loop control variable? If so, why? If not, why not?

**Answer:**

Yes, if the element type is expensive to copy. `const auto &` is suggested, to make it clear that we promise not to change any element in the list. However, since the elements in an `initializer_list` are `const` automatically, it should be the same if we just deduce by `auto &`.//

### Exercise 6.30

> Compile the version of str_subrange as presented on page 223 to see what your compiler does with the indicated errors.


**Answer:**

## Exercise 6.31

> When is it valid to return a reference? A reference to const?

**Answer:**

When the reference refers to an object that exists after the called function ends. For a reference-to-const, as an additional requirement, the caller should promise not to change the object via the returned reference.

### Exercise 6.32

> Indicate whether the following function is legal. If so, explain what it does; if not, correct any errors and then explain it.

```c++
int &get(int *arry, int index) { return arry[index]; }
int main() {
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
}
```

**Answer:**

Yes, it is legal. It assigns to elements of array `ia[10]` their indices.

### Exercise 6.33

> Write a recursive function to print the contents of a vector.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// Options for parameters:
// 1. vector and one iterator;
// 2. two iterators.
// Option 2 is preferred to follow the convetion of an iterator range.
void recursive_print(vector<int>::iterator b, vector<int>::const_iterator e)
{
  if (b == e)
    cout << endl;
  else {
    cout << *b++ << " ";
    recursive_print(b, e);
  }
}

int main()
{
  vector<int> vec {1, 2, 3, 4, 5};
  recursive_print(vec.begin(), vec.cend());
  return 0;
}

### Exercise 6.34

> What would happen if the stopping condition in factorial were `if (val != 0)`?

```c++
// calculate val!, which is 1 * 2 * 3 . . . * val
int factorial(int val)
{
    if (val > 1)
        return factorial(val-1) * val;
    return 1;
}
```

**Answer:**

Disaster for negative `val`.

### Exercise 6.35

> In the call to `factorial`, why did we pass `val - 1` rather than `val--`?

**Answer:**

Value of `val--` is unchanged from original `val`.//

### Exercise 6.36

> Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, decltype, or a type alias.

**Answer:**

### Exercise 6.37

> Write three additional declarations for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should use decltype. Which form do you prefer and why?

**Answer:**

### Exercise 6.36

> Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, decltype, or a type alias.

**Answer:**

### Exercise 6.38

> Revise the arrPtr function on to return a reference to the array.

**Answer:**

### Exercise 6.39

> Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.

```c++
(a) int calc(int, int);
int calc(const int, const int);
(b) int get();
double get();
(c) int *reset(int *);
double *reset(double *);
```

**Answer:**

(a) illegal, since the top-level const are ignored when arguments are passed.

(b) illegal, since only return types differ.

(c) legal.18/02/08 = Thu

### Exercise 6.40

> Which, if either, of the following declarations are errors? Why?

(a)

```c++
int ff(int a, int b = 0, int c = 0);
```

(b)

```c++
char *init(int ht = 24, int wd, char bckgrnd);
```

**Answer:**

(b) is an error. Because we can only omit trailing arguments, if we had supplied a default argument for a parameter, we would have to supply default arguments for all the parameters following it.

*The general principle is to put the parameter that you are most likely to change first, and the one you are least likely to change last.*

### Exercise 6.41

> Which, if any, of the following calls are illegal? Why? Which, if any, are legal but unlikely to match the programmer’s intent? Why?

```c++
char *init(int ht, int wd = 80, char bckgrnd = ' ');
```

(a) `init();`

(b) `init(24, 10);`

(c) `init(14, '*');`

**Answer:**

(a) is illegal. (c) is unlikely to match the programmer's intent because `'*'` is supplied to as an argument to `wd`.// 18/02/08 = Thu

### Exercise 6.42

> Give the second parameter of make_plural (§ 6.3.2, p. 224) a default argument of 's'. Test your program by printing singular and plural versions of the words success and failure.

**Answer:**

### Exercise 6.43

> Which one of the following declarations and definitions would you put in a header? In a source file? Explain why.

(a) `inline bool eq(const BigInt&, const BigInt&) {...}`

(b) `void putValues(int *arr, int size);`

**Answer:**

Both. (a) is an inline function definition, while (b) is a function declaration.// 18/02/08 = Thu

### Exercise 6.44

> Rewrite the isShorter function from § 6.2.2 (p. 211) to be inline.

**Answer:**

### Exercise 6.45

> Review the programs you’ve written for the earlier exercises and decide whether they should be defined as inline. If so, do so. If not, explain why they should not be inline.

**Answer:**

`inline` suggested if the functions are simple and frequently called.

### Exercise 6.46

> Would it be possible to define `isShorter` as a `constexpr`? If so, do so. If not, explain why not.

```c++
inline bool isShorter(const string & s1, const string & s2)
{ return s1.size() < s2.size(); }
```

**Answer:**

No. `string` is not a literal type.

### Exercise 6.47

> Revise the program you wrote in the exercises in § 6.3.2 (p. 228) that used recursion to print the contents of a vector to conditionally print information about its execution. For example, you might print the size of the vector on each call. Compile and run the program with debugging turned on and again with it turned off.


**Answer:**


### Exercise 6.48

> Explain what this loop does and whether it is a good use of `assert`:

```c++
string s;
while (cin >> s && s != sought) { }  // empty body
assert(cin);
```

**Answer:**

Repeatedly read standard input to a `string`, whose name is `s`, until the standard input fails or `sought` is read.

No, it is not a good use of `assert`, because `assert` should not be used to perform run-time check.18/02/08 = Thu

### Exercise 6.49

> What is a candidate function? What is a viable function?

**Answer:**

A candidate function is a function with the same name as the called function and for which the declaration is visible at the point of the call. A viable function in addition must have the same number of parameters as there are arguments in the call.

### Exercise 6.50

>  Given  the  declarations  for `f`  from  *page 242*,  list  the  viable functions, if any for each of the following calls. Indicate which function is the best match, or if the call is illegal whether there is no match or why the call is ambiguous.

```c++
void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);
```

(a) `f(2.56, 42)`

(b) `f(42)`

(c) `f(42, 0)`

(d) `f(2.56, 3.14)`

**Answer:**

(a) viable functions: `f(int, int)` and `f(double, double = 3.14)`. Ambiguous call as there is no better match over the other.

(b) viable functions: `f(int)` and `f(double, double = 3.14)`. Best match is `f(int)` since the types of the parameter and the argument are identical.

(c) viable functions: `f(int, int)` and `f(double, double = 3.14)`. Best match is `f(int, int)` since the types of the parameters and the arguments are identical.

(d) viable functions: `f(int, int)` and `f(double, double = 3.14)`. Best match is `f(double, double = 3.14)` since the types of the parameters and the arguments are identical.

### Exercise 6.51

> Write all four versions of f. Each function should print a distinguishing message. Check your answers for the previous exercise. If your answers were incorrect, study this section until you understand why your answers were wrong.

**Answer:**

### Exercise 6.52

> Given the following declarations,

```c++
void manip(int, int);
double dobj;
```

what is the rank (*§ 6.6.1, p. 245*) of each conversion in the following calls?

(a) `manip('a', 'z');`

(b) `manip(55.4, dobj);`

**Answer:**

(a) 3rd rank -- integral promotion; (b) 4th rank -- arithmetic conversion.

1. exact match (identical, array/function-to-pointer, top-level const)
2. const conversion
3. integral promotion
4. arithmetic/pointer conversion
5. class-type conversion

### Exercise 6.53

> Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.

(a)

```c++
int calc(int&, int&);
int calc(const int&, const int&);
```

(b)

```c++
int calc(char*, char*);
int calc(const char*, const char*);
```

(c)

```c++
int calc(char, char);
int calc(char* const, char* const);
```

**Answer:**

(a) and (b) offer better matches for arguments with low-level const. (c) is illegal because merely top-level const does not differentiate the arguments.// 18/02/08 = Thu

### Exercise 6.54

> Write a declaration for a function that takes two int parameters and returns an int, and declare a vector whose elements have this function pointer type.

**Answer:**

### Exercise 6.55

> Write four functions that add, subtract, multiply, and divide two int values. Store pointers to these values in your vector from the previous exercise.

**Answer:**


### Exercise 6.56

> Call each element in the vector and print their result.

**Answer:**


