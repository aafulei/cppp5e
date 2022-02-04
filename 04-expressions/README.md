# Chapter 4 Expressions

- [Section 4.1 Fundamentals](#section-41-fundamentals)
  - *Exercises* [`4.1`](#exercise-41) [`4.2`](#exercise-42)
  - *Exercises* [`4.3`](#exercise-43)

- [Section 4.2 Arithmetic Operators](#section-42-arithmetic-operators)
  - *Exercises* [`4.4`](#exercise-44) [`4.5`](#exercise-45) [`4.6`](#exercise-46) [`4.7`](#exercise-47)

- [Section 4.3 Logical and Relational Operators](#section-43-logical-and-relational-operators)
  - *Exercises* [`4.8`](#exercise-48) [`4.9`](#exercise-49) [`4.10`](#exercise-410) [`4.11`](#exercise-411) [`4.12`](#exercise-412)

- [Section 4.4 Assignment Operators](#section-44-assignment-operators)
  - *Exercises* [`4.13`](#exercise-413) [`4.14`](#exercise-414) [`4.15`](#exercise-415) [`4.16`](#exercise-416)

- [Section 4.5 Increment and Decrement Operators](#section-45-increment-and-decrement-operators)
  - *Exercises* [`4.17`](#exercise-417) [`4.18`](#exercise-418) [`4.19`](#exercise-419)

- [Section 4.6 The Member Access Operators](#section-46-the-member-access-operators)
  - *Exercises* [`4.20`](#exercise-420)

- [Section 4.7 The Conditional Operator](#section-47-the-conditional-operator)
  - *Exercises* [`4.21`](#exercise-421) [`4.22`](#exercise-422) [`4.23`](#exercise-423) [`4.24`](#exercise-424)

- [Section 4.8 The Bitwise Operators](#section-48-the-bitwise-operators)
  - *Exercises* [`4.25`](#exercise-425) [`4.26`](#exercise-426) [`4.27`](#exercise-427)

- [Section 4.9 The `sizeof` Operator](#section-49-the-sizeof-operator)
  - *Exercises* [`4.28`](#exercise-428) [`4.29`](#exercise-429) [`4.30`](#exercise-430)

- [Section 4.10 Comma Operator](#section-410-comma-operator)
  - *Exercises* [`4.31`](#exercise-431) [`4.32`](#exercise-432) [`4.33`](#exercise-433)

- [Section 4.11 Type Conversions](#section-411-type-conversions)
  - *Exercises* [`4.34`](#exercise-434) [`4.35`](#exercise-435)
  - *Exercises* [`4.36`](#exercise-436) [`4.37`](#exercise-437) [`4.38`](#exercise-438)

- [Section 4.12 Operator Precedence Table](#section-412-operator-precedence-table)

## Section 4.1 Fundamentals

### Exercise 4.1

> What is the value returned by `5 + 10 * 20 / 2`?

**Answer:**

```
  5 + 10 * 20 / 2
= 5 + 200 / 2
= 5 + 100
= 105
```

### Exercise 4.2

> Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:
>
> (a) `* vec.begin()`
>
> (b) `* vec.begin() + 1`

**Answer:**

(a) `*(((vec.begin)()))`

(b) `(*(((vec.begin)()))) + 1`

### Exercise 4.3

> Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

**Answer:**

Yes. On one hand, C++ is for performance. On the other hand, it is programmers' responsibility to write clear code without ambiguity.

## Section 4.2 Arithmetic Operators

### Exercise 4.4

> Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.
>
> ```c++
> 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
> ```

**Answer:**

### Exercise 4.5

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

(a)

```
  -30 * 3 + 21 / 5
= -90 + 4
= -86
```

(b)

```
  -30 + 3 * 21 / 5
= -30 + 63 / 5
= -30 + 12
= -18
```

(c)

```
  30 / 3 * 21 % 5
= 10 * 21 % 5
= 210 % 5
= 0
```

(d)

```
  -30 / 3 * 21 % 4
= -10 * 21 % 4
= -210 % 4
= -2
```

*^ note that in C/C++ the remainder always has the same sign as the dividend. This is because the quotient is rounded towards zero.*

### Exercise 4.6

> Write an expression to determine whether an `int` value is even or odd.

**Answer:**

```c++
a % 2 == 0
```

The above expression yields `1` if `int` `a` is even, or `0` if `a` is odd.

### Exercise 4.7

> What does overflow mean? Show three expressions that will overflow.

**Answer:**

An overflow happens when a value that is computed is out of range.

```c++
// assume 16-bit short, 32-bit int
short a = 32767;
int b = 2147483647;
signed char c = 127;
a += 1;
b += 1;
c += 1;
```

*^ note that unsigned numbers do not overflow.*

## Section 4.3 Logical and Relational Operators

### Exercise 4.8

> Explain when operands are evaluated in the logical AND, logical OR, and equality operators.

**Answer:**

- `a && b`

  `b` is evaluated only if `a` has been evaluated to `true`.

- `a || b`

  `b` is evaluated only if `a` has been evaluated to `false`.

- `a == b`

  Both `a` and `b` will be evaluated. Which one will be evaluated first is undefined.

### Exercise 4.9

> Explain the behavior of the condition in the following `if`:
>
> ```c++
> const char *cp = "Hello World";
> if (cp && *cp)
> ```

**Answer:**

The condition tests that `cp` points to something (i.e. not a null pointer) and that the C-style string it points is not empty (i.e. not starting with a null character `\0`). In this case, the condition evaluates to `true`, because `cp` points to a non-empty C-style string `"Hello World"`.

### Exercise 4.10

> Write the condition for a `while` loop that would read `int`s from the standard input and stop when the value read is equal to `42`.

**Answer:**

```c++
int a;
while (std::cin >> a && a != 42) {
  // ...
}
```

### Exercise 4.11

> Write an expression that tests four values, `a`, `b`, `c`, and `d`, and ensures that `a` is greater than `b`, which is greater than `c`, which is greater than `d`.

**Answer:**

```c++
a > b && b > c && c > d
```

### Exercise 4.12

> Assuming `i`, `j`, and `k` are all `int`s, explain what `i != j < k` means.

**Answer:**

`i != j < k` is equivalent to `i != (j < k)`. The subexpression `(j < k)`  evaluates to `1` if `j < k` or `0` if `j >= k`. Then the expression will compare `i` with the result, yielding `1` if the values are unequal, or `0` if the values are equal.

*^ note that `<` has higher than precedence than `!=`*

## Section 4.4 Assignment Operators

### Exercise 4.13

> What are the values of `i` and `d` after each assignment?
>
> ```c++
> int i;
> double d;
> ```
>
> (a) `d = i = 3.5;`
>
> (b) `i = d = 3.5;`

**Answer:**

(a) `i` is `3`, `d` is `3.0`

(b) `i` is `3`, `d` is `3.5`

### Exercise 4.14

> Explain what happens in each of the `if` tests:
>
> ```c++
> if (42 = i)
> if (i = 42)
> ```

**Answer:**

- `if (42 = i)` is illegal because it tries to assign to `42` which is an *rvalue*

- `if (i = 42)` evaluates to `true` because `42` is assigned to `i` which now has a nonzero value

### Exercise 4.15

> The following assignment is illegal. Why? How would you correct it?
>
> ```c++
> double dval;
> int ival;
> int *pi;
> dval = ival = pi = 0;
> ```

**Answer:**

The result of an assignment is its left-hand operand. In this case, it is illegal to assign the value of a pointer (`pi`) to an `int` (`ival`). Fix -

```c++
double dval;
int ival;
int *pi;
dval = ival = 0;
pi = 0;
```

### Exercise 4.16

> Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.
>
> (a) `if (p = getPtr() != 0)`
>
> (b) `if (i = 1024)`

**Answer:**

(a) The condition is equivalent to `if (p = (getPtr() != 0))`, which always assigns `1` or `0` to `p`. Rewrite -

```c++
if ((p = getPtr()) != 0)
```

*^ note that `!=` has higher precedence than `=`*

(b) The expression in the condition assigns `1024` to `i` and always evaluates to `true`. Rewrite -


```c++
if (i == 1024)
```

## Section 4.5 Increment and Decrement Operators

### Exercise 4.17

> Explain the difference between prefix and postfix increment.

**Answer:**

|                       | prefix increment     | postfix increment    |
| --------------------- | -------------------- | -------------------- |
| **notation**          | `++i`                | `i++`                |
| **effect on operand** | increment `i` by `1` | increment `i` by `1` |
| **expression type**   | *lvalue*             | *rvalue*             |
| **expression value**  | incremented `i`      | unincremented `i`    |

### Exercise 4.18

> What would happen if the `while` loop on *page 148* that prints the elements from a vector used the prefix increment operator?
>
> ```c++
> while (pbeg != v.end() && *pbeg >= 0)
>   cout << *pbeg++ << endl;
> ```

**Answer:**

The loop would print out the elements that are 1 element next to what should be printed out. In particular, the loop might try to deference one past the end of the `vector`, which has undefined behavior.

### Exercise 4.19

> Given that ptr points to an `int`, that `vec` is a `vector<int>`, and that `ival` is an `int`, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?
>
> (a) `ptr != 0 && *ptr++`
>
> (b) `ival++ && ival`
>
> (c) `vec[ival++] <= vec[ival]`

**Answer:**

(a) if `ptr` is not null, dereference the pointer and increment it by 1

(b) increment `ival` by 1, and test that both its old and new values are not zero

(c) because the order of evaluation is undefined, this expression has indeterministic behavior; should be `++ival, vec[ival - 1] < vec[ival]`

*^ as of C++11, only four operators guarantee the order of evaluation: (1) `&&` (2) `||` (3) `?:` (4) `,` Since C++17, it has been additionally guaranteed that the right-hand side of the assignment operator `=` is sequenced before the left-hand side. That is, from C++17 onwards, `i = i++ + 1;` is well defined.*

## Section 4.6 The Member Access Operators

### Exercise 4.20

> Assuming that `iter` is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those that aren't legal are in error.
>
> (a) `*iter++;`
>
> (b) `(*iter)++;`
>
> (c) `*iter.empty();`
>
> (d) `iter->empty();`
>
> (e) `++*iter;`
>
> (f) `iter++->empty();`

**Answer:**

(a) Legal - access the element and increment the iterator by 1

(b) Legal - the same as (a)

(c) Illegal - `empty()` is not defined for `vector<string>::iterator`

(d) Legal - test if the `string` element is empty

(e) Illegal - prefix increment operator `++` is not defined for `string`

(f) Legal - increment the iterator by 1, test if the original unincremented `string` element is empty

## Section 4.7 The Conditional Operator

### Exercise 4.21

> Write a program to use a conditional operator to find the elements in a `vector<int>` that have odd value and double the value of each such element.

**Answer:**

- [`04-21.cpp`](04-21.cpp)

### Exercise 4.22

> Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades between 60 and 75 inclusive. Write two versions: One version that uses only conditional operators; the other should use one or more if statements. Which version do you think is easier to understand and why?

**Answer:**

The version with more `if` statements is easier to understand, because nested conditional operators heavily reduce readability.

- [`04-22.cpp`](04-22.cpp)

### Exercise 4.23

> The following expression fails to compile due to operator precedence. Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
>
> ```c++
> string s = "word";
> string pl = s + s[s.size() - 1] == 's' ? "" : "s";
> ```

**Answer:**

Line 2 is equivalent to

```c++
string pl = (((s + s[s.size() - 1]) == 's') ? "" : "s");
```

but equality operator `==` is not defined between `std::string` and `char`. Fix -

```c++
string s = "word";
string pl = s + (s[s.size() - 1] == 's' ? "" : "s");
```

### Exercise 4.24

> Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is right associative. Describe how that operator would be evaluated if the operator were left associative.
>
> ```c++
> final_grade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
> ```

**Answer:**

If the conditional operator `?:` were left associative, the statement would be equivalent to

```c++
final_grade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
```

The program won't compile, because `"high pass"` is a `const char *` while `(grade < 60)` yields a `bool`. The two operand types are different.

## Section 4.8 The Bitwise Operators

### Exercise 4.25

> What is the value of `~'q' << 6` on a machine with 32-bit `int`s and 8 bit `char`s, that uses Latin-1 character set in which `'q'` has the bit pattern `01110001`?

**Answer:**

```
  ~'q' << 6
= ~(0000 0000 0000 0000 0000 0000 0111 0001) << 6
=  (1111 1111 1111 1111 1111 1111 1000 1110) << 6
=   1111 1111 1111 1111 1110 0011 1000 0000
=   FF FF E3 80
= -65536 + (14 * 16 + 3) * 256 + (8 * 16)
= -(256 * 256 - 227 * 256 - 8 * 16)
= -(29 * 16 * 16 - 8 * 16)
= -(456 * 16)
= -7296
```

- [`04-25.cpp`](04-25.cpp)

*^ note that integer promotion takes place before the `~` operation*

### Exercise 4.26

> In our grading example in this section, what would happen if we used `unsigned int` as the type for `quiz1`?
>
> ```c++
> unsigned long quiz1 = 0;            // we'll use this value as a collection of bits
> quiz1 |= 1UL << 27;                 // indicate student number 27 passed
> quiz1 &= ~(1UL << 27);              // student number 27 failed
> bool status = quiz1 & (1UL << 27);  // how did student number 27 do?
> ```

**Answer:**

If `unsigned int` has 32 bits, the effect would be same. However, if `unsigned int` has only 16 bits, then `quiz1` would be unable to represent the pass/fail status of all 30 students. In such case, for example, `quiz1 & (1UL << 27)` would always be `0`.

### Exercise 4.27

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

(a) `3`

```
  ul1 & ul2
= (bin) 0011 & 0111
= (bin) 0011
= (dec) 3
```

(b) `7`

```
  ul1 | ul2
= (bin) 0011 | 0111
= (bin) 0111
= (dec) 7
```

(c) `true`, or `1` after integer promotion

(d) `true`, or `1` after integer promotion

## Section 4.9 The `sizeof` Operator

### Exercise 4.28

> Write a program to print the size of each of the built-in types.

**Answer:**

| `sizeof`      | Linux/macOS | Windows |
| ------------- | ----------- | ------- |
| `bool`        | 1           | 1       |
| `char`        | 1           | 1       |
| `wchar_t`     | 4           | 2       |
| `char16_t`    | 2           | 2       |
| `char32_t`    | 4           | 4       |
| `short`       | 2           | 2       |
| `int`         | 4           | 4       |
| `long`        | 8           | 4       |
| `long long`   | 8           | 8       |
| `float`       | 4           | 4       |
| `double`      | 8           | 8       |
| `long double` | 16          | 16      |

- [`04-28.cpp`](04-28.cpp)

### Exercise 4.29

> Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.
>
> ```c++
> int x[10]; int *p = x;
> cout << sizeof(x)/sizeof(*x) << endl;
> cout << sizeof(p)/sizeof(*p) << endl;
> ```

**Answer:**

```
10
2
```

Note that `sizeof(x)` returns the size of the array, whereas `sizeof(p)` returns the size of the pointer.

- [`04-29.cpp`](04-29.cpp)

### Exercise 4.30

> Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation:
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

(b) `sizeof((p->mem)[i])`

(c) `sizeof(a) < b`

(d) `sizeof(f())`

## Section 4.10 Comma Operator

### Exercise 4.31

> The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.
>
> ```c++
> for (std::vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt) {
>   ivec[ix] = cnt;
> }
> ```

**Answer:**

It is recommended to use postfix increment only when necessary, because it stores a copy of the old value before incrementing the variable, which might incur a little cost. However, in standalone expressions, `i++` has the same effect as `++i`, so there is no change to make.

- [`04-31.cpp`](04-31.cpp)

### Exercise 4.32

> Explain the following loop.
>
> ```c++
> constexpr int size = 5;
> int ia[size] = {1, 2, 3, 4, 5};
> for (int *ptr = ia, ix = 0; ix != size && ptr != ia + size; ++ix, ++ptr) {
>   /* ... */
> }
> ```

**Answer:**

The `for` loop iterates over an `int` array `ia` using both pointer `ptr` and index `ix`. *It is unnecessary to use both. Either one will do the job.*

### Exercise 4.33

> Using Table 4.12 (p. 166) explain what the following expression does:
>
> ```c++
> someValue ? ++x, ++y : --x, --y
> ```

**Answer:**

The expression is equivalent to

```c++
(someValue ? ++x, ++y : --x), --y
```

If `someValue` is `true`, then increment `x` and `y` each by 1. If `someValue` is `false`, then decrement `x` by 1.

After that, no matter what value `someValue` is, decrement `y` by 1, and return `y` as the expression value.

## Section 4.11 Type Conversions

### Exercise 4.34

> Given the variable definitions in this section, explain what conversions take place in the following expressions:
>
> ```c++
> char cval;
> double dval;
> float fval;
> int ival;
> ```
>
> (a) `if (fval)`
>
> (b) `dval = fval + ival;`
>
> (c) `dval + ival * cval;`

**Answer:**

(a) `fval` is converted to `bool`: to `false` if it has value 0, to `true` if otherwise

(b) `ival` is converted to `float`, and then the sum is converted to `double`

(c) `cval` is promoted to `int`, and then the product is converted to `double`

### Exercise 4.35

> Given the following definitions,
>
> ```c++
> char cval;
> int ival;
> unsigned int ui;
> float fval;
> double dval;
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

(a) first integral promotion of `'a'` from `char` to `int`, then conversion from `int` to `char`.

(b) first `ival` is converted to `double`, then `ui` to `double`, finally in assignment the result to `float`.

(c) first `ui` is converted to `float`, to preserve precision, then the result is converted to `double`.

(d) first from `int` to `float`, then to `double`, finally to `char`.

*^ note that `1.0` as a floating-point literal is a `double`; to have a literal of type `float`, use `1.0f`*

### Exercise 4.36

> Assuming `i` is an `int` and `d` is a `double` write the expression `i *= d` so that it does integral, rather than floating-point, multiplication.

**Answer:**

### Exercise 4.37

> Rewrite each of the following old-style casts to use a named cast:
>
> ```c++
> int i;
> double d;
> const string *ps;
> char *pc;
> ```
>
> (a) `pv = (void*)ps;`
>
> (b) `i = int(*pc);`
>
> (c) `pv = &d;`
>
> (d) `pc = (char*) pv;`

**Answer:**

### Exercise 4.38

> Explain the following expression:
>
> ```c++
> double slope = static_cast<double>(j / i);
> ```

**Answer:**

## Section 4.12 Operator Precedence Table

