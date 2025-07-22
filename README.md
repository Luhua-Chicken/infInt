# InfInt - Arbitrary Precision Integer Library
## Overview
InfInt is a C++ library that provides arbitrary precision integer arithmetic operations. It allows you to perform calculations with integers of virtually unlimited size, limited only by available memory.

## Features
- **Basic Arithmetic Operations**: Addition, subtraction, multiplication, division, and modulus
- **Comparison Operators**: Full set of comparison operations (<, >, <=, >=, ==, !=)
- **Assignment Operators**: Support for various assignment operations
- **I/O Operations**: Stream insertion and extraction operators
- **Type Conversion**: Conversion to standard integer types (int, long)
- **Power Operation**: Efficient exponentiation using binary exponentiation
- **String Handling**: Construction from and conversion to strings

## Usage
### Include the Header
```cpp
#include "infInt.h"
```

### Creating InfInt Objects
```cpp
infInt a;               // Default constructor (value = 0)
infInt b(12345);        // From integer
infInt c("987654321");  // From string
infInt d = a;           // Copy constructor
```

### Comparison
```cpp
if (a < b) { /* ... */ }
if (c == "987654321") { /* ... */ }
```

### I/O Operations
```cpp
infInt num;
std::cin >> num;        // Read from input
std::cout << num;       // Write to output
```

## Implementation Details
- Uses strings internally to store the integer value
- Automatically removes leading zeros
- Handles negative numbers
- Implements efficient algorithms for arithmetic operations:
  - Schoolbook method for addition/subtraction
  - Karatsuba-like multiplication
  - Long division algorithm
 
## Error Handling
- Throws std::invalid_argument for invalid input strings
- Throws std::domain_error for division by zero

## License
Copyright (c) 2025 chicken8225  
All rights reserved.

This software is protected by copyright law and international treaties. Unauthorized reproduction or distribution may result in severe civil and criminal penalties.

## Date
2025-07-21

## Examples
```cpp
#include "infInt.h"
#include <iostream>

int main() {
    infInt a = "12345678901234567890";
    infInt b = "98765432109876543210";
    
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "b / a = " << (b / a) << std::endl;
    
    return 0;
}
```

## Limitations
- Currently only supports integer operations
- Performance may not be optimal for very large numbers compared to specialized libraries
- No built-in support for bitwise operations
