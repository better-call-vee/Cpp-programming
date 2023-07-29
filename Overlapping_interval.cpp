//overlapping interval: https://codeforces.com/contest/1849/problem/C

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int pre[N], nx[N];

int main() {
    int T;
    cin >> T;

    while (T--) {
        set<pair<int, int>> overlaps; // A set to store unique overlapping intervals
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        s = "?" + s; // Adding a '?' character at the beginning to handle 1-based indexing

        // Preprocess nearest occurrence of '0' from the left
        int lastZero = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') {
                lastZero = i;
            }
            pre[i] = lastZero;
        }

        for(int i=1; i<=n; i++) cout<<pre[i]<<" ";
        cout<<"\n";

        // Preprocess nearest occurrence of '1' from the right
        int lastOne = n + 1;
        for (int i = n; i >= 1; i--) {
            if (s[i] == '1') {
                lastOne = i;
            }
            nx[i] = lastOne;
        }

        for(int i=1; i<=n; i++) cout<<nx[i]<<" ";
        cout<<"\n";

        int res = 0;
        while (m--) {
            int l, r;
            cin >> l >> r;
            l = nx[l]; // Find nearest occurrence of '1' from the right of l
            r = pre[r]; // Find nearest occurrence of '0' from the left of r

            if (l < r) {
                overlaps.insert({l, r});
            } else {
                res = 1;
            }
        }

        cout << res + overlaps.size() << endl;
    }

    return 0;
}
