#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int power(int x, ll n) {
    vector<int> pw2(61, 0); // this contains x^(2^k) values for k = 0 to 60
    pw2[0] = x % mod;       // x^(2^0) = x^1 = x
    /*
1. We initialize a vector pw2 to store powers of x raised to powers of 2 (i.e.,
x^(2^k)).
2. pw2[0] is just x % mod, representing x^(2^0).
3. We then compute x^(2^k) by squaring the previous value (pw2[k-1]), and store
it back in pw2[k]. This builds up the sequence x^(2^1), x^(2^2), ..., x^(2^60).
    */
    for(int k = 1; k <= 60; k++) pw2[k] = 1LL * pw2[k - 1] * pw2[k - 1] % mod;
    ll ans = 1 % mod;
    for(int k = 0; k <= 60; k++)
        if(n >> k & 1) ans = 1LL * ans * pw2[k] % mod;
    return ans;
    /*
1. We start with ans = 1, which will accumulate the final result.
2. The loop iterates over each bit position k in n (from 0 to 60).
3. n >> k & 1 checks if the k-th bit of n is 1 (i.e., if 2^k is part of the
binary representation of n).
4. If the k-th bit is 1, we multiply the corresponding precomputed power pw2[k]
with ans and take modulo mod to prevent overflow.
     */
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll q, x, n;
    cin >> q;
    while(q--) {
        cin >> x >> n;
        cout << power(x, n) << "\n";
    }
    return 0;
}
/*
We know, 13 = 1101
This can be expressed as 2^3 + 2^2 + 2^0
so, x^(13) = x^(2^3 + 2^2 + 2^0);
=>  x^(13) = x^(2^3) * x^(2^2) * x^(2^0);

from here,
x^(2^3) = x^(2^2) * x^(2^2);    as (2^3 = 2^2 + 2^2) and x^(a + b) = x^a * x^b;
                                    x^(2^2 + 2^2)
SO,
x^(2^k) = x^(2^(k-1)) * x^(2^(k-1));

Sample input:
3
3 4
2 8
123 123

Sample output:
81
256
921450052
*/

// this can be written as:
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int power(int x, ll n) {
    vector<int> pw2(61, 0); // this contains x^(2^) values
    pw2[0] = x % mod;       // x^(2^0) = x^1 = x
    ll ans = 1 % mod;
    for(int k = 0; k <= 60; k++) {
        if(n >> k & 1) ans = 1LL * ans * pw2[k] % mod;
        pw2[k + 1] = 1LL * pw2[k] * pw2[k] % mod;
        // combination of both loops and directly setting the next power
    }
    return ans;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll q, x, n;
    cin >> q;
    while(q--) {
        cin >> x >> n;
        cout << power(x, n) << "\n";
    }
    return 0;
}

// MORE EFFICIENT: without vector:
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int power(int x, ll n) {
    x %= mod; // x^(2^0) = x^1 = x
    ll ans = 1 % mod;
    for(int k = 0; k <= 60; k++) {
        if(n >> k & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        // directly assigning the x^(2^k) to the x.
    }
    return ans;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll q, x, n;
    cin >> q;
    while(q--) {
        cin >> x >> n;
        cout << power(x, n) << "\n";
    }
    return 0;
}

// MORE EFFICIENT: just running only till the last set bit:
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int power(int x, ll n) {
    x %= mod; // x^(2^0) = x^1 = x
    ll ans = 1 % mod;
    while(n) {
        if(n & 1) ans = 1LL * ans * x % mod; // only granting if it's set bit
        x = 1LL * x * x % mod;
        // directly assigning the x^(2^k) to the x.
        n /= 2;
    }
    return ans;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll q, x, n;
    cin >> q;
    while(q--) {
        cin >> x >> n;
        cout << power(x, n) << "\n";
    }
    return 0;
}


// N.B: If mod == 1, we gotta return 0!