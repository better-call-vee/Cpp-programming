/*
We're given a bunch of coins with different values, and our task is to calculate the total sum using
these coins. We're also given a specific target sum. Our goal is to determine if it's possible to
reach the target sum using the given coins, and if so, we need to find out how many different ways
we can achieve it.

It's quite the same problem as 0/1Knapsack variation subset sum problem.

Sample inputs:
4 2
3 6 4 10

5 18
12 4 16 18 2
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> coins;
vector<vector<int>> dp;

int coin_changeNOrep(int n, int target)
{
    if (n == 0)
    {
        if (target == 0)
            return 1;
        return 0;
    }

    if (dp[n][target] != -1)
        return dp[n][target];

    int ans1 = coin_changeNOrep(n - 1, target);
    if (target < coins[n])
    {
        dp[n][target] = ans1;
        return ans1;
    }
    int ans2 = coin_changeNOrep(n - 1, target - coins[n]);

    int ans = ans1 + ans2;
    dp[n][target] = ans;
    return ans;
}

int main()
{
    int n, target;
    cin >> n >> target;

    coins.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> coins[i];

    dp.resize(n + 1, vector<int>(target + 1, -1));

    if (dp[n][target] != -1)
    {
        cout << "YEA HAW TARGET IS REACHED BY THE COINS AND";
        cout << " IN" << coin_changeNOrep(n, target) << " DIFFERENT WAYS";
    }

    else
        cout << "OH HELL NO! WE'RE DOOMED";

    return 0;
}