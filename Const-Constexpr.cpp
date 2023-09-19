// Understanding the difference between const and constexpr in C++

/*
    1. const:
    - Tells the compiler that the value won't change after it's set.
    - The value can be set during runtime (while the program is running).

    Example:
    const int runtimeValue = rand();  // The value is determined at runtime.

    2. constexpr:
    - Instructs the compiler to calculate the value before the program
    even starts running.
    - The value must be known and set during compile-time (before the
    program starts running).

    Example:
    constexpr int compileTimeValue = 10;  // The value is determined
    at compile time.

    Analogy:
    Imagine you're preparing a recipe:
    - const: It's like knowing you'll need 2 eggs, but you'll check the
    fridge and take them out when you're actually cooking.
    - constexpr: It's like deciding you'll need 2 eggs and taking them out,
     even before you enter the kitchen or start cooking.
*/

#include <cstdlib>
#include <iostream>

int main()
{
    // const example
    const int runtimeValue =
        rand(); // Value is determined when the program runs. everytime
    // it will give output 41 here.it's randomly set constant as
    // 41
    std::cout << "const value (determined at runtime): " << runtimeValue
              << std::endl;

    // constexpr example
    constexpr int compileTimeValue =
        10; // Value is determined before the program runs.
    std::cout << "constexpr value (determined at compile-time): "
              << compileTimeValue << std::endl;

    return 0;
}
