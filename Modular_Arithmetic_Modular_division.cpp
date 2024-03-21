/*
Here, it is a / b % m is what are we trying to get
We can say a / b ≡ x % m
thus => a ≡ (b * x) % m

how can we get a / b % m?
a / b % m can be written as a * 1/b % m
here 1 / b is b's multiplicative inverse.
So, under m, with multiplicative inverse of b, we will multiply a
to get the modular division.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll inverse(ll x, ll p, ll m) {
    ll ans = 1 % m;
    while(p) {
        if(p & 1) ans = 1LL * ans * x % m;
        x = x * x % m;
        p >>= 1;
    }
    return ans;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll a, b, mod;
    cin >> a >> b >> mod;
    cout << a * inverse(b, mod - 2, mod) % mod;
    return 0;
}

//sample input => 3 4 7 = 6 https://www.eolymp.com/en/problems/9606