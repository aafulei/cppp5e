# Chapter 18 Tools for Large Programs

- [Section 18.1 Exception Handling](#section-181-exception-handling)
  - *Exercises* [`18.1`](#exercise-181) [`18.2`](#exercise-182) [`18.3`](#exercise-183)
  - *Exercises* [`18.4`](#exercise-184) [`18.5`](#exercise-185) [`18.6`](#exercise-186)
  - *Exercises* [`18.7`](#exercise-187)
  - *Exercises* [`18.8`](#exercise-188)
  - *Exercises* [`18.9`](#exercise-189) [`18.10`](#exercise-1810) [`18.11`](#exercise-1811)

- [Section 18.2 Namespaces](#section-182-namespaces)
  - *Exercises* [`18.12`](#exercise-1812) [`18.13`](#exercise-1813) [`18.14`](#exercise-1814)
  - *Exercises* [`18.15`](#exercise-1815) [`18.16`](#exercise-1816) [`18.17`](#exercise-1817)
  - *Exercises* [`18.18`](#exercise-1818) [`18.19`](#exercise-1819)
  - *Exercises* [`18.20`](#exercise-1820)

- [Section 18.3 Multiple and Virtual Inheritance](#section-183-multiple-and-virtual-inheritance)
  - *Exercises* [`18.21`](#exercise-1821) [`18.22`](#exercise-1822)
  - *Exercises* [`18.23`](#exercise-1823) [`18.24`](#exercise-1824) [`18.25`](#exercise-1825)
  - *Exercises* [`18.26`](#exercise-1826) [`18.27`](#exercise-1827)
  - *Exercises* [`18.28`](#exercise-1828)
  - *Exercises* [`18.29`](#exercise-1829) [`18.30`](#exercise-1830)

## Section 18.1 Exception Handling

### Exercise 18.1

> What is the type of the exception object in the following throws?
>
> (a) `range_error r("error");`
>
> (b) `exception *p = &r;`
>
> ```c++
> throw r;
> throw *p;
> ```
>
> What would happen if the throw in (b) were written as throw p?

**Answer:**

### Exercise 18.2

> Explain what happens if an exception occurs at the indicated point:
>
> ```c++
> void exercise(int *b, int *e) {
>   vector<int> v(b, e);
>   int *p = new int[v.size()];
>   ifstream in("ints");
>   // exception occurs here
> }
> ```

**Answer:**

### Exercise 18.3

> There are two ways to make the previous code work correctly if an exception is thrown. Describe them and implement them.

**Answer:**

### Exercise 18.4

> Looking ahead to the inheritance hierarchy in Figure 18.1 (p. 783), explain what's wrong with the following try block. Correct it.
>
> ```c++
> try {
>   // use of the C++ standard library
> } catch (exception) {
>   // ...
> } catch (const runtime_error &re) {
>   // ...
> } catch (overflow_error eobj) { /* ... */
> }
> ```

**Answer:**

### Exercise 18.5

> Modify the following main function to catch any of the exception types shown in Figure 18.1 (p. 783):
>
> ```c++
> int main() {
>   // use of the C++ standard library
> }
> ```
>
> The handlers should print the error message associated with the exception before calling abort (defined in the header cstdlib) to terminate main.

**Answer:**

- [`18-05.cpp`](18-05.cpp)

### Exercise 18.6

> Given the following exception types and catch clauses, write a throw expression that creates an exception object that can be caught by each catch clause:
>
> (a)
> ```c++
> class exceptionType { };
> catch(exceptionType *pet) { }
> ```
>
> (b)
> ```c++
> catch(...) { }
> ```
>
> (c)
> ```c++
> typedef int EXCPTYPE;
> catch(EXCPTYPE) { }
> ```

**Answer:**

### Exercise 18.7

> Define your Blob and BlobPtr classes from Chapter 16 to use function try blocks for their constructors.

**Answer:**

- [`18-07.cpp`](18-07.cpp)

### Exercise 18.8

> Review the classes you've written and add appropriate exception specifications to their constructors and destructors. If you think one of your destructors might throw, change the code so that it cannot throw.

**Answer:**

### Exercise 18.9

> Define the bookstore exception classes described in this section and rewrite your `Sales_data` compound assigment operator to throw an exception.

**Answer:**

- [`18-09.cpp`](18-09.cpp)

### Exercise 18.10

> Write a program that uses the `Sales_data` addition operator on objects that have differing ISBN s. Write two versions of the program: one that handles the exception and one that does not. Compare the behavior of the programs so that you become familiar with what happens when an uncaught exception occurs.

**Answer:**

- [`18-10.cpp`](18-10.cpp)

### Exercise 18.11

> Why is it important that the what function doesn't throw?

**Answer:**

## Section 18.2 Namespaces

### Exercise 18.12

> Organize the programs you have written to answer the questions in each chapter into their own namespaces. That is, namespace chapter15 would contain code for the Query programs and chapter10 would contain the TextQuery code. Using this structure, compile the Query code examples.

**Answer:**

### Exercise 18.13

> When might you use an unnamed namespace?

**Answer:**

### Exercise 18.14

> Suppose we have the following declaration of the operator* that is a member of the nested namespace mathLib::MatrixLib:
>
> ```c++
> namespace mathLib {
> namespace MatrixLib {
> class matrix { /* ... */
> };
> matrix operator*(const matrix &, const matrix &);
> // ...
> } // namespace MatrixLib
> } // namespace mathLib
> ```
>
> How would you declare this operator in global scope?

**Answer:**

### Exercise 18.15

> Explain the differences between using declarations and directives.

**Answer:**

### Exercise 18.16

> Explain the following code assuming using declarations for all the members of namespace Exercise are located at the location labeled position 1. What if they appear at position 2 instead? Now answer the same question but replace the using declarations with a using directive for namespace Exercise.
>
> ```c++
> namespace Exercise {
> int ivar = 0;
> double dvar = 0;
> const int limit = 1000;
> } // namespace Exercise
> int ivar = 0;
> // position 1
> void manip() {
>   // position 2
>   double dvar = 3.1416;
>   int iobj = limit + 1;
>   ++ivar;
>   ++::ivar;
> }
> ```

**Answer:**

### Exercise 18.17

> Write code to test your answers to the previous question.

**Answer:**

- [`18-17.cpp`](18-17.cpp)

### Exercise 18.18

> Given the following typical definition of swap Section 13.3 (p. 517), determine which version of swap is used if mem1 is a string. What if mem1 is an `int`? Explain how name lookup works in both cases. void swap(T v1, T v2)
>
> ```c++
> {
>   using std::swap;
>   swap(v1.mem1, v2.mem1);
>   // swap remaining members of type T
> }
> ```

**Answer:**

### Exercise 18.19

> What if the call to swap was std::swap(v1.mem1, v2.mem1)?

**Answer:**

### Exercise 18.20

> In the following code, determine which function, if any, matches the call to compute. List the candidate and viable functions. What type conversions, if any, are applied to the argument to match the parameter in each viable function?
>
> ```c++
> namespace primerLib {
> void compute();
> void compute(const void *);
> } // namespace primerLib
> using primerLib::compute;
> void compute(int);
> void compute(double, double = 3.4);
> void compute(char *, char * = 0);
> void f() { compute(0); }
> ```
>
> What would happen if the using declaration were located in main before the call to compute? Answer the same questions as before.

**Answer:**

## Section 18.3 Multiple and Virtual Inheritance

### Exercise 18.21

> Explain the following declarations. Identify any that are in error and explain why they are incorrect:
>
> (a) `class CADVehicle : public CAD, Vehicle { ... };`
>
> (b) `class DblList: public List, public List { ... };`
>
> (c) `class iostream: public istream, public ostream { ... };`

**Answer:**

### Exercise 18.22

> Given the following class hierarchy, in which each class defines a default constructor: class class class class class class class

**Answer:**

### Exercise 18.23

> Using the hierarchy in exercise 18.22 along with class D defined below, and assuming each class defines a default constructor, which, if any, of the following conversions are not permitted?
>
> ```c++
> class D : public X, public C {
>   ...
> };
> D *pd = new D;
> ```
>
> (a) `X *px = pd;`
>
> (b) `A *pa = pd;`
>
> (c) `B *pb = pd;`
>
> (d) `C *pc = pd;`

**Answer:**

### Exercise 18.24

> On *page 807* we presented a series of calls made through a Bear pointer that pointed to a Panda object. Explain each call assuming we used a ZooAnimal pointer pointing to a Panda object instead.

**Answer:**

### Exercise 18.25

> Assume we have two base classes, Base1 and Base2, each of which defines a virtual member named print and a virtual destructor. From these base classes we derive the following classes, each of which redefines the print function:
>
> ```c++
> class D1 : public Base1 { /* ... */ };
> class D2 : public Base2 { /* ... */ };
> class MI : public D1, public D2 { /* ... */ };
> ```
>
> Using the following pointers, determine which function is used in each call:
>
> ```c++
> Base1 *pb1 = new MI;
> Base2 *pb2 = new MI;
> D1 *pd1 = new MI;
> D2 *pd2 = new MI;
> ```
>
> (a) `pb1->print();`
>
> (b) `pd1->print();`
>
> (c) `pd2->print();`
>
> (d) `delete pb2;`
>
> (e) `delete pd1;`
>
> (f) `delete pd2;`

**Answer:**

### Exercise 18.26

> Given the hierarchy in the box on *page 810*, why is the following call to print an error? Revise MI to allow this call to print to compile and execute correctly.
>
> ```c++
> MI mi;
> mi.print(42);
> ```

**Answer:**

- [`18-26.cpp`](18-26.cpp)

### Exercise 18.27

> Given the class hierarchy in the box on *page 810* and assuming we add a function named foo to MI as follows:
>
> ```c++
> int ival;
> double dval;
> void MI::foo(double cval) {
>   int dval;
>   // exercise questions occur here
> }
> ```
>
> (a) List all the names visible from within `MI::foo`.
> (b) Are any names visible from more than one base class?
> (c) Assign to the local instance of `dval` the sum of the `dval` member of `Base1` and the `dval` member of `Derived`.
> (d) Assign the value of the last element in `MI::dvec` to `Base2::fval`.
> (e) Assign `cval` from `Base1` to the first character in `sval` from `Derived`.

**Answer:**

### Exercise 18.28

> Given the following class hierarchy, which inherited members can be accessed without qualification from within the VMI class? Which require qualification? Explain your reasoning.
>
> ```c++
> struct Base {
>   void bar(int);
>
> protected:
>   int ival;
> };
> ```

**Answer:**

### Exercise 18.29

> Given the following class hierarchy: class class class class class class

**Answer:**

### Exercise 18.30

> Define a default constructor, a copy constructor, and a constructor that has an `int` parameter in Base. Define the same three constructors in each derived class. Each constructor should use its argument to initialize its Base part.

**Answer:**

- [`18-30.cpp`](18-30.cpp)

