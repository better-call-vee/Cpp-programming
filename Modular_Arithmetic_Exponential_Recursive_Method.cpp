#include <bits/stdc++.h>
using namespace std;
int power(int x, long long n, int mod) { // O(log n)
    if(n == 0) return 1 % mod;
    int cur = power(x, n / 2, mod);
    if(n % 2 == 0) {
        return 1LL * cur * cur % mod;
    } else {
        return 1LL * cur * cur % mod * x % mod;
        // why mod here after cur? (cur % mod);
        // because cur * cur can lead to 10^18, and thus more than this
        // multiplying with x will lead to overflow.
    }
}
// it's a divide and conquer method, if the number is odd, then it will take the
// number in count. suppose, 2 ^ 15 => 2 ^ 7 * 2 ^ 7 * 2. like this.
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x = 1e8 + 9;
    long long n = 1e18;
    int m = 1e9 + 7;
    cout << power(x, n, m) << '\n';
    return 0;
}