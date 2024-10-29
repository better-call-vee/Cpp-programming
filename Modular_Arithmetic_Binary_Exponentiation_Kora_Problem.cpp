#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
// https://atcoder.jp/contests/abc293/tasks/abc293_e?lang=en
/*
Here, they asked to output the summation of A^i where i = 0 to X - 1
And in MOD (M).
The MOD is not meant to be a prime for sure here. So, we can't apply
the geometric progression which is super easy.
i = x - 1
 ∑  a^i   => (a^x - 1) % M / (a - 1)
i = 0
here, the modular multiplicative inverse of a - 1 can't be calculated
as MOD and (a - 1)'s GCD must be 1 which is not ensured here.

Now, there is only another way. To do this.
The complexity will be (logn)^2
With Binary exponentiation.

Here, the main logic is Divide & Conquer.
a^0 + a^1 + a^2 + a^3 + ... + a^(x - 1)
suppose, the x - 1 is 7.
so,
0 1 2 3 | 4 5 6 7
after dividing by 2, we get the summation of a^0, a^1, a^2, a^3.
THEN, if we do, a^4(a^0 + a^1 + a^2 + a^3),
what do we get??
=> we get exactly the summation of right portion.
Now, for odd x / even x - 1:
we get:
0 1 2 3 | 4 5 6 7 8
here we just add the a^8 with the total answer.
*/
int power(int a, int x, int m) {
    int ans = 1 % m;
    while(x) {
        if(x & 1) ans = ans * a % m;
        a = a * a % m;
        x >>= 1;
    }
    return ans;
}
int solve(int a, int x, int m) {
    if(x == 0) return 1 % m; // for x == 0(a ^ 0) , we get 1.
    if(x & 1) {
        int p = x / 2;
        int curr = solve(a, p, m);
        int ans = (curr + power(a, p + 1, m) * curr % m) % m; // line 25
        return ans;
    } else {
        int ans = (solve(a, x - 1, m) + power(a, x, m)) % m; // line 32
        // goes to line 47 and calculates for odd and then goes on.
        return ans;
    }
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int A, X, M;
    cin >> A >> X >> M;
    cout << solve(A, X - 1, M) << nl; // giving X - 1 directly, after
    // that in the function, we will go like this.
    return 0;
}