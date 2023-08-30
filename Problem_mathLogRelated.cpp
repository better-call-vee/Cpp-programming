#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1471/B
typedef long long ll;
typedef long double lld;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

ll logdn(ll n, ll x) 
/*
The function logdn(n, x) is meant to determine the highest power of x that divides n. In other words, it tries to find how many times we can divide n by x before n is no longer divisible by x.

Mathematical Principle: The logarithm function can be used to determine the power to which a base number must be raised to produce a given number. For instance, logx(n) gives us the power to which x must be raised to get n. This principle is being used in the logdn function.
logx(n) = logn / logx;
*/
{
    ll count = 1;
    while (n % x == 0)
    {
        count++;
        n /= x;
    }
    return count;
}

int main()
{
    fast;

    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<ll> elem(n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
            cin >> elem[i];

        ll least = INT_MAX;
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (least > logdn(elem[i], x))
            {
                least = logdn(elem[i], x);
                idx = i;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i < idx)
                sum += ((least + 1) * elem[i]);
            else
                sum += (least * elem[i]);
        }

        cout << sum << "\n";
    }

    return 0;
}
