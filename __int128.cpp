// it's a 128 bit sized data type but...
//__int128 can't be used for taking input / showing output.
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// const ll mod = (ll)1e18 + 7;
// // but can be directly used for typecasting.
// ll mulmod(ll x, ll y) { return (ll)((__int128)x * y % mod); }
// int main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     ll n, m;
//     cin >> n >> m;
//     cout << mulmod(n, m);
//     return 0;
// }

// also, can be read or written using string.
#include <bits/stdc++.h>
using namespace std;
__int128 read() {
    string s;
    cin >> s;
    __int128 ans = 0;
    for(int i = 0; i < s.size(); i++) ans = ans * 10 + (s[i] - '0');
    return ans;
}
string to_string(__int128 x) {
    string s;
    while(x > 0) {
        s += (char)(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
void write(__int128 x) { cout << to_string(x) << '\n'; }
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    __int128 x = read(), y = read();
    __int128 ans = x * y;
    write(ans);
    return 0;
}