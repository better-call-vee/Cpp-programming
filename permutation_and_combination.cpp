/*
Permutations and Combinations
-----------------------------

nPr (Permutation) represents the number of ways to arrange 'r' objects out of
'n' distinct objects, where the order matters.
nPr = n! / (n−r)!
    = nCr * r!
If you have 5 books and you want to arrange 3 of them on a shelf, the number of
possible arrangements will be 5P3 = 60. See, here for 1 2 3 we can do 3 2 1, 2 1
3, 3 1 2, 2 3 1, 1 3 2, 1 2 3. Here, order is mattering.


nCr (Combination) represents the number of ways to choose 'r' objects from 'n'
distinct objects, where the order does not matter.
nCr = n! / r!(n−r)!
If you have 5 books and you want to arrange 3 of them on a shelf, the number of
possible arrangements will be 5C3 = 10.
Combination of choosing 3 out of 5 books will be simply:
1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5
*/

// suppose, I have 10^6 queries. Everytime I need to output either nCr or, nPr.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
const int N = 1e6 + 9, mod = 1e9 + 7;
int fac[N], ifac[N];
int power(int x, int n) {
    int ans = 1 % mod;
    while(n) {
        if(n & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        n >>= 1;
    }
    return ans;
}
int inverse(int a) { // modular multiplicative inverse.
    return power(a, mod - 2);
}
void prec() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1LL * fac[i - 1] * i % mod;
    // precalculating all the factorials and inverse factorials.
    // nCr = n! / (r! (n - r)!) = n! * 1/r! * 1/(n-r)!
    // nPr = n! / (n - r) ! = n! * 1/(n - r)!

    // for(int i = 0; i < N; i++) ifac[i] = inverse(fac[i]); O(logn)

    ifac[N - 1] =
        inverse(fac[N - 1]); // from N - 1 as fac[i] stores i! for 0 ≤ i < N
    for(int i = N - 2; i >= 0; i--)
        ifac[i] = 1LL * ifac[i + 1] * (i + 1) % mod; // O(n)
    // 1 / i! = 1 / (i + 1)! * (i + 1);
}
int nCr(int n, int r) {
    if(r > n || r < 0) return 0;
    return fac[n] * ifac[r] % mod * ifac[n - r] % mod;
}
int nPr(int n, int r) {
    if(r > n || r < 0) return 0;
    return fac[n] * ifac[n - r] % mod;
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    prec();
    int q;
    cin >> q;
    while(q--) {
        int n, r;
        cin >> n >> r;
        cout << nCr(n, r) << nl;
        cout << nPr(n, r) << nl;
    }
    return 0;
}

// Similar problem : https://cses.fi/problemset/task/1715
// good combinatorics problem : https://codeforces.com/problemset/problem/300/C

/*
When you have n unique (distinct) numbers, there’s nothing stopping you
from rearranging each one independently. So, the total number of unique ways to
arrange them is n! . This is simply the product of all
integers from 1 to n: n! = n×(n−1)×(n−2)×⋯×1. it is complete freedom to place
each number in any position.
When all items are unique, imagine arranging them one by one:
    For the first position, you have n options (any of the n items).
    For the second position, you’re left with n−1 options, and so on.
This freedom to choose progressively fewer options creates a sequence of
choices multiplying into n×(n−1)×(n−2)×⋯×1

With Duplicates (Some Numbers Repeating):
    Now, if certain numbers repeat, then not all rearrangements are unique. We
get duplicates because swapping identical items doesn’t change the arrangement.
    To correct for this, divide by the factorial of each group of identical
items to remove the duplicates. For example, if you have a1 of one number,
a2 of another, etc., then: n! / a1!×a2!×⋯×ak!

AAB
AAB, ABA, BAA, AAB, ABA, BAA
3! / 2! = 3
AAB, ABA, BAA.
*/

/*
nPm

for(int i = n; i >= (n - m + 1); i--) {
            ans = ans * i;
}

this is also permutation as n! / (n - m)!
n! = n * n - 1 * (n - m + 1) * n - m * ...* 1
so, we can just ignore the n-m*.. * 1 which is (n - m)!

to get the last non zero digit from here, we can just directly check everytime 
in the loop if there is the last digit which is zero. 
if not, we move on. if yes, we just remove it to track.
As, if there is zero at the ending, it will be continuing to stay with 
zeroes no matter with which number we multiply it.

*/