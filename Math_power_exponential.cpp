#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;

ll calculatePower(ll x, ll y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        y /= 2;
    }
    return res;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    cout << n << " to the power " << m << " is = " << calculatePower(n, m) << "\n";
}