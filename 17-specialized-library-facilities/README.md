# Chapter 17 Specialized Library Facilities

- [Section 17.1 The tuple Type](#section-171-the-tuple-type)
  - *Exercises* [`17.1`](#exercise-171) [`17.2`](#exercise-172) [`17.3`](#exercise-173)
  - *Exercises* [`17.4`](#exercise-174) [`17.5`](#exercise-175) [`17.6`](#exercise-176) [`17.7`](#exercise-177) [`17.8`](#exercise-178)

- [Section 17.2 The bitset Type](#section-172-the-bitset-type)
  - *Exercises* [`17.9`](#exercise-179)
  - *Exercises* [`17.10`](#exercise-1710) [`17.11`](#exercise-1711) [`17.12`](#exercise-1712) [`17.13`](#exercise-1713)

- [Section 17.3 Regular Expressions](#section-173-regular-expressions)
  - *Exercises* [`17.14`](#exercise-1714) [`17.15`](#exercise-1715) [`17.16`](#exercise-1716)
  - *Exercises* [`17.17`](#exercise-1717) [`17.18`](#exercise-1718)
  - *Exercises* [`17.19`](#exercise-1719) [`17.20`](#exercise-1720) [`17.21`](#exercise-1721) [`17.22`](#exercise-1722) [`17.23`](#exercise-1723)
  - *Exercises* [`17.24`](#exercise-1724) [`17.25`](#exercise-1725) [`17.26`](#exercise-1726) [`17.27`](#exercise-1727)

- [Section 17.4 Random Numbers](#section-174-random-numbers)
  - *Exercises* [`17.28`](#exercise-1728) [`17.29`](#exercise-1729) [`17.30`](#exercise-1730)
  - *Exercises* [`17.31`](#exercise-1731) [`17.32`](#exercise-1732) [`17.33`](#exercise-1733)

- [Section 17.5 The IO Library Revisited](#section-175-the-io-library-revisited)
  - *Exercises* [`17.34`](#exercise-1734) [`17.35`](#exercise-1735) [`17.36`](#exercise-1736)
  - *Exercises* [`17.37`](#exercise-1737) [`17.38`](#exercise-1738)
  - *Exercises* [`17.39`](#exercise-1739)

## Section 17.1 The tuple Type

### Exercise 17.1

> Define a tuple that holds three `int` values and initialize the members to 10, 20, and 30.

**Answer:**

- [`17-01.cpp`](17-01.cpp)

### Exercise 17.2

> Define a tuple that holds a string, a vector<string>, and a pair<string, int>.

**Answer:**

- [`17-02.cpp`](17-02.cpp)

### Exercise 17.3

> Rewrite the TextQuery programs from Section 12.3 (p. 484) to use a tuple instead of the QueryResult class. Explain which design you think is better and why.

**Answer:**

- [`17-03.cpp`](17-03.cpp)

### Exercise 17.4

> Write and test your own version of the findBook function.

**Answer:**

- [`17-04.cpp`](17-04.cpp)

### Exercise 17.5

> Rewrite findBook to return a pair that holds an index and a pair of iterators.

**Answer:**

- [`17-05.cpp`](17-05.cpp)

### Exercise 17.6

> Rewrite findBook so that it does not use tuple or pair.

**Answer:**

- [`17-06.cpp`](17-06.cpp)

### Exercise 17.7

> Explain which version of findBook you prefer and why.

**Answer:**

### Exercise 17.8

> What would happen if we passed Sales_data() as the third parameter to accumulate in the last code example in this section?

**Answer:**

## Section 17.2 The bitset Type

### Exercise 17.9

> Explain the bit pattern each of the following bitset objects contains:
>
> (a) `bitset<64> bitvec(32);`
>
> (b) `bitset<32> bv(1010101);`
>
> (c) `string bstr; cin >> bstr; bitset<8>bv(bstr);`

**Answer:**

### Exercise 17.10

> Using the sequence 1, 2, 3, 5, 8, 13, 21, initialize a bitset that has a 1 bit in each position corresponding to a number in this sequence. Default initialize another bitset and write a small program to turn on each of the appropriate bits.

**Answer:**

### Exercise 17.11

> Define a data structure that contains an integral object to track responses to a true/false quiz containing 10 questions. What changes, if any, would you need to make in your data structure if the quiz had 100 questions?

**Answer:**

- [`17-11.cpp`](17-11.cpp)

### Exercise 17.12

> Using the data structure from the previous question, write a function that takes a question number and a value to indicate a true/false answer and updates the quiz results accordingly.

**Answer:**

### Exercise 17.13

> Write an integral object that contains the correct answers for the true/false quiz. Use it to generate grades on the quiz for the data structure from the previous two exercises.

**Answer:**

- [`17-13.cpp`](17-13.cpp)

## Section 17.3 Regular Expressions

### Exercise 17.14

> Write several regular expressions designed to trigger various errors. Run your program to see what output your compiler generates for each error.

**Answer:**

- [`17-14.cpp`](17-14.cpp)

### Exercise 17.15

> Write a program using the pattern that finds words that violate the "i before e except after c" rule. Have your program prompt the user to supply a word and indicate whether the word is okay or not. Test your program with words that do and do not violate the rule.

**Answer:**

- [`17-15.cpp`](17-15.cpp)

### Exercise 17.16

> What would happen if your regex object in the previous program were initialized with "[^c]ei"? Test your program using that pattern to see whether your expectations were correct.

**Answer:**

### Exercise 17.17

> Update your program so that it finds all the words in an input sequence that violiate the "ei" grammar rule.

**Answer:**

- [`17-17.cpp`](17-17.cpp)

### Exercise 17.18

> Revise your program to ignore words that contain "ei" but are not misspellings, such as "albeit" and "neighbor."

**Answer:**

- [`17-18.cpp`](17-18.cpp)

### Exercise 17.19

> Why is it okay to call m[4].str() without first checking whether m[4] was matched?

**Answer:**

### Exercise 17.20

> Write your own version of the program to validate phone numbers.

**Answer:**

- [`17-20.cpp`](17-20.cpp)

### Exercise 17.21

> Rewrite your phone number program from Section 8.3.2 (p. 323) to use the valid function defined in this section.

**Answer:**

- [`17-21.cpp`](17-21.cpp)

### Exercise 17.22

> Rewrite your phone program so that it allows any number of whitespace characters to separate the three parts of a phone number.

**Answer:**

- [`17-22.cpp`](17-22.cpp)

### Exercise 17.23

> Write a regular expression to find zip codes. A zip code can have five or nine digits. The first five digits can be separated from the remaining four by a dash.

**Answer:**

- [`17-23.cpp`](17-23.cpp)

### Exercise 17.24

> Write your own version of the program to reformat phone numbers.

**Answer:**

- [`17-24.cpp`](17-24.cpp)

### Exercise 17.25

> Rewrite your phone program so that it writes only the first phone number for each person.

**Answer:**

- [`17-25.cpp`](17-25.cpp)

### Exercise 17.26

> Rewrite your phone program so that it writes only the second and subsequent phone numbers for people with more than one phone number.

**Answer:**

- [`17-26.cpp`](17-26.cpp)

### Exercise 17.27

> Write a program that reformats a nine-digit zip code as ddddd-dddd.

**Answer:**

- [`17-27.cpp`](17-27.cpp)

## Section 17.4 Random Numbers

### Exercise 17.28

> Write a function that generates and returns a uniformly distributed random unsigned int each time it is called.

**Answer:**

- [`17-28.cpp`](17-28.cpp)

### Exercise 17.29

> Allow the user to supply a seed as an optional argument to the function you wrote in the previous exercise.

**Answer:**

### Exercise 17.30

> Revise your function again this time to take a minimum and maximum value for the numbers that the function should return.

**Answer:**

- [`17-30.cpp`](17-30.cpp)

### Exercise 17.31

> What would happen if we defined b and e inside the do loop of the game-playing program from this section?

**Answer:**

### Exercise 17.32

> What would happen if we defined resp inside the loop?

**Answer:**

### Exercise 17.33

> Write a version of the word transformation program from Section 11.3.6 (p. 440) that allows multiple transformations for a given word and randomly selects which transformation to apply.

**Answer:**

- [`17-33.cpp`](17-33.cpp)

## Section 17.5 The IO Library Revisited

### Exercise 17.34

> Write a program that illustrates the use of each manipulator in Tables 17.17 (p. 757) and 17.18.

**Answer:**

- [`17-34.cpp`](17-34.cpp)

### Exercise 17.35

> Write a version of the program from *page 758*, that printed the square root of 2 but this time print hexadecimal digits in uppercase.

**Answer:**

- [`17-35.cpp`](17-35.cpp)

### Exercise 17.36

> Modify the program from the previous exercise to print the various floating-point values so that they line up in a column.

**Answer:**

- [`17-36.cpp`](17-36.cpp)

### Exercise 17.37

> Use the unformatted version of `getline` to read a file a line at a time. Test your program by giving it a file that contains empty lines as well as lines that are longer than the character array that you pass to `getline`.

**Answer:**

### Exercise 17.38

> Extend your program from the previous exercise to print each word you read onto its own line.

**Answer:**

### Exercise 17.39

> Write your own version of the seek program presented in this section.

**Answer:**

- [`17-39.cpp`](17-39.cpp)

