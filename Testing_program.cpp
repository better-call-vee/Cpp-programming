#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x;
    cin >> n;
    vector<pair<int, int>> a;
    for(int i = 0; i < n; i++) {
        cin >> x;
        a.emplace_back(x, i + 1);
    }
    rotate(a.begin(), a.begin() + 5, a.end());
    for(int i = 0; i < n; i++) cout << a[i].first << " ";
    cout << "\n";
    for(int i = 0; i < n; i++) cout << a[i].second << " ";

    return 0;
}