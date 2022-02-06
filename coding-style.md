# Coding Style

- [Format](#format)
- [Style](#style)
- [Naming Convention](#naming-convention)


## Format

We use `clang-format` with default options, which is the *LLVM* style. Four most noticeable styles are

1. *line width at 80 characters*
2. *identation with 2 spaces*
3. *do not break before opening curly braces*
4. *right alignment of `*` and  `&` for pointer and reference declarations*

For example,

```c++
#include <iostram> // line width at 80 characters

namespace ns { // do not break before opening curly braces
class C {      // do not break before opening curly braces
  int d;       // identation with 2 spaces
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

1. **always prefix with namespaces.** For example,

```c++
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
```

2. **always use curly braces `if`, `else`, `while` and `for` statements.** For example,

```c++
void visit(TreeNode *node) {
  if (!node) {
    return;
  }
  // ...
}
```

3. **never use `auto` when possible.** For example,

```c++
for (const std::vector<int>::const_iterator it = vec.cbegin(); it != vec.end();
  ++it) {
  // ...
}

for (int &elem : vec) {
  ++elem;
}
```

## Naming Convention

When we modify the existing code in the book, we inherit its names, no matter how strange-looking it is. One such example is

```c++
struct Sales_data {
  std::string bookNo;       // camelCase variable name
  unsigned units_sold = 0;  // lowercase variable name with underscores
  double revenue = 0.0;
};
```

Otherwise,

### Class / Struct Names

```c++
class PascalCase;
```

### File Names

```
lowercase-with-hyphens.hpp
lowercase-with-hyphens.cpp
```

### Function Names

```c++
void camelCase();
```

### Macro Names

```c++
#define UPPERCASE_WITH_UNDERSCORES
```

### Namespace Names

```c++
namespace lowercase_with_underscores;
```

### Variable Names

```c++
int lowercase_with_underscores;
```
