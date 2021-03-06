# Chapter 6 Functions

- [Section 6.1 Function Basics](#section-61-function-basics)
  - *Exercises* [`6.1`](#exercise-61) [`6.2`](#exercise-62) [`6.3`](#exercise-63) [`6.4`](#exercise-64) [`6.5`](#exercise-65)
  - *Exercises* [`6.6`](#exercise-66) [`6.7`](#exercise-67)
  - *Exercises* [`6.8`](#exercise-68)
  - *Exercises* [`6.9`](#exercise-69)

- [Section 6.2 Argument Passing](#section-62-argument-passing)
  - *Exercises* [`6.10`](#exercise-610)
  - *Exercises* [`6.11`](#exercise-611) [`6.12`](#exercise-612) [`6.13`](#exercise-613) [`6.14`](#exercise-614) [`6.15`](#exercise-615)
  - *Exercises* [`6.16`](#exercise-616) [`6.17`](#exercise-617) [`6.18`](#exercise-618) [`6.19`](#exercise-619) [`6.20`](#exercise-620)
  - *Exercises* [`6.21`](#exercise-621) [`6.22`](#exercise-622) [`6.23`](#exercise-623) [`6.24`](#exercise-624)
  - *Exercises* [`6.25`](#exercise-625) [`6.26`](#exercise-626)
  - *Exercises* [`6.27`](#exercise-627) [`6.28`](#exercise-628) [`6.29`](#exercise-629)

- [Section 6.3 Return Types and the return Statement](#section-63-return-types-and-the-return-statement)
  - *Exercises* [`6.30`](#exercise-630) [`6.31`](#exercise-631) [`6.32`](#exercise-632) [`6.33`](#exercise-633) [`6.34`](#exercise-634) [`6.35`](#exercise-635)
  - *Exercises* [`6.36`](#exercise-636) [`6.37`](#exercise-637) [`6.38`](#exercise-638)

- [Section 6.4 Overloaded Functions](#section-64-overloaded-functions)
  - *Exercises* [`6.39`](#exercise-639)

- [Section 6.5 Features for Specialized Uses](#section-65-features-for-specialized-uses)
  - *Exercises* [`6.40`](#exercise-640) [`6.41`](#exercise-641) [`6.42`](#exercise-642)
  - *Exercises* [`6.43`](#exercise-643) [`6.44`](#exercise-644) [`6.45`](#exercise-645) [`6.46`](#exercise-646)
  - *Exercises* [`6.47`](#exercise-647) [`6.48`](#exercise-648)

- [Section 6.6 Function Matching](#section-66-function-matching)
  - *Exercises* [`6.49`](#exercise-649) [`6.50`](#exercise-650) [`6.51`](#exercise-651)
  - *Exercises* [`6.52`](#exercise-652) [`6.53`](#exercise-653)

- [Section 6.7 Pointers to Functions](#section-67-pointers-to-functions)
  - *Exercises* [`6.54`](#exercise-654) [`6.55`](#exercise-655) [`6.56`](#exercise-656)

## Section 6.1 Function Basics

### Exercise 6.1

> What is the difference between a parameter and an argument?

**Answer:**

- A parameter is a local variable defined in a function's parameter list.

- An argument is a value that is used to initialize the parameter.

### Exercise 6.2

> Indicate which of the following functions are in error and why. Suggest how you might correct the problems.
>
> (a)
>
> ```c++
> int f() {
>   string s;
>   // ...
>   return s;
> }
> ```
>
> (b)
>
> ```c++
> f2(int i) { /* ... */ }
> ```
>
> (c)
>
> ```c++
> int calc(int v1, int v1)  /* ... */ }
> ```
>
> (d)
>
> ```c++
> double square(double x) return x * x;
> ```

**Answer:**

(a) Problem - return value does not match the return type. Fix -

```c++
string f() {
  string s;
  // ...
  return s;
}
```

(b) Problem - missing return type. Fix -

```c++
void f(int i) { /* ... */}
```

(c) Problem - duplicated parameter names; missing an opening curly brace. Fix -

```c++
int calc(int v1, int v2) { /* ... */}
```

(d) Problem - missing curly braces. Fix -

```c++
double square(double) { return x * x; }
```

### Exercise 6.3

> Write and test your own version of `fact`.

**Answer:**

- [`06-03.cpp`](06-03.cpp)

### Exercise 6.4

> Write a function that interacts with the user, asking for a number and generating the factorial of that number. Call this function from `main`.

**Answer:**

- [`06-04.cpp`](06-04.cpp)

### Exercise 6.5

> Write a function to return the absolute value of its argument.

**Answer:**

- [`06-05.cpp`](06-05.cpp)

### Exercise 6.6

> Explain the differences between a parameter, a local variable, and a local static variable. Give an example of a function in which each might be useful.

**Answer:**

- A parameter is a local variable that is defined in a function's parameter list.

- A local variable is an object that is defined in a function.

  - It is *local* in that it is only visible inside the function.

  - An *automatic* (not *static*) local variable exists only when the function is executing.

- A local static variable is a local variable that has static lifetime. That is, it exists across the calls to the function.

For example, the function below returns the max factorial computed so far, where `num` is a parameter, `res` is a local (automatic) variable, and `max` is a local static variable.

```c++
void factMax(int num) {
  int res = 1;
  static int max = 1;
  for (int i = 1; i <= num; ++i) {
    res *= i;
  }
  max = res > max ? res : max;
  return max;
}
```

### Exercise 6.7

> Write a function that returns `0` when it is first called and then generates numbers in sequence each time it is called again.

**Answer:**

- [`06-07.cpp`](06-07.cpp)

### Exercise 6.8

> Write a header file named `Chapter6.h` that contains declarations for the functions you wrote for the exercises in Section 6.1 (p. 205).

**Answer:**

- [`Chapter6.h`](Chapter6.h)

### Exercise 6.9

> Write your own versions of the `fact.cc` and `factMain.cc` files. These files should include your `Chapter6.h` from the exercises in the previous section. Use these files to understand how your compiler supports separate compilation.

**Answer:**

- [`fact.cc`](fact.cc)
- [`factMain.cc`](factMain.cc)

## Section 6.2 Argument Passing

### Exercise 6.10

> Using pointers, write a function to swap the values of two `int`s. Test the function by calling it and printing the swapped values.

**Answer:**

- [`06-10.cpp`](06-10.cpp)

### Exercise 6.11

> Write and test your own version of `reset` that takes a reference.

**Answer:**

- [`06-11.cpp`](06-11.cpp)

### Exercise 6.12

> Rewrite the program from exercise 6.10 in Section 6.2.1 (p. 210) to use references instead of pointers to swap the value of two `int`s. Which version do you think would be easier to use and why?

**Answer:**

- [`06-12.cpp`](06-12.cpp)

Using a reference is easier, becasue

1. it is less error-prone;

2. it avoids copying, which, in some cases, might be expensive or impossible.

### Exercise 6.13

> Assuming `T` is the name of a type, explain the difference between a function declared as `void f(T)` and `void f(T&)`.

**Answer:**

| `void f(T)`            | `void f(T&)`               |
| ---------------------- | -------------------------- |
| pass argument by value | pass argument by reference |

### Exercise 6.14

> Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.

**Answer:**

- a parameter that should be a reference type

```c++
std::size_t len(const std::string &s) {
  return s.size();
}
```

`s` should be passed by reference as it could be expansive to copy a string.

```c++
bool is_good(const std::ostream &os) {
  return os.good();
}
```

`os` must be passed by reference as `std::ostream` cannot be copied.

- a parameter that should not be a reference type

```c++
bool is_upper(char c) {
  return 'A' <= c && c <= 'Z';
}
```

It is very cheap to copy a `char` (1 byte), so we do not take a reference.

```c++
std::size_t len(const char *str) {
  return strlen(str);
}
```

In dealing with C-style strings, we operate on pointers, and there is no need to pass a pointer by reference.

### Exercise 6.15

> Explain the rationale for the type of each of `find_char`'s parameters. In particular, why is `s` a reference to `const` but `occurs` is a plain reference? Why are these parameters references, but the `char` parameter `c` is not? What would happen if we made `s` a plain reference? What if we made `occurs` a reference to `const`?
>
> ```c++
> string::size_type find_char(const string &s, char c, string::size_type &occurs) { /* ... */ }
> ```

**Answer:**

> Why is `s` a reference to `const`?

Because we do not modify the string `s` in the function, and, for parameters that we do not modify, it is recommended to declare them the reference as `const`.

> Why is `occurs` a plain reference?

Because we will modify the `occurs` in the function. It is used as a counter.

> Why is `char` parameter `c` not a reference?

Because it is very cheap to copy a `char` (1 byte).

> What would happen if we made `s` a plain refernce?

The function `find_char()` would still work, but it will cause trouble for other functions that call `find_char()`. If they have a variable that is a reference to `const string`, they can't pass it to `find_char()`.

```c++
bool is_sentence(const string &s) {
  string::size_type ctr = 0;
  return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}
```

Had we made `s` a plain reference if `find_char()`, the above function `is_sentence()` would not compile.

> What would happen if we made `occurs` a refernce to `const`?

The program would not compile as we modifies `occurs` in `find_char()`.

### Exercise 6.16

> The following function, although legal, is less useful than it might be. Identify and correct the limitation on this function:
>
> ```c++
> bool is_empty(string &s) { return s.empty(); }
> ```

**Answer:**

The reference should be a reference-to-`const` instead of a plain reference. Fix -

```c++
bool is_empty(const string &s) {
  return s.empty();
}
```

### Exercise 6.17

> Write a function to determine whether a string contains any capital letters. Write a function to change a string to all lowercase. Do the parameters you used in these functions have the same type? If so, why? If not, why not?

**Answer:**

- [`06-17.cpp`](06-17.cpp)

### Exercise 6.18

> Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does.
>
> (a) A function named `compare` that returns a `bool` and has two parameters that are references to a class named `matrix`.
>
> (b) A function named `change_val` that returns a `vector<int>` iterator and
> takes two parameters: One is an `int` and the other is an iterator for a `vector<int>`.

**Answer:**

(a)

```c++
bool compare(const matrix &m1, const matrix &m2);
```

(b)

```c++
vector<int>::iterator change_val(int val, vector<int>::iterator it);
```

### Exercise 6.19

> Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why.
>
> ```c++
> double calc(double);
> int count(const string &, char);
> int sum(vector<int>::iterator, vector<int>::iterator, int);
> vector<int> vec(10);
> ```
>
> (a) `calc(23.4, 55.1);`
>
> (b) `count("abcda", 'a');`
>
> (c) `calc(66);`
>
> (d) `sum(vec.begin(), vec.end(), 3.8);`

**Answer:**

(a) illegal - mismatch between the declaration and the call. In the declaration, `calc()` takes only 1 parameter, but the call passes 2 arguments.

(b) legal

(c) legal

(d) legal - note that there will be a narrowing conversion from `3.8` to `3`, since the last parameter of `sum()` is an `int`.

### Exercise 6.20

> When should reference parameters be references to `const`? What happens if we make a parameter a plain reference when it could be a reference to `const`?

**Answer:**

> When should reference parameters be references to `const`?

Whenever the function does not change the parameters.

> What happens if we make a parameter a plain reference when it could be a reference to `const`?

Then we will not be able to pass `const` objects and literals that could be bound to references to `const`.

### Exercise 6.21

> Write a function that takes an `int` and a pointer to an `int` and returns the larger of the `int` value or the value to which the pointer points. What type should you use for the pointer?

**Answer:**

`const int *`

- [`06-21.cpp`](06-21.cpp)

### Exercise 6.22

> Write a function to swap two `int` pointers.

**Answer:**

- [`06-22.cpp`](06-22.cpp)

### Exercise 6.23

> Write your own versions of each of the `print` functions presented in this section. Call each of these functions to print `i` and `j` defined as follows:
>
> ```c++
> int i = 0, j[2] = {0, 1};
> ```

**Answer:**

- [`06-23.cpp`](06-23.cpp)

### Exercise 6.24

> Explain the behavior of the following function. If there are problems in the code, explain what they are and how you might fix them.
>
> ```c++
> void print(const int ia[10]) {
>   for (size_t i = 0; i != 10; ++i)
>     cout << ia[i] << endl;
> }
> ```

**Answer:**

The function tries to print out the elements in an array of 10 `int`s. However, array cannot be copied and thus cannot be passed by value.

Fix -

```c++
void print(const int (&ia)[10]) {
  for (size_t i = 0; i != 10; ++i) {
    cout << ia[i] << endl;
  }
}
```

### Exercise 6.25

> Write a `main` function that takes two arguments. Concatenate the supplied arguments and print the resulting string.

**Answer:**

- [`06-25.cpp`](06-25.cpp)

### Exercise 6.26

> Write a program that accepts the options presented in this section. Print the values of the arguments passed to `main`.
>
> *^ i.e. `prog -d -o file data0`*

**Answer:**

- [`06-26.cpp`](06-26.cpp)

### Exercise 6.27

> Write a function that takes an `initializer_list<int>` and produces the sum of the elements in the list.

**Answer:**

- [`06-27.cpp`](06-27.cpp)

### Exercise 6.28

> In the second version of `error_msg` that has an `ErrCode` parameter, what is the type of `elem` in the `for` loop?
>
> ```c++
> void error_msg(ErrCode e, initializer_list<string> il) {
>   cout << e.msg() << ": ";
>   for (const auto &elem : il)
>     cout << elem << " ";
>   cout << endl;
> }
> ```

**Answer:**

`const string &`

### Exercise 6.29

> When you use an `initializer_list` in a range `for` would you ever use a reference as the loop control variable? If so, why? If not, why not?

**Answer:**

Yes, if the element type is expensive to copy. `const auto &` is recommended, to make it clear that we promise not to change any element in the list. However, since the elements in an `initializer_list` are always `const`, it should be the same if we just use `auto &`.

## Section 6.3 Return Types and the return Statement

### Exercise 6.30

> Compile the version of `str_subrange` as presented on *page 223* to see what your compiler does with the indicated errors.

**Answer:**

```
error: non-void function 'str_subrange' should return a value [-Wreturn-type]
  return;
  ^
1 error generated.
```

- [`06-30.cpp`](06-30.cpp)

### Exercise 6.31

> When is it valid to return a reference? A reference to `const`?

**Answer:**

When the reference refers to an object that exists after the called function ends. For a reference-to-`const`, as an additional requirement, the caller should promise not to change the object via the returned reference.

### Exercise 6.32

> Indicate whether the following function is legal. If so, explain what it does; if not, correct any errors and then explain it.
>
> ```c++
> int &get(int *arry, int index) { return arry[index]; }
> int main() {
>   int ia[10];
>   for (int i = 0; i != 10; ++i)
>     get(ia, i) = i;
> }
> ```

**Answer:**

Yes, it is legal. It assigns to elements of array `ia[10]` their indices.

### Exercise 6.33

> Write a recursive function to print the contents of a vector.

**Answer:**

- [`06-33.cpp`](06-33.cpp)

### Exercise 6.34

> What would happen if the stopping condition in `factorial` were `if (val != 0)`?
>
> ```c++
> int factorial(int val) {
>   if (val > 1)
>     return factorial(val - 1) * val;
>   return 1;
> }
> ```

**Answer:**

It could cause problems if a negative `val` is passed.

### Exercise 6.35

> In the call to `factorial`, why did we pass `val - 1` rather than `val--`?

**Answer:**

Value of the expression `val--` is the same as original `val`.

### Exercise 6.36

> Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, `decltype`, or a type alias.

**Answer:**

- [`06-36.cpp`](06-36.cpp)

### Exercise 6.37

> Write three additional declarations for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should use `decltype`. Which form do you prefer and why?

**Answer:**

I prefer the `using` type declaration introduced in C++11. Modern and readable.

- [`06-37.cpp`](06-37.cpp)

### Exercise 6.38

> Revise the `arrPtr` function on to return a reference to the array.
>
> ```c++
> int odd[] = {1,3,5,7,9};
> int even[] = {0,2,4,6,8};
> decltype(odd) *arrPtr(int i) {
>   return (i % 2) ? &odd : &even;
> }
> ```

**Answer:**

- [`06-38.cpp`](06-38.cpp)

## Section 6.4 Overloaded Functions

### Exercise 6.39

> Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.
>
> (a)
>
> ```c++
> int calc(int, int);
> int calc(const int, const int);
> ```
>
> (b)
>
> ```c++
> int get();
> double get();
> ```
>
> (c)
>
> ```c++
> int *reset(int *);
> double *reset(double *);
> ```

**Answer:**

(a) illegal - top-level `const` is indistinguishable in function overloading.

(b) illegal - only differing in return types is insufficient for function overloading.

(c) legal - the second declaration overloads the `reset()` function: it takes a `double *` and returns a `double *`.

## Section 6.5 Features for Specialized Uses

### Exercise 6.40

> Which, if either, of the following declarations are errors? Why?
>
> (a) `int ff(int a, int b = 0, int c = 0);`
>
> (b) `char *init(int ht = 24, int wd, char bckgrnd);`

**Answer:**

If the declarations are the only ones in the scope, then (a) is legal while (b) is illegal, because we can only specify default arguments for trailing parameters. However, we could create a context where (a) is illegal but (b) is legal. Had we already had

```c++
int ff(int a, int b, int c = 0);
char *init(int ht, int wd = 80, char bckgrnd = ' ');
```

then (a)

```c++
int ff(int a, int b = 0, int c = 0);
```

would be *illegal*, because it tries to specify the default argument for `c` for the second time, while (b)

```c++
char *init(int ht = 24, int wd, char bckgrnd);
```

would be *legal*, because the default arguments for `wd` and `bckgrnd` have been specified in a previous declaration.

### Exercise 6.41

> Which, if any, of the following calls are illegal? Why? Which, if any, are legal but unlikely to match the programmer's intent? Why?
>
> ```c++
> char *init(int ht, int wd = 80, char bckgrnd = ' ');
> ```
>
> (a) `init();`
>
> (b) `init(24, 10);`
>
> (c) `init(14, '*');`

**Answer:**

(a) illegal - no default argument for the first argument `ht`.

(b) legal - calling `init()` function with `ht=24`, `wd=10` and `bckgrnd=' '`.

(c) legal, but unlikely to match the programmer's intent - calling `init()` function with `ht=14`, `wd=42` and `bckgrnd=' '`.

*^ `42` is the ASCII value for `'*'`*

### Exercise 6.42

> Give the second parameter of `make_plural` (Section 6.3.2, p. 224) a default argument of `'s'`. Test your program by printing singular and plural versions of the words success and failure.
>
> ```c++
> string make_plural(size_t ctr, const string &word, const string &ending) {
>   return (ctr > 1) ? word + ending : word;
> }
> ```

**Answer:**

- [`06-42.cpp`](06-42.cpp)

### Exercise 6.43

> Which one of the following declarations and definitions would you put in a header? In a source file? Explain why.
>
> (a) `inline bool eq(const BigInt&, const BigInt&) {...}`
>
> (b) `void putValues(int *arr, int size);`

**Answer:**

(a) Header - inline functions may be defined multiple times, while the compiler needs the definition to expand the code.

(b) Header - in general, functions declarations should be put in headers.

### Exercise 6.44

> Rewrite the `isShorter` function from Section 6.2.2 (p. 211) to be `inline`.
>
> ```c++
> bool isShorter(const string &s1, const string &s2) {
>   return s1.size() < s2.size();
> }
> ```

**Answer:**

- [`06-44.cpp`](06-44.cpp)

### Exercise 6.45

> Review the programs you've written for the earlier exercises and decide whether they should be defined as `inline`. If so, do so. If not, explain why they should not be `inline`.

**Answer:**

I would put some short helper functions in headers and mark them `inline`.

### Exercise 6.46

> Would it be possible to define `isShorter` as a `constexpr`? If so, do so. If not, explain why not.
>
> ```c++
> bool isShorter(const string &s1, const string &s2) {
>   return s1.size() < s2.size();
> }
> ```

**Answer:** No, because `std::string` is not a literal type.

*Compiling with `g++-11` would yield the following error -*

```
error: call to non-???constexpr??? function ???std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size() const [with _CharT = char; _Traits = std::char_traits<char>; _Alloc = std::allocator<char>; std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type = long unsigned int]???
```

- [`06-46.cpp`](06-46.cpp)

### Exercise 6.47

> Revise the program you wrote in the exercises in Section 6.3.2 (p. 228) that used recursion to print the contents of a vector to conditionally print information about its execution. For example, you might print the size of the vector on each call. Compile and run the program with debugging turned on and again with it turned off.
>
> *^ i.e. exercise [`6.33`](#exercise-633)*

**Answer:**

- [`06-47.cpp`](06-47.cpp)

### Exercise 6.48

> Explain what this loop does and whether it is a good use of `assert`:
>
> ```c++
> string s;
> while (cin >> s && s != sought) { } // empty body
> assert(cin);
> ```

**Answer:**

The loop reads from `cin` until end-of-file or the `sought` string is found. It might not be a good use of `assert` to ensure the `cin` state, because when `NDEBUG` is defined in the release environment, this guard would be gone.

## Section 6.6 Function Matching

### Exercise 6.49

> What is a candidate function? What is a viable function?

**Answer:**

A candidate function is a function with the same name as the called function and for which the declaration is visible at the point of the call.

A viable function in addition must have the same number of parameters as there are arguments in the call, and the type of each argument must match -- or be convertible to -- the type of its corresponding parameter.

### Exercise 6.50

> Given the declarations for f from *page 242*, list the viable functions, if any for each of the following calls. Indicate which function is the best match, or if the call is illegal whether there is no match or why the call is ambiguous.
>
> ```c++
> void f();
> void f(int);
> void f(int, int);
> void f(double, double = 3.14);
> ```
>
> (a) `f(2.56, 42)`
>
> (b) `f(42)`
>
> (c) `f(42, 0)`
>
> (d) `f(2.56, 3.14)`

**Answer:**

(a) Viable functions are `void f(int, int);` and `void f(double, double = 3.14);`. The call is ambiguous.

(b) Viable functions are `void f(int);` and `void f(double, double = 3.14);`. The best match is `void f(int);`.

(c) Viable functions are `void f(int, int);` and `void f(double, double = 3.14);`. The best match is `void f(int, int);`.

(d) Viable functions are `void f(int, int);` and `void f(double, double = 3.14);`. The best match is `void f(double, double = 3.14);`.

### Exercise 6.51

> Write all four versions of `f`. Each function should print a distinguishing message. Check your answers for the previous exercise. If your answers were incorrect, study this section until you understand why your answers were wrong.

**Answer:**

- [`06-51.cpp`](06-51.cpp)

### Exercise 6.52

> Given the following declarations,
>
> ```c++
> void manip(int, int);
> double dobj;
> ```
>
> what is the rank (Section 6.6.1, p. 245) of each conversion in the following calls?
>
> (a) `manip('a', 'z');`
>
> (b) `manip(55.4, dobj);`

**Answer:**

(a) Rank 3 - promotion.

(b) Rank 4 - arithmetic conversion.

*To recap, ranks are*

1. exact match
    1. identical
    2. array/function-to-pointer
    3. top-level `const`
2. `const` conversion
3. promotion
4. arithmetic/pointer conversion
5. class-type conversion

### Exercise 6.53

> Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.
>
> (a)
> ```c++
> int calc(int&, int&);
> int calc(const int&, const int&);
> ```
>
> (b)
>
> ```c++
> int calc(char*, char*);
> int calc(const char*, const char*);
> ```
>
> (c)
>
> ```c++
> int calc(char, char);
> int calc(char* const, char* const);
> ```

**Answer:**

(a) and (b) offer better matches for arguments with low-level `const`.

(c) is illegal because just top-level `const` is insufficient to differentiate the arguments.


## Section 6.7 Pointers to Functions

### Exercise 6.54

> Write a declaration for a function that takes two `int` parameters and returns an `int`, and declare a vector whose elements have this function pointer type.

**Answer:**

- [`06-54.cpp`](06-54.cpp)

### Exercise 6.55

> Write four functions that add, subtract, multiply, and divide two `int` values. Store pointers to these functions in your vector from the previous exercise.

**Answer:**

- [`06-55.cpp`](06-55.cpp)

### Exercise 6.56

> Call each element in the vector and print their result.

**Answer:**

- *See [`06-55.cpp`](06-55.cpp)*
