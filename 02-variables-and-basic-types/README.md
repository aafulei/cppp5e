# Chapter 2 Variables and Basic Types

- [Section 2.1 Primitive Built-in Types](#section-21-primitive-builtin-types)
  - *Exercises* [`2.1`](#exercise-21) [`2.2`](#exercise-22)
  - *Exercises* [`2.3`](#exercise-23) [`2.4`](#exercise-24)
  - *Exercises* [`2.5`](#exercise-25) [`2.6`](#exercise-26) [`2.7`](#exercise-27) [`2.8`](#exercise-28)

- [Section 2.2 Variables](#section-22-variables)
  - *Exercises* [`2.9`](#exercise-29) [`2.10`](#exercise-210)
  - *Exercises* [`2.11`](#exercise-211)
  - *Exercises* [`2.12`](#exercise-212)
  - *Exercises* [`2.13`](#exercise-213) [`2.14`](#exercise-214)

- [Section 2.3 Compound Types](#section-23-compound-types)
  - *Exercises* [`2.15`](#exercise-215) [`2.16`](#exercise-216) [`2.17`](#exercise-217)
  - *Exercises* [`2.18`](#exercise-218) [`2.19`](#exercise-219) [`2.20`](#exercise-220) [`2.21`](#exercise-221) [`2.22`](#exercise-222) [`2.23`](#exercise-223) [`2.24`](#exercise-224)
  - *Exercises* [`2.25`](#exercise-225)

- [Section 2.4 const Qualiﬁer](#section-24-const-qualier)
  - *Exercises* [`2.26`](#exercise-226)
  - *Exercises* [`2.27`](#exercise-227) [`2.28`](#exercise-228) [`2.29`](#exercise-229)
  - *Exercises* [`2.30`](#exercise-230) [`2.31`](#exercise-231)
  - *Exercises* [`2.32`](#exercise-232)

- [Section 2.5 Dealing with Types](#section-25-dealing-with-types)
  - *Exercises* [`2.33`](#exercise-233) [`2.34`](#exercise-234) [`2.35`](#exercise-235)
  - *Exercises* [`2.36`](#exercise-236) [`2.37`](#exercise-237) [`2.38`](#exercise-238)

- [Section 2.6 Defining Our Own Data Structures](#section-26-defining-our-own-data-structures)
  - *Exercises* [`2.39`](#exercise-239) [`2.40`](#exercise-240)
  - *Exercises* [`2.41`](#exercise-241)
  - *Exercises* [`2.42`](#exercise-242)

## Section 2.1 Primitive Built-in Types

### Exercise 2.1

> What are the differences between `int`, `long`, `long long`, and `short`? Between an unsigned and a signed type? Between a `float` and a `double`?

**Answer:**

Difference

- between `int`, `long`, `long long`, and `short` - size

- between `unsigned` and `signed` - signedness

- between `float` and `double` - precision

### Exercise 2.2

> To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.

**Answer:**

I would use `double`, because floating-point computations are involved, and `double` is the most widely used type. `float` might not have enough precision while `long double` has unnecessary computational cost.

### Exercise 2.3

> What output will the following code produce?
>
> ```c++
> unsigned u = 10, u2 = 42;
> std::cout << u2 - u << std::endl;
> std::cout << u - u2 << std::endl;
> int i = 10, i2 = 42;
> std::cout << i2 - i << std::endl;
> std::cout << i - i2 << std::endl;
> std::cout << i - u << std::endl;
> std::cout << u - i << std::endl;
> ```

**Answer:**

```
32          // unsigned
4294967264  // unsigned
32          // int
-32         // int
0           // unsigned
0           // unsigned
```

### Exercise 2.4

> Write a program to check whether your predictions were correct. If not, study this section until you understand what the problem is.

**Answer:**

- [`02-04.cpp`](02-04.cpp)

### Exercise 2.5

> Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:
>
> (a) `'a', L'a', "a", L"a"`
>
> (b) `10, 10u, 10L, 10uL, 012, 0xC`
>
> (c) `3.14, 3.14f, 3.14L`
>
> (d) `10, 10u, 10., 10e-2`

**Answer:**

- (a)

| Literal | Literal Type      | Type               |
| ------- | ----------------- | ------------------ |
| `'a'`   | character literal | `char`             |
| `L'a'`  | character literal | `wchar_t`          |
| `"a"`   | string literal    | `const char[2]`    |
| `L"a"`  | string literal    | `const wchar_t[2]` |

- (b)

| Literal | Notation     | Literal Type    | Type            |
| ------- | ------------ | --------------- | --------------- |
| `10`    | decimal      | integer literal | `int`           |
| `10u`   | decimal      | integer literal | `unsigned`      |
| `10L`   | decimal      | integer literal | `long`          |
| `10uL`  | decimal      | integer literal | `unsigned long` |
| `012`   | octal        | integer literal | `int`           |
| `0xC`   | hexadecimal  | integer literal | `int`           |

- (c)

| Literal | Literal Type           | Type          |
| ------- | ---------------------- | ------------- |
| `3.14`  | floating-point literal | `double`      |
| `3.14f` | floating-point literal | `float`       |
| `3.14L` | floating-point literal | `long double` |

- (d)

| Literal | Literal Type           | Type          |
| ------- | ---------------------- | ------------- |
| `10`    | integer literal        | `int`         |
| `10u`   | integer literal        | `unsigned`    |
| `10.`   | floating-point literal | `double`      |
| `10e-2` | floating-point literal | `double`      |

### Exercise 2.6

> What, if any, are the differences between the following definitions:
>
> ```c++
> int month = 9, day = 7;
> int month = 09, day = 07;
> ```

**Answer:**

For the integer literals,

- `9` and `7` are decimals.

- `09` is invalid because digit `9` is not allowed in octal notation.

- `07` is an octal.

### Exercise 2.7

> What values do these literals represent? What type does each have?
>
> (a) `"Who goes with F\145rgus?\012"`
>
> (b) `3.14e1L`
>
> (c) `1024f`
>
> (d) `3.14L`

**Answer:**

| Literal                          | Literal Type           | Type             | Value                       |
| -------------------------------- | ---------------------- | ---------------- | --------------------------- |
| `"Who goes with F\145rgus?\012"` | string literal         | `const char[23]` | `"Who goes with Fergus?\n"` |
| `3.14e1L`                        | floating-point literal | `long double`    | `31.4`                      |
| `1024f`                          | floating-point literal | `float`          | `1024.0`                    |
| `3.14L`                          | floating-point literal | `double`         | `3.14`                      |

### Exercise 2.8

> Using escape sequences, write a program to print `2M` followed by a newline. Modify the program to print `2`, then a tab, then an `M`, followed by a newline.

**Answer:**

- [`02-08.cpp`](02-08.cpp)

## Section 2.2 Variables

### Exercise 2.9

> Explain the following definitions. For those that are illegal, explain what's wrong and how to correct it.
>
> (a) `std::cin >> int input_value;`
>
> (b) `int i = { 3.14 };`
>
> (c) `double salary = wage = 9999.99;`
>
> (d) `int i = 3.14;`

**Answer:**

(a) illegal - a variable definition cannot be mixed with the statement that uses it

```c++
int input_value;
std::cin >> input_value;
```

(b) illegal - list initialization does not allow narrowing conversion

```c++
int i = 3.14;
```

(c) illegal - commas are required to separate multiple variable definitions

```c++
double salary = 9999.99, wage = 9999.99;
```

(d) legal - define `i` as an `int` and initialize it with integer value `3`, which is truncated from `3.14`

### Exercise 2.10

> What are the initial values, if any, of each of the following variables?
>
> ```c++
> std::string global_str;
> int global_int;
> int main() {
>   int local_int;
>   std::string local_str;
> }
> ```

**Answer:**

| Variable     | Initial Value               |
| ------------ | --------------------------- |
| `global_str` | empty `std::string`         |
| `global_int` | `0`                         |
| `local_int`  | indeterminate integer value |
| `local_int`  | empty `std::string`         |

### Exercise 2.11

> Explain whether each of the following is a declaration or a definition:
>
> (a) `extern int ix = 1024;`
>
> (b) `int iy;`
>
> (c) `extern int iz;`

**Answer:**

### Exercise 2.12

> Which, if any, of the following names are invalid?
>
> (a) `int double = 3.14;`
>
> (b) `int _;`
>
> (c) `int catch-22;`
>
> (d) `int 1_or_2 = 1;`
>
> (e) `double Double = 3.14;`

**Answer:**

### Exercise 2.13

> What is the value of `j` in the following program?
>
> ```c++
> int i = 42;
> int main() {
>   int i = 100;
>   int j = i;
> }
> ```

**Answer:**

### Exercise 2.14

> Is the following program legal? If so, what values are printed?
>
> ```c++
> int i = 100, sum = 0;
> for (int i = 0; i != 10; ++i)
>   sum += i;
> std::cout << i << " " << sum << std::endl;
> ```

**Answer:**

## Section 2.3 Compound Types

### Exercise 2.15

> Which of the following definitions, if any, are invalid? Why?
>
> (a) `int ival = 1.01;`
>
> (b) `int &rval1 = 1.01;`
>
> (c) `int &rval2 = ival;`
>
> (d) `int &rval3;`

**Answer:**

### Exercise 2.16

> Which, if any, of the following assignments are invalid? If they are valid, explain what they do.
>
> ```c++
> int i = 0, &r1 = i;
> double d = 0, &r2 = d;
> ```
>
> (a) `r2 = 3.14159;`
>
> (b) `r2 = r1;`
>
> (c) `i = r2;`
>
> (d) `r1 = d;`

**Answer:**

### Exercise 2.17

> What does the following code print?
>
> ```c++
> int i, &ri = i;
> i = 5;
> ri = 10;
> std::cout << i << " " << ri << std::endl;
> ```

**Answer:**

### Exercise 2.18

> Write code to change the value of a pointer. Write code to change the value to which the pointer points.

**Answer:**

- [`02-18.cpp`](02-18.cpp)

### Exercise 2.19

> Explain the key differences between pointers and references.

**Answer:**

### Exercise 2.20

> What does the following program do?
>
> ```c++
> int i = 42;
> int *p1 = &i;
> *p1 = *p1 * *p1;
> ```

**Answer:**

### Exercise 2.21

> Explain each of the following definitions. Indicate whether any are illegal and, if so, why.
>
> ```c++
> int i = 0;
> ```
>
> (a) `double* dp = &i;`

**Answer:**

### Exercise 2.22

> Assuming p is a pointer to `int`, explain the following code:
>
> ```c++
> if (p)    // ...
>   if (*p) // ...
> ```

**Answer:**

### Exercise 2.23

> Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?

**Answer:**

### Exercise 2.24

> Why is the initialization of `p` legal but that of `lp` illegal?
>
> ```c++
> int i = 42;
> ```

**Answer:**

### Exercise 2.25

> Determine the types and values of each of the following variables.
>
> (a) `int* ip, i, &r = i;`

**Answer:**

## Section 2.4 const Qualiﬁer

### Exercise 2.26

> Which of the following are legal? For those that are illegal, explain why.
>
> (a) `const int buf;`
>
> (b) `int cnt = 0;`
>
> (c) `const int sz = cnt;`
>
> (d) `++cnt; ++sz;`

**Answer:**

### Exercise 2.27

> Which of the following initializations are legal? Explain why.
>
> (a) `int i = -1, &r = 0;`
>
> (b) `int *const p2 = &i2;`
>
> (c) `const int i = -1, &r = 0;`
>
> (d) `const int *const p3 = &i2;`
>
> (e) `const int *p1 = &i2;`
>
> (f) `const int &const r2;`
>
> (g) `const int i2 = i, &r = i;`

**Answer:**

### Exercise 2.28

> Explain the following definitions. Identify any that are illegal.
>
> (a) `int i, *const cp;`
>
> (b) `int *p1, *const p2;`
>
> (c) `const int ic, &r = ic;`
>
> (d) `const int *const p3;`
>
> (e) `const int *p;`

**Answer:**

### Exercise 2.29

> Uing the variables in the previous exercise, which of the following assignments are legal? Explain why.
>
> (a) `i = ic;`
>
> (b) `p1 = p3;`
>
> (c) `p1 = &ic;`
>
> (d) `p3 = &ic;`
>
> (e) `p2 = p1;`
>
> (f) `ic = *p3;`

**Answer:**

### Exercise 2.30

> For each of the following declarations indicate whether the object being declared has top-level or low-level `const`.
>
> ```c++
> const int v2 = 0;
> int v1 = v2;
> int *p1 = &v1, &r1 = v1;
> const int *p2 = &v2, *const p3 = &i, &r2 = v2;
> ```

**Answer:**

### Exercise 2.31

> Given the declarations in the previous exercise determine whether the following assignments are legal. Explain how the top-level or low-level `const` applies in each case.
>
> ```c++
> r1 = v2;
> p1 = p2;
> p1 = p3;
> ```

**Answer:**

### Exercise 2.32

> Is the following code legal or not? If not, how might you make it legal?
>
> ```c++
> int null = 0, *p = null;
> ```

**Answer:**

## Section 2.5 Dealing with Types

### Exercise 2.33

> Using the variable definitions from this section, determine what happens in each of these assignments:
>
> ```c++
> a = 42;
> d = 42;
> ```

**Answer:**

### Exercise 2.34

> Write a program containing the variables and assignments from the previous exercise. Print the variables before and after the assignments to check whether your predictions in the previous exercise were correct. If not, study the examples until you can convince yourself you know what led you to the wrong conclusion.

**Answer:**

- [`02-34.cpp`](02-34.cpp)

### Exercise 2.35

> Determine the types deduced in each of the following definitions. Once you've figured out the types, write a program to see whether you were correct.
>
> ```c++
> const int i = 42;
> auto j = i;
> const auto &k = i;
> auto *p = &i;
> const auto j2 = i, &k2 = i;
> ```

**Answer:**

### Exercise 2.36

> In the following code, determine the type of each variable and the value each variable has when the code finishes:
>
> ```c++
> int a = 3, b = 4;
> decltype(a) c = a;
> decltype((b)) d = a;
> ++c;
> ++d;
> ```

**Answer:**

### Exercise 2.37

> Assignment is an example of an expression that yields a reference type. The type is a reference to the type of the left-hand operand. That is, if i is an `int`, then the type of the expression `i = x` is `int &`. Using that knowledge, determine the type and value of each variable in this code:
>
> ```c++
> int a = 3, b = 4;
> decltype(a) c = a;
> decltype(a = b) d = a;
> ```

**Answer:**

### Exercise 2.38

> Describe the differences in type deduction between `decltype` and `auto`. Give an example of an expression where `auto` and `decltype` will deduce the same type and an example where they will deduce differing types.

**Answer:**

## Section 2.6 Defining Our Own Data Structures

### Exercise 2.39

> Compile the following program to see what happens when you forget the semicolon after a class definition. Remember the message for future reference.
>
> ```c++
> struct Foo { /* empty */
> } // Note: no semicolon
> int main()
> {
>   return 0;
> }
> ```

**Answer:**

- [`02-39.cpp`](02-39.cpp)

### Exercise 2.40

> Write your own version of the Sales_data class.

**Answer:**

- [`02-40.cpp`](02-40.cpp)

### Exercise 2.41

> Use your Sales_data class to rewrite the exercises in Section 1.5.1 (p. 22), Section 1.5.2 (p. 24), and Section 1.6 (p. 25). For now, you should define your Sales_data class in the same file as your main function.

**Answer:**

### Exercise 2.42

> Write your own version of the [`Sales_data.h`](Sales_data.h) header and use it to rewrite the exercise from Section 2.6.2 (p. 76).

**Answer:**

- [`02-42.cpp`](02-42.cpp)

