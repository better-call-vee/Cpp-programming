/*
Function overloading is a powerful feature in C++ that allows multiple functions
to share the same name but differ in their parameter types or number of
parameters. This capability makes it possible to implement functions that
perform similar operations on different types of data or varying numbers of
inputs, thus improving code readability and maintainability.
Example:
*/

#include <iostream>
using namespace std;

// Function to add two integers
int add(int a, int b) { return a + b; }

// Overloaded function to add two doubles
double add(double a, double b) { return a + b; }

// Overloaded function to add three integers
int add(int a, int b, int c) { return a + b + c; }

int main() {
    // Demonstrates calling the overloaded functions
    cout << "Adding two integers: " << add(5, 3) << endl; // Calls int add(int, int)
    cout << "Adding two doubles: " << add(2.5, 3.2) << endl; // Calls double add(double, double)
    cout << "Adding three integers: " << add(10, 20, 30) << endl; // Calls int add(int, int, int)
    return 0;
}

/*
When compiling, the C++ compiler determines which function to call based on the
number and types of arguments provided. This example illustrates how different
versions of a function named 'add' can be called depending on the context,
providing flexibility and clear functionality specialization without the need to
remember multiple function names.
*/

/*
The need of function overloading instead of using different names:

1) Simplicity and Clarity: Overloading allows you to use the same function name
for similar actions that operate on different types of data. This makes your
code more intuitive and easier to remember. For example, a function named add
can be used to add integers, doubles, or even complex numbers. This approach
keeps your function names logical and consistent, which is easier than
remembering multiple names like addInts, addDoubles, etc.

2) Consistency in Naming: When you use function overloading, the function name
can describe the operation being performed regardless of the types of inputs
it handles. This consistency helps in making the code more readable and
maintainable. For instance, methods like print() can be overloaded to print
different types of data structures, such as arrays, lists, or individual items
without needing separate function names for each.

3) Ease of Use: Overloading makes it simpler to manage the namespace of
functions in large programs. You don’t have to come up with new names for
functions that perform essentially the same task, which can help avoid the
proliferation of function names in the codebase.

4) Polymorphism: Function overloading is a way to achieve polymorphism, where
the same function name can invoke different behaviors based on the input
parameters. This is particularly useful in object-oriented programming where the
behavior of a function might vary slightly depending on the object it's being
called on or the parameters it receives.

5) Compile-Time Safety: Since the function to be executed is determined
during compile time based on the parameters passed, it ensures that the correct
type and number of parameters are provided, thus adding an extra layer of type
safety to function calls.
*/