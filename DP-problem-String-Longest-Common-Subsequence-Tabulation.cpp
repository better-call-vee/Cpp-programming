/*
There's an exception in this problem's tabulation method.
We can remember a grid path problem(unique paths) where we were
defining the base case as dp[0][0] = 1 and the recursive function was
fun(n, m) = fun(n-1, m) + fun(n, m-1); Here we can ususally find the answers if
we start the loop from 0.

But here we will define the base cases differently. It will be
clear if you can draw a dp array. We have to run the loop here reversely.
from n-1 to 0. Here we can't find the answers if we start the loop from 0.

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int n, m;
string s, t;

int main()
{
    cin >> s >> t;

    n = s.size();
    m = t.size();

    dp.resize(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++)
        dp[i][m] = 0;

    for (int j = 0; j <= m; j++)
        dp[n][j] = 0; // n for rows, m for columns

    // usually we would run a loop like this:
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    // }
    // }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (s[i] == t[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];

            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    cout << dp[0][0];

    return 0;
}

// BUT THERE's ANOTHER METHOD THROUGH WHICH WE CAN ACTUALLY DO WITHOUT REVERSING THE FOR
// LOOP CONDITION
// We were working i...n, j...m heretofore. LCS on suffix
// Now we will work on s[0...i], t[0...j]   LCS on prefix
/*

for(int i=0; i<=n; i++) {
    dp[i][0] = 0;
}

for(int j=0; j<=m; j++) {
    dp[0][j] = 0;
}

for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
        if(s[i-1] == t[j-1]) {
            dp[i][j] = 1+dp[i-1][j-1];
        }
        else {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[n][m];
}
*/