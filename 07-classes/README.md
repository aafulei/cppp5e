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

### Exercise 7.17

> What, if any, are the differences between using class or struct?

**Answer:**

### Exercise 7.18

> What is encapsulation? Why is it useful?

**Answer:**

### Exercise 7.19

> Indicate which members of your Person class you would declare as public and which you would declare as private. Explain your choice.

**Answer:**

### Exercise 7.20

> When are friends useful? Discuss the pros and cons of using friends.

**Answer:**

### Exercise 7.21

> Update your `Sales_data` class to hide its implementation. The programs you've written to use `Sales_data` operations should still continue to work. Recompile those programs with your new class definition to verify that they still work.

**Answer:**

- [`07-21.cpp`](07-21.cpp)

### Exercise 7.22

> Update your Person class to hide its implementation.

**Answer:**

- [`07-22.cpp`](07-22.cpp)

## Section 7.3 Additional Class Features

### Exercise 7.23

> Write your own version of the Screen class.

**Answer:**

- [`07-23.cpp`](07-23.cpp)

### Exercise 7.24

> Give your Screen class three constructors: a default constructor; a constructor that takes values for height and width and initializes the contents to hold the given number of blanks; and a constructor that takes values for height, width, and a character to use as the contents of the screen.

**Answer:**

### Exercise 7.25

> Can Screen safely rely on the default versions of copy and assignment? If so, why? If not, why not?

**Answer:**

### Exercise 7.26

> Define Sales_data::avg_price as an inline function.

**Answer:**

- [`07-26.cpp`](07-26.cpp)

### Exercise 7.27

> Add the move, set, and display operations to your version of Screen. Test your class by executing the following code:
>
> ```c++
> Screen myScreen(5, 5, 'X');
> myScreen.move(4, 0).set('#').display(cout);
> cout << "\n";
> myScreen.display(cout);
> cout << "\n";
> ```

**Answer:**

### Exercise 7.28

> What would happen in the previous exercise if the return type of move, set, and display was Screen rather than Screen&?

**Answer:**

### Exercise 7.29

> Revise your Screen class so that move, set, and display functions return Screen and check your prediction from the previous exercise.

**Answer:**

- [`07-29.cpp`](07-29.cpp)

### Exercise 7.30

> It is legal but redundant to refer to members through the this pointer. Discuss the pros and cons of explicitly using the this pointer to access members.

**Answer:**

### Exercise 7.31

> Define a pair of classes X and Y, in which X has a pointer to Y, and Y has an object of type X.

**Answer:**

- [`07-31.cpp`](07-31.cpp)

### Exercise 7.32

> Define your own versions of Screen and Window_mgr in which clear is a member of Window_mgr and a friend of Screen.

**Answer:**

- [`07-32.cpp`](07-32.cpp)

## Section 7.4 Class Scope

### Exercise 7.33

> What would happen if we gave Screen a size member defined as follows? Fix any problems you identify.
>
> ```c++
> pos Screen::size() const { return height * width; }
> ```

**Answer:**

### Exercise 7.34

> What would happen if we put the typedef of pos in the Screen class on *page 285* as the last line in the class?

**Answer:**

### Exercise 7.35

> Explain the following code, indicating which definition of Type or initVal is used for each use of those names. Say how you would fix any errors.
>
> ```c++
> typedef string Type;
> Type initVal();
> class Exercise {
> public:
>   typedef double Type;
>   Type setVal(Type);
>   Type initVal();
>
> private:
>   int val;
> };
> Type Exercise::setVal(Type parm) {
>   val = parm + initVal();
>   return val;
> }
> ```

**Answer:**

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

### Exercise 7.37

> Using the version of `Sales_data` from this section, determine which constructor is used to initialize each of the following variables and list the values of the data members in each object:
>
> ```c++
> Sales_data first_item(cin);
> int main() {
>   Sales_data next;
>   Sales_data last("9-999-99999-9");
> }
> ```

**Answer:**

### Exercise 7.38

> We might want to supply `cin` as a default argument to the constructor that takes an istream&. Write the constructor declaration that uses `cin` as a default argument.

**Answer:**

- [`07-38.cpp`](07-38.cpp)

### Exercise 7.39

> Would it be legal for both the constructor that takes a string and the one that takes an istream& to have default arguments? If not, why not?

**Answer:**

### Exercise 7.40

> Choose one of the following abstractions (or an abstraction of your own choosing). Determine what data are needed in the class. Provide an appropriate set of constructors. Explain your decisions.
>
> (a) Book
> (b) Date
> (c) Employee
> (d) Vehicle
> (e) Object
> (f) Tree

**Answer:**

### Exercise 7.41

> Rewrite your own version of the `Sales_data` class to use delegating constructors. Add a statement to the body of each of the constructors that prints a message whenever it is executed. Write declarations to construct a `Sales_data` object in every way possible. Study the output until you are certain you understand the order of execution among delegating constructors.

**Answer:**

- [`07-41.cpp`](07-41.cpp)

### Exercise 7.42

> For the class you wrote for exercise 7.40 in Section 7.5.1 (p. 291), decide whether any of the constructors might use delegation. If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.

**Answer:**

- [`07-42.cpp`](07-42.cpp)

### Exercise 7.43

> Assume we have a class named NoDefault that has a constructor that takes an `int`, but has no default constructor. Define a class C that has a member of type NoDefault. Define the default constructor for C.

**Answer:**

- [`07-43.cpp`](07-43.cpp)

### Exercise 7.44

> Is the following declaration legal? If not, why not?
>
> ```c++
> vector<NoDefault> vec(10);
> ```

**Answer:**

### Exercise 7.45

> What if we defined the vector in the previous execercise to hold objects of type C?

**Answer:**

### Exercise 7.46

> Which, if any, of the following statements are untrue? Why?
>
> (a) A class must provide at least one constructor.
> (b) A default constructor is a constructor with an empty parameter list.
> (c) If there are no meaningful default values for a class, the class should not provide a default constructor.
> (d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type.

**Answer:**

### Exercise 7.47

> Explain whether the `Sales_data` constructor that takes a string should be explicit. What are the benefits of making the constructor explicit? What are the drawbacks?

**Answer:**

### Exercise 7.48

> Assuming the `Sales_data` constructors are not explicit, what operations happen during the following definitions string null_isbn("9-999-99999-9");
>
> ```c++
> Sales_data item1(null_isbn);
> Sales_data item2("9-999-99999-9");
> What happens if the Sales_data constructors are explicit ?
> ```

**Answer:**

### Exercise 7.49

> For each of the three following declarations of combine, explain what happens if we call i.combine(s), where i is a `Sales_data` and s is a string:
>
> (a) `Sales_data &combine(Sales_data);`
>
> (b) `Sales_data &combine(Sales_data&);`
>
> (c) `Sales_data &combine(const Sales_data&) const;`

**Answer:**

### Exercise 7.50

> Determine whether any of your Person class constructors should be explicit.

**Answer:**

### Exercise 7.51

> Why do you think vector defines its single-argument constructor as explicit, but string does not?

**Answer:**

### Exercise 7.52

> Using our first version of `Sales_data` from Section 2.6.1 (p. 72), explain the following initialization. Identify and fix any problems.
>
> ```c++
> Sales_data item = {"978-0590353403", 25, 15.99};
> ```

**Answer:**

### Exercise 7.53

> Define your own version of Debug.

**Answer:**

- [`07-53.cpp`](07-53.cpp)

### Exercise 7.54

> Should the members of Debug that begin with set_ be declared as constexpr? If not, why not?

**Answer:**

### Exercise 7.55

> Is the Data class from Section 7.5.5 (p. 298) a literal class? If not, why not? If so, explain why it is literal.

**Answer:**

## Section 7.6 static Class Members

### Exercise 7.56

> What is a static class member? What are the advantages of static members? How do they differ from ordinary members?

**Answer:**

### Exercise 7.57

> Write your own version of the Account class.

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
> // example.C
> #include "example.h"
> double Example::rate;
> vector<double> Example::vec;
> ```

**Answer:**

