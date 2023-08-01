// https://codeforces.com/problemset/problem/61/E

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using PBDS = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main()
{
    fast;

    int n;
    cin >> n;

    vector<int> enemies(n);

    for (int i = 0; i < n; i++)
        cin >> enemies[i];

    PBDS<int> p;
    ll ans = 0;
    vector<ll> inv(n);

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == (n - 1))
            p.insert(enemies[i]);

        else
        {
            inv[i] = p.order_of_key(enemies[i]);
            p.insert(enemies[i]);
        }
    }
    // first counting the inversions.

    //suppose an example:
    /*
    7 10 3 2 8 1
    here, suppose we take the element 3. what's it's inversion count? 2.
    and how many greater elements it have in front of it? 2.
    so the total combinations will be 4. how?
    7 3 2
    7 3 1
    10 3 2
    10 3 1 . we take j and k is counted through the inversion count, and then we take i by the
    next for loop.
    */
    p.clear();
    for (int j = 0; j < n; j++)
    {
        if (j == 0)
            p.insert(enemies[j]);
        else
        {
            ll less = p.order_of_key(enemies[j]);
            ll greater = p.size() - less;
            
            ans += greater * inv[j];
            p.insert(enemies[j]);
        }
    }
    cout << "\n"
         << ans << "\n";

    return 0;
}