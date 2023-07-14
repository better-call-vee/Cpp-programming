//https://codeforces.com/problemset/problem/1066/A

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main()
{
    fast;

    int t;
    cin >> t;

    while (t--)
    {
        int L, v, l, r;
        cin >> L >> v >> l >> r;

        int inbetween = L / v;
        int inTRAIN = r / v - (l - 1) / v;

        int lantern = inbetween - inTRAIN;
        cout << lantern << "\n";
    }

    return 0;
}