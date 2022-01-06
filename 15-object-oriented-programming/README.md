# Chapter 15 Object-Oriented Programming

- [Section 15.1 OOP: An Overview](#section-151-oop-an-overview)

- [Section 15.2 Defining Base and Derived Classes](#section-152-defining-base-and-derived-classes)
  - *Exercises* [`15.1`](#exercise-151) [`15.2`](#exercise-152) [`15.3`](#exercise-153)
  - *Exercises* [`15.4`](#exercise-154) [`15.5`](#exercise-155) [`15.6`](#exercise-156) [`15.7`](#exercise-157)
  - *Exercises* [`15.8`](#exercise-158) [`15.9`](#exercise-159) [`15.10`](#exercise-1510)

- [Section 15.3 Virtual Functions](#section-153-virtual-functions)
  - *Exercises* [`15.11`](#exercise-1511) [`15.12`](#exercise-1512) [`15.13`](#exercise-1513) [`15.14`](#exercise-1514)

- [Section 15.4 Abstract Base Classes](#section-154-abstract-base-classes)
  - *Exercises* [`15.15`](#exercise-1515) [`15.16`](#exercise-1516) [`15.17`](#exercise-1517)

- [Section 15.5 Access Control and Inheritance](#section-155-access-control-and-inheritance)
  - *Exercises* [`15.18`](#exercise-1518) [`15.19`](#exercise-1519) [`15.20`](#exercise-1520) [`15.21`](#exercise-1521) [`15.22`](#exercise-1522)

- [Section 15.6 Class Scope under Inheritance](#section-156-class-scope-under-inheritance)
  - *Exercises* [`15.23`](#exercise-1523)

- [Section 15.7 Constructors and Copy Control](#section-157-constructors-and-copy-control)
  - *Exercises* [`15.24`](#exercise-1524)
  - *Exercises* [`15.25`](#exercise-1525)
  - *Exercises* [`15.26`](#exercise-1526)
  - *Exercises* [`15.27`](#exercise-1527)

- [Section 15.8 Containers and Inheritance](#section-158-containers-and-inheritance)
  - *Exercises* [`15.28`](#exercise-1528) [`15.29`](#exercise-1529)
  - *Exercises* [`15.30`](#exercise-1530)

- [Section 15.9 Text Queries Revisited](#section-159-text-queries-revisited)
  - *Exercises* [`15.31`](#exercise-1531)
  - *Exercises* [`15.32`](#exercise-1532) [`15.33`](#exercise-1533)
  - *Exercises* [`15.34`](#exercise-1534) [`15.35`](#exercise-1535) [`15.36`](#exercise-1536) [`15.37`](#exercise-1537) [`15.38`](#exercise-1538)
  - *Exercises* [`15.39`](#exercise-1539) [`15.40`](#exercise-1540) [`15.41`](#exercise-1541) [`15.42`](#exercise-1542)

## Section 15.1 OOP: An Overview

## Section 15.2 Defining Base and Derived Classes

### Exercise 15.1

> What is a virtual member?

**Answer:**

### Exercise 15.2

> How does the protected access specifier differ from private?

**Answer:**

### Exercise 15.3

> Define your own versions of the Quote class and the print_total function.

**Answer:**

- [`15-03.cpp`](15-03.cpp)

### Exercise 15.4

> Which of the following declarations, if any, are incorrect? Explain why.
>
> ```c++
> class Base {
>   ...
> };
> ```
>
> (a) `class Derived : public Derived { ... };`
>
> (b) `class Derived : private Base { ... };`
>
> (c) `class Derived : public Base;`

**Answer:**

### Exercise 15.5

> Define your own version of the Bulk_quote class.

**Answer:**

- [`15-05.cpp`](15-05.cpp)

### Exercise 15.6

> Test your print_total function from the exercises in Section 15.2.1 (p. 595) by passing both Quote and Bulk_quote objects o that function.

**Answer:**

### Exercise 15.7

> Define a class that implements a limited discount strategy, which applies a discount to books purchased up to a given limit. If the number of copies exceeds that limit, the normal price applies to those purchased beyond the limit.

**Answer:**

- [`15-07.cpp`](15-07.cpp)

### Exercise 15.8

> Define static type and dynamic type.

**Answer:**

- [`15-08.cpp`](15-08.cpp)

### Exercise 15.9

> When is it possible for an expression's static type to differ from its dynamic type? Give three examples in which the static and dynamic type differ.

**Answer:**

### Exercise 15.10

> Recalling the discussion from Section 8.1 (p. 311), explain how the program on *page 317* that passed an ifstream to the `Sales_data` read function works.

**Answer:**

## Section 15.3 Virtual Functions

### Exercise 15.11

> Add a virtual debug function to your Quote class hierarchy that displays the data members of the respective classes.

**Answer:**

### Exercise 15.12

> Is it ever useful to declare a member function as both override and final? Why or why not?

**Answer:**

### Exercise 15.13

> Given the following classes, explain each print function:
>
> ```c++
> class base {
> public:
>   string name() { return basename; }
>   virtual void print(ostream &os) { os << basename; }
>
> private:
>   string basename;
> };
> class derived : public base {
> public:
>   void print(ostream &os) {
>     print(os);
>     os << " " << i;
>   }
>
> private:
>   int i;
> };
> ```
>
> If there is a problem in this code, how would you fix it?

**Answer:**

### Exercise 15.14

> Given the classes from the previous exercise and the following objects, determine which function is called at run time:
>
> ```c++
> base bobj;
> base *bp1 = &bobj;
> derived dobj;
> base *bp2 = &dobj;
> ```
>
> (a) `bobj.print();`
>
> (b) `dobj.print();`
>
> (c) `bp1->name();`
>
> (d) `bp2->name();`
>
> (e) `br1.print();`
>
> (f) `br2.print();`

**Answer:**

## Section 15.4 Abstract Base Classes

### Exercise 15.15

> Define your own versions of Disc_quote and Bulk_quote.

**Answer:**

- [`15-15.cpp`](15-15.cpp)

### Exercise 15.16

> Rewrite the class representing a limited discount strategy, which you wrote for the exercises in Section 15.2.2 (p. 601), to inherit from Disc_quote.

**Answer:**

- [`15-16.cpp`](15-16.cpp)

### Exercise 15.17

> Try to define an object of type Disc_quote and see what errors you get from the compiler.

**Answer:**

## Section 15.5 Access Control and Inheritance

### Exercise 15.18

> Given the classes from *page 612* and *page 613*, and assuming each object has the type specified in the comments, determine which of these assignments are legal. Explain why those that are illegal aren't allowed:
>
> ```c++
> Base *p = &d1; // d1 has type Pub_Derv
> p = &d2;
> // d2 has type Priv_Derv
> p = &d3;
> // d3 has type Prot_Derv
> p = &dd1;
> // dd1 has type Derived_from_Public
> p = &dd2;
> // dd2 has type Derived_from_Private
> p = &dd3;
> // dd3 has type Derived_from_Protected
> ```

**Answer:**

### Exercise 15.19

> Assume that each of the classes from *page 612* and *page 613* has a member function of the form:
>
> ```c++
> void memfcn(Base &b) { b = *this; }
> ```
>
> For each class, determine whether this function would be legal.

**Answer:**

### Exercise 15.20

> Write code to test your answers to the previous two exercises.

**Answer:**

- [`15-20.cpp`](15-20.cpp)

### Exercise 15.21

> Choose one of the following general abstractions containing a family of types (or choose one of your own). Organize the types into an inheritance hierarchy:
>
> (a) Graphical file formats (such as gif, tiff, jpeg, bmp)
> (b) Geometric primitives (such as box, circle, sphere, cone)
> (c) C++ language types (such as class, function, member function)

**Answer:**

### Exercise 15.22

> For the class you chose in the previous exercise, identify some of the likely virtual functions as well as public and protected members.

**Answer:**

## Section 15.6 Class Scope under Inheritance

### Exercise 15.23

> Assuming class D1 on *page 620* had intended to override its inherited fcn function, how would you fix that class? Assuming you fixed the class so that fcn matched the definition in Base, how would the calls in that section be resolved?

**Answer:**

## Section 15.7 Constructors and Copy Control

### Exercise 15.24

> What kinds of classes need a virtual destructor? What operations must a virtual destructor perform?

**Answer:**

### Exercise 15.25

> Why did we define a default constructor for Disc_quote? What effect, if any, would removing that constructor have on the behavior of Bulk_quote?

**Answer:**

### Exercise 15.26

> Define the Quote and Bulk_quote copy-control members to do the same job as the synthesized versions. Give them and the other constructors print statements that identify which function is running. Write programs using these classes and predict what objects will be created and destroyed. Compare your predictions with the output and continue experimenting until your predictions are reliably correct.

**Answer:**

- [`15-26.cpp`](15-26.cpp)

### Exercise 15.27

> Redefine your Bulk_quote class to inherit its constructors.

**Answer:**

## Section 15.8 Containers and Inheritance

### Exercise 15.28

> Define a vector to hold Quote objects but put Bulk_quote objects into that vector. Compute the total net_price of all the elements in the vector.

**Answer:**

- [`15-28.cpp`](15-28.cpp)

### Exercise 15.29

> Repeat your program, but this time store shared_ptrs to objects of type Quote. Explain any discrepancy in the sum generated by the this version and the previous program. If there is no discrepancy, explain why there isn't one.

**Answer:**

### Exercise 15.30

> Write your own version of the Basket class and use it to compute prices for the same transactions as you used in the previous exercises.

**Answer:**

- [`15-30.cpp`](15-30.cpp)

## Section 15.9 Text Queries Revisited

### Exercise 15.31

> Given that s1, s2, s3, and s4 are all strings, determine what objects are created in the following expressions:
>
> (a) `Query(s1) | Query(s2) & ~ Query(s3);`
>
> (b) `Query(s1) | (Query(s2) & ~ Query(s3));`
>
> (c) `(Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));`

**Answer:**

### Exercise 15.32

> What happens when an object of type Query is copied, moved, assigned, and destroyed?

**Answer:**

### Exercise 15.33

> What about objects of type Query_base?

**Answer:**

### Exercise 15.34

> For the expression built in Figure 15.3 (p. 638):
>
> (a) List the constructors executed in processing that expression.
> (b) List the calls to rep that are made from cout << q.
> (c) List the calls to eval made from q.eval().

**Answer:**

### Exercise 15.35

> Implement the Query and Query_base classes, including a definition of rep but omitting the definition of eval.

**Answer:**

- [`15-35.cpp`](15-35.cpp)

### Exercise 15.36

> Put print statements in the constructors and rep members and run your code to check your answers to (a) and (b) from the first exercise.

**Answer:**

### Exercise 15.37

> What changes would your classes need if the derived classes had members of type shared_ptr<Query_base> rather than of type Query?

**Answer:**

### Exercise 15.38

> Are the following declarations legal? If not, why not? If so, explain what the declarations mean.
>
> ```c++
> BinaryQuery a = Query("fiery") & Query("bird");
> AndQuery b = Query("fiery") & Query("bird");
> OrQuery c = Query("fiery") & Query("bird");
> ```

**Answer:**

### Exercise 15.39

> Implement the Query and Query_base classes. Test your application by evaluating and printing a query such as the one in Figure 15.3 (p. 638).

**Answer:**

- [`15-39.cpp`](15-39.cpp)

### Exercise 15.40

> In the OrQuery eval function what would happen if its rhs member returned an empty set? What if its lhs member did so? What if both rhs and lhs returned empty sets?

**Answer:**

### Exercise 15.41

> Reimplement your classes to use built-in pointers to Query_base rather than shared_ptrs. Remember that your classes will no longer be able to use the synthesized copy-control members.

**Answer:**

- [`15-41.cpp`](15-41.cpp)

### Exercise 15.42

> Design and implement one of the following enhancements:
>
> (a) Print words only once per sentence rather than once per line.
> (b) Introduce a history system in which the user can refer to a previous query by number, possibly adding to it or combining it with another.
> (c) Allow the user to limit the results so that only matches in a given range of lines are displayed.

**Answer:**

