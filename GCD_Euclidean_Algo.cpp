/*
The Euclidean algorithm is based on a simple, yet powerful,
principle: the GCD of two numbers does not change if the larger number is
replaced by its difference with the smaller number. In a more practical sense,
for two integers, a and b where a > b, the GCD of a and b is the same as the GCD
of b and a mod b. because if a number d divides both a and b, it must also
divide a mod b. Thus, any divisor of a and b is also a divisor of b and a mod b.
a = d * m and b = d * n;
a & b are multiples of d. d is a common divisor of a & b;
now,
a = b * q + r;
where, r = a mod b(remainder). 
q is the quotient when dividing a by b;
next, we get r = a - (b * q); from the 
equation of line 11.
Now, 
replacing the a = d * m and b = d * n with this :
r = d * m - (d * n * q);
r = d * (m - (n * q));

This shows that r is also divisible by d because d is a factor of 
r. Hence, any divisor d of both a and b will also divide r which is
a mod b;


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



/*
SOME GCD PROPERTIES:

gcd(a, b) = gcd(a, |a - b|) = gcd(b, |a - b|)

suppose, gcd(a1, a2, a3);
      => gcd(a2, a1, a3);
      => gcd(a2, gcd(a1, a3));
      => gcd(a2, gcd(a1, |a3 - a1|));
      => gcd(a2, a1, |a3 - a1|);
      => gcd(gcd(a2, a1), |a3 - a1|);
      => gcd(a1, |a2 - a1|, |a3 - a1|);

for the problem, Row GCD, at codeforces, we can write this as:
gcd(a1 + bj, a2 + bj, a3 + bj, a4 + bj .... an + bj);
here,
if we do, 
gcd(a1 + bj, a2 + bj - a1 - bj, .... an + bj - a1 - bj) 
we get:
gcd(a1 + bj, a2 - a1, a3 - a1, a4 - a1, .....);

*/