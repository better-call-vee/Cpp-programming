#include <iostream>
using namespace std;

int gcd(int a, int b) {
    // Base case: If b is 0, the GCD is a
    if (b == 0) {
        return a;
    }

    // by recursively calling gcd with b and the remainder of a divided by b
    return gcd(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;

    int grt = max(a, b);
    int less =min(a, b);

    int result = gcd(grt, less);

    cout << "GCD: " << result << endl;

    return 0;
}

//it's a very easy gcd method. 
//we select a as the greater number and b as the less number.
//everytime we get the remainder. then we take previously set b as a now and
//take the remainder as b.
//we continue this until b becomes 0. if b becomes 0 then a is the gcd.
/*
If c is divisible by the GCD of a and b, then it's possible to make c using a and b. This is because
the GCD represents the common factor that can be multiplied by a and b to obtain any multiple of it. 
*/
