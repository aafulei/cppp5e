# Chapter 4 Expressions

- [Section 4.1 Fundamentals](#section-41-fundamentals)
  - Exercises [`4.1`](#exercise-41) [`4.2`](#exercise-42)
  - Exercises [`4.3`](#exercise-43)

- [Section 4.2 Arithmetic Operators](#section-42-arithmetic-operators)
  - Exercises [`4.4`](#exercise-44) [`4.5`](#exercise-45) [`4.6`](#exercise-46) [`4.7`](#exercise-47)

- [Section 4.3 Logical and Relational Operators](#section-43-logical-and-relational-operators)
  - Exercises [`4.8`](#exercise-48) [`4.9`](#exercise-49) [`4.10`](#exercise-410) [`4.11`](#exercise-411) [`4.12`](#exercise-412)

- [Section 4.4 Assignment Operators](#section-44-assignment-operators)
  - Exercises [`4.13`](#exercise-413) [`4.14`](#exercise-414) [`4.15`](#exercise-415)  [`4.16`](#exercise-416)

- [Section 4.5 Increment and Decrement Operators](#section-45-increment-and-decrement-operators)
  - Exercises [`4.17`](#exercise-417) [`4.18`](#exercise-418) [`4.19`](#exercise-419)

- [Section 4.6 The Member Access Operator](#section-46-the-member-access-operator)
  - Exercises [`4.20`](#exercise-420)

- [Section 4.7 The Conditional Operator](#section-47-the-conditional-operator)
  - Exercises [`4.21`](#exercise-421) [`4.22`](#exercise-422) [`4.23`](#exercise-423) [`4.24`](#exercise-424)

- [Section 4.8 The Bitwise Operator](#section-48-the-bitwise-operator)
  - Exercises [`4.25`](#exercise-425) [`4.26`](#exercise-426) [`4.27`](#exercise-427)

- [Section 4.9 The `sizeof` Operator](#section-49-the-sizeof-operator)
  - Exercises [`4.28`](#exercise-428) [`4.29`](#exercise-429) [`4.30`](#exercise-430)

- [Section 4.10 Comma Operator](#section-410-comma-operator)
  - Exercises [`4.31`](#exercise-431) [`4.32`](#exercise-432) [`4.33`](#exercise-433)

- [Section 4.11 Type Conversions](#section-411-type-conversions)
  - Exercises [`4.34`](#exercise-434) [`4.35`](#exercise-435)
  - Exercises [`4.36`](#exercise-436) [`4.37`](#exercise-437) [`4.38`](#exercise-438)

- [Section 4.12 Operator Precedence Table](#section-412-operator-precedence-table)

## Section 4.1 Fundamentals

## Exercise 4.1

> What is the value returned by `5 + 10 * 20 / 2`?

**Answer:**

105.

## Exercise 4.2

> Using *Table 4.12* (*p. 166*), parenthesize the following expressions to indicate the order in which the operands are grouped:
>
> (a) `* vec.begin()`
>
> (b) `* vec.begin() + 1`

**Answer:**

(a) `*(vec.begin())`

(b) `(*(vec.begin())) + 1`

## Exercise 4.3

> Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off > between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

**Answer:** Yes. The general principle is dedicate each statement to a single aim. To that end, I strongly discourage any expression that uses and changes one object at the same time, except when there is no room for ambiguity like `*++iter`.

## Section 4.2 Arithmetic Operators

## Exercise 4.4

> Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.
>
> `12 / 3 * 4 + 5 * 15 + 24 % 4 / 2`

**Answer:**

`(((12 / 3) * 4) + (5 * 15)) + ((24 % 4) / 2)`

## Exercise 4.5

> Determine the result of the following expressions.
>
> (a) `-30 * 3 + 21 / 5`
>
> (b) `-30 + 3 * 21 / 5`
>
> (c) `30 / 3 * 21 % 5`
>
> (d) `-30 / 3 * 21 % 4`

**Answer:**

(a) -86

(b) -18

(c) 0

(d) -2

## Exercise 4.6

> Write an expression to determine whether an `int` value is even or odd.

**Answer:**

```c++
(a % 2 == 0)
```

## Exercise 4.7

> What does overflow mean? Show three expressions that will overflow.

**Answer:**

A value is out of range.

```c++
unsigned short a = 0;
a += 65536;
bool b = true;
b += 2;
char c = 'c';
c += 256;
```

## Section 4.3 Logical and Relational Operators

## Exercise 4.8

> Explain when operands are evaluated in the logical AND, logical OR, and equality operators.

**Answer:**

- logical AND - `a && b`

  `b` is evaluated if and only if `a` is `true`

- logical OR - `a || b`

  `b` is evaluated if and only if `a` is `false`

- equality - `a == b`

  `a` and `b` are both evaluated; which part is first evaluated is not defined

## Exercise 4.9

> Explain the behavior of the condition in the following `if`:
>
> ```c++
> const char *cp = "Hello World";
> if (cp && *cp)
> ```

**Answer:** Since `cp` points to something (not a null pointer), `cp` yields `true` as a condition. `*cp` returns `'H'`, which is a `char`, which is converted to `true` since the value is nonzero. Thus condition is `true`. It is equivalent to checking if "`cp` points to anything other than a null character".

## Exercise 4.10

> Write the condition for a `while` loop that would read `int`s from the standard input and stop when the value read is equal to 42.

**Answer:**

```c++
int a;
while (std::cin >> a && a != 42)
```

## Exercise 4.11

> Write an expression that tests four values, `a`, `b`, `c`, and `d`, and ensures that `a` is greater than `b`, which is greater than  `c`,  which is greater than `d`.

**Answer:**

```c++
a > b && b > c && c > d
```

## Exercise 4.12

> Assuming `i`, `j`, and `k` are all `int`s, explain what `i != j < k` means.

**Answer:**

The expression is `true` if:

1. `j` is less than `k`, and `i` is not 1, OR
2. `j` is greater than or equal to `k`, and `i` is not 0.

The expression is `false` if otherwise.

*For example, if `i` is 2, then the condition is always true.*

*`<` is higher than `!=` in precedence.*

## Section 4.4 Assignment Operators

## Exercise 4.13

> What are the values of `i` and `d` after each assignment?
>
> `int i; double d;`
>
> (a) `d = i = 3.5;`
>
> (b) `i = d = 3.5;`

**Answer:**

(a) 3, 3.0

(b) 3, 3.5

## Exercise 4.14

> Explain what happens in each of the if tests:
>
> `if (42 = i)  // ...`
> `if (i = 42)  // ...`

**Answer:**

1. Compilation error: Cannot assign to rvalue.
2. `42` is assigned to `i`. The condition is `true`.

## Exercise 4.15

> The following assignment is illegal. Why? How would you correct it?

```c++
double dval; int ival; int *pi;
dval = ival = pi = 0;
```

**Answer:**

Impossible to convert `int *` to `int`.

```c++
double dval; int ival; int *pi;
dval = ival = 0;
pi = 0;
```

## Exercise 4.16

> Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.
>
> (a) `if (p = getPtr() != 0)`
>
> (b) `if (i = 1024)`

**Answer:**

Because assignment operator is low in precedence and is not equality operator.

(a) `if ((p = getPtr()) != 0)`

(b) `if (i == 1024)`

## Section 4.5 Increment and Decrement Operators

## Exercise 4.17

> Explain the difference between prefix and postfix increment.

**Answer:**

| prefix increment                         | postfix increment                        |
| ---------------------------------------- | ---------------------------------------- |
| `++i`                                    | `i++`                                    |
| increment `i` by 1 and returns the new `i` | increment `i` by 1 but returns a copy of the original `i` |

## Exercise 4.18

> What would happen if the `while` loop on *page 148* that prints the elements from a `vector` used the prefix increment operator?
>
> ```c++
> auto pbeg = v.begin();
> while (pbeg != v.end() && *beg >= 0)
>   cout << *pbeg++ << endl;
> ```

**Answer:**

It would wrongly access the element that is after where it should access.

## Exercise 4.19

> Given that `ptr` points to an `int`, that `vec` is a `vector<int>`, and that `ival` is an `int`, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?
>
> (a) `ptr != 0 && *ptr++`
>
> (b) `ival++ && ival`
>
> (c) `vec[ival++] <= vec[ival]`

**Answer:**

(a) Test `ptr` is not a null pointer and, if so, access the element it points to, before moving it forward

(b) Increment `ival` by 1 and test if the `ival` before increment is non-zero

(c) Likely to be problematic, because it is not sure if the `ival` value in `vec[ival]` is before or after the self-increment

```c++
vec[ival] <= vec[ival + 1];
++ival;
```

## Section 4.6 The Member Access Operator

## Exercise 4.20

> Assuming that `iter` is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those that aren’t legal are in error.
>
> (a) `*iter++;`
>
> (b) `(*iter)++;`
>
> (c) `*iter.empty()`
>
> (d) `iter->empty();`
>
> (e) `++*iter;`
>
> (f) `iter++->empty();`

**Answer:**

(a), (d), (f) are legal.

(a) in effect, return `iter` dereferenced, and then increment `iter` by 1;

(b) illegal because `++` is not defined for a `string`;

(c) illegal because iterator `iter` has no member;

(d) return if `iter` points to an empty `string`;

(e) illegal because `++` is not defined for a `string`;

(f) in effect, return if `iter` points to an empty `string`, and then increment `iter` by 1.

## Section 4.7 The Conditional Operator

## Exercise 4.21

> Write a program to use a conditional operator to find the elements in a vector<int> that have odd value and double the value of each such element.

**Answer:**

- [`04-21-conditional.cpp`](04-21-conditional.cpp)

## Exercise 4.22

> Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades between 60 and 75 inclusive. Write two versions: One version that uses only conditional operators; the other should use one or more if statements. Which version do you think is easier to understand and why?

**Answer:**

- [`04-22-grades-conditional.cpp`](04-22-grades-conditional.cpp)

- [`04-22-grades-if.cpp`](04-22-grades-if.cpp)

## Exercise 4.23

> The following expression fails to compile due to operator precedence. Using *Table 4.12 (p. 166)*, explain why it fails. How would you fix it?
>
> ```c++
> string s = "word";
> string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
> ```

**Answer:**

Conditional operator `?:` is higher in precedence than assignment operator `=`.

```c++
string s = "word";
string pl = s + (s[s.size() - 1] == 's' ? "" : "s");
```

## Exercise 4.24

> Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is *right* associative. Describe how that operator would be valuated if the operator were *left* associative.
>
> ```c++
> final_grade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
> ```

**Answer:**

It would be

```c++
final_grade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
```

Always `"fail"`.

## Section 4.8 The Bitwise Operator

## Exercise 4.25

> What is the value of `~'q' << 6` on a machine with 32-bit `int`s and 8 bit `char`s, that uses Latin-1 character set in which `'q'` has the bit pattern `01110001`?

**Answer:**

First, `01110001` is promoted to `00000000 00000000 00000000 01110001`.

Then, `~'q'` is evaluated as `11111111 11111111 11111111 10001110`.

In the end, `~'q' << 6` is `11111111 11111111 11100011 10000000`, or `-7296` in decimal.

How do we know it's `-7296` in decimal?

In order to write in octal, we write it as`011 111 111 111 111 111 110 001 110 000 000`.

That's `37777761600` in octal.

With `cout << 037777761600 << endl;` we know that's `-7296`.

## Exercise 4.26

> In our grading example in this section, what would happen if we used `unsigned int` as the type for `quiz1`?

```c++
unsigned long quiz1 = 0; // we'll use this value as a collection of bits
1UL << 27 // generate a value with only bit number 27 set
quiz1 |= 1UL << 27; // indicate student number 27 passed
quiz1 &= ~(1UL << 27); // student number 27 failed
bool status = quiz1 & (1UL << 27); // how did student number 27 do?
```

**Answer:**

Suppose `quiz1` is an `unsigned int`. `quiz1 | 1UL << 27` would return an `unsigned long`. Assigning this `unsigned long` to an `unsigned int` could be undefined, if the `unsigned int` has only 16 bits whereas the `unsigned long` has 32 bits.

## Exercise 4.27

> What is the result of each of these expressions?
>
> ```c++
> unsigned long ul1 = 3, ul2 = 7;
> ```
>
> (a) `ul1 & ul2`
>
> (b) `ul1 | ul2`
>
> (c) `ul1 && ul2`
>
> (d) `ul1 || ul2`

**Answer:**

For the rightmost 8 bits:

(a) `0000 0011 & 0000 0111` returns `0000 0011`, which is 3.

(b) `0000 0011 | 0000 0111` returns `0000 0111`, which is 7.

(c) `3 && 7` returns `true`, or `1` as integral.

(d) `3 || 7` returns `true`, or `1` as integral.

## Section 4.9 The `sizeof` Operator

## Exercise 4.28

> Write a program to print the size of each of the built-in types.

**Answer:**

- [`04-28-sizeof.cpp`](04-28-sizeof.cpp)

## Exercise 4.29

> Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.
>
> ```c++
> int x[10];   int *p = x;
> cout << sizeof(x)/sizeof(*x) << endl;
> cout << sizeof(p)/sizeof(*p) << endl;
> ```

**Answer:**

The output is

10

I don't know (On my machine that turns out to be 8 / 4 = 2)

`sizeof(x)/sizeof(*x)` returns the size of the array `x[10]`, which is 10.

`sizeof(p)/sizeof(*p)` returns the size of `int *` divided by the size of `int`, both of which are not specified.

## Exercise  4.30

> Using  *Table  4.12  (p.  166)*,  parenthesize  the  following expressions to match the default evaluation:
>
> (a) `sizeof x + y`
>
> (b) `sizeof p->mem[i]`
>
> (c) `sizeof a < b`
>
> (d) `sizeof f()`

**Answer:**

(a) `(sizeof x) + y`

(b) `sizeof ((p->mem)[i])`

(c) `(sizeof a) < b`

(d) `sizeof (f())`

## Section 4.10 Comma Operator

## Exercise 4.31

> The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.
>
> c++
> // vector<int>::size_type cnt = ivec.size();
> // // assign values from size... 1 to the elements in ivec
> // for(vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
> //  ivec[ix] = cnt;

**Answer:**

There is no change to make. In standalone expressions, ++i is no difference to ++i in effect.

- [`04-31-postfix.cpp`](04-31-postfix.cpp)

## Exercise 4.32

> Explain the following loop.
>
> ```c++
> constexpr int size = 5;
> int ia[size] = {1,2,3,4,5};
> for (int *ptr = ia, ix = 0;
>   ix != size && ptr != ia+size;
>   ++ix, ++ptr)  { /* ...  */ }
> ```

**Answer:**

A for loop that iterates through array `ia[5]`, with index `ix` ranging from 0 to 4, and pointer `ptr` moving from the beginning to the end.

## Exercise 4.33

> Using *Table 4.12 (p. 166)* explain what the following expression does:
>
> ```c++
> someValue ? ++x, ++y : --x, --y
> ```

**Answer:**

Equivalent to

```c++
(someValue ? ++x, ++y : --x), --y
```

If `someValue` is `true`, then sequentially increment `x` and `y` by 1.

If `someValue` is `false`, then decrement `x` by 1.

No matter what value `someValue` is,  decrement `y` by 1.

This expression returns the new value of `y`.

## Section 4.11 Type Conversions

## Exercise 4.34

> Given the variable definitions in this section, explain what conversions take place in the following expressions:
>
> (a) `if (fval)`
>
> (b) `dval = fval + ival;`
>
> (c) `dval + ival * cval;`

**Answer:**

(a) `fval` is converted to `bool`: to `false` if it has value 0, to `true` if otherwise.

(b) `ival` is converted to `float`, and then the result is converted to `double`.

(c) integral promotion to raise `cval` to `int`, and then the product is converted to `double`.

## Exercise 4.35

> Given the following definitions,
>
> ```c++
> char cval;   int ival;  unsigned int ui;
> float fval;  double dval;
> ```
>
> identify the implicit type conversions, if any, taking place:
>
> (a) `cval = 'a' + 3;`
>
> (b) `fval = ui - ival * 1.0;`
>
> (c) `dval = ui * fval;`
>
> (d) `cval = ival + fval + dval;`

**Answer:**

(a) first integral promotion from `char` to `int`, then conversion from `int` to `char`.

(b) first `ival` is converted to `double`, then `ui` to `double`, finally in assignment the result to `float`.

(c) first `ui` is converted to `float`, to preserve precision, then the result is converted to `double`.

(d) first from `int` to `float`, then to `double`, finally to `char`.

## Exercise 4.36

> Assuming `i` is an `int` and `d` is a `double` write the expression `i *= d` so that it does integral, rather than floating-point, multiplication.

**Answer:**

`i *= static_cast<int>(d)`

## Exercise 4.37

> Rewrite each of the following old-style casts to use a named cast:
>
> ```c++
> int i;
> double d;
> const string *ps;
> char *pc;
> void *pv;
> ```
>
> (a) `pv = (void*)ps;`
>
> (b) `i = int(*pc);`
>
> (c) `pv = &d`;
>
> (d) `pc = (char*) pv;`

**Answer:**

(a) `INCORRECT: const_cast<void *> ...`  `pv = const_cast<string *>(ps);`

(b) `i = static_cast<int>(*pc); // though automatically implicit integral promotion`

(c) `pv = static_cast<void *>(&d); // though (void *) may hold any type of non-const pointers`

(d) `INCORRECT: reinterpret_cast` `pc = static_cast<char *>(pv);`

## Exercise 4.38

> Explain the following expression:
>
> ```c++
> double slope = static_cast<double>(j/i);
> ```

**Answer:**

Do integral division of `j/i`, then explicitly convert the result from an `int` to a `double` and initialize `slope` from it.

## Section 4.12 Operator Precedence Table
