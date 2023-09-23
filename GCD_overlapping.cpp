/*
  +----------+
  | Better.  |
  | Call.Vee |
  +----+-----+
       |
       V
https://codeforces.com/problemset/problem/1200/C
created: 23th September, 2023 04:20:09 GMT+6
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

ll GCD(ll a, ll b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int main()
{
    fast;

    ll n, m, q;
    cin >> n >> m >> q;

    ll in_seg = n / GCD(n, m);
    ll out_seg = m / GCD(n, m);
    // these two portions makes a group through which anyone can
    // roam easily from one cell to other. The overlapping concept.
    // look, 8 and 12's gcd is 4. 8/4 = 2, 12/4 = 3. So, in a group,
    // where they can roam unrestrictedly, there will  be 2 segments
    // from inner part, 3 segments from outer part.

    while (q--)
    {
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        ll startgrp = (sx == 1) ? (sy + in_seg - 1) / in_seg
                                : (sy + out_seg - 1) / out_seg; // ceiling
        ll endgrp = (ex == 1) ? (ey + in_seg - 1) / in_seg
                              : (ey + out_seg - 1) / out_seg;

        // checking if they both belongs to the same group or not
        if (startgrp == endgrp)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}