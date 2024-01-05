#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// https://codeforces.com/contest/1601/problem/A
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), cnt(30);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 30; j++) cnt[j] += (1 << j & a[i] ? 1 : 0);
        // or, (a[i] >> j & 1); this directly gives the set bit check.
        for(int k = 1; k <= n; k++) {
            int ok = 1;
            for(int j = 0; j < 30; j++)
                if(cnt[j] % k != 0) {
                    ok = 0;
                    break;
                }
            if(ok) cout << k << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
AND property:
Suppose, we AND two numbers, after that if we subtract both the numbers with
their AND value, the both values will be lessened by the number of set bits of
the AND value. Suppose: 13 AND 7 => 5. 13 = 1101, 7 = 111. 13 - 5(101) = 1000, 7
- 5 = 10.

In this problem, when the count of a bit position is divided by k, we can make
pair of that k and subtract leading to zero(0). thus we check cnt[j] % k is 0 or
not.
*/