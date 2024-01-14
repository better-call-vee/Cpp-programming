#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    ll ans = 0, n = s.size();
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or
           s[i] == 'u')
            ans += 1LL * (i + 1) * (n - i);
    }
    cout << ans;
    return 0;
}