# Chapter 7 Classes

- [Section 7.1 Defining Abstract Data Types](#section-71-defining-abstract-data-types)
  - *Exercises* [`7.1`](#exercise-71)
  - *Exercises* [`7.2`](#exercise-72) [`7.3`](#exercise-73) [`7.4`](#exercise-74) [`7.5`](#exercise-75)
  - *Exercises* [`7.6`](#exercise-76) [`7.7`](#exercise-77) [`7.8`](#exercise-78) [`7.9`](#exercise-79) [`7.10`](#exercise-710)
  - *Exercises* [`7.11`](#exercise-711) [`7.12`](#exercise-712) [`7.13`](#exercise-713) [`7.14`](#exercise-714) [`7.15`](#exercise-715)

- [Section 7.2 Access Control and Encapsulation](#section-72-access-control-and-encapsulation)
  - *Exercises* [`7.16`](#exercise-716) [`7.17`](#exercise-717) [`7.18`](#exercise-718) [`7.19`](#exercise-719)
  - *Exercises* [`7.20`](#exercise-720) [`7.21`](#exercise-721) [`7.22`](#exercise-722)

- [Section 7.3 Additional Class Features](#section-73-additional-class-features)
  - *Exercises* [`7.23`](#exercise-723) [`7.24`](#exercise-724) [`7.25`](#exercise-725) [`7.26`](#exercise-726)
  - *Exercises* [`7.27`](#exercise-727) [`7.28`](#exercise-728) [`7.29`](#exercise-729) [`7.30`](#exercise-730)
  - *Exercises* [`7.31`](#exercise-731)
  - *Exercises* [`7.32`](#exercise-732)

- [Section 7.4 Class Scope](#section-74-class-scope)
  - *Exercises* [`7.33`](#exercise-733)
  - *Exercises* [`7.34`](#exercise-734) [`7.35`](#exercise-735)

- [Section 7.5 Constructors Revisited](#section-75-constructors-revisited)
  - *Exercises* [`7.36`](#exercise-736) [`7.37`](#exercise-737) [`7.38`](#exercise-738) [`7.39`](#exercise-739) [`7.40`](#exercise-740)
  - *Exercises* [`7.41`](#exercise-741) [`7.42`](#exercise-742)
  - *Exercises* [`7.43`](#exercise-743) [`7.44`](#exercise-744) [`7.45`](#exercise-745) [`7.46`](#exercise-746)
  - *Exercises* [`7.47`](#exercise-747) [`7.48`](#exercise-748) [`7.49`](#exercise-749) [`7.50`](#exercise-750) [`7.51`](#exercise-751)
  - *Exercises* [`7.52`](#exercise-752)
  - *Exercises* [`7.53`](#exercise-753) [`7.54`](#exercise-754) [`7.55`](#exercise-755)

- [Section 7.6 static Class Members](#section-76-static-class-members)
  - *Exercises* [`7.56`](#exercise-756) [`7.57`](#exercise-757) [`7.58`](#exercise-758)

## Section 7.1 Defining Abstract Data Types

### Exercise 7.1

> Write a version of the transaction-processing program from Section 1.6 (p. 24) using the `Sales_data` class you defined for the exercises in Section 2.6.1 (p. 72).
>
> *^ i.e. exercise [`2.40`](../02-variables-and-basic-types/README.md#exercise-240)*

**Answer:**

- [`07-01.cpp`](07-01.cpp)

### Exercise 7.2

> Add the `combine` and `isbn` members to the `Sales_data` class you wrote for the exercises in Section 2.6.2 (p. 76).
>
> *^ i.e. exercise [`2.41`](../02-variables-and-basic-types/README.md#exercise-241)*

**Answer:**

- [`07-02.cpp`](07-02.cpp)

### Exercise 7.3

> Revise your transaction-processing program from Section 7.1.1 (p. 256) to use these members.
>
> *^ i.e. exercise [`7.1`](#exercise-71)*

**Answer:**

- See [`07-02.cpp`](07-02.cpp)

### Exercise 7.4

> Write a class named `Person` that represents the name and address of a person. Use a string to hold each of these elements. Subsequent exercises will incrementally add features to this class.

**Answer:**

- [`07-04.cpp`](07-04.cpp)

### Exercise 7.5

> Provide operations in your `Person` class to return the name and address. Should these functions be `const`? Explain your choice.

**Answer:**

Yes, because they do not alter a `Person` object.

- See [`07-04.cpp`](07-04.cpp)

### Exercise 7.6

> Define your own versions of the `add`, `read`, and `print` functions.

**Answer:**

- [`07-06.cpp`](07-06.cpp)

### Exercise 7.7

> Rewrite the transaction-processing program you wrote for the exercises in Section 7.1.2 (p. 260) to use these new functions.
>
> *^ i.e. exercise [`7.3`](#exercise-73)*

**Answer:**

- See [`07-06.cpp`](07-06.cpp)

### Exercise 7.8

> Why does `read` define its `Sales_data` parameter as a plain reference and `print` define its parameter as a reference to `const`?

**Answer:**

Because `read` changes the `Sales_data` object that the parameter refers to, while `print` does not.

### Exercise 7.9

> Add operations to read and print `Person` objects to the code you wrote for the exercises in Section 7.1.2 (p. 260).
>
> *^ i.e. exercise [`7.4`](#exercise-74)*

**Answer:**

- [`07-09.cpp`](07-09.cpp)

### Exercise 7.10

> What does the condition in the following `if` statement do?
>
> ```c++
> if (read(read(cin, data1), data2))
> ```

**Answer:**

The `if` statement verifies that `cin` does not fail after reading `data1` and `data2`.

### Exercise 7.11

> Add constructors to your `Sales_data` class and write a program to use each of the constructors.

**Answer:**

- [`07-11.cpp`](07-11.cpp)

### Exercise 7.12

> Move the definition of the `Sales_data` constructor that takes an istream into the body of the `Sales_data` class.

**Answer:**

- [`07-12.cpp`](07-12.cpp)

### Exercise 7.13

> Rewrite the program from *page 255* to use the `istream` constructor.
>
> ```c++
> Sales_data total;
> if (read(cin, total)) {
>   Sales_data trans;
>   while (read(cin, trans)) {
>     if (total.isbn() == trans.isbn()) {
>       total.combine(trans);
>     } else {
>       print(cout, total);
>       total = trans;
>     }
>   }
>   print(cout, total);
> } else {
>   cerr << "No data?!" << endl;
> }
> ```

**Answer:**

- [`07-13.cpp`](07-13.cpp)

### Exercise 7.14

> Write a version of the default constructor that explicitly initializes the members to the values we have provided as in-class initializers.

**Answer:**

- [`07-14.cpp`](07-14.cpp)

### Exercise 7.15

> Add appropriate constructors to your `Person` class.

**Answer:**

- [`07-15.cpp`](07-15.cpp)

## Section 7.2 Access Control and Encapsulation

### Exercise 7.16

> What, if any, are the constraints on where and how often an access specifier may appear inside a class definition? What kinds of members should be defined after a public specifier? What kinds should be private?

**Answer:**

- *What, if any, are the constraints on where and how often an access specifier may appear inside a class definition?*

  No constraints.

- *What kinds of members should be defined after a public specifier?*

  Interface.

- *What kinds should be private?*

  Implementation.

### Exercise 7.17

> What, if any, are the differences between using `class` or `struct`?

**Answer:**

| Default Access Specifier for  | `class`   | `struct` |
| ----------------------------- | --------- | -------- |
| members                       | `private` | `public` |
| derivation list               | `private` | `public` |

*^ see Chapter 15 Object-Oriented Programming for the derivation list*

### Exercise 7.18

> What is encapsulation? Why is it useful?

**Answer:**

Encapsulation hides implementation by specifying access control, so that while users have the access to the interface, they do not need to worry about the implemention.

### Exercise 7.19

> Indicate which members of your `Person` class you would declare as `public` and which you would declare as `private`. Explain your choice.

**Answer:**

Constructors and getter functions are declared as `public` because they are the interface. Data members are declared as `private` as they are implementation.

### Exercise 7.20

> When are friends useful? Discuss the pros and cons of using friends.

**Answer:**

- Pros

  1\. granting access to special classes/functions so that they can visit the areas that are not open to the general public

  2\. useful functions can refer to class members without prefixing them with the class name

- Cons

  1\. having to make sure the friends you invite do not mess up your house

  2\. reduce encapsulation and thus maintainability

### Exercise 7.21

> Update your `Sales_data` class to hide its implementation. The programs you've written to use `Sales_data` operations should still continue to work. Recompile those programs with your new class definition to verify that they still work.

**Answer:**

- [`07-21.cpp`](07-21.cpp)

### Exercise 7.22

> Update your `Person` class to hide its implementation.

**Answer:**

- [`07-22.cpp`](07-22.cpp)

## Section 7.3 Additional Class Features

### Exercise 7.23

> Write your own version of the `Screen` class.

**Answer:**

- [`07-23.cpp`](07-23.cpp)

### Exercise 7.24

> Give your `Screen` class three constructors: a default constructor; a constructor that takes values for height and width and initializes the contents to hold the given number of blanks; and a constructor that takes values for height, width, and a character to use as the contents of the screen.

**Answer:**

- [`07-24.cpp`](07-24.cpp)

### Exercise 7.25

> Can `Screen` safely rely on the default versions of copy and assignment? If so, why? If not, why not?

**Answer:**

 Yes, because there is no memory allocation outside the class.

### Exercise 7.26

> Define `Sales_data::avg_price` as an inline function.

**Answer:**

- [`07-26.cpp`](07-26.cpp)

### Exercise 7.27

> Add the `move`, `set`, and `display` operations to your version of `Screen`. Test your class by executing the following code:
>
> ```c++
> Screen myScreen(5, 5, 'X');
> myScreen.move(4, 0).set('#').display(cout);
> cout << "\n";
> myScreen.display(cout);
> cout << "\n";
> ```

**Answer:**

- [`07-27.cpp`](07-27.cpp)

### Exercise 7.28

> What would happen in the previous exercise if the return type of `move`, `set`, and `display` was `Screen` rather than `Screen &`?
>
> *^ i.e. exercise [`7.27`](#exercise-727)*

**Answer:**

A copy of the `Screen` is returned. As a result, the `move` and `set` operation would not affect the `myScreen`.

### Exercise 7.29

> Revise your `Screen` class so that `move`, `set`, and `display` functions return Screen and check your prediction from the previous exercise.

**Answer:**

- [`07-29.cpp`](07-29.cpp)

### Exercise 7.30

> It is legal but redundant to refer to members through the this pointer. Discuss the pros and cons of explicitly using the `this` pointer to access members.

**Answer:**

- Pros

  1\. explicit

  2\. mebmber function may have a parameter which has the same name as the data member, for example

  ```c++
  class C {
      char c;

  public:
      void get() const { return c; }
      void set(char c) { this->c = c; }
  };
  ```

- Cons

  1\. redundant

### Exercise 7.31

> Define a pair of classes `X` and `Y`, in which `X` has a pointer to `Y`, and `Y` has an object of type `X`.

**Answer:**

- [`07-31.cpp`](07-31.cpp)

### Exercise 7.32

> Define your own versions of `Screen` and `Window_mgr` in which `clear` is a member of `Window_mgr` and a friend of `Screen`.

**Answer:**

- [`07-32.cpp`](07-32.cpp)

## Section 7.4 Class Scope

### Exercise 7.33

> What would happen if we gave `Screen` a size member defined as follows? Fix any problems you identify.
>
> ```c++
> pos Screen::size() const { return height * width; }
> ```

**Answer:**

Problem - `pos` is not in scope when the compiler sees it. Fix -

```c++
Screen::pos Screen::size() const { return height * width; }
```

### Exercise 7.34

> What would happen if we put the `typedef` of `pos` in the `Screen` class on *page 285* as the last line in the class?
>
> ```c++
> int height;   // defines a name subsequently used inside Screen
> class Screen {
> public:
>   typedef std::string::size_type pos;
>   void dummy_fcn(pos height) {
>     cursor = width * height; // which height? the parameter
>   }
> private:
>   pos cursor = 0;
>   pos height = 0, width = 0;
> };
> ```

**Answer:**

The compiler would issue errors about *all* the occurrences of `pos` in the class definition, complaining that `pos` has not been declared.

### Exercise 7.35

> Explain the following code, indicating which definition of `Type` or `initVal` is used for each use of those names. Say how you would fix any errors.
>
> ```c++
> typedef string Type;
> Type initVal();
>
> class Exercise {
> public:
>   typedef double Type;
>   Type setVal(Type);
>   Type initVal();
>
> private:
>   int val;
> };
>
> Type Exercise::setVal(Type parm) {
>   val = parm + initVal();
>   return val;
> }
> ```

**Answer:**

In class `Exercise` all the occurrences of `Type` stand for an alias of `double`. In

```c++
Type Exercise::setVal(Type parm) {
  val = parm + initVal();
  return val;
}
```

the return type `Type` stands for `string`, while the parameter type `Type` as in `Type parm` stands for `double`. The `initVal()` in the function `Exercise::setVal` is the version declared in class `Exercise`, which returns a `double`.

Therefore, there is a type mismatch between the value returned and the type specified in `Type Exercise::setVal(Type parm)`. To fix it, change from

```c++
Type Exercise::setVal(Type parm) {  // type mismatch
  // ...
}
```

to

```c++
Exercise::Type Exercise::setVal(Type parm) {
  // ...
}
```

## Section 7.5 Constructors Revisited

### Exercise 7.36

> The following initializer is in error. Identify and fix the problem.
>
> ```c++
> struct X {
>   X(int i, int j) : base(i), rem(base % j) {}
>   int rem, base;
> };
> ```

**Answer:**

Members are initialized in the order in which they appear in the class definition. Thus `rem` is initialized before `base`. But the constructor initializer list initializes `rem` using value of `base`. Fix -

```c++
struct X {
  X(int i, int j) : base(i), rem(i % j) {}
  int rem, base;
};
```

### Exercise 7.37

> Using the version of `Sales_data` from this section, determine which constructor is used to initialize each of the following variables and list the values of the data members in each object:
>
> ```c++
> Sales_data first_item(cin);
>
> int main() {
>   Sales_data next;
>   Sales_data last("9-999-99999-9");
> }
> ```

**Answer:**

`Sales_data(std::istream &is)` is used for `first_item`. Values of the data members are according to `cin`.

`Sales_data(std::string s = "")` is used for `next` and `last`.

- `next`

  | Member       | Value |
  | ------------ | ----- |
  | `bookNo`     | `""`  |
  | `units_sold` | 0     |
  | `revenue`    | 0     |

- `last`

  | Member       | Value             |
  | ------------ | ----------------- |
  | `bookNo`     | `"9-999-99999-9"` |
  | `units_sold` | 0                 |
  | `revenue`    | 0                 |

### Exercise 7.38

> We might want to supply `cin` as a default argument to the constructor that takes an `istream &`. Write the constructor declaration that uses `cin` as a default argument.

**Answer:**

```c++
Sales_data(std::istream &is = std::cin);
```

### Exercise 7.39

> Would it be legal for both the constructor that takes a string and the one that takes an `istream &` to have default arguments? If not, why not?

**Answer:**

No, because that would lead to ambiguous call when we call the default constructor.

```c++
Sales_data sales_data;
```

### Exercise 7.40

> Choose one of the following abstractions (or an abstraction of your own choosing). Determine what data are needed in the class. Provide an appropriate set of constructors. Explain your decisions.
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

**Answer:**

We choose (a)

```c++
class Book {
public:
  Book(std::string isbn = "", std::string title = "", std::string author = "");
  Book(std::istream & is);

private:
  std::string isbn;
  std::string title;
  std::string author;
};
```

An ISBN is the unique identifier for a book. If anything is provided for a book, we would first like to know its ISBN.

A book usually has a title and an author. We allow a book to be constructed without those data members. But if an author is provided, we require the book's title be known as well. This determines the order of parameters in the first constructor.

In addition, we might read this information from an `istream &` such as `std::cin`. For example, given data

```
978-7-121-20038-0
978-7-121-20038-0|C++ Primer
978-7-121-20038-0|C++ Primer|Lippman et al.
```

we interpret each line as a book and use `|` as the delimiter between fields.

### Exercise 7.41

> Rewrite your own version of the `Sales_data` class to use delegating constructors. Add a statement to the body of each of the constructors that prints a message whenever it is executed. Write declarations to construct a `Sales_data` object in every way possible. Study the output until you are certain you understand the order of execution among delegating constructors.

**Answer:**

- [`07-41.cpp`](07-41.cpp)

### Exercise 7.42

> For the class you wrote for exercise [7.40](#exercise-740) in Section 7.5.1 (p. 291), decide whether any of the constructors might use delegation. If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.

**Answer:**

- [`07-42.cpp`](07-42.cpp)

### Exercise 7.43

> Assume we have a class named `NoDefault` that has a constructor that takes an `int`, but has no default constructor. Define a class `C` that has a member of type `NoDefault`. Define the default constructor for `C`.

**Answer:**

- [`07-43.cpp`](07-43.cpp)

### Exercise 7.44

> Is the following declaration legal? If not, why not?
>
> ```c++
> vector<NoDefault> vec(10);
> ```

**Answer:**

No, the declaration is legal. Because when `vec` is being value initialized, its elements are default initialized. However, there is no default constructor in class `NoDefault`.

### Exercise 7.45

> What if we defined the vector in the previous execercise to hold objects of type C?

**Answer:**

That is fine. Because `C` has a default constructor.

### Exercise 7.46

> Which, if any, of the following statements are untrue? Why?
>
> (a) A class must provide at least one constructor.
>
> (b) A default constructor is a constructor with an empty parameter list.
>
> (c) If there are no meaningful default values for a class, the class should not provide a default constructor.
>
> (d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type.

**Answer:**

All are untrue.

(a) If a class does not provide any constructors, the compiler will synthesize one for it.

(b) A default constructor is a constructor that is called if no initializer is supplied. In addition, a constructor that supplies default arguments for all of its parameters also defines the default constructor.

(c) Without a default constructor, a class might cause trouble to other classes which have a member of its type.

(d) The compiler only synthesizes a default constructor when a class does not have any constructors at all.

### Exercise 7.47

> Explain whether the `Sales_data` constructor that takes a string should be explicit. What are the benefits of making the constructor explicit? What are the drawbacks?

**Answer:**

If the constructor is declared `explicit`, we prevent the implicit conversion from a `std::string` to a `Sales_data`. This is acceptable, because a temporary object with only an ISBN, but no quantity, is unlikely to be useful.

Consider case 1 where `data` is a `Sales_data` and `isbn` is a `std::string`.

```c++
data.combine(isbn);
```

The operation is meaningless.

Consider case 2

```c++
data = isbn;
```

This might confuse a reader of the code since we are assigning a `std::string` to a `Sales_data`.

By declaring `explicit`, we avoid the above two cases, which is not only acceptable, but also desirable.

The benefits versus drawbacks are a trade-off between control and convenience.

### Exercise 7.48

> Assuming the `Sales_data` constructors are not `explicit`, what operations happen during the following definitions `string null_isbn("9-999-99999-9");`
>
> ```c++
> string null_isbn("9-999-99999-9");
> Sales_data item1(null_isbn);
> Sales_data item2("9-999-99999-9");
> ```
>
> What happens if the `Sales_data` constructors are `explicit`?
>
> ```c++
> class Sales_data {
> public:
>   Sales_data();
>   Sales_data(const std::string & bookNo, unsigned units_sold, double price);
>   explicit Sales_data(const std::string &bookNo);
>   explicit Sales_data(std::istream &is);
>   // remaining members as before
> };
> ```

**Answer:**

Whether the `Sales_data` constructors are `explicit` or not has no impact on this case. What matters is whether the `std::string` constructor from a `const char *` is `explicit`. It is not. Thus implicit conversion is allowed, and the initializations of `item1` and `item2` should happen as expected.

### Exercise 7.49

> For each of the three following declarations of `combine`, explain what happens if we call `i.combine(s)`, where `i` is a `Sales_data` and `s` is a `string`:
>
> (a) `Sales_data &combine(Sales_data);`
>
> (b) `Sales_data &combine(Sales_data &);`
>
> (c) `Sales_data &combine(const Sales_data &) const;`

**Answer:**

(a) legal, assuming *no* `explicit` for `Sales_data(const std::string &);` - a temporary `Sales_data` object initialized from `s` will be combined with `i`

(b) illegal - we cannot bind a *plain* reference to a temporary object. It could be legal if the declaration were `Sales_data & combine(const Sales_data &)`.

(c) illegal - declaring a member function `const` forbids any further change to the object. Thus we cannot combine anything to `i`.

### Exercise 7.50

> Determine whether any of your `Person` class constructors should be explicit.
>
> *^ i.e. exercise [`7.22`](#exercise-722)*

**Answer:**

```c++
class Person {
// ...

public:
  Person();
  Person(const std::string &name);
  Person(const std::string &name, const std::string &addr);

// ...
};
```

The `Person` constructor from a `const std::string &` takes only one single argument but should not be declared `explicit`. It is natrual that when we speak of a person's name, we are referring to that person. However, if we had a constructor like `Person(std::istream &)`, then we should declare it as `explicit`, because it would be confusing for a function that takes a `Person` as parameter to take a `std::istream &` such as `std::cin`.

### Exercise 7.51

> Why do you think `vector` defines its single-argument constructor as `explicit`, but `string` does not?

**Answer:**

Semantically, a number (`size_type`) is far away from a `vector`, but a C-style `char` array is closely related to a `string`. Therefore, whenever a `std::string` is needed as an argument, we may pass a `const char *` to initialize it, but when a `vector` is needed, we cannot just pass a `size_type`. Consider

```c++
std::vector::size_type len(const std::vector<int> &vec) { return vec.size(); }
```

Without `explicit`, the implicit conversion would be allowed, and it would be very confusing to allow a call like `len(42)`. On the other hand, consider

```c++
std::string::size_type len(const std::string &str) { return str.size(); }
```

It wouldn't be surprising to see a call like `len("Hello, World!")`. For this convenience we allow the implicit conversion and do not declare `explicit` for the `std::string` constructor.

### Exercise 7.52

> Using our first version of `Sales_data` from Section 2.6.1 (p. 72), explain the following initialization. Identify and fix any problems.
>
> ```c++
> Sales_data item = {"978-0590353403", 25, 15.99};
> ```
>
> ```c++
> struct Sales_data {
>   std::string bookNo;
>   unsigned units_sold = 0;
>   double revenue = 0.0;
> };
> ```

**Answer:**

An aggregate class cannot have in-class initializers. Thus, in order to initialize `item` with a curly braced list, we have to rewrite the class definition as

```c++
struct Sales_data {
  std::string bookNo;
  unsigned units_sold;
  double revenue;
};
```

### Exercise 7.53

> Define your own version of `Debug`.

**Answer:**

- [`07-53.cpp`](07-53.cpp)

### Exercise 7.54

> Should the members of `Debug` that begin with `set_` be declared as `constexpr`? If not, why not?

**Answer:**

No. Ultimately, a `constexpr` function is a function which we may use in a constant expression. As `set_` functions return no value, it seems pointless to declare it as `constexpr`. Apart from that, the C++11 restriction on a `constexpr` is quite strict:

1. a `constexpr` function must have *exactly one* `return`, which the `set_` functions do not satisfy

2. a `constexpr` function is implicitly `const` in C++11, which the `set_` functions do not satisfy

*^ C++11 states that all non-static member functions that are declared `constexpr` are also implicitly declared `const`, with respect to `this`. That has since been removed; non-static member functions can be non-`const` in C++14.*

### Exercise 7.55

> Is the `Data` class from Section 7.5.5 (p. 298) a literal class? If not, why not? If so, explain why it is literal.
>
> ```c++
> struct Data {
>   int ival;
>   string s;
> };
> ```

**Answer:**

No. To be a literal class, an aggregate class must have all of its members have literal types, but `s` is a `std::string`, which is not a literal type.

## Section 7.6 static Class Members

### Exercise 7.56

> What is a static class member? What are the advantages of static members? How do they differ from ordinary members?

**Answer:**

- *What is a static class member?*

  A static class member is a class member that is associated with the entire class. It is not associated with any individual objects.

- *What are the advantages of `static` members?*

  - It can used to store values that are common to all objects, for example, the interest rate for all the bank accounts. When the value changes, we do not have to make changes for each object.

  - It can be used in ways that ordinary members cannot. For example, it can have incomplete type. In particular, it may have the same type as that of its class.

- *How do they differ from ordinary members?*

  - a `static` data member does not belong to any object and thus should be defined outside the class

  - a `static` member function does not have the implicit `this` pointer and thus may not specified as `const`

### Exercise 7.57

> Write your own version of the `Account` class.

**Answer:**

- [`07-57.cpp`](07-57.cpp)

### Exercise 7.58

> Which, if any, of the following static data member declarations and definitions are errors? Explain why.
>
> ```c++
> // example.h
> class Example {
> public:
>   static double rate = 6.5;
>   static const int vecSize = 20;
>   static vector<double> vec(vecSize);
> };
>
> // example.C
> #include "example.h"
> double Example::rate;
> vector<double> Example::vec;
> ```

**Answer:**

`static double rate = 6.5;` and `static vector<double> vec(vecSize);` are wrong in C++11. It is illegal to provide in-class initializers to non-`const` static data members.

*^ C++17 makes it possible with inline variables. An inline static data member can be defined in the class definition.*
