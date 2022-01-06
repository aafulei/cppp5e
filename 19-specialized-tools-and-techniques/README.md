# Chapter 19 Specialized Tools and Techniques

- [Section 19.1 Controlling Memory Allocation](#section-191-controlling-memory-allocation)
  - *Exercises* [`19.1`](#exercise-191) [`19.2`](#exercise-192)

- [Section 19.2 Run-Time Type Identification](#section-192-runtime-type-identification)
  - *Exercises* [`19.3`](#exercise-193) [`19.4`](#exercise-194) [`19.5`](#exercise-195)
  - *Exercises* [`19.6`](#exercise-196) [`19.7`](#exercise-197) [`19.8`](#exercise-198)
  - *Exercises* [`19.9`](#exercise-199) [`19.10`](#exercise-1910)

- [Section 19.3 Enumerations](#section-193-enumerations)

- [Section 19.4 Pointer to Class Member](#section-194-pointer-to-class-member)
  - *Exercises* [`19.11`](#exercise-1911) [`19.12`](#exercise-1912) [`19.13`](#exercise-1913)
  - *Exercises* [`19.14`](#exercise-1914) [`19.15`](#exercise-1915) [`19.16`](#exercise-1916) [`19.17`](#exercise-1917)
  - *Exercises* [`19.18`](#exercise-1918) [`19.19`](#exercise-1919)

- [Section 19.5 Nested Classes](#section-195-nested-classes)
  - *Exercises* [`19.20`](#exercise-1920)

- [Section 19.6 union: A Space-Saving Class](#section-196-union-a-spacesaving-class)
  - *Exercises* [`19.21`](#exercise-1921) [`19.22`](#exercise-1922) [`19.23`](#exercise-1923) [`19.24`](#exercise-1924) [`19.25`](#exercise-1925)

- [Section 19.7 Local Classes](#section-197-local-classes)

- [Section 19.8 Inherently Nonportable Features](#section-198-inherently-nonportable-features)
  - *Exercises* [`19.26`](#exercise-1926)

## Section 19.1 Controlling Memory Allocation

### Exercise 19.1

> Write your own operator `new(size_t)` function using `malloc` and use `free` to write the `operator delete(void*)` function.

**Answer:**

- [`19-01.cpp`](19-01.cpp)

### Exercise 19.2

> By default, the allocator class uses operator new to obtain storage and operator delete to free it. Recompile and rerun your StrVec programs (Section 13.5, p. 526) using your versions of the functions from the previous exercise.

**Answer:**

- [`19-02.cpp`](19-02.cpp)

## Section 19.2 Run-Time Type Identification

### Exercise 19.3

> Given the following class hierarchy in which each class defines a public default constructor and virtual destructor: class class class class

**Answer:**

### Exercise 19.4

> Using the classes defined in the first exercise, rewrite the following code to convert the expression `*pa` to the `type C&`:
>
> ```c++
> if (C *pc = dynamic_cast<C *>(pa))
> // use C's members
> }
> else {
>   // use A's members
> }
> ```

**Answer:**

### Exercise 19.5

> When should you use a dynamic_cast instead of a virtual function?

**Answer:**

### Exercise 19.6

> Write an expression to dynamically cast a pointer to a Query_base to a pointer to an AndQuery (Section 15.9.1, p. 636). Test the cast by using objects of AndQuery and of another query type. Print a statement indicating whether the cast works and be sure that the output matches your expectations.

**Answer:**

- [`19-06.cpp`](19-06.cpp)

### Exercise 19.7

> Write the same cast, but cast a Query_base object to a reference to AndQuery. Repeat the test to ensure that your cast works correctly.

**Answer:**

- [`19-07.cpp`](19-07.cpp)

### Exercise 19.8

> Write a typeid expression to see whether two Query_base pointers point to the same type. Now check whether that type is an AndQuery.

**Answer:**

- [`19-08.cpp`](19-08.cpp)

### Exercise 19.9

> Write a program similar to the last one in this section to print the names your compiler uses for common type names. If your compiler gives output similar to ours, write a function that will translate those strings to more human-friendly form.

**Answer:**

- [`19-09.cpp`](19-09.cpp)

### Exercise 19.10

> Given the following class hierarchy in which each class defines a public default constructor and virtual destructor, which type name do the following statements print?
>
> ```c++
> class A { /* . . . */
> };
> class B : public A {
>   /* . . .
> class C : public B { /* . . .
> ```

**Answer:**

## Section 19.3 Enumerations

## Section 19.4 Pointer to Class Member

### Exercise 19.11

> What is the difference between an ordinary data pointer and a pointer to a data member?

**Answer:**

### Exercise 19.12

> Define a pointer to member that can point to the cursor member of class Screen. Fetch the value of Screen::cursor through that pointer.

**Answer:**

- [`19-12.cpp`](19-12.cpp)

### Exercise 19.13

> Define the type that can represent a pointer to the bookNo member of the `Sales_data` class.

**Answer:**

- [`19-13.cpp`](19-13.cpp)

### Exercise 19.14

> Is the following code legal? If so, what does it do? If not, why?
>
> ```c++
> auto pmf = &Screen::get_cursor;
> pmf = &Screen::get;
> ```

**Answer:**

### Exercise 19.15

> What is the difference between an ordinary function pointer and a pointer to a member function?

**Answer:**

### Exercise 19.16

> Write a type alias that is a synonym for a pointer that can point to the avg_price member of `Sales_data`.

**Answer:**

- [`19-16.cpp`](19-16.cpp)

### Exercise 19.17

> Define a type alias for each distinct Screen member function type.

**Answer:**

- [`19-17.cpp`](19-17.cpp)

### Exercise 19.18

> Write a function that uses count_if to count how many empty strings there are in a given vector.

**Answer:**

- [`19-18.cpp`](19-18.cpp)

### Exercise 19.19

> Write a function that takes a vector<Sales_data> and finds the first element whose average price is greater than some given amount.

**Answer:**

- [`19-19.cpp`](19-19.cpp)

## Section 19.5 Nested Classes

### Exercise 19.20

> Nest your QueryResult class inside TextQuery and rerun the programs you wrote to use TextQuery in Section 12.3.2 (p. 490).

**Answer:**

## Section 19.6 union: A Space-Saving Class

### Exercise 19.21

> Write your own version of the Token class.

**Answer:**

- [`19-21.cpp`](19-21.cpp)

### Exercise 19.22

> Add a member of type `Sales_data` to your Token class.

**Answer:**

### Exercise 19.23

> Add a move constructor and move assignment to Token.

**Answer:**

### Exercise 19.24

> Explain what happens if we assign a Token object to itself.

**Answer:**

### Exercise 19.25

> Write assignment operators that take values of each type in the union.

**Answer:**

- [`19-25.cpp`](19-25.cpp)

## Section 19.7 Local Classes

## Section 19.8 Inherently Nonportable Features

### Exercise 19.26

> Explain these declarations and indicate whether they are legal:
>
> ```c++
> extern "C" int compute(int *, int);
> extern "C" double compute(double *, double);
> ```

**Answer:**

