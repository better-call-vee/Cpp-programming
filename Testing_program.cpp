#include <bits/stdc++.h>
using namespace std;
#define N 200010

//https://codeforces.com/contest/1838/problem/B
/*
 by ensuring that the largest element n is placed between elements 1 and 2, the code covers
 all possible scenarios and guarantees that the number of permutation subarrays is minimized. 
*/
int idx[N];

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i)
        {
            int x;
            cin >> x;
            idx[x] = i;
        }

        if (idx[n] < min(idx[1], idx[2]))
            cout << idx[n] << ' ' << min(idx[1], idx[2]) << '\n';

        else if (idx[n] > max(idx[1], idx[2]))
            cout << idx[n] << ' ' << max(idx[1], idx[2]) << '\n';

        else
            cout << idx[1] << ' ' << idx[2] << '\n';
    }
    return 0;
}