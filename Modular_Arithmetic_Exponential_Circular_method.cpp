#include <bits/stdc++.h>
using namespace std;

int power(int x, int n, int mod) { // O(mod)
    if(mod == 1) return 0;
    vector<int> a;
    vector<bool> vis(mod, false);
    a.push_back(1); // x^0
    vis[1] = true;
    int cur = 1, st = 0, i = 0;

    cout << "Before using the circular method: \n";
    while(i++ <= 20) {
        cur = 1LL * cur * x % mod;
        a.push_back(cur);
    }
    for(auto x : a) {
        cout << x << ' ';
    }
    cout << "\nAfter using the circular method: \n";

    a.clear();
    a.push_back(1);
    cur = 1;
    while(true) {
        cur = 1LL * cur * x % mod;
        if(vis[cur]) {
            st = find(a.begin(), a.end(), cur) - a.begin();
            break;
        }
        vis[cur] = true;
        a.push_back(cur);
    }
    for(auto x : a) {
        cout << x << ' ';
    }
    cout << '\n';
    cout << "st = " << st << '\n';

    int period = (int)a.size() - st;
    if(n < st) return a[n];
    n -= st;
    return a[st + n % period];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x = 2, n = 20, m = 40;
    cout << power(x, n, m) << '\n';
    return 0;
}
