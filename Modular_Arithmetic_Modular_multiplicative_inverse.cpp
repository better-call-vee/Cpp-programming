/*
 In modular arithmetic, we work with integers rather than real numbers, so we
 don't typically talk about division in the same way we do in real number
 arithmetic. Instead, we use the concept of a multiplicative inverse to achieve
 a similar outcome.
 We can say:
 a × a^−1(1 / a) ≡ 1 (% mod)

 The MMI of a % mod exists if and only if "a and mod are coprime (i.e.,
 their greatest common divisor is 1)".
 In real number arithmetic, the multiplicative inverse or reciprocal of a is
 1/a, which can be a fraction. However, in modular arithmetic, we deal only with
 integers. So, instead of finding a fractional inverse, we find an integer i
 such that "("when a is multiplied by i and then taken modulo m, the result is
 1")" This ensures that the operation stays within the realm of integers and
 modular arithmetic.



 And also if MMI exists, it will be UNIQUE and only ONE.

Proof by contradiction:
let,
1 <= b != c <= m - 1;   where b and c are two different numbers and MMI

So, a * b ≡ 1 % m
    a * c ≡ 1 % m

  so, ab - ac ≡ (1 - 1) % m;
    =>a(b - c) ≡ 0 % m;
    => b - c ≡ 0 % m
    => b ≡ c % m

Thus, b != c is not possible.
Also, all a * i will be distinct.

Also, why till m - 1?? because for m, it will give 0 which is not acceptable.
*/
// naive approach
#include <bits/stdc++.h>
using namespace std;
int inverse(int a, int m) { // O(m)
    for(int i = 1; i < m; i++) {
        if(1LL * a * i % m == 1) return i;
        return -1; // inverse doesn't exist
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << inverse(2, 5) << '\n'; // 3
    cout << inverse(3, 6) << '\n'; // -1
    return 0;
}

// Faster:
#include <bits/stdc++.h>
using namespace std;

int power(int x, int n, int mod) { // O(log n)
    int ans = 1 % mod;
    while(n > 0) {
        if(n & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        n >>= 1;
    }
    return ans;
}

// m is prime
int inverse(int a, int m) { // O(log m)
    return power(a, m - 2, m);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << inverse(2, 5) << '\n'; // 3
    return 0;
}

/*
The faster approach is done by Fermat's Little Theorem.
Proof:
***CAN BE DONE ONLY WHEN THE MOD IS PRIME.

=> a^(m - 1) ≡ 1 (% m)
=> a^(m - 1) / a ≡ 1 / a (% m)
=> a^(m - 2) ≡ 1 / a % m   (we know that 1/a is known as inverse)

Thus, a^(m - 2) % m = 1 / a

*/