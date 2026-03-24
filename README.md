# C++ Fixed-Point Arithmetic

Implementation of a fixed-point number class from scratch in C++, demonstrating operator overloading, ad-hoc polymorphism, and the Orthodox Canonical Form — with a mini BSP (Binary Space Partitioning) point-in-triangle algorithm as the final exercise.

## Fixed-Point Number Representation

```
 31      8  7       0
 ├───────┤  ├───────┤
   integer    fractional (8 bits)
```

The value is stored as a single `int` where the lower 8 bits represent the fractional part:

```cpp
float toFloat() const {
    return (float)_fixedPointValue / (1 << _fractionalBits);
}
```

## Operator Overloading

| Category | Operators |
|----------|-----------|
| Arithmetic | `+` `-` `*` `/` |
| Comparison | `>` `<` `>=` `<=` `==` `!=` |
| Increment/Decrement | `++` (pre/post) `--` (pre/post) |
| Stream | `<<` |

## Static Utility Functions

```cpp
Fixed &Fixed::min(Fixed &a, Fixed &b);        // returns smaller
Fixed &Fixed::max(Fixed &a, Fixed &b);        // returns larger
const Fixed &Fixed::min(const Fixed &a, ...); // const overload
```

## BSP Algorithm (Final Exercise)

Determines if a point lies inside a triangle using signed area cross-products — no floating point, purely fixed-point arithmetic:

```cpp
bool bsp(Point a, Point b, Point c, Point point);
```

## Build

```bash
make && ./ex03
```

## Tech Stack

`C++98` `Operator Overloading` `Fixed-Point Math` `BSP Algorithm` `Orthodox Canonical Form`

