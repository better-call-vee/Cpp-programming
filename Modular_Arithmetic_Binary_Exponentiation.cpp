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

// N.B: If mod == 1, we gotta return 0! doesn't need here as we do x %= mod;

// a great problem, suppose, they say you a^b and give you the last digit.
// use pow(a, b, 10) to win here
// suppose, we need 3 digits, we have to mod with 1000. 4 digits, 10000. like
// this

/*
Modular Arithmetic & Logarithm with great logics:
link:
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1970

here,
we have to output n^k and mod value isn't given.

now,
   n^k = x
=> log10(n ^ k) = log10(x)
=> klog10(n) = log10(x)
=> 10^(klog10(n)) = x
here,
suppose, 10^(klog10(n)) comes like:
10^25.3233344 , where klog10(n) is 25.3233344
next,
10^(25 + 0.3233344)
and 10^0.3233344 * 10^25 will be the final value
where, eventually the first digits of the final number
will depend on this fractional part!!!!

finally, the fractional part * 100.
why?? 10^fraction means it will definitely , definitely
show us a value greater than 1. like 10^0.3233344 is 2.105398...
see, now, *=100 and boom, we get the first three digits.
*/

#include <bits/stdc++.h>
using namespace std;

int power(int a, int k, int mod) { // a^k % mod
    int ans = 1 % mod;
    while(k) {
        if(k & 1) ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        k >>= 1;
    }
    return ans;
}
int leading_3(int n, int k) {
    double p = k * log10(n);
    double q = p - floor(p); // getting the fractional part
    double x = pow(10, q);   // 10 ^ fractional part
    return floor(x * 100);   // getting the leading 3 digits
}
int trailing_3(int n, int k) { return power(n, k, 1000); }
string format(int x) { // make it of length 3 by appending necessary 0s
    string x_str = to_string(x);
    while(x_str.size() < 3) { // suppose, the trailing 3 / leading 3 is giving
                              // 001 or 002 or something
        // then, we have to add this!!! tricky
        x_str.insert(x_str.begin(), '0');
    }
    return x_str;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << format(leading_3(n, k)) << "..." << format(trailing_3(n, k))
             << '\n';
    }
    return 0;
}

/*
https://www.spoj.com/problems/ZSUM/en/

problems like this, we need to express the function and try to do
maths and simplify it.
Like here,
we can make the term Z(n) + Z(n - 1) - 2Z(n - 2)
= (n^k) + 2((n - 1)^k) + 2((n - 1) ^ (n - 1)) + n ^ n
now , boom, easy peasy.
*/
#include <bits/stdc++.h>
using namespace std;

const int mod = 10000007;

int power(int a, int k) { // a^k % mod
    int ans = 1 % mod;
    while(k) {
        if(k & 1) ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        k >>= 1;
    }
    return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    while(cin >> n >> k) {
        if(n == 0 and k == 0) break;
        int ans = (2 * power(n - 1, k) % mod + power(n, k)) % mod;
        ans += (2 * power(n - 1, n - 1) % mod + power(n, n)) % mod;
        ans %= mod;
        cout << ans << '\n';
    }
    return 0;
}