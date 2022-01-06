# Chapter 14 Overloaded Operations and Conversions

- [Section 14.1 Basic Concepts](#section-141-basic-concepts)
  - *Exercises* [`14.1`](#exercise-141) [`14.2`](#exercise-142) [`14.3`](#exercise-143) [`14.4`](#exercise-144) [`14.5`](#exercise-145)

- [Section 14.2 Input and Output Operators](#section-142-input-and-output-operators)
  - *Exercises* [`14.6`](#exercise-146) [`14.7`](#exercise-147) [`14.8`](#exercise-148)
  - *Exercises* [`14.9`](#exercise-149) [`14.10`](#exercise-1410) [`14.11`](#exercise-1411) [`14.12`](#exercise-1412)

- [Section 14.3 Arithmetic and Relational Operators](#section-143-arithmetic-and-relational-operators)
  - *Exercises* [`14.13`](#exercise-1413) [`14.14`](#exercise-1414) [`14.15`](#exercise-1415)
  - *Exercises* [`14.16`](#exercise-1416) [`14.17`](#exercise-1417)
  - *Exercises* [`14.18`](#exercise-1418) [`14.19`](#exercise-1419)

- [Section 14.4 Assignment Operators](#section-144-assignment-operators)
  - *Exercises* [`14.20`](#exercise-1420) [`14.21`](#exercise-1421) [`14.22`](#exercise-1422) [`14.23`](#exercise-1423) [`14.24`](#exercise-1424) [`14.25`](#exercise-1425)

- [Section 14.5 Subscript Operator](#section-145-subscript-operator)
  - *Exercises* [`14.26`](#exercise-1426)

- [Section 14.6 Increment and Decrement Operators](#section-146-increment-and-decrement-operators)
  - *Exercises* [`14.27`](#exercise-1427) [`14.28`](#exercise-1428) [`14.29`](#exercise-1429)

- [Section 14.7 Member Access Operators](#section-147-member-access-operators)
  - *Exercises* [`14.30`](#exercise-1430) [`14.31`](#exercise-1431) [`14.32`](#exercise-1432)

- [Section 14.8 Function-Call Operator](#section-148-functioncall-operator)
  - *Exercises* [`14.33`](#exercise-1433) [`14.34`](#exercise-1434) [`14.35`](#exercise-1435) [`14.36`](#exercise-1436) [`14.37`](#exercise-1437)
  - *Exercises* [`14.38`](#exercise-1438) [`14.39`](#exercise-1439) [`14.40`](#exercise-1440) [`14.41`](#exercise-1441)
  - *Exercises* [`14.42`](#exercise-1442) [`14.43`](#exercise-1443)
  - *Exercises* [`14.44`](#exercise-1444)

- [Section 14.9 Overloading, Conversions, and Operators](#section-149-overloading-conversions-and-operators)
  - *Exercises* [`14.45`](#exercise-1445) [`14.46`](#exercise-1446) [`14.47`](#exercise-1447) [`14.48`](#exercise-1448) [`14.49`](#exercise-1449)
  - *Exercises* [`14.50`](#exercise-1450) [`14.51`](#exercise-1451)
  - *Exercises* [`14.52`](#exercise-1452) [`14.53`](#exercise-1453)

## Section 14.1 Basic Concepts

### Exercise 14.1

> In what ways does an overloaded operator differ from a built-in operator? In what ways are overloaded operators the same as the built-in operators?

**Answer:**

### Exercise 14.2

> Write declarations for the overloaded input, output, addition, and compound-assignment operators for `Sales_data`.

**Answer:**

- [`14-02.cpp`](14-02.cpp)

### Exercise 14.3

> Both string and vector define an overloaded == that can be used to compare objects of those types. Assuming svec1 and svec2 are vectors that hold strings, identify which version of == is applied in each of the following expressions:
>
> (a) `"cobble" == "stone"`
>
> (b) `svec1[0] == svec2[0]`
>
> (c) `svec1 == svec2`
>
> (d) `"svec1[0] == "stone"`

**Answer:**

### Exercise 14.4

> Explain how to decide whether the following should be class members:
>
> (a) `%`
>
> (b) `%=`
>
> (c) `++`
>
> (d) `->`
>
> (e) `<<`
>
> (f) `&&`
>
> (g) `==`
>
> (h) `()`

**Answer:**

### Exercise 14.5

> In exercise 7.40 from Section 7.5.1 (p. 291) you wrote a sketch of one of the following classes. Decide what, if any, overloaded operators your class should provide.
>
> (a) Book
> (b) Date
> (c) Employee
> (d) Vehicle
> (e) Object
> (f) Tree

**Answer:**

## Section 14.2 Input and Output Operators

### Exercise 14.6

> Define an output operator for your `Sales_data` class.

**Answer:**

- [`14-06.cpp`](14-06.cpp)

### Exercise 14.7

> Define an output operator for you String class you wrote for the exercises in Section 13.5 (p. 531).

**Answer:**

- [`14-07.cpp`](14-07.cpp)

### Exercise 14.8

> Define an output operator for the class you chose in exercise 7.40 from Section 7.5.1 (p. 291).

**Answer:**

- [`14-08.cpp`](14-08.cpp)

### Exercise 14.9

> Define an input operator for your `Sales_data` class.

**Answer:**

- [`14-09.cpp`](14-09.cpp)

### Exercise 14.10

> Describe the behavior of the `Sales_data` input operator if given the following input:
>
> (a) `0-201-99999-9 10 24.95`
>
> (b) `10 24.95 0-210-99999-9`

**Answer:**

### Exercise 14.11

> What, if anything, is wrong with the following `Sales_data` input operator? What would happen if we gave this operator the data in the previous exercise?
>
> ```c++
> istream &operator>>(istream &in, Sales_data &s) {
>   double price;
>   in >> s.bookNo >> s.units_sold >> price;
>   s.revenue = s.units_sold * price;
>   return in;
> }
> ```

**Answer:**

### Exercise 14.12

> Define an input operator for the class you used in exercise 7.40 from Section 7.5.1 (p. 291). Be sure the operator handles input errors.

**Answer:**

- [`14-12.cpp`](14-12.cpp)

## Section 14.3 Arithmetic and Relational Operators

### Exercise 14.13

> Which other arithmetic operators (Table 4.1 (p. 139)), if any, do you think `Sales_data` ought to support? Define any you think the class should include.

**Answer:**

- [`14-13.cpp`](14-13.cpp)

### Exercise 14.14

> Why do you think it is more efficient to define operator+ to call operator+= rather than the other way around?

**Answer:**

### Exercise 14.15

> Should the class you chose for exercise 7.40 from Section 7.5.1 (p. 291) define any of the arithmetic operators? If so, implement them. If not, explain why not.

**Answer:**

### Exercise 14.16

> Define equality and inequality operators for your StrBlob (Section 12.1.1, p. 456), StrBlobPtr (Section 12.1.6, p. 474), StrVec (Section 13.5, p. 526), and String (Section 13.5, p. 531) classes.

**Answer:**

- [`14-16.cpp`](14-16.cpp)

### Exercise 14.17

> Should the class you chose for exercise 7.40 from Section 7.5.1 (p. 291) define the equality operators? If so, implement them. If not, explain why not.

**Answer:**

### Exercise 14.18

> Define relational operators for your StrBlob, StrBlobPtr, StrVec, and String classes.

**Answer:**

- [`14-18.cpp`](14-18.cpp)

### Exercise 14.19

> Should the class you chose for exercise 7.40 from Section 7.5.1 (p. 291) define the relational operators? If so, implement them. If not, explain why not.

**Answer:**

## Section 14.4 Assignment Operators

### Exercise 14.20

> Define the addition and compound-assignment operators for your `Sales_data` class.

**Answer:**

- [`14-20.cpp`](14-20.cpp)

### Exercise 14.21

> Write the `Sales_data` operators so that + does the actual addition and += calls +. Discuss the disadvantages of this approach compared to the way these operators were defined in Section 14.3 (p. 560) and Section 14.4 (p. 564).

**Answer:**

- [`14-21.cpp`](14-21.cpp)

### Exercise 14.22

> Define a version of the assignment operator that can assign a string representing an ISBN to a `Sales_data`.

**Answer:**

- [`14-22.cpp`](14-22.cpp)

### Exercise 14.23

> Define an initializer_list assignment operator for your version of the StrVec class.

**Answer:**

- [`14-23.cpp`](14-23.cpp)

### Exercise 14.24

> Decide whether the class you used in exercise 7.40 from Section 7.5.1 (p. 291) needs a copy- and move-assignment operator. If so, define those operators.

**Answer:**

### Exercise 14.25

> Implement any other assignment operators your class should define. Explain which types should be used as operands and why.

**Answer:**

- [`14-25.cpp`](14-25.cpp)

## Section 14.5 Subscript Operator

### Exercise 14.26

> Define subscript operators for your StrVec, String, StrBlob, and StrBlobPtr classes.

**Answer:**

- [`14-26.cpp`](14-26.cpp)

## Section 14.6 Increment and Decrement Operators

### Exercise 14.27

> Add increment and decrement operators to your StrBlobPtr class.

**Answer:**

### Exercise 14.28

> Define addition and subtraction for StrBlobPtr so that these operators implement pointer arithmetic (Section 3.5.3, p. 119).

**Answer:**

- [`14-28.cpp`](14-28.cpp)

### Exercise 14.29

> We did not define a `const` version of the increment and decrement operators. Why not?

**Answer:**

## Section 14.7 Member Access Operators

### Exercise 14.30

> Add dereference and arrow operators to your StrBlobPtr class and to the ConstStrBlobPtr class that you defined in exercise 12.22 from Section 12.1.6 (p. 476). Note that the operators in constStrBlobPtr must return `const` references because the data member in constStrBlobPtr points to a const vector.

**Answer:**

### Exercise 14.31

> Our StrBlobPtr class does not define the copy constructor, assignment operator, or a destructor. Why is that okay?

**Answer:**

### Exercise 14.32

> Define a class that holds a pointer to a StrBlobPtr. Define the overloaded arrow operator for that class.

**Answer:**

- [`14-32.cpp`](14-32.cpp)

## Section 14.8 Function-Call Operator

### Exercise 14.33

> How many operands may an overloaded function-call operator take?

**Answer:**

### Exercise 14.34

> Define a function-object class to perform an if-then-else operation: The call operator for this class should take three parameters. It should test its first parameter and if that test succeeds, it should return its second parameter; otherwise, it should return its third parameter.

**Answer:**

- [`14-34.cpp`](14-34.cpp)

### Exercise 14.35

> Write a class like PrintString that reads a line of input from an istream and returns a string representing what was read. If the read fails, return the empty string.

**Answer:**

- [`14-35.cpp`](14-35.cpp)

### Exercise 14.36

> Use the class from the previous exercise to read the standard input, storing each line as an element in a vector.

**Answer:**

### Exercise 14.37

> Write a class that tests whether two values are equal. Use that object and the library algorithms to write a program to replace all instances of a given value in a sequence.

**Answer:**

- [`14-37.cpp`](14-37.cpp)

### Exercise 14.38

> Write a class that tests whether the length of a given string matches a given bound. Use that object to write a program to report how many words in an input file are of sizes 1 through 10 inclusive.

**Answer:**

- [`14-38.cpp`](14-38.cpp)

### Exercise 14.39

> Revise the previous program to report the count of words that are sizes 1 through 9 and 10 or more.

**Answer:**

- [`14-39.cpp`](14-39.cpp)

### Exercise 14.40

> Rewrite the biggies function from Section 10.3.2 (p. 391) to use functionobject classes in place of lambdas.

**Answer:**

- [`14-40.cpp`](14-40.cpp)

### Exercise 14.41

> Why do you suppose the new standard added lambdas? Explain when you would use a lambda and when you would write a class instead.

**Answer:**

### Exercise 14.42

> Using library function objects and adaptors, define an expression to
>
> (a) `Count the number of values that are greater than 1024`
>
> (b) `Find the first string that is not equal to pooh`
>
> (c) `Multiply all values by 2`

**Answer:**

### Exercise 14.43

> Using library function objects, determine whether a given `int` value is divisible by any element in a container of ints.

**Answer:**

### Exercise 14.44

> Write your own version of a simple desk calculator that can handle binary operations.

**Answer:**

- [`14-44.cpp`](14-44.cpp)

## Section 14.9 Overloading, Conversions, and Operators

### Exercise 14.45

> Write conversion operators to convert a `Sales_data` to string and to `double`. What values do you think these operators should return?

**Answer:**

- [`14-45.cpp`](14-45.cpp)

### Exercise 14.46

> Explain whether defining these `Sales_data` conversion operators is a good idea and whether they should be explicit.

**Answer:**

### Exercise 14.47

> Explain the difference between these two conversion operators:
>
> ```c++
> struct Integral {
>   operator const int();
>   operator int() const;
> };
> ```

**Answer:**

### Exercise 14.48

> Determine whether the class you used in exercise 7.40 from Section 7.5.1 (p. 291) should have a conversion to bool. If so, explain why, and explain whether the operator should be explicit. If not, explain why not.

**Answer:**

### Exercise 14.49

> Regardless of whether it is a good idea to do so, define a conversion to bool for the class from the previous exercise.

**Answer:**

### Exercise 14.50

> Show the possible class-type conversion sequences for the initializations of ex1 and ex2. Explain whether the initializations are legal or not.
>
> ```c++
> struct LongDouble {
>   LongDouble(double = 0.0);
>   operator double();
>   operator float();
> };
> LongDouble ldObj;
> int ex1 = ldObj;
> float ex2 = ldObj;
> ```

**Answer:**

### Exercise 14.51

> Show the conversion sequences (if any) needed to call each version of calc and explain why the best viable function is selected.
>
> ```c++
> void calc(int);
> void calc(LongDouble);
> double dval;
> calc(dval); // which calc?
> ```

**Answer:**

### Exercise 14.52

> Which operator+, if any, is selected for each of the addition expressions? List the candidate functions, the viable functions, and the type conversions on the arguments for each viable function:
>
> ```c++
> struct LongDouble {
>   // member operator+ for illustration purposes; + is usually a nonmember
>   LongDouble operator+(const SmallInt &);
>   // other members as in Section 14.9.2 (p. 587)
> };
> LongDouble operator+(LongDouble &, double);
> SmallInt si;
> LongDouble ld;
> ld = si + ld;
> ld = ld + si;
> ```

**Answer:**

### Exercise 14.53

> Given the definition of SmallInt on *page 588*, determine whether the following addition expression is legal. If so, what addition operator is used? If not, how might you change the code to make it legal?
>
> ```c++
> SmallInt s1;
> double d = s1 + 3.14;
> ```

**Answer:**

