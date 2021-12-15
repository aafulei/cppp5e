# Chapter 7 Classes

- [Section 7.1. Defining Abstract Data Types](#71-defining-abstract-data-types)
  - *Exercises* [`7.1`](#exercise-71)
  - *Exercises* [`7.2`](#exercise-72) [`7.3`](#exercise-73) [`7.4`](#exercise-74) [`7.5`](#exercise-75)
  - *Exercises* [`7.6`](#exercise-76) [`7.7`](#exercise-77) [`7.7`](#exercise-77) [`7.8`](#exercise-78) [`7.9`](#exercise-79) [`7.10`](#exercise-710)
  - *Exercises* [`7.11`](#exercise-711) [`7.12`](#exercise-712) [`7.13`](#exercise-713) [`7.14`](#exercise-714) [`7.15`](#exercise-715)

- [Section 7.2. Access Control and Encapsulation](#72-access-control-and-encapsulation)
  - *Exercises* [`7.16`](#exercise-716) [`7.17`](#exercise-717) [`7.18`](#exercise-718) [`7.19`](#exercise-719) [`7.20`](#exercise-720) [`7.21`](#exercise-721) [`7.22`](#exercise-722)

- [Section 7.3. Additional Class Features](#73-additional-class-features)
  - *Exercises* [`7.23`](#exercise-723) [`7.24`](#exercise-724) [`7.25`](#exercise-725) [`7.26`](#exercise-726)
  - *Exercises* [`7.27`](#exercise-727) [`7.28`](#exercise-728) [`7.29`](#exercise-729) [`7.30`](#exercise-730)
  - *Exercises* [`7.31`](#exercise-731)
  - *Exercises* [`7.32`](#exercise-732)

- [Section 7.4. Class Scope](#74-class-scope)
  - *Exercises* [`7.33`](#exercise-733)
  - *Exercises* [`7.34`](#exercise-734) [`7.35`](#exercise-735)

- [Section 7.5. Constructors Revisited](#75-constructors-revisited)
  - *Exercises* [`7.36`](#exercise-736) [`7.37`](#exercise-737) [`7.38`](#exercise-738) [`7.39`](#exercise-739) [`7.40`](#exercise-740)
  - *Exercises* [`7.41`](#exercise-741) [`7.42`](#exercise-742)
  - *Exercises* [`7.43`](#exercise-743) [`7.44`](#exercise-744) [`7.45`](#exercise-745) [`7.46`](#exercise-746)
  - *Exercises* [`7.47`](#exercise-747) [`7.48`](#exercise-748) [`7.49`](#exercise-749) [`7.50`](#exercise-750) [`7.51`](#exercise-751)
  - *Exercises* [`7.52`](#exercise-752)
  - *Exercises* [`7.53`](#exercise-753) [`7.54`](#exercise-754) [`7.55`](#exercise-755)

- [Section 7.6. `static` Class Members](#76-static-class-members)
  - *Exercises* [`7.56`](#exercise-756) [`7.57`](#exercise-757) [`7.58`](#exercise-758)

## 7.1. Defining Abstract Data Types

### Exercise 7.1

> Write a version of the transaction-processing program from § 1.6 (p. 24) using the `Sales_data` class you defined for the exercises in § 2.6.1 (p. 72).

**Answer:**

- [`07-01-proc.cpp`](07-01-proc.cpp)

  - [`07-01-sales-data.hpp`](07-01-sales-data.hpp)

  - [`07-01-sales-data.cpp`](07-01-sales-data.cpp)

### Exercise 7.2

> Add the `combine` and `isbn` members to the `Sales_data` class you wrote for the exercises in § 2.6.2 (p. 76).

**Answer:**

- [`07-02-proc.cpp`](07-02-proc.cpp)

  - [`07-02-sales-data.hpp`](07-02-sales-data.hpp)

  - [`07-02-sales-data.cpp`](07-02-sales-data.cpp)

### Exercise 7.3

> Revise your transaction-processing program from § 7.1.1 (p. 256) to use these members.

**Answer:** See the answer to [`Exercise 7.2`](#exercise-72)

### Exercise 7.4

> Write a class named `Person` that represents the name and address of a person. Use a string to hold each of these elements. Subsequent exercises will incrementally add features to this class.

**Answer:**

- [`07-04-test.cpp`](07-04-test.cpp)

  - [`07-04-person.hpp`](07-04-person.hpp)

  - [`07-04-person.cpp`](07-04-person.cpp)

### Exercise 7.5

> Provide operations in your `Person` class to return the name and address. Should these functions be `const`? Explain your choice.

**Answer:** See the answer to [`Exercise 7.4`](#exercise-74) for the code. Yes, because these functions do not modify the object.

### Exercise 7.6

> Define your own versions of the `add`, `read`, and `print` functions.

**Answer:**

- [`07-06.hpp`](07-06.hpp)

- [`07-06.cpp`](07-06.cpp)

### Exercise 7.7

> Rewrite the transaction-processing program you wrote for the exercises in § 7.1.2 (p. 260) to use these new functions.

**Answer:** See the answer to [`Exercise 7.6`](#exercise-76)

### Exercise 7.8

> Why does `read` define its `Sales_data` parameter as a plain reference and `print` define its parameter as a reference to `const`?

**Answer:** Because `read` changes the `Sales_data` object that the parameter refers to, while `print` does not.

### Exercise 7.9

> Add operations to read and print `Person` objects to the code you wrote for the exercises in § 7.1.2 (p. 260).

**Answer:**

- [`07-09.hpp`](07-09.hpp)

- [`07-09.cpp`](07-09.cpp)

### Exercise 7.10

> What does the condition in the following `if` statement do?

```c++
if (read(read(cin, data1), data2))
```

**Answer:** Verify that `cin` does not fail after reading `data1` and `data2`.

### Exercise 7.11

> Add constructors to your `Sales_data` class and write a program to use each of the constructors.

**Answer:**

- [`07-11.hpp`](07-11.hpp)

- [`07-11.cpp`](07-11.cpp)

### Exercise 7.12

> Move the definition of the `Sales_data` constructor that takes an `istream` into the body of the `Sales_data` class.

**Answer:** See the answer to [`Exercise 7.11`](#exercise-711)

### Exercise 7.13

> Rewrite the program from *page 255* to use the `istream` constructor.

**Answer:** See the answer to [`Exercise 7.11`](#exercise-711)

### Exercise 7.14

> Write a version of the default constructor that explicitly initializes the members to the values we have provided as in-class initializers.

**Answer:** See the answer to [`Exercise 7.11`](#exercise-711)

### Exercise 7.15

> Add appropriate constructors to your `Person` class.

**Answer:**

- [`07-15.hpp`](07-15.hpp)

- [`07-15.cpp`](07-15.cpp)

## 7.2. Access Control and Encapsulation

[Back to Top](#chapter-7-classes)

### Exercise 7.16

> What, if any, are the constraints on where and how often an access specifier may appear inside a class definition? What kinds of members should be defined after a public specifier? What kinds should be private?

**Answer:** Let the interface be `public` and the implementation be `private`. For example, constructors ordinarily should be `public`.

### Exercise 7.17

> What, if any, are the differences between using `class` or `struct`?

**Answer:** Default access specifier is `private` for `class` , `public` for `struct`.

### Exercise 7.18

> What is encapsulation? Why is it useful?

**Answer:** Hiding implementation by specifying access control, so that users have access to the interface but have no access to the implementation.

### Exercise 7.19

> Indicate which members of your `Person` class you would declare as `public` and which you would declare as `private`. Explain your choice.

**Answer:** Declare the constructors and getter functions as `public` as they are the interface, whereas declare the data members as `private` as they belong to the implementation.

```c++
class Person
{
  string name;
  string addr;
public:
  Person(const string & n) : name(n) {}
  Person(const string & n, const string & a) : name(n), addr(a) {}
  string get_name() const { return name; }
  string get_addr() const { return addr; }
};
```

### Exercise 7.20

> When are friends useful? Discuss the pros and cons of using friends.

**Answer:**

| pros                                                         | cons                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| granting access to special classes/functions so that they may visit the areas that are not open to the general public | having to make sure the friends you invited do not mess up your house |
| useful functions may refer to class members without prefixing them with the class name | reduce encapsulation and thus maintainability, cause code verbosity |


### Exercise 7.21

> Update your `Sales_data` class to hide its implementation. The programs you’ve written to use `Sales_data` operations should still continue to work. Recompile those programs with your new class definition to verify that they still work.

### Exercise 7.22

> Update your `Person` class to hide its implementation.

## 7.3. Additional Class Features

### Exercise 7.23

> Write your own version of the `Screen` class.

**Answer:**

- [`07-23-screen.hpp`](07-23-screen.hpp)

- [`07-23-test.cpp`](07-23-test.cpp)

### Exercise 7.24

> Give your `Screen` class three constructors:
>
> 1. a default constructor;
>
> 2. a constructor that takes values for height and width and initializes the
> contents to hold the given number of blanks; and
>
> 3. a constructor that takes values for height, width, and a character to use
> as the contents of the screen.

**Answer:**

- [`07-24-screen.hpp`](07-24-screen.hpp)

- [`07-24-test.cpp`](07-24-test.cpp)

### Exercise 7.25

> Can `Screen` safely rely on the default versions of copy and assignment? If
> so, why? If not, why not?

**Answer:** Yes, because there is no memory allocation outside the class.

### Exercise 7.26

> Define `Sales_data::avg_price` as an inline function.

**Answer:**

```c++
inline Sales_data::avg_price() { return revenue / units_sold; }
```

### Exercise 7.27

> Add the `move`, `set`, and `display` operations to your version of `Screen`.
> Test your class by executing the following code:
>
> ```c++
> Screen myScreen(5, 5, 'X');
> myScreen.move(4,0).set('#').display(cout);
> cout << "\n";
> myScreen.display(cout);
> cout << "\n";
> ```

**Answer:**

- [`07-27-screen.hpp`](07-27-screen.hpp)
- [`07-27-screen.cpp`](07-27-screen.cpp)
- [`07-27-test.cpp`](07-27-test.cpp)

### Exercise 7.28

> What would happen in the previous exercise if the return type of `move`,
> `set`, and `display` was `Screen` rather than Screen&?

**Answer:** A copy of `Screen` is returned. As `move` and `set` will not modify
`myScreen`, the second display output is different from the first one.

First output

```
XXXXX
XXXXX
XXXXX
XXXXX
#XXXX
```
Second output

```
XXXXX
XXXXX
XXXXX
XXXXX
XXXXX
```

### Exercise 7.29

> Revise your Screen class so that `move`, `set`, and `display` functions return
> `Screen` and check your prediction from the previous exercise.

**Answer:**

- [`07-29-screen.hpp`](07-29-screen.hpp)
- [`07-29-screen.cpp`](07-29-screen.cpp)
- [`07-29-test.cpp`](07-29-test.cpp)

### Exercise 7.30

> It is legal but redundant to refer to members through the `this` pointer. Discuss the pros and cons of explicitly using the this pointer to access members.

**Answer:**

*Pros*

1. explicit

2. can still refer to the members when a function parameter hides it, e.g.

```c++
class Foo {
  char c;
public:
  void get() const { return c; }
  void set(char c) { this->c = c; }
};
```

### Exercise 7.31

> Define a pair of classes `X` and `Y`, in which `X` has a pointer to `Y`, and
> `Y` has an object of type `X`.

**Answer:**

```c++
class Y;

class X {
  Y *py;
};

class Y {
  X x;
};
```

See also [`07-31.cpp`](07-31.cpp)

### Exercise 7.32

> Define your own versions of `Screen` and `Window_mgr` in which `clear` is a
> member of `Window_mgr` and a friend of `Screen`.

**Answer:**

- [`07-32.hpp`](07-32.hpp)
- [`07-32.cpp`](07-32.cpp)

## 7.4. Class Scope

### Exercise 7.33

> What would happen if we gave `Screen` a size member defined as follows? Fix
> any problems you identify.

```c++
pos Screen::size() const
{
  return height * width;
}
```

**Answer:** Return type `pos`, defined in `Screen` scope, is not seen by the
compiler.

```c++
Screen::pos Screen::size() const
{
  return height * width;
}
```

### Exercise 7.34

> What would happen if we put the `typedef` of `pos` in the `Screen` class on
> *page 285* as the last line in the class?
>
> ```c++
> int height;
> class Screen {
> public:
>   // typedef std::string::size_type pos;
>   void dummy_fcn(pos height) {
>     cursor = width * height;
>   }
>
> private:
>   pos cursor = 0;
>   pos height = 0, width = 0;
>   typedef std::string::size_type pos;
> };
> ```

**Answer:** The compiler would complain about all the occurrences of `pos`, as
type definitions must appear before use.


### Exercise 7.35

Explain the following code, indicating which definition of `Type` or `initVal`
is used for each use of those names. Say how you would fix any errors.

```c++
typedef string Type;
Type initVal();

class Exercise {
public:
  typedef double Type;
  Type setVal(Type);
  Type initVal();

private:
  int val;
};

Type Exercise::setVal(Type parm) {
  val = parm + initVal();
  return val;
}
```

**Answer:** For the declaration of `initVal()` at the global scope,

  - the return `Type` is the one defined at the global scope (`string`)

Inside the definition of class `Exercise`, all the `Type`s refer to the one
defined in the class (`double`).

For the definition of `Exercise::setVal()`,

  - the return type `Type` is the one defined at the global scope (`string`)
  - the parameter type `Type` is the one defined inside the class (`double`)
  - the `initVal()` is the one defined inside the class

To fix, use

```c++
Exercise::Type Exercise::setVal(Type parm) {
  // ...
}
```

## 7.5. Constructors Revisited

### Exercise 7.36

> The following initializer is in error. Identify and fix the problem.
>
> ```c++
> struct X {
>   X (int i, int j): base(i), rem(base % j) {}
>   int rem, base;
> };
> ```

**Answer:** Members are initialized in the order in which they appear in the
class definition. Thus, `rem` is initialized before `base`. But the constructor
initializer list initializes `rem` using value of `base`. To fix it, consider
changing `int rem, base;` to `int base, rem;`.

### Exercise 7.37

> Using the version of `Sales_data` from this section, determine which
> constructor is used to initialize each of the following variables and list the
> values of the data members in each object:
>
> ```c++
> Sales_data first_item(cin);
> int main() {
>   Sales_data next;
>   Sales_data last("9-999-99999-9");
> }
> ```
>
> ```c++
> class Sales_data {
> public:
>   Sales_data(std::string s = "") : bookNo(s) {}
>   Sales_data(std::string s, unsigned cnt, double rev)
>       : bookNo(s), units_sold(cnt), revenue(rev * cnt) {}
>   Sales_data(std::istream &is) { read(is, *this); }
>   // ...
> };
> ```

**Answer:**

- `Sales_data first_item(cin);`
  - Use `Sales_data(std::istream &is)`
  - Values according to `cin`.

- `Sales_data next;`
  - Use `Sales_data(std::string s = "")`
  - `bookNo` is `""`
  - `units_sold` is `0`
  - `revenue` is `0`

- `Sales_data last("9-999-99999-9");`
  - Use `Sales_data(std::string s = "")`
  - `bookNo` is `"9-999-99999-9"`
  - `units_sold` is `0`
  - `revenue` is `0`

### Exercise 7.38

> We might want to supply `cin` as a default argument to the constructor that
> takes an `istream&`. Write the constructor declaration that uses `cin` as a
> default argument.

**Answer:**

```c++
Sales_data(std::istream &is = std::cin) { read(is, *this); }
```

### Exercise 7.39

> Would it be legal for both the constructor that takes a `string` and the one
> that takes an `istream&` to have default arguments? If not, why not?

**Answer:** No, because then default initialization would be ambiguous.

### Exercise 7.40

> Choose one of the following abstractions (or an abstraction of your own
> choosing). Determine what data are needed in the class. Provide an appropriate
> set of constructors. Explain your decisions.
>
> (a) Book
>
> (b) Date
>
> (c) Employee
>
> (d) Vehicle
>
> (e) Object
>
> (f) Tree

**Answer:** We choose (a).

```c++
class Book {
public:
  Book(std::string isbn = "", std::string title = "", std::string author = "");
  Book(std::istream &is);

private:
  std::string isbn;
  std::string title;
  std::string author;
};
```

An ISBN is the unique identifier for a book. If anything is supplied, we
require to know its ISBN.

A book usually has a title and an author. We allow a book to be constructed
without supplying those data members. But if an author is supplied, we require
the book's title be supplied as well.

In addition, we allow the information to be read from `std::istream &`, e.g.
`std::cin`, with format

```c++
978-7-121-20038-0
978-7-121-20038-0 C++_Primer
978-7-121-20038-0 C++_Primer Lippman
```

We plan to read one line for one book. For each line we read, the first
`std::string` corresponds to ISBN, the second title, the third author, the
rest we don't care, if any.

See [`07-42.cpp`](07-42.cpp) for implementation.

### Exercise 7.41

> Rewrite your own version of the `Sales_data` class to use delegating constructors. Add a statement to the body of each of the constructors that prints a message whenever it is executed. Write declarations to construct a Sales_data object in every way possible. Study the output until you are certain you understand the order of execution among delegating constructors.

### Exercise 7.42

> For the class you wrote for exercise 7.40 in § 7.5.1 (p. 291), decide whether any of the constructors might use delegation. If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.

### Exercise 7.43

> Assume we have a class named NoDefault that has a constructor that takes an int, but has no default constructor. Define a class C that has a member of type NoDefault. Define the default constructor for C.

### Exercise 7.44

> Is the following declaration legal? If not, why not?

// vector<NoDefault> vec(10);

// Answer: No. Because when vec is value initialized, its elements are default initialized. However, there is no default constructor in class NoDefault.

### Exercise 7.45

> What if we defined the vector in the previous exercise to hold objects of type C?

// Answer: Yes, that's legal. Because C has a valid default constructor.

18/02/10 = Sat

### Exercise 7.46

> Which, if any, of the following statements are untrue? Why?

> (a) A class must provide at least one constructor.

> (b) A default constructor is a constructor with an empty parameter list.

> (c) If there are no meaningful default values for a class, the class should not provide a default constructor.

> (d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type.

**Answer:** All are untrue.

(a) If a class does not provide any constructor, the compiler will synthesize one for it.

(b) A default constructor is a constructor that is called if no initializer is supplied. In addition, a constructor that supplies default arguments for all of its parameters also defines the default constructor.

(c) Without a default constructor, a class may cause trouble to other classes which have a member of its type.

(d) The compiler only synthesizes a default constructor when a class does not have any constructor at all.

### Exercise 7.47

> Explain whether the `Sales_data` constructor that takes a string should be `explicit`. What are the benefits of making the constructor explicit? What are the drawbacks?

**Answer:** If the constructor is declared `explicit`, then we forbid the implicit conversion from a `string` to a `Sales_data`. This is acceptable, because a temporary object with only an ISBN, but no quantity, is unlikely to be useful.

Consider Case 1 where `data` is a `Sales_data` and `isbn` is a `string`.

```c++
data.combine(isbn);
```

The operation is meaningless.

Consider Case 2

```c++
data = isbn;
```

This may confuse a reader of the code since we are assigning a `string` to a `Sales_data`.

By declaring `explicit`, we forbid the above two cases, which is perfectly fine, and even desirable.

The benefits versus drawbacks are a trade-off between control and convenience.

### Exercise 7.48

> Assuming the `Sales_data` constructors are not `explicit`, what operations happen during the following definitions

```c++
string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
```

What happens if the `Sales_data` constructors are `explicit`?

```c++
class Sales_data {
public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p):
               bookNo(s), units_sold(n), revenue(p*n) { }
    explicit Sales_data(const std::string &s): bookNo(s) { }
    explicit Sales_data(std::istream&);
    // remaining members as before
};
```

**Answer:** Whether the `Sales_data` constructors are `explicit` or not have no impact on this case. What matters is whether the `string` constructor from a `const char *` is `explicit`. It is not. Thus implicit conversion is allowed, and the initializations of `item1` and `item2` should happen as expected.

### Exercise 7.49

> For each of the three following declarations of `combine`, explain what happens if we call `i.combine(s)`, where `i` is a `Sales_data` and `s` is a `string`:

(a) `Sales_data &combine(Sales_data);`

(b) `Sales_data &combine(Sales_data&);`

(c) `Sales_data &combine(const Sales_data&) const;`

**Answer:** Assuming no `explicit` for `Sales_data(string)`.

(a) A temporary `Sales_data` object initialized from `s` is combined with `i`.

(b) Illegal. We cannot bind a *plain* reference to a temporary object. It could be legal if the declaration were `Sales_data & combine(const Sales_data &)`.

(c) Illegal. Declaring a member function `const` forbids any further change to the object. Thus we cannot combine anything to `i`.

### Exercise 7.50

> Determine whether any of your `Person` class constructors should be `explicit`.

```c++
class Person
{
  friend istream & read(istream &, Person &);
  friend ostream & print(ostream &, const Person &);

  string name;
  string addr;
public:
  Person(const string & n) : name(n) {}
  Person(const string & n, const string & a) : name(n), addr(a) {}
  string get_name() const { return name; }
  string get_addr() const { return addr; }
};
```

**Answer:** Constructor `Person(const string & n)` takes only one single argument but should not be declared `explicit`. In a large sense, when we speak of a person's name, we are referring to that person. However, if we had a constructor like `Person(istream & is)`, then we should declare it as `explicit`, because it would be confusing for a function that takes a `Person` as parameter to take an `istream &` such as `std::cin`.

### Exercise 7.51

> Why do you think `vector` defines its single-argument constructor as `explicit`, but `string` does not?

**Answer:** (17/11/02 = Thu) Semantically, a number (`size_type`) is far away from a `vector`, but a C-style `char` array is closely related to a `string`. Therefore, whenever a `string` is needed as a parameter, we may pass a `const char *` to initialize it, but when a `vector` is needed, we cannot just pass a `size_type`.

Consider

```c++
vector::size_type size(vector<int> vec) { return vec.size(); }
```

If without `explicit`, implicit conversion would be allowed, and it would be very confusing to allow a call like `size(42)`.

On the other hand, consider

```c++
string::size_type size(string str) { return str.size(); }
```

It wouldn't be surprising to see a call like `size("Hello, World!")`. For this convenience we allow the implicit conversion and do not declare `explicit` for the `string` constructor.

### Exercise 7.52

> Using our first version of `Sales_data` from *§ 2.6.1 (p. 72)*, explain the following initialization. Identify and fix any problems.

```c++
Sales_data item = {"978-0590353403", 25, 15.99};
```

```c++
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```

**Answer:** An aggregate class cannot have any in-class initializers. Thus, in order to initialize `item` with a curly braced list, we need to rewrite the class definition as

```c++
struct Sales_data {
  std::string bookNo;
    unsigned units_sold;
    double revenue;
};
```

### Exercise 7.53

> Define your own version of Debug.

### Exercise 7.54

> Should the members of `Debug` that begin with `set_` be declared as `constexpr`? If not, why not?

```c++
void set_io(bool b) { io = b; }
void set_hw(bool b) { hw = b; }
void set_other(bool b) { hw = b; }
```

**Answer:** No. Ultimately, a `constexpr` function is a function which we may use in a constant expression. As `set_` functions return no value, it seems pointless to declare it as `constexpr`. Apart from that, the C++11 restriction on a `constexpr` is quite strict:

1. a `constexpr` function must have *exactly one* `return`, which `set_` functions do not satisfy;
2. a `constexpr` function is implicitly `const` [^C++11], which `set_` functions do not satisfy.

[^C++11]: C++11 stated that all non-static member functions that were declared `constexpr` were also implicitly declared `const`, with respect to `this`. That has since been removed; non-static member functions may be non-`const` in C++14.

### Exercise 7.55

> Is the `Data` class from *§ 7.5.5 (p. 298)* a literal class? If not, why not? If so, explain why it is literal.

```c++
struct Data {
    int ival;
    string s;
};
```

**Answer:** No. To be a literal class, an aggregate class must have all of its members have literal types, but `s` is a `string`, which is not a literal type.

## 7.6. `static` Class Members

### Exercise 7.56

> What is a `static` class member? What are the advantages of `static` members? How do they differ from ordinary members?

**Answer:** A class member that is associated with the entire class, rather than with any individual object.

> What are the advantages of `static` members?

- It can used to store values that are common to all objects, for example, the interest rate for all the bank accounts. When the value changes, we do not have to make changes for each object.
- It can be used in ways that ordinary members cannot. For example, it can have incomplete type. In particular, it may have the same type as that of the class that it belongs.

> How do they differ from ordinary members?

- A `static` data member does not belong to any object and thus should be defined outside the class.
- A `static` member function does not have the implicit `this` pointer and may not specified as `const`.


### Exercise 7.57

> Write your own version of the `Account` class.

### Exercise 7.58

> Which, if any, of the following `static` data member declarations and definitions are errors? Explain why.

```c++
// example.h
class Example {
public:
  static double rate = 6.5;
  static const int vecSize = 20;
  static vector<double> vec(vecSize);
};
// example.C
#include "example.h"
double Example::rate;
vector<double> Example::vec;
```

**Answer:** `static double rate = 6.5;` and `static vector<double> vec(vecSize);` are wrong. Cannot provide in-class initializers to non-const data members.
