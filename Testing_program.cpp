#define TANVEE009

#include "D:\CP\DEBUG_TEMPLATE.h"
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define INF 1e18
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef DEBUG_MODE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stderr);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x, ans = 0;
    cin >> n;
    vector<vector<int>> cnt(31, vector<int>(2, 0));
    for(int i = 0; i < n; i++) {
        cin >> x;
        for(int bit = 0; bit <= 30; bit++)
            (x >> bit & 1) ? cnt[bit][1]++ : cnt[bit][0]++;
    }
    debug(cnt);
    debug(cnt);
    for(int i = 0; i <= 30; i++) {
        int contribution = cnt[i][0] * cnt[i][1] * 2;
        ans += contribution * (1 << i);
        // bit by bit calcultaion, so for sum we need to apply
        // this(why=stated previously)
    }

    return 0;
}