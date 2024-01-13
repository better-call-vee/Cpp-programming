#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k, i = 1;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for(auto &[val, id] : a) {
        cin >> val;
        id = i++;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        int rest = k - a[i].first, l = i + 1, r = n - 1;
        while(l < r) {
            int curr = a[l].first + a[r].first;
            if(curr == rest) {
                cout << a[i].second << " " << a[l].second << " " << a[r].second;
                goto hell;
            } else if(curr < rest)
                l++;
            else
                r--;
        }
    }
    cout << "IMPOSSIBLE\n";
hell:;
    return 0;
}

// https://cses.fi/problemset/task/1641/
