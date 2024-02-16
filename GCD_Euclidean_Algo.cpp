/*
The Euclidean algorithm is based on a simple, yet powerful,
principle: the GCD of two numbers does not change if the larger number is
replaced by its difference with the smaller number. In a more practical sense,
for two integers, a and b where a > b, the GCD of a and b is the same as the GCD
of b and a mod b. because if a number d divides both a and b, it must also
divide a mod b. Thus, any divisor of a and b is also a divisor of b and a mod b.

also it doesn't matter whether we are giving a as bigger number or b as bigger
number, eventually the bigger number will be set to a because of the mod
operation.

We can keep applying this process recursively. In each step, we replace
a with b and b with a mod b, until b becomes 0. At that point, a is the GCD.
*/

#include <iostream>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    return 0;
}
