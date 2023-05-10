//MEMORIZATION.
#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
const int mod = 1e9 + 7;
char grid[N][N];
int dp[N][N];

int grido(int n, int m)
{
    if (n == 0 && m == 0) return 1;
    if (dp[n][m] != -1) return dp[n][m];

    int ans = 0;
    if (n > 0 && grid[n - 1][m] != '*')
    {
        ans += grido(n - 1, m);
        ans %= mod;
    }
    if (m > 0 && grid[n][m - 1] != '*')
    {
        ans += grido(n, m - 1);
        ans %= mod;
    }
    dp[n][m] = ans;
    return dp[n][m];
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    if (grid[0][0] == '*' || grid[n-1][n-1] == '*')
    {
        cout << 0;
    }
    else
    {
        cout << grido(n - 1, n - 1);
    }

    return 0;
}


//TABULATION.
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    char grid[n][n];
    int dp[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    dp[0][0] = 1;

    if (grid[0][0] == '*' || grid[n-1][n-1] == '*')
    {
        cout << 0;
        return 0;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 && j==0) continue;

            int ans = 0;
            if(i>0 && grid[i-1][j] != '*')
            {
                ans += dp[i-1][j];
                ans %= mod;
            }
            if(j>0 && grid[i][j-1] != '*')
            {
                ans += dp[i][j-1];
                ans %= mod;
            }
            dp[i][j] = ans;
        }
    }

    cout << dp[n-1][n-1];

    return 0;
}

