/*
It's like the knapsack problem but we can take one item more than once which is actually called the
unbounded knapsack. It's quite likely the main knapsack problem. But here is a thing that we get the
concept from a problem named dice combinations.
we take an object as many times we can until it's not going out of the capacity.
and we will take the max of all cases.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int W = 1005;
long long dp[N][W];
int wt[N], val[N];

long long knapsack(int n, int cap)
{
    if (n == 0 || cap == 0)
        return 0;

    if (wt[n] > cap)
    {
        long long ans = knapsack(n - 1, cap);
        dp[n][cap] = ans;
        return ans;
    }

    if (dp[n][cap] != -1)
        return dp[n][cap];

    long long ans1 = 0;
    for (int i = 1; cap >= i * wt[n]; i++) // here are the main differences
        ans1 = max(ans1, val[n] * i + knapsack(n - 1, cap - i * wt[n]));

    long long ans2 = knapsack(n - 1, cap);

    long long ans = max(ans1, ans2);
    dp[n][cap] = ans;

    return ans;
}

int main()
{
    int n, w;
    cin >> n >> w;

    for (int i = 1; i <= n; i++)
        cin >> val[i];

    for (int i = 1; i <= n; i++)
        cin >> wt[i];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= w; j++)
            dp[i][j] = -1;

    cout << knapsack(n, w);

    return 0;
}
