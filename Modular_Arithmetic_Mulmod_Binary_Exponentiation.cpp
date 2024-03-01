#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = (ll)1e18 + 7;
// do without typecasting, it will not give 1e18 + 7, because, 1e18 is
// calculated in double. It troubles with precision when calculating double over
// 1e16 even if double has better range than long long.
ll mulmod(ll x, ll y) {
    x %= mod;
    ll ans = 0; // as it's addition, not multiplication like base
    while(y) {
        if(y & 1) ans = (ans + x) % mod;
        x = (x + x) % mod;
        y >>= 1;
    }
    return ans;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    cout << mulmod(n, m);
    return 0;
}
/*
Sample Input: 1000000000000000000 1000000000000000000
x * y = x + x + x + ... + x (x is added y times);
now, 13th line => like before(binary exponentiation) x is being set as previous
x + adding one more x;
suppose, x * 7.
=> x * (2^2 + 2^1 + 2^0)
=> x * 2^2 + x * 2^1 + x * 2^0
So, like previous, we would have store the (x * 2 ^ i)s in a vector.
and then finally will add the bit by bit set values. Which we do here using
while loop directly.

suppose, 12 * 7
at first 12 is added to the answer. ans = 12!
(as 7 & 1 = 1), x becomes previous x + x = 24,
and y becomes 3.
then, 3 & 1 = 1, and again x(24) is added to the answer. ans = 36.
and x becomes 24 + 24 = 48. y becomes 1.
again y = 1, so ans = 36 + 48 = 84. and we are done.
*/