#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, q, l, r;
        cin >> n >> q;
        vector<int> a(n + 2, 0);
        map<int, int> adjust;
        for(int i = 0; i < q; i++) {
            cin >> l >> r;
            a[l]++;
            a[r + 1]--;
            adjust[r + 1] -= (r - l + 1);
        }
        for(int i = 1; i <= n; i++) a[i] += a[i - 1];
        for(int i = 1; i <= n; i++) a[i] += a[i - 1], a[i] += adjust[i];
        for(int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    }
    return 0;
}

/*
https://www.codechef.com/problems/AGCY
See, here we first take the calculation of how many times each number is
occuring(line 19) then, we take the (i - L + 1) in mind according to the problem
statement, and go on, by doing another prefix some achieving that. Now this is
the clever part. Suppose, this case:
1
5 3
1 3
1 2
4 5
here, we get 2 2 1 1 1 after line 19.
then after executing line 20, for 2 we get 4, which is correct.
Then, for 3 we will get 5. which is incorrect. BUT, the very next line,
the map adjusts it!! So, where the range ends, we generally substract the extra
added value according to the need(r - l + 1);
*/