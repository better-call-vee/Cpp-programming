/*
C++ Lambda functions are a concise way to create anonymous (unnamed) functions right 
within the body of a function. You can use it when you need a short function that you 
don't want to define it elsewhere in your code.

The general syntax of a lambda function is:
[capture](parameters) -> return_type {
    // code
}

Capture: Determines how variables from outside the lambda function can be accessed within it.
Parameters: Specifies the parameters, like in a regular function.
Return Type: (Optional) Specifies the return type. If omitted, it's inferred from the return 
statements in the lambda.
Code: The code inside the lambda function.
Capture modes enable access to variables from the enclosing scope.

[]: Captures nothing.
[=]: Captures all local variables by value.
[&]: Captures all local variables by reference.
[a, &b]: Captures variable a by value and variable, b by reference.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    // Example 1: Capture by Value
    int x = 10;
    auto lambda_by_value = [=](int a) -> int {
        // you can't change x in this lambda function
        // x is always 10 even if you change it outside later
        return a + x;
    };
    cout << "Capture by value: " << lambda_by_value(5) << endl; // Output: 15

    // Example 2: Capture by Reference
    auto lambda_by_reference = [&](int a) -> int {
        // you can change x in this lambda function
        // x is the same as the one outside at any moment
        return a + x;
    };

    cout << "Capture by reference: " << lambda_by_reference(5) << endl; // Output: 15
    x = 20;
    cout << "Capture by reference after changing x: " << lambda_by_reference(5) << endl; // Output: 25

    // Example 3: Mixed Capture
    int a = 10, b = 20;
    auto mixed_capture = [a, &b](int y) -> int {
        return y + a + b;
    };
    cout << "Mixed capture: " << mixed_capture(5) << endl; // Output: 35
    a = 20; b = 30;
    cout << "Mixed capture after changing b: " << mixed_capture(5) << endl; // Output: 45

    // Example 4: Capture Nothing
    auto no_capture = [](int a, int b) -> int {
        // can't access any variable from the outside
        return a * b;
    };
    cout << "Capture nothing: " << no_capture(5, 6) << endl; // Output: 30

    // Example 5: Auto Return Type (Inferred)
    auto inferred_return = [x](int a) {
        return a * x; // Return type inferred as int
    };
    cout << "Inferred return type: " << inferred_return(5) << endl; // Output: 50

    return 0;
}