#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
ll modpow(ll base, ll exp) {
    ll result = 1;
    while(exp > 0) {
        if(exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc, t;
    cin >> tc;
    t = 1;
    while(t <= tc) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        ll total_sum = 0;
        for(int i = 0; i < n; i++) {
            ll count_as_max = modpow(2, i);
            ll count_as_min = modpow(2, n - i - 1);
            ll contribution = (a[i] * (count_as_max - count_as_min)) % MOD;
            total_sum = (total_sum + contribution + MOD) % MOD;
        }
        cout << "Case #" << t++ << ": " << total_sum << "\n";
    }
    return 0;
}

/*
THIS IS CALLED BINARY EXPONENTIATION:
LATER I CREATED ONE FILE DESCRIBING THIS. SEARCH BINARY EXPONENTIATION.
*/

/*
It's that same Max - Min sums of subsets. 
But n can be 100000. so, we can't take directly 2's exponent.
We had to go through a technique.
let's see (1 << 13)
2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2
   Binary Exp  | Operation        | Result Calculation
  -------------|------------------|--------------------
       1 (LSB) | Current bit is 1 | result *= base         => base = 2, becomes 4       => we loss one 2 from 13, we have 12
       0       | Current bit is 0 | (no multiplication)    => base = 4, becomes 16
       1       | Current bit is 1 | result *= base^4       => base = 16, becomes 256    => we loss four 2 from 12, we have 8
       1 (MSB) | Current bit is 1 | result *= base^8       => base = 256, becomes 65536 => we loss eight 2 from 8, we have 0

*/


/*
This storing one is better:
line 65:

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int N = 1e5;
vector<int> twospower(N, 1);
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for(int i = 1; i < N; i++) twospower[i] = twospower[i - 1] * 2 % mod;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1) {
        cout << a[0];
        return 0;
    }
    sort(a.begin(), a.end());
    ll total = 0;
    for(int i = 0; i < n; i++) {
        ll contrb =
            ((1LL * a[i] * i - 1LL * a[i] * (n - i - 1)) % mod + mod) % mod;
        total = (total + contrb) % mod;
    }
    cout << (1LL * total * twospower[n - 2]) % mod;
    return 0;
}
*/