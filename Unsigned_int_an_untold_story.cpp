#include <iostream>
using namespace std;

int main() {
    // Demonstrating overflow with unsigned int
    unsigned int max_value = 4294967295;
    // This is 2^32 - 1, the maximum value for unsigned int
    unsigned int one = 1;

    // This addition results in overflow: (2^32 - 1) + 1 wraps around to 0 due
    // to modulo 2^32 arithmetic
    unsigned int overflow_result = max_value + one;
    cout << "Overflow: (4294967295 + 1) mod 2^32 = " << overflow_result << endl;

    // Demonstrating underflow with unsigned int
    unsigned int zero = 0;

    // This subtraction results in underflow: 0 - 1 wraps around to 2^32 - 1,
    // showcasing modulo 2^32 arithmetic
    unsigned int underflow_result = zero - one;
    cout << "Underflow: (0 - 1) mod 2^32 = " << underflow_result << endl;

    return 0;
}

/*
In C++, unsigned integers are a type of integer that can only represent
non-negative numbers. Unlike their signed counterparts, unsigned integers do not
dedicate a bit to signify the number's sign (positive or negative). This design
choice doubles the maximum value that can be represented compared to a signed
integer of the same bit width.

For a 32-bit integer:
A signed integer (int) uses one bit for sign, leaving 31 bits for the value,
allowing it to represent numbers in the range
[−2^31, 2^31 − 1]
An unsigned integer (unsigned int), on the other hand, uses all 32 bits for the
value, allowing it to represent numbers in the range[0, 2^32 − 1]

Why No Sign Bit Matters?
The lack of a sign bit in unsigned integers fundamentally changes how arithmetic
operations are interpreted and performed by the compiler. In particular, it
influences overflow and underflow behavior:

Overflow: When an operation results in a number larger than
2^32 - 1 for an unsigned int, the result "wraps around" back into the range [0,
2^32] due to modular arithmetic. This is a direct result of not having a sign
bit; the arithmetic is modulo 2^32, so any excess simply rolls over.

Underflow: Similarly, if a subtraction results in a negative number, the
operation wraps around in the opposite direction, producing a value that is
effectively 2^32 minus the absolute value of the result.
*/