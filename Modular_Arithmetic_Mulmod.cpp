#include <bits/stdc++.h>
using namespace std;

long long mulmod(long long x, long long y, long long mod) {
    long long ans = 0;
    while(y > 0) {
        if(y & 1) ans = (ans + x) % mod;
        x = (x + x) % mod;
        y >>= 1;
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long x = (long long)1e15 + 2, y = (long long)1e13 + 4,
              m = (long long)1e18 + 7;
    cout << mulmod(x, y, m) << '\n';
    return 0;
}

/*
Explanation of the mulmod Function

The function `mulmod(x, y, mod)` efficiently computes (x * y) % mod
without causing overflow, especially useful for large x and y.
It follows a bitwise approach similar to binary exponentiation,
but with addition instead of multiplication.

Step-by-Step Explanation:
1. Breaking Down y Using Powers of 2:
   - y is represented in binary form. For example, if y = 13,
     its binary form is 1101, representing 2^3 + 2^2 + 2^0.
   - This lets us rewrite x * y as a series of shifted values.

2. Loop Mechanics:
   - For each bit in y (starting from the least significant):
     - If the bit is 1: add the current x to the answer (ans).
     - Shift x: double x each loop (equivalent to x * 2),
       keeping the result under mod to prevent overflow.
     - Shift y: right-shift y by one to check the next bit.

3. Final Output:
   - After all bits of y have been processed, `ans` holds
     the result (x * y) % mod.

Time Complexity: O(log y), as it processes each bit of y.


*** if 1e18 + 7 is used as mod, we need to typecast it (long long)1e18 + 7;
else, it will not work and go overflowing as 1e, here e is generated through
double
*/

/*
https://basecamp.eolymp.com/en/problems/1121

here, the constraint is big, 2^63 - 1;
here’s what this code is doing:

It’s calculating (a^b) % mod without running into overflow issues,
even for huge values up to 2^63 - 1. To do this, we combine two techniques:
1. `mulmod` - modular multiplication (prevents overflow in multiplications).
2. `binpow` - binary exponentiation (efficient way to compute a^b).

Here’s the breakdown:

1. Function `mulmod`:
   - Purpose: Calculates (a * b) % mod without overflow.
   - How It Works:
     - It adds `a` to the answer (ans) bit-by-bit.
     - If the current bit of `b` is 1, adds `a` to ans and takes `mod`.
     - Doubles `a` (i.e., a = a + a) each time and reduces it with `mod` to stay safe.
     - Shifts `b` to the right to process each bit.
   - Why We Need It: Directly calculating (a * b) could overflow, so this splits
the multiplication.

2. Main Function Logic:
   - Reads input values for a, b, and mod.
   - Sets `ans` to 1 % mod as the base case.
   - Then, it goes through each bit of `b`:
     - If the bit is 1, it updates `ans` with (ans * a) % mod using `mulmod`.
     - Squares `a` with `mulmod` to prepare it for the next power.
     - Shifts `b` to the right for the next bit.
   - When all bits of `b` are processed, `ans` has (a^b) % mod.

Why This Works:
- Using `mulmod` inside `binpow` allows us to handle super large values
  without overflowing, even with a massive mod constraint (like 2^63 - 1).

Efficiency:
- O(log^2 b) - This keeps the code fast enough, even for huge numbers!
*/

#include <bits/stdc++.h>
    using namespace std;
#define int long long
#define ull unsigned long long
#define nl '\n'
ull mulmod(ull a, ull b, ull mod) {
    ull ans = 0;
    while(b) {
        if(b & 1) ans = (ans + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return ans;
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ull a, b, mod;
    while(cin >> a >> b >> mod) {
        ull ans = 1 % mod;
        while(b) {
            if(b & 1) ans = mulmod(ans, a, mod);
            a = mulmod(a, a, mod);
            b >>= 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
