/*
Now We have to do the coin change problem but this time I can take coins repetitively
If the target is 8
and the coins vector has only one coin 1. We can take '1' 8 times and reach our target.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> coins;
vector<vector<int>> dp;

int coin_changerep(int n, int target)
{
    if (n == 0)
    {
        if (target == 0)
            return 1;
        return 0;
    }

    if (dp[n][target] != -1)
        return dp[n][target];

    int ans1 = coin_changerep(n - 1, target);
    if (target < coins[n])
    {
        dp[n][target] = ans1;
        return ans1;
    }

    int ans2 = 0;

    for (int i = 1; target >= i * coins[n]; i++)
        ans2 += coin_changerep(n - 1, target - i * coins[n]);

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

    dp[0][0] = 1;

    int result = coin_changerep(n, target);

    if (dp[n][target] != -1)
    {
        cout << "YEA HAW TARGET IS REACHED BY THE COINS AND";
        cout << " IN " << result << " DIFFERENT WAYS";
    }

    else if (dp[n][target] == -1)
        cout << "OH HELL NO! WE'RE DOOMED";

    return 0;
}