## Chapter 2 Variables and Basic Types

- [Section 2.1 Primitive Built-in Types](#exercise-21) (exercises 2.1-2.8)
- [Section 2.2 Variables](#exercise-29) (exercises 2.9-2.14)
- [Section 2.3 Compound Types](#exercise-215) (exercises 2.15-2.25)
- [Section 2.4 `const` Qualifier](#exercise-226) (exercises 2.26-2.32)
- [Section 2.5 Dealing with Types](#exercise-233) (exercises 2.33-2.38)
- [Section 2.6 Defining Our Own Data Structure](#exercise-239) (exercises 2.39-2.42)

### Exercise 2.1

What are the differences between `int`, `long`, `long long`, and `short`? Between an `unsigned` and a `signed` type? Between a `float` and a `double`?

**Answer:** Size. Nonnegative or not. Size and precision.

| type        | size                       |
| ----------- | -------------------------- |
| `short`     | at least 2 bytes (16 bits) |
| `int`       | at least 2 bytes (16 bits) |
| `long`      | at least 4 bytes (32 bits) |
| `long long` | at least 8 bytes (64 bits) |

| type     | size                       | precision                                                    |
| -------- | -------------------------- | ------------------------------------------------------------ |
| `float`  | at least 4 bytes (32 bits) | 23 bits of significands = about 7 significant decimal digits |
| `double` | at least 8 bytes (64 bits) | 52 bits of significands = about 15 significant decimal digits |

### Exercise 2.2

To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.

**Answer:** Use `float` for all of them, because floating-point calculations are involved, and the precision it provides (about 7 significant decimal digits) should be okay.

### Exercise 2.3

What output will the following code produce?

```c++
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

**Answer:** Note that `2^32 - 32 = 4294967264`.

```
32
4294967264
32
-32
0
0
```


[Back to Top](#chapter-2-variables-and-basic-types)

