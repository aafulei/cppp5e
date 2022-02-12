# Coding Style

- [Format](#format)
- [Style](#style)
- [Naming Convention](#naming-convention)


## Format

We use `clang-format` with default options, which is the *LLVM* style. Four most noticeable style controls are

1. *line width at 80 characters*
2. *identation with 2 spaces*
3. *do not break before opening curly braces*
4. *right alignment of `*` and  `&` for pointer and reference declarations*

For example,

```c++
#include <iostream> // line width at 80 characters

namespace ns { // do not break before opening curly braces
struct S {     // do not break before opening curly braces
  int a = 0;   // identation with 2 spaces
};
} // namespace ns

int main() {           // do not break before opening curly braces
  int a = 0;           // identation with 2 spaces
  int *p = &a;         // right alignment of * for pointer declaration
  int &r = a;          // right alignment of & for reference declaration
  if (std::cin >> a) { // do not break before opening curly braces
    std::cout << *p << std::endl;
    std::cout << r << std::endl;
  }
  return 0;
}
```

## Style

We tend to be explicit. That is,

1. *do not omit namespace prefixes unless required.* For example,

```c++
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
```

2. *do not omit curly braces for the body of `if`, `else`, `while` and `for` statements.* For example,

```c++
void visit(TreeNode *node) {
  if (!node) {
    return;
  }
  // ...
}
```

3. *do not use `auto` unless required.* For example, we prefer

```c++
unsigned long long a = 0ULL;

for (unsigned long long &elem : vec) {
  // ...
}

for (const std::vector<unsigned long long>::const_iterator it = vec.cbegin();
     it != vec.cend(); ++it) {
  // ...
}
```

to

```c++
auto a = 0ULL;

for (auto &elem : vec) {
  // ...
}

for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
  // ...
}
```

## Naming Convention

When we modify the existing code in the book, we inherit its names, no matter how strange-looking they are. One such example is

```c++
struct Sales_data {
  std::string bookNo;       // camelCase variable name
  unsigned units_sold = 0;  // lowercase variable name with underscores
  double revenue = 0.0;
};
```

Otherwise,

| Name Type      | Example                                                   |
| -------------- | --------------------------------------------------------- |
| Class Name     | `class PascalCase;` `struct PascalCase;`                  |
| File Name      | `lowercase-with-hyphens.hpp` `lowercase-with-hyphens.cpp` |
| Function Name  | `int lowercase_with_underscores();`                       |
| Macro Name     | `#define UPPERCASE_WITH_UNDERSCORES`                      |
| Namespace Name | `namespace lowercase_with_underscores {}`                 |
| Variable Name  | `int lowercase_with_underscores;`                         |

## Declaration Order of Class Members

Public, protected, private.

Typedefs and enums, constants, constructors, destructor, methods, data members.
