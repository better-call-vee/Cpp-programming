// https://codeforces.com/contest/1909/problem/C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n;
        vector<int> l(n), c(n), diff(n);
        map<int, int> r;
        for(int i = 0; i < n; i++) cin >> l[i];
        for(int i = 0; i < n; i++) {
            cin >> x;
            r[x]++;
        }
        for(int i = 0; i < n; i++) cin >> c[i];
        for(int i = 0; i < n; i++) {
            auto nxt = r.upper_bound(l[i]); // that's how bound works in maps.
            diff[i] = nxt->first - l[i];    // that's how you access a pointer.
            r.erase(nxt);
        }
        sort(diff.begin(), diff.end());
        sort(c.rbegin(), c.rend());
        ll total = 0;
        for(int i = 0; i < n; i++) total += 1LL * diff[i] * c[i];
        cout << total << "\n";
    }
    return 0;
}