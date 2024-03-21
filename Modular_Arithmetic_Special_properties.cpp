/*
Property of Modulo Operation:

If you are calculating x mod m, and m is greater than x, then the result simply
equals x.

This happens because modulo calculates the remainder after division, and if m is
greater than x, you cannot divide x by m even once, so the remainder is just x.
If you are calculating x mod m, and m is less than or equal to x, then there are
two scenarios:

a. If m is less than or equal to x/2, then x mod m is less than or equal to x/2.
- This is due to the fact that once m surpasses x/2, the remainder must be less
than x/2 because m cannot fit into x more than once without exceeding x.

b. If m is greater than x/2, then x mod m is x - m, which is less than x/2.
- In this scenario, m can only be subtracted from x once, as subtracting it
twice would lead to a negative number, which isn't possible in modulo as it
deals with remainders. So the result must be x - m, which is smaller than x/2
because m is more than half of x.

Intuition:
=> When m is 1 or 20, the result is 20 because 20 mod 1 = 0 (20 is divisible by
1 with no remainder), and for any m greater than 20, the result is simply 20, as
explained in point 1.

=> When m is 2, 4, 5, or 10, the result is 0 because 20 is
exactly divisible by these numbers. For other values of m that are less than 20,
the result is the remainder of dividing 20 by m. For m larger than 10 but
smaller than 20, the results decrease from 9 to 1 as m increases, following the
logic that the remainder decreases as the divisor approaches the dividend.
*/

/*
Among the elements of a given array, the maximum mod of any possible pair will
be second maximum % maximum. There won't be any other mod which is greater than
this.
suppose, 5 4 1 8. here we can't get a mod larger than 5.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, tc = 0;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n;
        vector<ll> a(n + 1);
        priority_queue<pair<ll, int>> q;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            q.push({a[i], i});
        }
        ll Q;
        cin >> Q;
        while(Q--) {
            cin >> m;
            while(!q.empty()) {
                auto [x, i] = q.top();
                if(x < m) break;
                // when the number is less than m, means the value
                // will be always the value no matter the mod
                q.pop();
                q.push({x % m, i});
            }
        }
        while(!q.empty()) {
            auto [x, i] = q.top();
            q.pop();
            a[i] = x;
        }
        cout << "Case " << ++tc << ":\n";
        for(int i = 1; i <= n; i++) cout << a[i] << (i < n ? ' ' : '\n');
    }
    return 0;
}