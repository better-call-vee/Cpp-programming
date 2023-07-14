#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main()
{
    fast;

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        if (n & (n - 1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    /*
    This is a fuckin' tricky binary related question. If the number 'n' has an odd divisor which
    which is greater than one, definitely it will have an odd prime divisor. To understand this fact,
    we can consider what happens when multiplying even and odd numbers:
    #even * even = even;
    #even * odd = even;
    #odd * even = even;
    #odd * odd = odd;

    There is only one even prime number - 2. So, if a number has no odd divisors, then it must be
    a power of 2. 2^2, 2^3, 2^4...
    Let's dive deep into this.
    If 'n' is not the power of 2, then it's binary representation will contain more than one '1' bit
    in it.
    Suppose, n = 8 = 1000. n = 10 = 1010. Here, 8 is the power of 2. 
    Now let's understand why did we do the AND operation here...

    When 'n' is a power of 2, it has only one bit which is 1. And therefore, the number before this
    2 powered 'n' will have all the 1 bits to the right. 
    the binary representation of 7 is 0111. while 8 is 1000.
    So, if we AND them:
    1000
 &  0111
 ---------
    0000; 0 => which means false. so, (n&(n-1)), if this condition is false, we simply know that
    'n' does not have an odd divisor greater than 1.
    if it's true(1), we simply know that 'n' has an odd divisor greater than 1.
    */

    return 0;
}